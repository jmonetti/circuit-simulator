
#include <fstream>
#include <stdio.h>
#include "common_HiloComunicacion.h"
#include "modelo/circuito/common_Circuito.h"

HiloComunicacion::HiloComunicacion(ProtocoloServidor* protocolo) {

	this->protocolo= protocolo;

}

HiloComunicacion::~HiloComunicacion() {

	delete this->protocolo;

}

void HiloComunicacion::terminar() {

	protocolo->shutdown();
	this->stop();
	std::cerr<<"Cliente Desconectado"<<std::endl;

}

std::string HiloComunicacion::recibirPedido(int &codigoError) {

	std::string contPedidosAux;
	std::string linea;
	std::string mensaje;
	int contLineas = 0;
	std::string codigo;
	std::string length;
	std::string aux;
	do{
		protocolo->recibirMensaje(linea);
		if(contLineas == 0){
			codigo = linea.substr(0,3);
		}
			contLineas++;
		aux = linea.substr(0,16);
		if(aux == LENGTH){
			length = linea.substr(16);
		}
	}while(linea != "\n");

	if(codigo == "GET") {

		int longitud =  atoi(length.c_str());

		while(longitud >0) {
			protocolo->recibirMensaje(linea);
			mensaje += linea;
			longitud -= linea.size();
		}
		std::string ruta_pedido = ManagerArchivos::getInstancia()->getNombrePedido();
		ofstream output(ruta_pedido.c_str());
		output << mensaje;
		output.close();
		codigoError = 200;
		return ruta_pedido;

	}
	codigoError = 400;
	return NULL;
}

void HiloComunicacion::enviarRespuesta(const std::string &ruta, int &codigoError) {

	std::string total;

	if(codigoError == 200){
		if(ruta != STRNUEVOCIRCUITO) {
			ifstream fmensaje (ruta.c_str());
			std::string linea;

			std::string soap;

			while (std::getline(fmensaje,linea)) {

				soap+=linea + "\n";

			}

			total += "HTML/1.1 200 OK\n";

			std::string lenght;
		    std::stringstream converter;
		    converter << soap.size();
		    lenght = converter.str();

			total += "Content-Length: " + lenght + "\n\n";
			total += soap;
			protocolo->enviarMensaje(total);
		}
		else
		{

			total += "HTML/1.1 200 OK\n";
			total += "Content-Length: 0\n\n";
			protocolo->enviarMensaje(total);

		}
	} else {
		if (codigoError == 400) {
			total += "HTML/1.1 400 Bad Request\n";
			total += "Content-Length: 0\n\n";
			protocolo->enviarMensaje(total);
		}
	}


}

void* HiloComunicacion::run() {

	while (this->esta_Activo()) {

		int codigoError;

		std::string ruta_pedido = recibirPedido(codigoError);

		std::string ruta_respuesta = modelo.generarRespuesta(ruta_pedido);
		ManagerArchivos::getInstancia()->removerArchivo(ruta_pedido);
		if (ruta_respuesta.empty())
			codigoError = 400;

		enviarRespuesta(ruta_respuesta, codigoError);
		ManagerArchivos::getInstancia()->removerArchivo(ruta_respuesta);

		protocolo->desconectar();
		this->stop();
		std::cerr<<"Cliente Desconectado"<<std::endl;
	}
	return NULL;

}


