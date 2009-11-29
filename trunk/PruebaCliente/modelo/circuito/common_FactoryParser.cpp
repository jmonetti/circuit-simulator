
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
									,int idCompuerta,int idSalida, int idEntrada1,int idEntrada2) {


	switch (tipo) {

		case T_AND:

			crearAND(circuito,idCompuerta,idEntrada1,idEntrada2,idSalida,posicion,sentido);
			break;

		case T_OR:

			crearOR(circuito,idCompuerta,idEntrada1,idEntrada2,idSalida,posicion,sentido);
			break;

		case T_XOR:

			crearXOR(circuito,idCompuerta,idEntrada1,idEntrada2,idSalida,posicion,sentido);
			break;

		case T_NOT:

			crearNOT(circuito,idCompuerta,idEntrada1,idSalida,posicion,sentido);
			break;

		case T_PISTA:

			crearPISTA(circuito,idCompuerta,idEntrada1,idSalida,posicion,sentido);
			break;

		default:

			throw CircuitoException("Tipo de compuerta invalida");

			break;

	}
}

void FactoryParser::crearEntrada(Circuito &circuito,int idCompuerta,int idSalida, Posicion posicion, const std::string &nombre,SENTIDO sentido) {

	SalidaCompuerta* salidaEntrada= new SalidaCompuerta(idSalida);
	circuito.agregarSalidaCompuerta(salidaEntrada);

	Compuerta* compuerta= new Entrada(idCompuerta,salidaEntrada,posicion,sentido,nombre);
	circuito.agregarCompuerta(compuerta);

	salidaEntrada->setCompuerta(compuerta);

}

void FactoryParser::crearSalida(Circuito &circuito,int idCompuerta,int idEntrada, Posicion posicion, const std::string &nombre,SENTIDO sentido) {

	EntradaCompuerta* entradaSalida= new EntradaCompuerta(idEntrada);
	circuito.agregarEntradaCompuerta(entradaSalida);

	Compuerta* compuerta= new Salida(idCompuerta,entradaSalida,posicion,sentido,nombre);
	circuito.agregarCompuerta(compuerta);

}

void FactoryParser::crearAND(Circuito &circuito,int idCompuerta,int idEntrada1,int idEntrada2, int idSalida,Posicion posicion,SENTIDO sentido) {

	EntradaCompuerta* entrada1= new EntradaCompuerta(idEntrada1);
	circuito.agregarEntradaCompuerta(entrada1);

	EntradaCompuerta* entrada2= new EntradaCompuerta(idEntrada2);
	circuito.agregarEntradaCompuerta(entrada2);

	SalidaCompuerta* salida= new SalidaCompuerta(idSalida);
	circuito.agregarSalidaCompuerta(salida);

	Compuerta* compuerta= new AND(idCompuerta,TIEMPO_TRANSICION_AND,entrada1,entrada2,salida,posicion,sentido);
	circuito.agregarCompuerta(compuerta);

	salida->setCompuerta(compuerta);

}

void FactoryParser::crearOR(Circuito &circuito,int idCompuerta,int idEntrada1,int idEntrada2, int idSalida,Posicion posicion,SENTIDO sentido) {

	EntradaCompuerta* entrada1= new EntradaCompuerta(idEntrada1);
	circuito.agregarEntradaCompuerta(entrada1);

	EntradaCompuerta* entrada2= new EntradaCompuerta(idEntrada2);
	circuito.agregarEntradaCompuerta(entrada2);

	SalidaCompuerta* salida= new SalidaCompuerta(idSalida);
	circuito.agregarSalidaCompuerta(salida);

	Compuerta* compuerta= new OR(idCompuerta,TIEMPO_TRANSICION_OR,entrada1,entrada2,salida,posicion,sentido);
	circuito.agregarCompuerta(compuerta);

	salida->setCompuerta(compuerta);

}

void FactoryParser::crearNOT(Circuito &circuito,int idCompuerta,int idEntrada, int idSalida,Posicion posicion,SENTIDO sentido) {

	EntradaCompuerta* entrada= new EntradaCompuerta(idEntrada);
	circuito.agregarEntradaCompuerta(entrada);

	SalidaCompuerta* salida= new SalidaCompuerta(idSalida);
	circuito.agregarSalidaCompuerta(salida);

	Compuerta* compuerta= new NOT(idCompuerta,TIEMPO_TRANSICION_NOT,entrada,salida,posicion,sentido);
	circuito.agregarCompuerta(compuerta);

	salida->setCompuerta(compuerta);

}

void FactoryParser::crearXOR(Circuito &circuito,int idCompuerta,int idEntrada1,int idEntrada2, int idSalida,Posicion posicion,SENTIDO sentido) {

	EntradaCompuerta* entrada1= new EntradaCompuerta(idEntrada1);
	circuito.agregarEntradaCompuerta(entrada1);

	EntradaCompuerta* entrada2= new EntradaCompuerta(idEntrada2);
	circuito.agregarEntradaCompuerta(entrada2);

	SalidaCompuerta* salida= new SalidaCompuerta(idSalida);
	circuito.agregarSalidaCompuerta(salida);

	Compuerta* compuerta= new XOR(idCompuerta,TIEMPO_TRANSICION_XOR,entrada1,entrada2,salida,posicion,sentido);
	circuito.agregarCompuerta(compuerta);

	salida->setCompuerta(compuerta);

}

void FactoryParser::crearPISTA(Circuito &circuito,int idCompuerta,int idEntrada, int idSalida,Posicion posicion,SENTIDO sentido) {

	EntradaCompuerta* entrada= new EntradaCompuerta(idEntrada);
	circuito.agregarEntradaCompuerta(entrada);

	SalidaCompuerta* salida= new SalidaCompuerta(idSalida);
	circuito.agregarSalidaCompuerta(salida);

	Compuerta* compuerta= new Pista(idCompuerta,entrada,salida,posicion,sentido);
	circuito.agregarCompuerta(compuerta);

	salida->setCompuerta(compuerta);

}



