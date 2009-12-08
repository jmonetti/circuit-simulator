
#include "common_Publicacion.h"
#include <iostream>
#include "../../common/common_Utils.h"


void Publicacion::enviar(const std::string &nombreCircuito,Servidor servidor) {


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
