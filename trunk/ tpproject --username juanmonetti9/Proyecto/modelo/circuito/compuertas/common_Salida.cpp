#include "common_Salida.h"

Salida::Salida(int id, EntradaCompuerta* entrada,Posicion posicion,SENTIDO sentido, const std::string &nombre)
: Compuerta(id,posicion,sentido) , nombre(nombre) {

	this->entrada= entrada;
	this->tiempoTransicion= 0;

	actualizarEntradas();

}

Salida::~Salida() {

	delete entrada;

}

void Salida::actuarTiempo(int* tiempos) {

	this->tiempoTransicion= tiempos[0];

}

Salida* Salida::getSalida(){

	return this;

}

void Salida::actuarSimular(bool* valores) {

	this->valor= valores[0];

}

bool Salida::getValor() const{

	return valor;

}

int Salida::getTiempoTransicion() const{

	return tiempoTransicion;

}

TIPO_COMPUERTA Salida::getTipo() const{

	return T_SALIDA;

}

std::string Salida::getNombre() const{

	return nombre;

}

EntradaCompuerta** Salida::getEntradas() {

	return &entrada;

}

SalidaCompuerta** Salida::getSalidas() {

	return NULL;

}

int Salida::getCantidadEntradas() {

	return 1;

}

int Salida::getCantidadSalidas() {

	return 0;

}


void Salida::guardar(DOMDocument* doc, DOMNode* padre) {

	XMLCh tempStr[100];
	std::string aux;

    XMLString::transcode("Salida", tempStr, 99);
    DOMElement*   elem_Salida = doc->createElement(tempStr);

    /******* ATRIBUTO POSICION X *****************/

    aux = "x";
    Persistencia::guardarElemento(doc,elem_Salida,aux,getPosicion().getX());

    /******* ATRIBUTO POSICION Y *****************/

    aux = "y";
    Persistencia::guardarElemento(doc,elem_Salida,aux,getPosicion().getY());

    /******* ATRIBUTO SENTIDO *****************/

    aux = "sentido";
    Persistencia::guardarElemento(doc,elem_Salida,aux,getSentido());

    /******* ATRIBUTO NOMBRE *****************/

    aux = "nombre";
    Persistencia::guardarElemento(doc,elem_Salida,aux,nombre);

    padre->appendChild(elem_Salida);

}

void Salida::actualizarEntradas() {

	unsigned int xCompuerta= getPosicion().getX();
	unsigned int yCompuerta= getPosicion().getY();

	unsigned int xEntrada = 0;
	unsigned int yEntrada = 0;


	switch (getSentido()) {

		case NORTE:
		{

			xEntrada= xCompuerta;
			yEntrada= yCompuerta + 1;

			break;

		}
		case ESTE:
		{

			xEntrada= xCompuerta - 1;
			yEntrada= yCompuerta;

			break;

		}
		case SUR:
		{

			xEntrada= xCompuerta;
			yEntrada= yCompuerta - 1;

			break;

		}
		case OESTE:
		{

			xEntrada= xCompuerta + 1;
			yEntrada= yCompuerta;

			break;

		}
		default:

			break;

	}

	Posicion posicionEntrada(xEntrada,yEntrada);
	entrada->mover(posicionEntrada);
	entrada->rotar(getSentido());

}

void Salida::actualizarSalidas() {

}
