
#ifndef COMMON_SIMULADOR_H_
#define COMMON_SIMULADOR_H_

#include "../circuito/common_Circuito.h"
#include "common_ResultadoSimulacion.h"
#include <vector>
#include "common_ResultadoTiempo.h"
#include "common_Resultado.h"

class Simulador {

public:

	Resultado* simular(Circuito &circuito);

private:

	bool* generarEntradas(int i, unsigned int cantidadEntradas,const bool* entradasAnt);
	std::vector<ResultadoSimulacion*>* calcularSimulacion(Circuito &circuito);
	ResultadoTiempo* calcularTiempo(Circuito &circuito);

	void vaciarResultadoSimulacion(std::vector<ResultadoSimulacion*>* resultado);
};

#endif /* COMMON_SIMULADOR_H_ */
