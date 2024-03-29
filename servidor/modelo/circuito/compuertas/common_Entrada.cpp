
#include "common_Entrada.h"

Entrada::Entrada(int id,SalidaCompuerta* salida, Posicion posicion, SENTIDO sentido, const std::string &nombre)
: Compuerta(id,posicion,sentido) , nombre(nombre){

	this->salida= salida;

	actualizarSalidas();

	tiempo= 0;

}

Entrada::~Entrada() {

	delete salida;

}

void Entrada::actuarTiempo(int* tiempos) {

	this->salida->setTiempoTransicion(tiempo);

}

Entrada* Entrada::getEntrada(){

	return this;

}

void Entrada::actuarSimular(bool* valores) {

	this->salida->setValorSalida(valor);

}

void Entrada::setValorEntrada(bool valor) {

	this->valor= valor;

}

void Entrada::setTiempo(int tiempo) {

	this->tiempo= tiempo;

}

bool Entrada::getValorEntrada() const {

	return this->valor;

}

std::string Entrada::getNombre() const {

	return nombre;

}

TIPO_COMPUERTA Entrada::getTipo() const{

	return T_ENTRADA;

}


EntradaCompuerta** Entrada::getEntradas() {

	return NULL;

}

SalidaCompuerta** Entrada::getSalidas() {

	return &salida;

}

int Entrada::getCantidadEntradas() {

	return 0;

}

int Entrada::getCantidadSalidas() {

	return 1;

}


void Entrada::guardar(DOMDocument* doc, DOMNode* padre) {

	XMLCh tempStr[100];
	std::string aux;

    XMLString::transcode("Entrada", tempStr, 99);
    DOMElement*   elem_Entrada = doc->createElement(tempStr);

    /******* ATRIBUTO POSICION X *****************/

    aux = "x";
    Persistencia::guardarElemento(doc,elem_Entrada,aux,getPosicion().getX());

    /******* ATRIBUTO POSICION Y *****************/

    aux = "y";
    Persistencia::guardarElemento(doc,elem_Entrada,aux,getPosicion().getY());

    /******* ATRIBUTO SENTIDO *****************/

    aux = "sentido";
    Persistencia::guardarElemento(doc,elem_Entrada,aux,getSentido());

    /******* ATRIBUTO NOMBRE *****************/

    aux = "nombre";
    Persistencia::guardarElemento(doc,elem_Entrada,aux,nombre);

    padre->appendChild(elem_Entrada);

}

void Entrada::actualizarEntradas() {


}

void Entrada::actualizarSalidas() {

	unsigned int xCompuerta= getPosicion().getX();
	unsigned int yCompuerta= getPosicion().getY();

	unsigned int xSalida = 0;
	unsigned int ySalida = 0;


	switch (getSentido()) {

		case NORTE:
		{

			xSalida= xCompuerta;
			ySalida= yCompuerta - 1;

			break;

		}
		case ESTE:
		{

			xSalida= xCompuerta + 1;
			ySalida= yCompuerta;

			break;

		}
		case SUR:
		{

			xSalida= xCompuerta;
			ySalida= yCompuerta + 1;

			break;

		}
		case OESTE:
		{

			xSalida= xCompuerta - 1;
			ySalida= yCompuerta;

			break;

		}
		default:

			break;

	}

	Posicion posicionSalida(xSalida,ySalida);
	salida->mover(posicionSalida);
	salida->rotar(getSentido());

}

