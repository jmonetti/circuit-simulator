
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


int FactoryCompuerta::crearCompuerta(TIPO_COMPUERTA tipo, Circuito &circuito, Posicion posicion, SENTIDO sentido) {

	switch (tipo) {

		case T_AND:

			return crearAND(circuito,posicion,sentido);
			break;

		case T_OR:

			return crearOR(circuito,posicion,sentido);
			break;

		case T_XOR:

			return crearXOR(circuito,posicion,sentido);
			break;

		case T_NOT:

			return crearNOT(circuito,posicion,sentido);
			break;

		case T_PISTA:

			return crearPISTA(circuito,posicion,sentido);
			break;

		default:

			throw CircuitoException("Tipo de compuerta invalida");

			break;

	}

}

int FactoryCompuerta::crearEntrada(Circuito &circuito, Posicion posicion, const std::string &nombre, SENTIDO sentido) {

	SalidaCompuerta* salidaEntrada= new SalidaCompuerta();

	Compuerta* compuerta= new Entrada(circuito.getContadorCompuertas(),salidaEntrada,posicion,sentido,nombre);

	salidaEntrada->setCompuerta(compuerta);

	return circuito.agregarCompuerta(compuerta);

}

int FactoryCompuerta::crearSalida(Circuito &circuito, Posicion posicion, const std::string &nombre, SENTIDO sentido) {

	EntradaCompuerta* entradaSalida= new EntradaCompuerta();

	Compuerta* compuerta= new Salida(circuito.getContadorCompuertas(),entradaSalida,posicion,sentido,nombre);

	return circuito.agregarCompuerta(compuerta);

}


int FactoryCompuerta::crearAND(Circuito &circuito, Posicion posicion, SENTIDO sentido) {

	EntradaCompuerta* entrada1= new EntradaCompuerta();

	EntradaCompuerta* entrada2= new EntradaCompuerta();

	SalidaCompuerta* salida= new SalidaCompuerta();

	Compuerta* compuerta= new AND(circuito.getContadorCompuertas(),TIEMPO_TRANSICION_AND,entrada1,entrada2,salida,posicion,sentido);

	salida->setCompuerta(compuerta);

	return circuito.agregarCompuerta(compuerta);

}

int FactoryCompuerta::crearOR(Circuito &circuito, Posicion posicion, SENTIDO sentido) {

	EntradaCompuerta* entrada1= new EntradaCompuerta();

	EntradaCompuerta* entrada2= new EntradaCompuerta();

	SalidaCompuerta* salida= new SalidaCompuerta();

	Compuerta* compuerta= new OR(circuito.getContadorCompuertas(),TIEMPO_TRANSICION_OR,entrada1,entrada2,salida,posicion,sentido);

	salida->setCompuerta(compuerta);

	return circuito.agregarCompuerta(compuerta);

}

int FactoryCompuerta::crearNOT(Circuito &circuito, Posicion posicion, SENTIDO sentido) {

	EntradaCompuerta* entrada= new EntradaCompuerta();

	SalidaCompuerta* salida= new SalidaCompuerta();

	Compuerta* compuerta= new NOT(circuito.getContadorCompuertas(),TIEMPO_TRANSICION_NOT,entrada,salida,posicion,sentido);

	salida->setCompuerta(compuerta);

	return 	circuito.agregarCompuerta(compuerta);

}

int FactoryCompuerta::crearXOR(Circuito &circuito, Posicion posicion, SENTIDO sentido) {

	EntradaCompuerta* entrada1= new EntradaCompuerta();

	EntradaCompuerta* entrada2= new EntradaCompuerta();

	SalidaCompuerta* salida= new SalidaCompuerta();

	Compuerta* compuerta= new XOR(circuito.getContadorCompuertas(),TIEMPO_TRANSICION_XOR,entrada1,entrada2,salida,posicion,sentido);

	salida->setCompuerta(compuerta);

	return 	circuito.agregarCompuerta(compuerta);

}

int FactoryCompuerta::crearPISTA(Circuito &circuito, Posicion posicion, SENTIDO sentido) {

	EntradaCompuerta* entrada= new EntradaCompuerta();

	SalidaCompuerta* salida= new SalidaCompuerta();

	Compuerta* compuerta= new Pista(circuito.getContadorCompuertas(),entrada,salida,posicion,sentido);

	salida->setCompuerta(compuerta);

	return circuito.agregarCompuerta(compuerta);

}

