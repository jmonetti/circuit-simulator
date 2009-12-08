
#include "common_Peticion.h"

Peticion::Peticion() {
	// TODO Auto-generated constructor stub

}

Peticion::~Peticion() {
	// TODO Auto-generated destructor stub
}

bool* Peticion::simular(const std::string &nombreCircuito,Servidor servidor,bool* entradas,int cantidad) {

	return NULL;

}

int* Peticion::calcularTiempoTransicion(const std::string &nombreCircuito,Servidor servidor,int* tiempos,int cantidad) {

	return NULL;

}

std::string Peticion::generarPedido (std::string &nombreCircuito,int cantEntradas, bool* entradas) {

	XMLCh tempStr[100];

	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "GetSimulacion.xml";

	Persistencia::generarSOAP(impl,doc,ruta,Mensajes::GetSimular(doc,nombreCircuito,cantEntradas, entradas));

	return ruta;

}

std::string Peticion::generarPedido (std::string &nombreCircuito,int cantEntradas, int* entradas) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "GetTiempoSimulacion.xml";

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::GetTiempoSimulacion(doc,nombreCircuito));

	return ruta;


}

std::string Peticion::generarRespuesta (int cantSalidas, bool* salidas) {

	XMLCh tempStr[100];

	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "GetSimulacionResponse.xml";

	Persistencia::generarSOAP(impl,doc,ruta,Mensajes::GetSimularResponse(doc,cantSalidas, salidas));

	return ruta;

}

std::string Peticion::generarRespuesta (int cantSalidas, int* salidas) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "GetTiempoSimulacionResponse.xml";

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::GetTiempoSimulacionResponse(doc,cantSalidas, salidas));

	return ruta;

}

std::string Peticion::generarRespuesta () {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "PublicarCircuitoResponse.xml";

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::PublicarCircuitoResponse(doc));

	return ruta;

}

std::string Peticion::generarListaCircuitos(std::vector<Circuito*> circuitos) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "ListaCircuitos.xml";

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::GetListaCircuitosResponse(doc,circuitos));

	return ruta;

}

std::string Peticion::generarRespuesta(int cantEntradas, int cantSalidas) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "DatosCircuito.xml";

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::GetCircuitoResponse(doc,cantEntradas, cantSalidas));

	return ruta;

}
