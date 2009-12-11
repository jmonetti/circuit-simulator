#include <stdexcept>

#include <sys/types.h>
#include <sys/stat.h>

#include <errno.h>
#include "../circuito/common_Circuito.h"

#include "common_Mensajes.h"

DOMElement* Mensajes::GetSimular(DOMDocument* doc,const std::string &nombreCircuito,int cantEntradas, bool* entradas) {

	XMLCh tempStr [99];
	std::string aux;

	XMLString::transcode("GetSimulacion",tempStr,99);
	DOMElement *funcion = doc->createElement(tempStr);

    XMLString::transcode("nombreCircuito", tempStr, 99);
    DOMElement* nombre = doc->createElement(tempStr);

    XMLString::transcode(nombreCircuito.c_str(),tempStr,99);
    nombre->setTextContent(tempStr);
    funcion->appendChild(nombre);

    for(int i=0;i<cantEntradas;++i){
    	aux = "Entrada";
    	Persistencia::guardarElementoTexto(doc,funcion,aux,entradas[i]);
    }

    return funcion;

}

DOMElement* Mensajes::GetTiempoSimulacion(DOMDocument* doc,const std::string &nombreCircuito, int cantEntradas, int* entradas) {

	XMLCh tempStr [99];
	std::string aux;

	XMLString::transcode("GetTiempoSimulacion",tempStr,99);
	DOMElement *funcion = doc->createElement(tempStr);

    XMLString::transcode("nombreCircuito", tempStr, 99);
    DOMElement* nombre = doc->createElement(tempStr);

    XMLString::transcode(nombreCircuito.c_str(),tempStr,99);
    nombre->setTextContent(tempStr);
    funcion->appendChild(nombre);

    for(int i=0;i<cantEntradas;++i){
    	aux = "Entrada";
    	Persistencia::guardarElementoTexto(doc,funcion,aux,entradas[i]);
    }

    return funcion;

}

DOMElement* Mensajes::GetSimularResponse(DOMDocument* doc,int cantSalidas, bool* salidas) {

	XMLCh tempStr [99];
	std::string aux;

	XMLString::transcode("GetSimulacionResponse",tempStr,99);
	DOMElement *funcion = doc->createElement(tempStr);

    for(int i=0;i<cantSalidas;++i){
    	aux = "salida";
    	Persistencia::guardarElementoTexto(doc,funcion,aux,salidas[i]);
    }

    return funcion;

}

DOMElement* Mensajes::GetTiempoSimulacionResponse(DOMDocument* doc,int cantSalidas, int* salidas) {

	XMLCh tempStr [99];
	std::string aux;

	XMLString::transcode("GetTiempoSimulacionResponse",tempStr,99);
	DOMElement *funcion = doc->createElement(tempStr);

    for(int i=0;i<cantSalidas;++i){
    	aux = "TiempoSalida";
    	Persistencia::guardarElementoTexto(doc,funcion,aux,salidas[i]);
    }

    return funcion;

}

DOMElement* Mensajes::GetListaCircuitosResponse(DOMDocument* doc, std::vector<char*> circuitos) {

	XMLCh tempStr[100];

	XMLCh tempStrNombre[100];

	XMLString::transcode("GetListaCircuitosResponse",tempStr,99);
	DOMElement* elem_circuitos = doc->createElement(tempStr);

	for (unsigned int var = 0; var < circuitos.size(); ++var) {

		XMLString::transcode("nombreCircuito", tempStrNombre, 99);
		DOMElement*   elem_circuito = doc->createElement(tempStrNombre);

		XMLString::transcode(circuitos[var],tempStrNombre,99);
		elem_circuito->setTextContent(tempStrNombre);

		elem_circuitos->appendChild(elem_circuito);

		delete[] circuitos[var];
	}

	return elem_circuitos;

}

DOMElement* Mensajes::GetCircuitoResponse(DOMDocument* doc, int cantEntradas, int cantSalidas) {

	XMLCh tempStr[100];

	XMLString::transcode("GetCircuitoResponse",tempStr,99);
	DOMElement* elem_datos = doc->createElement(tempStr);

	std::string aux = "cantEntradas";
	Persistencia::guardarElementoTexto(doc,elem_datos,aux,cantEntradas);


	aux = "cantSalidas";
	Persistencia::guardarElementoTexto(doc,elem_datos,aux,cantSalidas);


    return elem_datos;

}


