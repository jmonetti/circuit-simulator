
#ifndef COMMON_FACTORYCOMPUERTA_H_
#define COMMON_FACTORYCOMPUERTA_H_

#include "compuertas/common_Compuerta.h"
#include "common_Circuito.h"
#include "../common/constantes.h"

class FactoryCompuerta {

public:

	static void crearCompuerta(TIPO_COMPUERTA tipo, Circuito &circuito);

private:

	static void crearAND(Circuito &circuito);
	static void crearOR(Circuito &circuito);
	static void crearNOT(Circuito &circuito);
	static void crearXOR(Circuito &circuito);
	static void crearPISTA(Circuito &circuito);
	static void crearENTRADA(Circuito &circuito);
	static void crearSALIDA(Circuito &circuito);

};

#endif /* COMMON_FACTORYCOMPUERTA_H_ */
