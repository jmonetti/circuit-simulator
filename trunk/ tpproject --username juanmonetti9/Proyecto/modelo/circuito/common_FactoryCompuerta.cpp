
#include "common_FactoryCompuerta.h"
#include "compuertas/common_EntradaCompuerta.h"
#include "compuertas/common_SalidaCompuerta.h"
#include "compuertas/common_Entrada.h"
#include "compuertas/common_Salida.h"
#include "compuertas/common_AND.h"
#include "compuertas/common_NOT.h"
#include "compuertas/common_OR.h"
#include "compuertas/common_XOR.h"
#include "compuertas/common_Compuerta.h"
#include "compuertas/common_Pista.h"
#include "../../excepciones/common_CircuitoException.h"


void FactoryCompuerta::crearCompuerta(TIPO_COMPUERTA tipo, Circuito &circuito, Posicion posicion, SENTIDO sentido) {

	switch (tipo) {

		case T_AND:

			crearAND(circuito,posicion,sentido);
			break;

		case T_OR:

			crearOR(circuito,posicion,sentido);
			break;

		case T_XOR:

			crearXOR(circuito,posicion,sentido);
			break;

		case T_NOT:

			crearNOT(circuito,posicion,sentido);
			break;

		case T_PISTA:

			crearPISTA(circuito,posicion,sentido);
			break;

		default:

			throw CircuitoException("Tipo de compuerta invalida");

			break;

	}

}

void FactoryCompuerta::crearEntrada(Circuito &circuito, Posicion posicion, const std::string &nombre, SENTIDO sentido) {

	SalidaCompuerta* salidaEntrada= new SalidaCompuerta();

	Compuerta* compuerta= new Entrada(circuito.getContadorCompuertas(),salidaEntrada,posicion,sentido,nombre);

	salidaEntrada->setCompuerta(compuerta);

	circuito.agregarCompuerta(compuerta);

}

void FactoryCompuerta::crearSalida(Circuito &circuito, Posicion posicion, const std::string &nombre, SENTIDO sentido) {

	EntradaCompuerta* entradaSalida= new EntradaCompuerta();

	Compuerta* compuerta= new Salida(circuito.getContadorCompuertas(),entradaSalida,posicion,sentido,nombre);

	circuito.agregarCompuerta(compuerta);

}


void FactoryCompuerta::crearAND(Circuito &circuito, Posicion posicion, SENTIDO sentido) {

	EntradaCompuerta* entrada1= new EntradaCompuerta();

	EntradaCompuerta* entrada2= new EntradaCompuerta();

	SalidaCompuerta* salida= new SalidaCompuerta();

	Compuerta* compuerta= new AND(circuito.getContadorCompuertas(),TIEMPO_TRANSICION_AND,entrada1,entrada2,salida,posicion,sentido);

	salida->setCompuerta(compuerta);

	circuito.agregarCompuerta(compuerta);

}

void FactoryCompuerta::crearOR(Circuito &circuito, Posicion posicion, SENTIDO sentido) {

	EntradaCompuerta* entrada1= new EntradaCompuerta();

	EntradaCompuerta* entrada2= new EntradaCompuerta();

	SalidaCompuerta* salida= new SalidaCompuerta();

	Compuerta* compuerta= new OR(circuito.getContadorCompuertas(),TIEMPO_TRANSICION_OR,entrada1,entrada2,salida,posicion,sentido);

	salida->setCompuerta(compuerta);

	circuito.agregarCompuerta(compuerta);

}

void FactoryCompuerta::crearNOT(Circuito &circuito, Posicion posicion, SENTIDO sentido) {

	EntradaCompuerta* entrada= new EntradaCompuerta();

	SalidaCompuerta* salida= new SalidaCompuerta();

	Compuerta* compuerta= new NOT(circuito.getContadorCompuertas(),TIEMPO_TRANSICION_NOT,entrada,salida,posicion,sentido);

	salida->setCompuerta(compuerta);

	circuito.agregarCompuerta(compuerta);

}

void FactoryCompuerta::crearXOR(Circuito &circuito, Posicion posicion, SENTIDO sentido) {

	EntradaCompuerta* entrada1= new EntradaCompuerta();

	EntradaCompuerta* entrada2= new EntradaCompuerta();

	SalidaCompuerta* salida= new SalidaCompuerta();

	Compuerta* compuerta= new XOR(circuito.getContadorCompuertas(),TIEMPO_TRANSICION_XOR,entrada1,entrada2,salida,posicion,sentido);

	salida->setCompuerta(compuerta);

	circuito.agregarCompuerta(compuerta);

}

void FactoryCompuerta::crearPISTA(Circuito &circuito, Posicion posicion, SENTIDO sentido) {

	EntradaCompuerta* entrada= new EntradaCompuerta();

	SalidaCompuerta* salida= new SalidaCompuerta();

	Compuerta* compuerta= new Pista(circuito.getContadorCompuertas(),entrada,salida,posicion,sentido);

	salida->setCompuerta(compuerta);

	circuito.agregarCompuerta(compuerta);

}

