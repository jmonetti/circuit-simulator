#include <stdexcept>

#include <sys/types.h>
#include <sys/stat.h>

#include <errno.h>
#include "../circuito/common_Circuito.h"

#include "common_Mensajes.h"

DOMElement* Mensajes::GetSimular(DOMDocument* doc,std::string &nombreCircuito,int cantEntradas, bool* entradas) {

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

DOMElement* Mensajes::GetTiempoSimulacion(DOMDocument* doc,std::string &nombreCircuito,int cantEntradas, int* entradas) {

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
    	aux = "TiempoEntrada";
    	Persistencia::guardarElementoTexto(doc,funcion,aux,entradas[i]);
    }

    return funcion;

}

DOMElement* Mensajes::GetListaCircuitos(DOMDocument* doc) {

	XMLCh tempStr [99];
	std::string aux;

	XMLString::transcode("GetListaCircuitos",tempStr,99);
	DOMElement *funcion = doc->createElement(tempStr);

	return funcion;

}

DOMElement* Mensajes::GetCircuito(DOMDocument* doc, std::string &nombreCircuito) {

	XMLCh tempStr [99];
	std::string aux;

	XMLString::transcode("GetCircuito",tempStr,99);
	DOMElement *funcion = doc->createElement(tempStr);

    XMLString::transcode("nombreCircuito", tempStr, 99);
    DOMElement* nombre = doc->createElement(tempStr);

    XMLString::transcode(nombreCircuito.c_str(),tempStr,99);
    nombre->setTextContent(tempStr);
    funcion->appendChild(nombre);

    return funcion;

}

