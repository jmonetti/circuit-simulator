#include <fstream>
#include "common_Publicacion.h"
#include <iostream>
#include "../../common/common_Utils.h"


void Publicacion::enviar(const std::string &nombreCircuito,Servidor servidor) {

	Persistencia persistencia;
	Circuito* circuito= persistencia.recuperar(0,nombreCircuito);

	std::string ruta = publicarCircuito(circuito);

	conectar(servidor);
	enviarMensaje(ruta);
	recibirMensaje();

}

bool* Publicacion::simular(const std::string &nombreCircuito,Servidor servidor,bool* entradas,int cantidad) {

	return NULL;

}

int* Publicacion::calcularTiempoTransicion(const std::string &nombreCircuito,Servidor servidor,int* tiempos,int cantidad) {

	return NULL;

}

TamanioCajaNegra Publicacion::recibir(const std::string &nombreCircuito,Servidor servidor,Circuito* circuito) {

	return TamanioCajaNegra(17,20);

}

std::vector<char*>* Publicacion::obtenerCircuitos(Servidor servidor) {

	std::vector<char*>* circuitos= new std::vector<char*>();

	Utils::obtenerArchivos(PATH_SAVES,circuitos);

	return circuitos;

}

std::string Publicacion::generarPedido (std::string &nombreCircuito,int cantEntradas, bool* entradas) {

	XMLCh tempStr[100];

	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "GetSimulacion.xml";

	Persistencia::generarSOAP(impl,doc,ruta,Mensajes::GetSimular(doc,nombreCircuito,cantEntradas, entradas));

	return ruta;

}

std::string Publicacion::generarPedido (std::string &nombreCircuito,int cantEntradas, int* entradas) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "GetTiempoSimulacion.xml";

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::GetTiempoSimulacion(doc,nombreCircuito,cantEntradas, entradas));

	return ruta;


}


std::string Publicacion::publicarCircuito(Circuito *circuito) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "PublicarCircuito.xml";

	Persistencia::generarSOAP(impl,doc,ruta, circuito->obtenerCircuito(doc));

	return ruta;

}

std::string Publicacion::generarPedido() {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "GetListaCircuitos.xml";

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::GetListaCircuitos(doc));

	return ruta;

}

std::string Publicacion::generarPedido(std::string nombreCircuito) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "GetCircuito.xml";

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::GetCircuito(doc, nombreCircuito));

	return ruta;

}

void Publicacion::conectar(Servidor servidor) {

	protocolo.conectar(servidor);

}
void Publicacion::enviarMensaje(const std::string &mensaje) {


	ifstream fmensaje (mensaje.c_str());
	std::string linea;

	std::string total;

	while (std::getline(fmensaje,linea)) {

		total+=linea + "\n";

	}

	protocolo.enviarMensaje(total);

}

std::string Publicacion::recibirMensaje() {

	std::string linea;
	std::string mensaje;
	protocolo.recibirMensaje(linea);
	/* Codigo de error: chequeo codigo de error q llega en la primera linea
	 * desde el caracter 8 al 13
	 */
	std::string codigoError = linea.substr(8,3);
	protocolo.recibirMensaje(linea);
	std::string length = linea.substr(16);
	if(codigoError == "400") {
		throw runtime_error("Pedido Invalido");
	}
	if(codigoError == "200") {
		int longitud =  atoi(length.c_str());

		protocolo.recibirMensaje(linea);

		while(longitud >0) {
			protocolo.recibirMensaje(linea);
			mensaje += linea;
			longitud -= linea.size();
		}

		return mensaje;

	}
	throw runtime_error("Codigo de error HTML invalido - recibirMensaje()");

}

