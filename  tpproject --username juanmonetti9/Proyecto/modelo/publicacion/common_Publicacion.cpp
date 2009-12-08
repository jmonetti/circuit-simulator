#include <fstream>
#include <stdexcept>
#include "common_Publicacion.h"
#include <iostream>
#include <sstream>
#include "../../common/common_Utils.h"
#include <stdexcept>


void Publicacion::enviar(const std::string &nombreCircuito,Servidor servidor) {

	Persistencia persistencia;
	Circuito* circuito= persistencia.recuperar(0,nombreCircuito);

	std::string ruta = publicarCircuito(circuito);

	conectar(servidor);
	enviarMensaje(ruta);
	std::string respuesta = recibirMensaje();
	protocolo.desconectar();
}

bool* Publicacion::simular(const std::string &nombreCircuito,Servidor servidor,bool* entradas,int cantidad) {

	std::string ruta = generarPedido(nombreCircuito,cantidad,entradas);

	conectar(servidor);
	enviarMensaje(ruta);
	std::string respuesta = recibirMensaje();
	ofstream frespuesta ("temp/respuesta.xml");
	frespuesta.write(respuesta.c_str(),respuesta.size());
	ruta = "temp/respuesta.xml";
	bool* salidas = recuperarDatosSimular(ruta);

	protocolo.desconectar();

	return salidas;

}

int* Publicacion::calcularTiempoTransicion(const std::string &nombreCircuito,Servidor servidor,int* tiempos,int cantidad) {

	std::string ruta = generarPedido(nombreCircuito,cantidad,tiempos);

	conectar(servidor);
	enviarMensaje(ruta);
	std::string respuesta = recibirMensaje();
	ofstream frespuesta ("temp/respuesta.xml");
	frespuesta.write(respuesta.c_str(),respuesta.size());
	ruta = "temp/respuesta.xml";
	int* salidas_tiempos = recuperarDatosTiempos(ruta);

	protocolo.desconectar();

	return salidas_tiempos;

}

TamanioCajaNegra Publicacion::recibir(const std::string &nombreCircuito,Servidor servidor,Circuito* circuito) {

	return TamanioCajaNegra(17,20);

}

std::vector<char*>* Publicacion::obtenerCircuitos(Servidor servidor) {

	std::vector<char*>* circuitos= new std::vector<char*>();

	Utils::obtenerArchivos(PATH_SAVES,circuitos);

	return circuitos;

}

std::string Publicacion::generarPedido (const std::string &nombreCircuito,int cantEntradas, bool* entradas) {

	XMLCh tempStr[100];

	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "GetSimulacion.xml";

	Persistencia::generarSOAP(impl,doc,ruta,Mensajes::GetSimular(doc,nombreCircuito,cantEntradas, entradas));

	return ruta;

}

std::string Publicacion::generarPedido (const std::string &nombreCircuito,int cantEntradas, int* entradas) {

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

std::string Publicacion::generarPedido(const std::string nombreCircuito) {

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
void Publicacion::enviarMensaje(const std::string &ruta) {

	ifstream fmensaje (ruta.c_str());
	std::string linea;

	std::string soap;
	std::string total;

	while (std::getline(fmensaje,linea)) {

		soap+=linea + "\n";

	}

	total += "GET HTTP/1.1\n";

	std::string lenght;
    std::stringstream converter;
    converter << total.size();
    lenght = converter.str();

	total += "Contenten-Length: " + lenght + "\n\n";
	total += soap;
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
	protocolo.recibirMensaje(linea);
	std::string length = linea.substr(16);
	if(codigoError == "400") {
		throw runtime_error("Pedido Invalido");
	}
	if(codigoError == "200") {
		int longitud =  atoi(length.c_str());

		while(longitud >0) {
			protocolo.recibirMensaje(linea);
			mensaje += linea;
			longitud -= linea.size();
		}

		return mensaje;

	}
	throw runtime_error("Codigo de error HTML invalido - recibirMensaje()");

}

bool* Publicacion::recuperarDatosSimular(std::string &ruta) {

	Persistencia persistencia;

	std::string elemento = "GetSimulacionResponse";
	DOMElement* elem_salidas = persistencia.getElemSOAP(ruta,elemento );

	DOMNodeList* lista_attr = elem_salidas->getChildNodes();
	DOMNode* atributo;
	bool* salidas = new bool[lista_attr->getLength()];
	std::string str_valor;
	bool  valor;
	DOMElement* ElemCte;
	for (unsigned int i = 0; i<lista_attr->getLength() ; ++i) {

		atributo = lista_attr->item(i);
		ElemCte = dynamic_cast < xercesc::DOMElement* > ( atributo );
		str_valor = persistencia.recuperarDatoTexto(ElemCte);
		if (str_valor == "0")
			valor = false;
		else
			valor = true;
		salidas[i] = valor;

	}

	return salidas;

}

int* Publicacion::recuperarDatosTiempos(std::string &ruta) {


	Persistencia persistencia;

	std::string elemento = "GetTiempoSimulacionResponse";
	DOMElement* elem_salidas = persistencia.getElemSOAP(ruta,elemento );

	DOMNodeList* lista_attr = elem_salidas->getChildNodes();
	DOMNode* atributo;
	int* salidas = new int[lista_attr->getLength()];
	std::string str_salida;
	int salida;
	DOMElement* ElemCte;
	for (unsigned int i = 0; i<lista_attr->getLength(); ++i) {

		atributo = lista_attr->item(i);
		ElemCte = dynamic_cast < xercesc::DOMElement* > ( atributo );
		str_salida = persistencia.recuperarDatoTexto(ElemCte);
		salida = atoi(str_salida.c_str());
		salidas[i] = salida;

	}

	return salidas;

}

