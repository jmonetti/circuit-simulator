/*
 * FactoryParser.cpp
 *
 *  Created on: 23/11/2009
 *      Author: giovanni
 */

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


void FactoryParser::crearCompuerta(TIPO_COMPUERTA tipo, Circuito &circuito,int idCompuerta,
		int tiempoTransicion,int idSalida, int idEntrada1,int idEntrada2) {

	switch (tipo) {

		case T_AND:

			crearAND(circuito,idCompuerta,tiempoTransicion,idEntrada1,idEntrada2,idSalida);
			break;

		case T_OR:

			crearOR(circuito,idCompuerta,tiempoTransicion,idEntrada1,idEntrada2,idSalida);
			break;

		case T_XOR:

			crearXOR(circuito,idCompuerta,tiempoTransicion,idEntrada1,idEntrada2,idSalida);
			break;

		case T_NOT:

			crearNOT(circuito,idCompuerta,tiempoTransicion,idEntrada1,idSalida);
			break;

		case T_PISTA:

			crearPISTA(circuito,idCompuerta,idEntrada1,idSalida);
			break;

		case T_ENTRADA:

			crearENTRADA(circuito,idCompuerta,idSalida);
			break;

		case T_SALIDA:

			crearSALIDA(circuito,idCompuerta,idEntrada1);
			break;

		default:

			//TODO
			break;

	}
}

void FactoryParser::crearAND(Circuito &circuito,int idCompuerta,int tiempo,int idEntrada1,int idEntrada2, int idSalida) {

	EntradaCompuerta* entrada1= new EntradaCompuerta(idEntrada1);
	circuito.agregarEntradaCompuerta(entrada1);

	EntradaCompuerta* entrada2= new EntradaCompuerta(idEntrada2);
	circuito.agregarEntradaCompuerta(entrada2);

	SalidaCompuerta* salida= new SalidaCompuerta(idSalida);
	circuito.agregarSalidaCompuerta(salida);

	Compuerta* compuerta= new AND(idCompuerta,tiempo,entrada1,entrada2,salida);
	circuito.agregarCompuerta(compuerta);

	salida->setCompuerta(compuerta);

}

void FactoryParser::crearOR(Circuito &circuito,int idCompuerta,int tiempo,int idEntrada1,int idEntrada2, int idSalida) {

	EntradaCompuerta* entrada1= new EntradaCompuerta(idEntrada1);
	circuito.agregarEntradaCompuerta(entrada1);

	EntradaCompuerta* entrada2= new EntradaCompuerta(idEntrada2);
	circuito.agregarEntradaCompuerta(entrada2);

	SalidaCompuerta* salida= new SalidaCompuerta(idSalida);
	circuito.agregarSalidaCompuerta(salida);

	Compuerta* compuerta= new OR(idCompuerta,tiempo,entrada1,entrada2,salida);
	circuito.agregarCompuerta(compuerta);

	salida->setCompuerta(compuerta);

}

void FactoryParser::crearNOT(Circuito &circuito,int idCompuerta,int tiempo,int idEntrada, int idSalida) {

	EntradaCompuerta* entrada= new EntradaCompuerta(idEntrada);
	circuito.agregarEntradaCompuerta(entrada);

	SalidaCompuerta* salida= new SalidaCompuerta(idSalida);
	circuito.agregarSalidaCompuerta(salida);

	Compuerta* compuerta= new NOT(idCompuerta,tiempo,entrada,salida);
	circuito.agregarCompuerta(compuerta);

	salida->setCompuerta(compuerta);

}

void FactoryParser::crearXOR(Circuito &circuito,int idCompuerta,int tiempo,int idEntrada1,int idEntrada2, int idSalida) {

	EntradaCompuerta* entrada1= new EntradaCompuerta(idEntrada1);
	circuito.agregarEntradaCompuerta(entrada1);

	EntradaCompuerta* entrada2= new EntradaCompuerta(idEntrada2);
	circuito.agregarEntradaCompuerta(entrada2);

	SalidaCompuerta* salida= new SalidaCompuerta(idSalida);
	circuito.agregarSalidaCompuerta(salida);

	Compuerta* compuerta= new XOR(idCompuerta,tiempo,entrada1,entrada2,salida);
	circuito.agregarCompuerta(compuerta);

	salida->setCompuerta(compuerta);

}

void FactoryParser::crearPISTA(Circuito &circuito,int idCompuerta,int idEntrada, int idSalida) {

	EntradaCompuerta* entrada= new EntradaCompuerta(idEntrada);
	circuito.agregarEntradaCompuerta(entrada);

	SalidaCompuerta* salida= new SalidaCompuerta(idSalida);
	circuito.agregarSalidaCompuerta(salida);

	Compuerta* compuerta= new Pista(idCompuerta,entrada,salida);
	circuito.agregarCompuerta(compuerta);

	salida->setCompuerta(compuerta);

}

void FactoryParser::crearENTRADA(Circuito &circuito,int idCompuerta,int idSalida) {

	SalidaCompuerta* salidaEntrada= new SalidaCompuerta(idSalida);
	circuito.agregarSalidaCompuerta(salidaEntrada);

	Compuerta* compuerta= new Entrada(idCompuerta,salidaEntrada);
	circuito.agregarCompuerta(compuerta);

	salidaEntrada->setCompuerta(compuerta);

}

void FactoryParser::crearSALIDA(Circuito &circuito,int idCompuerta,int idEntrada) {

	EntradaCompuerta* entradaSalida= new EntradaCompuerta(idEntrada);
	circuito.agregarEntradaCompuerta(entradaSalida);

	Compuerta* compuerta= new Salida(idCompuerta,entradaSalida);
	circuito.agregarCompuerta(compuerta);

}

