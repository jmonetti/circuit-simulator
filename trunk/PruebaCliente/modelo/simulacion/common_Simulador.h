
#ifndef COMMON_SIMULADOR_H_
#define COMMON_SIMULADOR_H_

#include "../circuito/common_Circuito.h"
#include "common_ResultadoSimulacion.h"
#include <vector>

class Simulador {

public:

	std::vector<ResultadoSimulacion*>* simular(Circuito &circuito);

private:

	bool* generarEntradas(int i, unsigned int cantidadEntradas,const bool* entradasAnt);
};

#endif /* COMMON_SIMULADOR_H_ */
