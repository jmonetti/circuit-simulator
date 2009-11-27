
#ifndef COMMON_FACTORYCOMPUERTA_H_
#define COMMON_FACTORYCOMPUERTA_H_

#include "compuertas/common_Compuerta.h"
#include "common_Circuito.h"
#include "../../common/constantes.h"
#include "../../common/common_Posicion.h"
#include <string>

class FactoryCompuerta {

public:

	static void crearCompuerta(TIPO_COMPUERTA tipo, Circuito &circuito, Posicion posicion,SENTIDO sentido);

	static void crearEntrada(Circuito &circuito, Posicion posicion, const std::string &nombre, SENTIDO sentido);

	static void crearSalida(Circuito &circuito, Posicion posicion, const std::string &nombre, SENTIDO sentido);

private:

	static void crearAND(Circuito &circuito,Posicion posicion, SENTIDO sentido);
	static void crearOR(Circuito &circuito,Posicion posicion, SENTIDO sentido);
	static void crearNOT(Circuito &circuito,Posicion posicion, SENTIDO sentido);
	static void crearXOR(Circuito &circuito,Posicion posicion, SENTIDO sentido);
	static void crearPISTA(Circuito &circuito,Posicion posicion, SENTIDO sentido);

};

#endif /* COMMON_FACTORYCOMPUERTA_H_ */
