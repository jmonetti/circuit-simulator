
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

bool* ModeloServidor::simular(int idCircuito,const std::string &nombreCircuito,bool* entradas) {

	Circuito* circuito= persistencia.recuperarCircuito(idCircuito,nombreCircuito);

	bool* salidas= circuito->simular(entradas);

	delete circuito;

	return salidas;

}

int* ModeloServidor::calcularTiempoTransicion(int idCircuito,const std::string &nombreCircuito,int* entradas) {

	Circuito* circuito= persistencia.recuperarCircuito(idCircuito,nombreCircuito);

	std::vector<Entrada*> entradasCircuito = circuito->getEntradas();
	for (unsigned int var = 0; var < entradasCircuito.size(); ++var) {

		entradasCircuito[var]->setTiempo(entradas[var]);

	}

	int* tiempos= circuito->calcularTiempoTransicion();

	delete circuito;

	return tiempos;

}

void ModeloServidor::recuperarDatosSimular(DOMNodeList* atributos, std::string &nombre, bool* entradas) {

	DOMNode* atributo = atributos->item(0);
	DOMElement* nombreCircuito = dynamic_cast < xercesc::DOMElement* > ( atributo );
	nombre = persistencia.recuperarDatoTexto(nombreCircuito);
	int cant = atributos->getLength();
	DOMElement* ElemCte;
	std::string valor;
	bool entrada;
	for (int i = 1; i<cant; ++i) {

		atributo = atributos->item(i);
		ElemCte = dynamic_cast < xercesc::DOMElement* > ( atributo );
		valor = persistencia.recuperarDatoTexto(ElemCte);

		if(valor == "0")
			entrada = false;
		else
			entrada = true;

		entradas[i-1] = entrada;

	}

}

void ModeloServidor::recuperarDatosTiempos(DOMNodeList* atributos, std::string &nombre, int* entradas) {

	DOMNode* atributo = atributos->item(0);
	DOMElement* nombreCircuito = dynamic_cast < xercesc::DOMElement* > ( atributo );
	nombre = persistencia.recuperarDatoTexto(nombreCircuito);
	int cant = atributos->getLength();
	DOMElement* ElemCte;
	std::string valor;
	int entrada;
	for (int i = 1; i<cant; ++i) {

		atributo = atributos->item(i);
		ElemCte = dynamic_cast < xercesc::DOMElement* > ( atributo );
		valor = persistencia.recuperarDatoTexto(ElemCte);
		entrada = atoi(valor.c_str());
		entradas[i-1] = entrada;

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

	cout<<"tipo: "<<tipo<<endl;

	switch (tipo) {

		case LISTA: {

			aux = peticion.generarListaCircuitos(circuitos);

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
					aux = peticion.generarRespuesta(cantEntradas,cantSalidas);
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
			int cantEntradas = atributos->getLength() - 1 ;
			bool* entradas = new bool[cantEntradas];
			int idCircuito = getIdCircuito(nombre);
			if (idCircuito != -1){
				recuperarDatosSimular(atributos,nombre,entradas);
				bool* salidas = simular(idCircuito,nombre,entradas);
				aux = peticion.generarRespuesta(cantEntradas, salidas);

				return aux;
			}
			break;
		}

		case SIMULARTIEMPO: {
			DOMNodeList* atributos = funcion->getChildNodes();
			std::string nombre;
			int cantEntradas = atributos->getLength() - 1 ;
			int* entradas = new int[cantEntradas];
			int idCircuito = getIdCircuito(nombre);
			if(idCircuito != -1) {
				recuperarDatosTiempos(atributos,nombre,entradas);
				int* tiempos = calcularTiempoTransicion(idCircuito,nombre, entradas);
				aux = peticion.generarRespuesta(cantEntradas, tiempos);
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
