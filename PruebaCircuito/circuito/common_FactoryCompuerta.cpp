
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

void FactoryCompuerta::crearCompuerta(TIPO_COMPUERTA tipo, Circuito &circuito, int tiempoTransicion) {

	switch (tipo) {

		case T_AND:

			crearAND(circuito,tiempoTransicion);
			break;

		case T_OR:

			crearOR(circuito,tiempoTransicion);
			break;

		case T_XOR:

			crearXOR(circuito,tiempoTransicion);
			break;

		case T_NOT:

			crearNOT(circuito,tiempoTransicion);
			break;

		case T_PISTA:

			crearPISTA(circuito);
			break;

		case T_ENTRADA:

			crearENTRADA(circuito);
			break;

		case T_SALIDA:

			crearSALIDA(circuito);
			break;

		default:

			//TODO
			break;

	}
}

void FactoryCompuerta::crearAND(Circuito &circuito,int tiempo) {

	EntradaCompuerta* entrada1= new EntradaCompuerta(circuito.getContadorEntradasCompuerta());
	circuito.agregarEntradaCompuerta(entrada1);

	EntradaCompuerta* entrada2= new EntradaCompuerta(circuito.getContadorEntradasCompuerta());
	circuito.agregarEntradaCompuerta(entrada2);

	SalidaCompuerta* salida= new SalidaCompuerta(circuito.getContadorSalidasCompuerta());
	circuito.agregarSalidaCompuerta(salida);

	Compuerta* compuerta= new AND(circuito.getContadorCompuertas(),tiempo,entrada1,entrada2,salida);
	circuito.agregarCompuerta(compuerta);

	entrada1->setCompuerta(compuerta);
	entrada2->setCompuerta(compuerta);
	salida->setCompuerta(compuerta);

}

void FactoryCompuerta::crearOR(Circuito &circuito,int tiempo) {

	EntradaCompuerta* entrada1= new EntradaCompuerta(circuito.getContadorEntradasCompuerta());
	circuito.agregarEntradaCompuerta(entrada1);

	EntradaCompuerta* entrada2= new EntradaCompuerta(circuito.getContadorEntradasCompuerta());
	circuito.agregarEntradaCompuerta(entrada2);

	SalidaCompuerta* salida= new SalidaCompuerta(circuito.getContadorSalidasCompuerta());
	circuito.agregarSalidaCompuerta(salida);

	Compuerta* compuerta= new OR(circuito.getContadorCompuertas(),tiempo,entrada1,entrada2,salida);
	circuito.agregarCompuerta(compuerta);

	entrada1->setCompuerta(compuerta);
	entrada2->setCompuerta(compuerta);
	salida->setCompuerta(compuerta);

}

void FactoryCompuerta::crearNOT(Circuito &circuito,int tiempo) {

	EntradaCompuerta* entrada= new EntradaCompuerta(circuito.getContadorEntradasCompuerta());
	circuito.agregarEntradaCompuerta(entrada);

	SalidaCompuerta* salida= new SalidaCompuerta(circuito.getContadorSalidasCompuerta());
	circuito.agregarSalidaCompuerta(salida);

	Compuerta* compuerta= new NOT(circuito.getContadorCompuertas(),tiempo,entrada,salida);
	circuito.agregarCompuerta(compuerta);

	entrada->setCompuerta(compuerta);
	salida->setCompuerta(compuerta);

}

void FactoryCompuerta::crearXOR(Circuito &circuito,int tiempo) {

	EntradaCompuerta* entrada1= new EntradaCompuerta(circuito.getContadorEntradasCompuerta());
	circuito.agregarEntradaCompuerta(entrada1);

	EntradaCompuerta* entrada2= new EntradaCompuerta(circuito.getContadorEntradasCompuerta());
	circuito.agregarEntradaCompuerta(entrada2);

	SalidaCompuerta* salida= new SalidaCompuerta(circuito.getContadorSalidasCompuerta());
	circuito.agregarSalidaCompuerta(salida);

	Compuerta* compuerta= new XOR(circuito.getContadorCompuertas(),tiempo,entrada1,entrada2,salida);
	circuito.agregarCompuerta(compuerta);

	entrada1->setCompuerta(compuerta);
	entrada2->setCompuerta(compuerta);
	salida->setCompuerta(compuerta);

}

void FactoryCompuerta::crearPISTA(Circuito &circuito) {

	EntradaCompuerta* entrada= new EntradaCompuerta(circuito.getContadorEntradasCompuerta());
	circuito.agregarEntradaCompuerta(entrada);

	SalidaCompuerta* salida= new SalidaCompuerta(circuito.getContadorSalidasCompuerta());
	circuito.agregarSalidaCompuerta(salida);

	Compuerta* compuerta= new Pista(circuito.getContadorCompuertas(),entrada,salida);
	circuito.agregarCompuerta(compuerta);

	entrada->setCompuerta(compuerta);
	salida->setCompuerta(compuerta);

}

void FactoryCompuerta::crearENTRADA(Circuito &circuito) {

	SalidaCompuerta* salidaEntrada= new SalidaCompuerta(circuito.getContadorSalidasCompuerta());
	circuito.agregarSalidaCompuerta(salidaEntrada);

	Compuerta* compuerta= new Entrada(circuito.getContadorCompuertas(),salidaEntrada);
	circuito.agregarCompuerta(compuerta);

	salidaEntrada->setCompuerta(compuerta);

}

void FactoryCompuerta::crearSALIDA(Circuito &circuito) {

	EntradaCompuerta* entradaSalida= new EntradaCompuerta(circuito.getContadorEntradasCompuerta());
	circuito.agregarEntradaCompuerta(entradaSalida);

	Compuerta* compuerta= new Salida(circuito.getContadorCompuertas(),entradaSalida);
	circuito.agregarCompuerta(compuerta);

	entradaSalida->setCompuerta(compuerta);

}