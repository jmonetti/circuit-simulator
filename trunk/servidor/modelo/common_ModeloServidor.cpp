
#include "common_ModeloServidor.h"
#include "circuito/common_Circuito.h"
#include <vector>
#include "circuito/compuertas/common_Entrada.h"
#include "../common/common_Utils.h"
#include <fstream>

ModeloServidor::ModeloServidor() {

}

ModeloServidor::~ModeloServidor() {


}


bool* ModeloServidor::simular(Circuito* circuito,bool* entradas) {

	bool* salidas= circuito->simular(entradas);

	return salidas;

}

int* ModeloServidor::calcularTiempoTransicion(Circuito* circuito, int* entradas) {

	std::vector<Entrada*> entradasCircuito = circuito->getEntradas();
	for (unsigned int var = 0; var < entradasCircuito.size(); ++var) {

		entradasCircuito[var]->setTiempo(entradas[var]);

	}

	int* tiempos= circuito->calcularTiempoTransicion();

	return tiempos;

}

void ModeloServidor::recuperarDatosSimular(DOMNodeList* atributos, std::string &nombre, bool* entradas) {

	DOMNode* atributo;
	unsigned int cant = atributos->getLength();
	DOMElement* ElemCte;
	std::string valor;
	bool entrada;
	int contadorEntradas = 0;
	for (unsigned int i = 2; i<cant; ++i) {

		atributo = atributos->item(i);
		if( atributo->getNodeType() &&  // true is not NULL
		 atributo->getNodeType() == DOMNode::ELEMENT_NODE ) // is element
		{
			ElemCte = dynamic_cast < xercesc::DOMElement* > ( atributo );
			valor = persistencia.recuperarDatoTexto(ElemCte);

			if(valor == "0")
				entrada = false;
			else
				entrada = true;

			entradas[contadorEntradas] = entrada;
			contadorEntradas++;
		}
	}

}

void ModeloServidor::recuperarDatosTiempos(DOMNodeList* atributos, std::string &nombre, int* entradas) {

	DOMNode* atributo;
	int cant = atributos->getLength();
	DOMElement* ElemCte;
	std::string valor;
	int entrada;
	int contadorEntradas = 0;
	for (int i = 2; i<cant; ++i) {

		atributo = atributos->item(i);

		if( atributo->getNodeType() &&  // true is not NULL
		 atributo->getNodeType() == DOMNode::ELEMENT_NODE ) // is element
		{
			ElemCte = dynamic_cast < xercesc::DOMElement* > ( atributo );
			valor = persistencia.recuperarDatoTexto(ElemCte);
			entrada = atoi(valor.c_str());
			entradas[contadorEntradas] = entrada;
			contadorEntradas++;
		}
	}

}


void ModeloServidor::obtenerDatosCircuito(std::string &nombre,int &cantEntradas,int &cantSalidas) {

	Circuito* circuito = persistencia.recuperarCircuito(0,nombre);

	cantEntradas = circuito->getCantidadEntradas();

	cantSalidas = circuito->getCantidadSalidas();

	delete circuito;

}

std::string ModeloServidor::generarRespuesta(std::string& ruta_pedido) {

	TIPO_SOAP tipo;
	std::string aux;

	DOMElement* funcion = persistencia.getTipoSOAP(ruta_pedido,tipo);

	switch (tipo) {

		case LISTA: {
			std::vector<char*> circuitos;
			Utils::obtenerArchivos(PATH_SAVES,&circuitos);

			aux = generarListaCircuitos(circuitos);

			return aux;

		}

		case CIRCUITO: {
			DOMNodeList* list_aux = funcion->getChildNodes();
			DOMNode* circuito;
			for (unsigned int var = 0; var < list_aux->getLength(); ++var) {
				circuito = list_aux->item(var);
				if( circuito->getNodeType() &&  // true is not NULL
				 circuito->getNodeType() == DOMNode::ELEMENT_NODE ) // is element
				{
					DOMElement* elem_nombre = dynamic_cast < xercesc::DOMElement* > ( circuito );
					std::string nombre = persistencia.recuperarDatoTexto(elem_nombre);
					int cantEntradas;
					int cantSalidas;
					obtenerDatosCircuito(nombre,cantEntradas,cantSalidas);
					aux = generarRespuesta(cantEntradas,cantSalidas);
				}
			}

			return aux;

		}

		case NUEVOCIRCUITO: {

			aux = persistencia.obtenerNombre(funcion);
			Circuito* circuito = persistencia.parserCircuito(funcion, 0, aux);
			persistencia.guardarCircuito(*circuito);
			aux = STRNUEVOCIRCUITO;

			delete circuito;

			return aux;
		}

		case SIMULAR: {
			DOMNodeList* atributos = funcion->getChildNodes();
			std::string nombre;

			DOMNode* nodo_circuito = atributos->item(1);
			DOMElement* nombre_circuito = dynamic_cast < xercesc::DOMElement* > ( nodo_circuito );
			nombre = Persistencia::recuperarDatoTexto(nombre_circuito);

			Circuito* circuito= persistencia.recuperarCircuito(0,nombre);

			bool* entradas = new bool[circuito->getCantidadEntradas()];
			recuperarDatosSimular(atributos,nombre,entradas);
			bool* salidas = simular(circuito,entradas);
			int cantSalidas = circuito->getCantidadSalidas();
			aux = generarRespuesta(cantSalidas, salidas);
			cout<<aux<<endl;
			delete[] entradas;
			delete[] salidas;
			delete circuito;
			return aux;

		}

		case SIMULARTIEMPO: {
			DOMNodeList* atributos = funcion->getChildNodes();
			std::string nombre;
			DOMNode* nodo_circuito = atributos->item(1);
			DOMElement* nombre_circuito = dynamic_cast < xercesc::DOMElement* > ( nodo_circuito );
			nombre = Persistencia::recuperarDatoTexto(nombre_circuito);

			Circuito* circuito= persistencia.recuperarCircuito(0,nombre);

			int* entradas = new int[circuito->getCantidadEntradas()];
			recuperarDatosTiempos(atributos,nombre,entradas);

			int* tiempos = calcularTiempoTransicion(circuito,entradas);
			int cantSalidas = circuito->getCantidadSalidas();
			aux = generarRespuesta(cantSalidas, tiempos);
			delete[] entradas;
			delete[] tiempos;
			delete circuito;
			return aux;

		}

		case DISENIO: {

			DOMNodeList* atributos = funcion->getChildNodes();
			std::string nombre;
			DOMNode* nodo_circuito = atributos->item(1);
			DOMElement* nombre_circuito = dynamic_cast < xercesc::DOMElement* > ( nodo_circuito );
			nombre = Persistencia::recuperarDatoTexto(nombre_circuito);
			Circuito* circuito = persistencia.recuperarCircuito(0,nombre);
			aux = generarRespuesta(circuito);
			delete circuito;

			return aux;

		}

	}
	return NULL;
}


std::string ModeloServidor::generarRespuesta (int cantSalidas, bool* salidas) {

	XMLCh tempStr[100];

	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = ManagerArchivos::getInstancia()->getNombreRespuesta();

	Persistencia::generarSOAP(impl,doc,ruta,Mensajes::GetSimularResponse(doc,cantSalidas, salidas));

	return ruta;

}

std::string ModeloServidor::generarRespuesta (int cantSalidas, int* salidas) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = ManagerArchivos::getInstancia()->getNombreRespuesta();

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::GetTiempoSimulacionResponse(doc,cantSalidas, salidas));

	return ruta;

}



std::string ModeloServidor::generarListaCircuitos(std::vector<char*> circuitos) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = ManagerArchivos::getInstancia()->getNombreRespuesta();

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::GetListaCircuitosResponse(doc,circuitos));

	return ruta;

}

std::string ModeloServidor::generarRespuesta(int cantEntradas, int cantSalidas) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = ManagerArchivos::getInstancia()->getNombreRespuesta();

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::GetCircuitoResponse(doc,cantEntradas, cantSalidas));

	return ruta;

}

std::string ModeloServidor::generarRespuesta(Circuito* circuito) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = ManagerArchivos::getInstancia()->getNombreRespuesta();

	Persistencia::generarSOAP(impl,doc,ruta, circuito->obtenerCircuito(doc));

	return ruta;

}

