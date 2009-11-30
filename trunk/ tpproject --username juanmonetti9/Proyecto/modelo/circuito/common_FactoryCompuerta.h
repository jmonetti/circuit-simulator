
#ifndef COMMON_FACTORYCOMPUERTA_H_
#define COMMON_FACTORYCOMPUERTA_H_

#include "compuertas/common_Compuerta.h"
#include "common_Circuito.h"
#include "../../common/constantes.h"
#include "../../common/common_Posicion.h"
#include <string>

class FactoryCompuerta {

public:

	static int crearCompuerta(TIPO_COMPUERTA tipo, Circuito &circuito, Posicion posicion,SENTIDO sentido);

	static int crearEntrada(Circuito &circuito, Posicion posicion, const std::string &nombre, SENTIDO sentido);

	static int crearSalida(Circuito &circuito, Posicion posicion, const std::string &nombre, SENTIDO sentido);

private:

	static int crearAND(Circuito &circuito,Posicion posicion, SENTIDO sentido);
	static int crearOR(Circuito &circuito,Posicion posicion, SENTIDO sentido);
	static int crearNOT(Circuito &circuito,Posicion posicion, SENTIDO sentido);
	static int crearXOR(Circuito &circuito,Posicion posicion, SENTIDO sentido);
	static int crearPISTA(Circuito &circuito,Posicion posicion, SENTIDO sentido);

};

#endif /* COMMON_FACTORYCOMPUERTA_H_ */
