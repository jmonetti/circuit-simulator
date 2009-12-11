
#include "common_ModeloServidor.h"
#include "circuito/common_Circuito.h"
#include <vector>
#include "circuito/compuertas/common_Entrada.h"
#include "../common/common_Utils.h"
#include <fstream>

ModeloServidor::ModeloServidor() {

	contadorId = 0;

}

ModeloServidor::~ModeloServidor() {

	for (unsigned int var = 0; var < circuitos.size(); ++var) {

		delete circuitos[var];

	}

}

void ModeloServidor::cargarCircuitos() {

	std::vector<char*> circuitos;
	Utils::obtenerArchivos(PATH_SAVES,&circuitos);
	for (unsigned int var = 0; var < circuitos.size(); ++var) {

		std::string ruta = circuitos[var];
		std::string ruta_saves = PATH_SAVES + ruta;
		ifstream nuevoCircuito(ruta.c_str());

		Circuito* circuitoNuevo = persistencia.recuperarCircuito(contadorId,ruta);

		guardar(circuitoNuevo);

		delete[] circuitos[var];

	}

}

void ModeloServidor::guardar(Circuito* circuito) {

	circuitos.push_back(circuito);

	contadorId++;

}

void ModeloServidor::recuperar() {

}

bool* ModeloServidor::simular(int idCircuito,bool* entradas) {

	bool* salidas= circuitos[idCircuito]->simular(entradas);

	return salidas;

}

int* ModeloServidor::calcularTiempoTransicion(int idCircuito,const std::string &nombreCircuito,int* entradas) {

	Circuito* circuito= circuitos[idCircuito];

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

int ModeloServidor::getIdCircuito(std::string &nombreCircuito) {

	for (unsigned int var = 0; var < circuitos.size(); ++var) {

		if (nombreCircuito == circuitos[var]->getNombre())
			return var; 	//TODO Id Circuito == var

	}

	return -1;

}



void ModeloServidor::obtenerDatosCircuito(std::string &nombre,int &cantEntradas,int &cantSalidas) {

	int id = getIdCircuito(nombre);

	Circuito* circuito = circuitos[id];

	cantEntradas = circuito->getCantidadEntradas();

	cantSalidas = circuito->getCantidadSalidas();

}

std::string ModeloServidor::generarRespuesta(std::string& ruta_pedido) {

	TIPO_SOAP tipo;
	std::string aux;

	DOMElement* funcion = persistencia.getTipoSOAP(ruta_pedido,tipo);

	switch (tipo) {

		case LISTA: {

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
			Circuito* circuito = persistencia.parserCircuito(funcion, getId(), aux);
			guardar(circuito);
			persistencia.guardarCircuito(*circuito);
			aux = STRNUEVOCIRCUITO;

			return aux;
		}

		case SIMULAR: {
			DOMNodeList* atributos = funcion->getChildNodes();
			std::string nombre;

			DOMNode* nodo_circuito = atributos->item(1);
			DOMElement* nombre_circuito = dynamic_cast < xercesc::DOMElement* > ( nodo_circuito );
			nombre = Persistencia::recuperarDatoTexto(nombre_circuito);

			int idCircuito = getIdCircuito(nombre);

			if (idCircuito != -1){

				bool* entradas = new bool[circuitos[idCircuito]->getCantidadEntradas()];
				recuperarDatosSimular(atributos,nombre,entradas);
				bool* salidas = simular(idCircuito,entradas);
				int cantSalidas = circuitos[idCircuito]->getCantidadSalidas();
				aux = generarRespuesta(cantSalidas, salidas);
				cout<<aux<<endl;
				delete[] entradas;
				delete[] salidas;
				return aux;
			}
			break;
		}

		case SIMULARTIEMPO: {
			DOMNodeList* atributos = funcion->getChildNodes();
			std::string nombre;
			DOMNode* nodo_circuito = atributos->item(1);
			DOMElement* nombre_circuito = dynamic_cast < xercesc::DOMElement* > ( nodo_circuito );
			nombre = Persistencia::recuperarDatoTexto(nombre_circuito);

			int idCircuito = getIdCircuito(nombre);

			if(idCircuito != -1) {
;
				int* entradas = new int[circuitos[idCircuito]->getCantidadEntradas()];
				recuperarDatosTiempos(atributos,nombre,entradas);

				int* tiempos = calcularTiempoTransicion(idCircuito,nombre, entradas);
				int cantSalidas = circuitos[idCircuito]->getCantidadSalidas();
				aux = generarRespuesta(cantSalidas, tiempos);
				delete[] entradas;
				delete[] tiempos;
				return aux;

			}
			break;
		}

	}
	return NULL;
}




int ModeloServidor::getId() {

	return contadorId;

}


std::string ModeloServidor::generarRespuesta (int cantSalidas, bool* salidas) {

	XMLCh tempStr[100];

	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "temp/GetSimulacionResponse.xml";

	Persistencia::generarSOAP(impl,doc,ruta,Mensajes::GetSimularResponse(doc,cantSalidas, salidas));

	return ruta;

}

std::string ModeloServidor::generarRespuesta (int cantSalidas, int* salidas) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "temp/GetTiempoSimulacionResponse.xml";

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::GetTiempoSimulacionResponse(doc,cantSalidas, salidas));

	return ruta;

}



std::string ModeloServidor::generarListaCircuitos(std::vector<Circuito*> circuitos) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "temp/GetListaCircuitosResponse.xml";

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::GetListaCircuitosResponse(doc,circuitos));

	return ruta;

}

std::string ModeloServidor::generarRespuesta(int cantEntradas, int cantSalidas) {

	XMLCh tempStr[100];
	XMLString::transcode("LS", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	DOMDocument* doc = impl->createDocument();

	std::string ruta = "temp/GetCircuitoResponse.xml";

	Persistencia::generarSOAP(impl,doc,ruta, Mensajes::GetCircuitoResponse(doc,cantEntradas, cantSalidas));

	return ruta;

}


