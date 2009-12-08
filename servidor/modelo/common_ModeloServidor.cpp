
#include "common_ModeloServidor.h"
#include "circuito/common_Circuito.h"
#include <vector>
#include "circuito/compuertas/common_Entrada.h"

ModeloServidor::ModeloServidor() {

	contadorId = 0;

}

ModeloServidor::~ModeloServidor() {

	for (unsigned int var = 0; var < circuitos.size(); ++var) {

		delete circuitos[var];

	}

}

void ModeloServidor::guardar(Circuito* circuito) {

	circuitos.push_back(circuito);

	contadorId++;

}

void ModeloServidor::recuperar() {

}

bool* ModeloServidor::simular(int idCircuito,const std::string &nombreCircuito,bool* entradas) {

	Circuito* circuito= persistencia.recuperar(idCircuito,nombreCircuito);

	bool* salidas= circuito->simular(entradas);

	delete circuito;

	return salidas;

}

int* ModeloServidor::calcularTiempoTransicion(int idCircuito,const std::string &nombreCircuito,int* entradas) {

	Circuito* circuito= persistencia.recuperar(idCircuito,nombreCircuito);

	//circuito->getConexionVertice() TODO

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
	DOMNodeList* atributos = funcion->getChildNodes();
	switch (tipo) {

		case LISTA: {

			aux = peticion.generarListaCircuitos(circuitos);
			//TODO AGREGAR CODIGO HTML con 200 OK;
			return aux;

		}

		case CIRCUITO: {

			std::string nombre = persistencia.obtenerNombre(funcion);
			int cantEntradas;
			int cantSalidas;
			obtenerDatosCircuito(nombre,cantEntradas,cantSalidas);
			aux = peticion.generarRespuesta(cantEntradas,cantSalidas);

			//TODO GENERAR HTML CON 200 OK


		}

		case NUEVOCIRCUITO: {
			aux = persistencia.obtenerNombre(funcion);
			Circuito* circuito = persistencia.parserCircuito(funcion, getId(), aux);
			guardar(circuito);
			persistencia.guardarCircuito(*circuito);
			aux = peticion.generarRespuesta();
			//TODO AGREGAR CODIGO HTML con 200 OK;
			return aux;
		}

		case SIMULAR: {
			std::string nombre;
			int cantEntradas = atributos->getLength() - 1 ;
			bool* entradas = new bool[cantEntradas];
			int idCircuito = getIdCircuito(nombre);
			if (idCircuito != -1){
				recuperarDatosSimular(atributos,nombre,entradas); //TODO preguntar a diego el tema de Resultado*
				bool* salidas = simular(idCircuito,nombre,entradas);
				aux = peticion.generarRespuesta(cantEntradas, salidas);
				//TODO AGREGAR CODIGO HTML con 200 OK;
				return aux;
			}
			//TODO HTML MENSAJE ERROR ID.
		}

		case SIMULARTIEMPO: {
			std::string nombre;
			int cantEntradas = atributos->getLength() - 1 ;
			int* entradas = new int[cantEntradas];
			int idCircuito = getIdCircuito(nombre);
			if(idCircuito != -1) {
				recuperarDatosTiempos(atributos,nombre,entradas); //TODO
				int* tiempos = calcularTiempoTransicion(idCircuito,nombre, entradas);
				aux = peticion.generarRespuesta(cantEntradas, tiempos);
				return aux;
				//TODO AGREGAR CODIGO HTML con 200 OK;
			}
			//TODO HTML MENSAJE ERROR ID.
		}

		case INVALIDO: {
			//TODO HTML MENSAJE ERROR.
			break;
		}
	}
	return aux; //TODO HTML MENSAJE ERROR
}




int ModeloServidor::getId() {

	return contadorId;

}
