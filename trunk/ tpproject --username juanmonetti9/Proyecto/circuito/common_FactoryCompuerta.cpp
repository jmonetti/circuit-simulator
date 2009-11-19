
#include "common_FactoryCompuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"
#include "common_Entrada.h"
#include "common_Salida.h"
#include "common_AND.h"
#include "common_NOT.h"
#include "common_OR.h"
#include "common_XOR.h"
#include "common_Compuerta.h"
#include "common_Pista.h"

Compuerta* FactoryCompuerta::crearCompuerta(TIPO_COMPUERTA tipo, Circuito* circuito, int tiempoTransicion) {

	switch (tipo) {

		case AND:

			crearAND(circuito,tiempoTransicion);
			break;

		case OR:

			crearOR(circuito,tiempoTransicion);
			break;

		case XOR:

			crearXOR(circuito,tiempoTransicion);
			break;

		case NOT:

			crearNOT(circuito,tiempoTransicion);
			break;

		case PISTA:

			crearPISTA(circuito);
			break;

		case ENTRADA:

			crearENTRADA(circuito);
			break;

		case SALIDA:

			crearSALIDA(circuito);
			break;

		default:

			//TODO
			break;

	}
}

void FactoryCompuerta::crearAND(Circuito* circuito,int tiempo) {

	EntradaCompuerta* entrada1= new EntradaCompuerta(circuito->getContadorEntradasCompuerta());
	circuito->agregarEntradaCompuerta(entrada1);
	EntradaCompuerta* entrada2= new EntradaCompuerta(circuito->getContadorEntradasCompuerta());
	circuito->agregarEntradaCompuerta(entrada2);
	SalidaCompuerta* salida= new SalidaCompuerta(circuito->getContadorSalidasCompuerta());
	circuito->agregarSalidaCompuerta(salida);
	Compuerta* compuerta= new AND(circuito->getContadorCompuertas(),tiempo,entrada1,entrada2,salida);

	entrada1->setCompuerta(compuerta);
	entrada2->setCompuerta(compuerta);
	salida->setCompuerta(compuerta);

	circuito->agregarCompuerta(compuerta);

}

void FactoryCompuerta::crearOR(Circuito* circuito,int tiempo) {

	EntradaCompuerta* entrada1= new EntradaCompuerta(circuito->getContadorEntradasCompuerta());
	circuito->agregarEntradaCompuerta(entrada1);
	EntradaCompuerta* entrada2= new EntradaCompuerta(circuito->getContadorEntradasCompuerta());
	circuito->agregarEntradaCompuerta(entrada2);
	SalidaCompuerta* salida= new SalidaCompuerta(circuito->getContadorSalidasCompuerta());
	circuito->agregarSalidaCompuerta(salida);
	Compuerta* compuerta= new OR(circuito->getContadorCompuertas(),tiempo,entrada1,entrada2,salida);

	entrada1->setCompuerta(compuerta);
	entrada2->setCompuerta(compuerta);
	salida->setCompuerta(compuerta);

	circuito->agregarCompuerta(compuerta);

}

void FactoryCompuerta::crearNOT(Circuito* circuito,int tiempo) {

	EntradaCompuerta* entrada= new EntradaCompuerta();
	SalidaCompuerta* salida= new SalidaCompuerta();
	Compuerta* compuerta= new NOT(tiempo,entrada,salida);
	entrada->setCompuerta(compuerta);
	salida->setCompuerta(compuerta);

	circuito->agregarCompuerta(compuerta);
	circuito->agregarEntradaCompuerta(entrada);
	circuito->agregarSalidaCompuerta(salida);

}

void FactoryCompuerta::crearXOR(Circuito* circuito,int tiempo) {

	EntradaCompuerta* entrada1= new EntradaCompuerta();
	EntradaCompuerta* entrada2= new EntradaCompuerta();
	SalidaCompuerta* salida= new SalidaCompuerta();
	Compuerta* compuerta= new XOR(tiempo,entrada1,entrada2,salida);
	entrada1->setCompuerta(compuerta);
	entrada2->setCompuerta(compuerta);
	salida->setCompuerta(compuerta);

	circuito->agregarCompuerta(compuerta);
	circuito->agregarEntradaCompuerta(entrada1);
	circuito->agregarEntradaCompuerta(entrada2);
	circuito->agregarSalidaCompuerta(salida);

}

void FactoryCompuerta::crearPISTA(Circuito* circuito) {

	EntradaCompuerta* entrada= new EntradaCompuerta();
	SalidaCompuerta* salida= new SalidaCompuerta();
	Compuerta* compuerta= new Pista(entrada,salida);
	entrada->setCompuerta(compuerta);
	salida->setCompuerta(compuerta);

	circuito->agregarCompuerta(compuerta);
	circuito->agregarEntradaCompuerta(entrada);
	circuito->agregarSalidaCompuerta(salida);

}

void FactoryCompuerta::crearENTRADA(Circuito* circuito) {

	SalidaCompuerta* salidaEntrada= new SalidaCompuerta();
	Compuerta* compuerta= new Entrada(salidaEntrada);
	salidaEntrada->setCompuerta(compuerta);

	circuito->agregarCompuerta(compuerta);
	circuito->agregarSalidaCompuerta(salidaEntrada);

}

void FactoryCompuerta::crearSALIDA(Circuito* circuito) {

	EntradaCompuerta* entradaSalida= new EntradaCompuerta();
	Compuerta* compuerta= new Salida(entradaSalida);
	entradaSalida->setCompuerta(compuerta);

	circuito->agregarCompuerta(compuerta);
	circuito->agregarEntradaCompuerta(entradaSalida);

}
