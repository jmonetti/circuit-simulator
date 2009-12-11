#include <fstream>
#include <stdexcept>
#include "common_Peticion.h"



void Peticion::simular(const std::string &nombreCircuito,Servidor servidor,bool* entradas,int cantidad,bool* salidas) {

	std::string ruta = generarPedido(nombreCircuito,cantidad,entradas);

	conectar(servidor);
	enviarPedido(ruta);
	std::string respuesta = recibirRespuesta();
	ofstream frespuesta ("temp/GetSimulacionResponse.xml");
	frespuesta << respuesta;
	frespuesta.close();
	ruta = "temp/GetSimulacionResponse.xml";
	recuperarDatosSimular(ruta,salidas);

	protocolo.desconectar();


}

void Peticion::calcularTiempoTransicion(const std::string &nombreCircuito,Servidor servidor,int* tiempos,int cantidad,int* salidas) {

	std::string ruta = generarPedido(nombreCircuito,cantidad,tiempos);

	conectar(servidor);
	enviarPedido(ruta);
	std::string respuesta = recibirRespuesta();
	ofstream frespuesta ("temp/GetTiempoSimulacionResponse.xml");
	frespuesta << respuesta;
	frespuesta.close();
	//frespuesta.write(respuesta.c_str(),respuesta.size()); TODO
	ruta = "temp/GetTiempoSimulacionResponse.xml";
	recuperarDatosTiempos(ruta,salidas);

	protocolo.desconectar();


}


void Peticion::conectar(Servidor servidor) {

	protocolo.conectar(servidor);

}

void Peticion::enviarPedido(const std::string &ruta) {

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

std::string Peticion::recibirRespuesta() {

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

void Peticion::recuperarDatosSimular(const std::string &ruta,bool* salidas) {

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

void Peticion::recuperarDatosTiempos(const std::string &ruta,int* salidas) {


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

std::string Peticion::generarPedido (const std::string &nombreCircuito,int cantEntradas, bool* entradas) {

	XMLCh tempStr[100];

	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "temp/GetSimulacion.xml";

	Persistencia::generarSOAP(impl,doc,ruta,Mensajes::GetSimular(doc,nombreCircuito,cantEntradas, entradas));

	return ruta;

}

std::string Peticion::generarPedido (const std::string &nombreCircuito,int cantEntradas, int* entradas) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "temp/GetTiempoSimulacion.xml";

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::GetTiempoSimulacion(doc,nombreCircuito,cantEntradas, entradas));

	return ruta;


}
