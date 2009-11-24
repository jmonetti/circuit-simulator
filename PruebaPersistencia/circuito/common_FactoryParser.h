/*
 * FactoryParser.h
 *
 *  Created on: 23/11/2009
 *      Author: giovanni
 */

#ifndef FACTORYPARSER_H_
#define FACTORYPARSER_H_

#include "compuertas/common_Compuerta.h"
#include "common_Circuito.h"
#include "../common/constantes.h"

class FactoryParser {
public:

	static void crearCompuerta(TIPO_COMPUERTA tipo, Circuito &circuito,int idCompuerta, int tiempoTransicion = 0, int idEntrada1 = 0,int idEntrada2 = 0,int idSalida = 0, bool Valor = false);

private:

	static void crearAND(Circuito &circuito,int idCompuerta,int tiempo,int idEntrada1,int idEntrada2, int idSalida);
	static void crearOR(Circuito &circuito,int idCompuerta,int tiempo,int idEntrada1,int idEntrada2, int idSalida);
	static void crearNOT(Circuito &circuito,int idCompuerta,int tiempo,int idEntrada, int idSalida);
	static void crearXOR(Circuito &circuito,int idCompuerta,int tiempo,int idEntrada1,int idEntrada2, int idSalida);
	static void crearPISTA(Circuito &circuito,int idCompuerta,int idEntrada, int idSalida);
	static void crearENTRADA(Circuito &circuito,int idCompuerta,int idSalida, bool valor);
	static void crearSALIDA(Circuito &circuito,int idCompuerta,int idEntrada, bool valor);
};

#endif /* FACTORYPARSER_H_ */
