#include <fstream>
#include <stdexcept>
#include "common_Publicacion.h"
#include <iostream>
#include <sstream>
#include "../../common/common_Utils.h"
#include <stdexcept>
#include <stdio.h>
#include "../../excepciones/common_PublicacionException.h"
#include "../../excepciones/common_SocketException.h"


void Publicacion::enviar(const std::string &nombreCircuito,Servidor servidor) {

	Persistencia persistencia;
	Circuito* circuito= persistencia.recuperarCircuito(0,nombreCircuito);

	std::string ruta = publicarCircuito(circuito);

	try {

		conectar(servidor);
		enviarPedido(ruta);
		remove(ruta.c_str());
		std::string respuesta = recibirRespuesta();
		remove(respuesta.c_str());
		protocolo.desconectar();

	} catch (SocketException e) {

		protocolo.desconectar();
		throw PublicacionException("Error al enviar el circuito");

	}

}

void Publicacion::simular(const std::string &nombreCircuito,Servidor servidor,bool* entradas,int cantidad,bool* salidas) {

	std::string ruta = generarPedidoSimulacion(nombreCircuito,cantidad,entradas);

	try {

		conectar(servidor);
		enviarPedido(ruta);
		remove(ruta.c_str());
		std::string respuesta = recibirRespuesta();
		ofstream frespuesta ("temp/GetSimulacionResponse.xml");
		frespuesta << respuesta;
		frespuesta.close();
		ruta = "temp/GetSimulacionResponse.xml";
		recuperarDatosSimular(ruta,salidas);
		remove(ruta.c_str());

		protocolo.desconectar();

	} catch (SocketException e) {

		protocolo.desconectar();
		throw PublicacionException("Error al simular el circuito en servidor");

	}

}

void Publicacion::calcularTiempoTransicion(const std::string &nombreCircuito,Servidor servidor,int* tiempos,int cantidad,int* salidas) {

	std::string ruta = generarPedidoTiempoSimulacion(nombreCircuito,cantidad,tiempos);

	try {

		conectar(servidor);
		enviarPedido(ruta);
		remove(ruta.c_str());
		std::string respuesta = recibirRespuesta();
		ofstream frespuesta ("temp/GetTiempoSimulacionResponse.xml");
		frespuesta << respuesta;
		frespuesta.close();
		ruta = "temp/GetTiempoSimulacionResponse.xml";
		recuperarDatosTiempos(ruta,salidas);
		remove(ruta.c_str());

		protocolo.desconectar();

	} catch (SocketException e) {

		protocolo.desconectar();
		throw PublicacionException("Error al calcular tiempos del circuito en servidor");

	}

}

TamanioCajaNegra Publicacion::recibir(const std::string &nombreCircuito,Servidor servidor) {

	std::string ruta = generarPedidoCircuito(nombreCircuito);

	try {

		conectar(servidor);
		enviarPedido(ruta);
		remove(ruta.c_str());
		std::string respuesta = recibirRespuesta();
		ofstream frespuesta ("temp/GetCircuitoResponse.xml");
		frespuesta << respuesta;
		frespuesta.close();
		ruta = "temp/GetCircuitoResponse.xml";
		TamanioCajaNegra tamanio = recuperarDatosCajaNegra(ruta);
		remove(ruta.c_str());

		protocolo.desconectar();
		return tamanio;

	} catch (SocketException e) {

		protocolo.desconectar();
		throw PublicacionException("Error al recibir circuito");

	}

}

void Publicacion::obtenerCircuitos(Servidor servidor,std::vector<char*>* circuitos) {

	std::string ruta = generarPedidoListaCircuitos();

	try {

		conectar(servidor);
		enviarPedido(ruta);
		remove(ruta.c_str());
		std::string respuesta = recibirRespuesta();
		ofstream frespuesta ("temp/GetListaCircuitosResponse.xml");
		frespuesta << respuesta;
		frespuesta.close();
		ruta = "temp/GetListaCircuitosResponse.xml";
		recuperarDatosCircuitos(ruta,circuitos);
		remove(ruta.c_str());

		protocolo.desconectar();

	} catch (SocketException e) {

		protocolo.desconectar();
		throw PublicacionException("Error al recibir la lista de circuitos");

	}

}

Circuito* Publicacion::verCajaNegra(const std::string &nombreCajaNegra, Servidor servidor) {


	std::string ruta = generarPedidoDisenio(nombreCajaNegra);

	try {

		conectar(servidor);
		enviarPedido(ruta);
		remove(ruta.c_str());
		std::string respuesta = recibirRespuesta();
		ofstream frespuesta ("temp/GetDisenioResponse.xml");
		frespuesta << respuesta;
		frespuesta.close();
		ruta = "temp/GetDisenioResponse.xml";
		Circuito* cajaNegra = recuperarDisenioCajaNegra(ruta);
		remove(ruta.c_str());

		protocolo.desconectar();
		return cajaNegra;

	} catch (SocketException e) {

		protocolo.desconectar();
		throw PublicacionException("Error al recibir el diseño del circuito Caja Negra");

	}

}

std::string Publicacion::generarPedidoSimulacion (const std::string &nombreCircuito,int cantEntradas, bool* entradas) {

	XMLCh tempStr[100];

	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "temp/GetSimulacion.xml";

	Persistencia::generarSOAP(impl,doc,ruta,Mensajes::GetSimular(doc,nombreCircuito,cantEntradas, entradas));

	return ruta;

}

std::string Publicacion::generarPedidoTiempoSimulacion (const std::string &nombreCircuito,int cantEntradas, int* entradas) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "temp/GetTiempoSimulacion.xml";

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::GetTiempoSimulacion(doc,nombreCircuito,cantEntradas, entradas));

	return ruta;


}


std::string Publicacion::publicarCircuito(Circuito *circuito) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "temp/PublicarCircuito.xml";

	Persistencia::generarSOAP(impl,doc,ruta, circuito->obtenerCircuito(doc));

	return ruta;

}

std::string Publicacion::generarPedidoListaCircuitos() {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "temp/GetListaCircuitos.xml";

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::GetListaCircuitos(doc));

	return ruta;

}

std::string Publicacion::generarPedidoCircuito(const std::string &nombreCircuito) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "temp/GetCircuito.xml";

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::GetCircuito(doc, nombreCircuito));

	return ruta;

}

std::string Publicacion::generarPedidoDisenio(const std::string &nombreCircuito) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "temp/GetDisenio.xml";

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::GetDisenio(doc, nombreCircuito));

	return ruta;

}

void Publicacion::conectar(Servidor servidor) {

	protocolo.conectar(servidor);

}

void Publicacion::enviarPedido(const std::string &ruta) {

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
    converter << soap.size();
    lenght = converter.str();

	total += "Content-Length: " + lenght + "\n\n";
	total += soap;
	protocolo.enviarMensaje(total);

}

std::string Publicacion::recibirRespuesta() {

	std::string linea;
	std::string mensaje;
	protocolo.recibirMensaje(linea);
	/* Codigo de error: chequeo codigo de error q llega en la primera linea
	 * desde el caracter 8 al 13
	 */

	std::string codigoError = linea.substr(9,3);

	protocolo.recibirMensaje(linea);

	std::string length = linea.substr(16);

	protocolo.recibirMensaje(linea);
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
	throw runtime_error("Codigo de error HTML invalido - recibirRespuesta()");

}

void Publicacion::recuperarDatosSimular(const std::string &ruta,bool* salidas) {

	Persistencia persistencia;

	std::string elemento = "GetSimulacionResponse";
	DOMElement* elem_salidas = persistencia.getElemSOAP(ruta,elemento );

	DOMNodeList* lista_attr = elem_salidas->getChildNodes();
	DOMNode* atributo;
	std::string str_valor;
	bool  valor;
	DOMElement* ElemCte;
	int j= 0;
	for (unsigned int i = 0; i<lista_attr->getLength() ; ++i) {

		atributo = lista_attr->item(i);
		if( atributo->getNodeType() &&  // true is not NULL
		 atributo->getNodeType() == DOMNode::ELEMENT_NODE ) // is element
		{
			ElemCte = dynamic_cast < xercesc::DOMElement* > ( atributo );
			str_valor = persistencia.recuperarDatoTexto(ElemCte);
			if (str_valor == "0")
				valor = false;
			else
				valor = true;
			salidas[j] = valor;
			j++;
		}
	}

}

void Publicacion::recuperarDatosTiempos(const std::string &ruta,int* salidas) {


	Persistencia persistencia;

	std::string elemento = "GetTiempoSimulacionResponse";
	DOMElement* elem_salidas = persistencia.getElemSOAP(ruta,elemento );

	DOMNodeList* lista_attr = elem_salidas->getChildNodes();
	DOMNode* atributo;
	std::string str_salida;
	int salida;
	DOMElement* ElemCte;
	int j= 0;
	for (unsigned int i = 0; i<lista_attr->getLength(); ++i) {

		atributo = lista_attr->item(i);
		if( atributo->getNodeType() &&  // true is not NULL
		 atributo->getNodeType() == DOMNode::ELEMENT_NODE ) // is element
		{
			ElemCte = dynamic_cast < xercesc::DOMElement* > ( atributo );
			str_salida = persistencia.recuperarDatoTexto(ElemCte);
			salida = atoi(str_salida.c_str());
			salidas[j] = salida;
			j++;
		}
	}

}


TamanioCajaNegra Publicacion::recuperarDatosCajaNegra(const std::string &ruta) {

	Persistencia persistencia;

	std::string elemento = "GetCircuitoResponse";
	DOMElement* elem_conexiones = persistencia.getElemSOAP(ruta,elemento );

	XMLCh tempStr[30];
	XMLString::transcode("cantEntradas",tempStr,29);
	DOMNodeList* lista_entradas = elem_conexiones->getElementsByTagName(tempStr);
	DOMNode* atributo = lista_entradas->item(0);
	DOMElement* ElemCte = dynamic_cast < xercesc::DOMElement* > ( atributo );

	std::string aux = persistencia.recuperarDatoTexto(ElemCte);
	int cantEntradas = atoi(aux.c_str());

	XMLString::transcode("cantSalidas",tempStr,29);
	DOMNodeList* lista_salidas = elem_conexiones->getElementsByTagName(tempStr);
	atributo = lista_salidas->item(0);
	ElemCte = dynamic_cast < xercesc::DOMElement* > ( atributo );

	aux = persistencia.recuperarDatoTexto(ElemCte);

	int cantSalidas = atoi(aux.c_str());

	TamanioCajaNegra tamanio(cantEntradas,cantSalidas);

	return tamanio;

}

void Publicacion::recuperarDatosCircuitos(const std::string &ruta,std::vector<char*>* circuitos) {

	Persistencia persistencia;

	std::string elemento = "GetListaCircuitosResponse";
	DOMElement* elem_lista = persistencia.getElemSOAP(ruta,elemento );

	DOMNodeList* lista_attr = elem_lista->getChildNodes();
	DOMNode* atributo;
	std::string nombre;
	DOMElement* ElemCte;
	unsigned int length = lista_attr->getLength();
	char* aux;

	for (unsigned int i = 0; i<length; ++i) {

		atributo = lista_attr->item(i);
		if( atributo->getNodeType() &&  // true is not NULL
		atributo->getNodeType() == DOMNode::ELEMENT_NODE ) // is element
		{
			ElemCte = dynamic_cast < xercesc::DOMElement* > ( atributo );

			nombre = persistencia.recuperarDatoTexto(ElemCte);

			aux= new char[nombre.size() + 1];
			aux[nombre.size()] = '\0';
			nombre.copy(aux,nombre.size());
			circuitos->push_back(aux);
		}
	}

}

Circuito* Publicacion::recuperarDisenioCajaNegra(const std::string &ruta) {

	Persistencia persistencia;

	std::string elemento = "Circuito";
	DOMElement* elem_Circuito = persistencia.getElemSOAP(ruta,elemento );

	std::string aux;

	aux = persistencia.obtenerNombre(elem_Circuito);
	Circuito* circuito = persistencia.parserCircuito(elem_Circuito, 0, aux);

	return circuito;


}
