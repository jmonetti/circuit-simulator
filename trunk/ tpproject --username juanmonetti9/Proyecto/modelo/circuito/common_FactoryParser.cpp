
#include "common_FactoryParser.h"

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


void FactoryParser::crearCompuerta(TIPO_COMPUERTA tipo, Circuito &circuito, Posicion posicion,SENTIDO sentido
									,int idCompuerta) {


	switch (tipo) {

		case T_AND:

			crearAND(circuito,idCompuerta,posicion,sentido);
			break;

		case T_OR:

			crearOR(circuito,idCompuerta,posicion,sentido);
			break;

		case T_XOR:

			crearXOR(circuito,idCompuerta,posicion,sentido);
			break;

		case T_NOT:

			crearNOT(circuito,idCompuerta,posicion,sentido);
			break;

		case T_PISTA:

			crearPISTA(circuito,idCompuerta,posicion,sentido);
			break;

		default:

			throw CircuitoException("Tipo de compuerta invalida");

			break;

	}
}

void FactoryParser::crearEntrada(Circuito &circuito,int idCompuerta, Posicion posicion, const std::string &nombre,SENTIDO sentido) {

	SalidaCompuerta* salidaEntrada= new SalidaCompuerta();

	Compuerta* compuerta= new Entrada(idCompuerta,salidaEntrada,posicion,sentido,nombre);

	salidaEntrada->setCompuerta(compuerta);

	circuito.agregarCompuerta(compuerta);

}

void FactoryParser::crearSalida(Circuito &circuito,int idCompuerta, Posicion posicion, const std::string &nombre,SENTIDO sentido) {

	EntradaCompuerta* entradaSalida= new EntradaCompuerta();

	Compuerta* compuerta= new Salida(idCompuerta,entradaSalida,posicion,sentido,nombre);

	circuito.agregarCompuerta(compuerta);

}

void FactoryParser::crearAND(Circuito &circuito,int idCompuerta,Posicion posicion,SENTIDO sentido) {

	EntradaCompuerta* entrada1= new EntradaCompuerta();

	EntradaCompuerta* entrada2= new EntradaCompuerta();

	SalidaCompuerta* salida= new SalidaCompuerta();

	Compuerta* compuerta= new AND(idCompuerta,TIEMPO_TRANSICION_AND,entrada1,entrada2,salida,posicion,sentido);

	salida->setCompuerta(compuerta);

	circuito.agregarCompuerta(compuerta);

}

void FactoryParser::crearOR(Circuito &circuito,int idCompuerta,Posicion posicion,SENTIDO sentido) {

	EntradaCompuerta* entrada1= new EntradaCompuerta();

	EntradaCompuerta* entrada2= new EntradaCompuerta();

	SalidaCompuerta* salida= new SalidaCompuerta();

	Compuerta* compuerta= new OR(idCompuerta,TIEMPO_TRANSICION_OR,entrada1,entrada2,salida,posicion,sentido);

	salida->setCompuerta(compuerta);

	circuito.agregarCompuerta(compuerta);

}

void FactoryParser::crearNOT(Circuito &circuito,int idCompuerta,Posicion posicion,SENTIDO sentido) {

	EntradaCompuerta* entrada= new EntradaCompuerta();

	SalidaCompuerta* salida= new SalidaCompuerta();

	Compuerta* compuerta= new NOT(idCompuerta,TIEMPO_TRANSICION_NOT,entrada,salida,posicion,sentido);

	salida->setCompuerta(compuerta);

	circuito.agregarCompuerta(compuerta);

}

void FactoryParser::crearXOR(Circuito &circuito,int idCompuerta,Posicion posicion,SENTIDO sentido) {

	EntradaCompuerta* entrada1= new EntradaCompuerta();

	EntradaCompuerta* entrada2= new EntradaCompuerta();

	SalidaCompuerta* salida= new SalidaCompuerta();

	Compuerta* compuerta= new XOR(idCompuerta,TIEMPO_TRANSICION_XOR,entrada1,entrada2,salida,posicion,sentido);

	salida->setCompuerta(compuerta);

	circuito.agregarCompuerta(compuerta);

}

void FactoryParser::crearPISTA(Circuito &circuito,int idCompuerta,Posicion posicion,SENTIDO sentido) {

	EntradaCompuerta* entrada= new EntradaCompuerta();

	SalidaCompuerta* salida= new SalidaCompuerta();

	Compuerta* compuerta= new Pista(idCompuerta,entrada,salida,posicion,sentido);

	salida->setCompuerta(compuerta);

	circuito.agregarCompuerta(compuerta);

}



