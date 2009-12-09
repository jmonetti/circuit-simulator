
#ifndef COMMON_SIMULADOR_H_
#define COMMON_SIMULADOR_H_

#include "../circuito/common_Circuito.h"
#include "common_ResultadoSimulacion.h"
#include <vector>
#include "common_ResultadoTiempo.h"
#include "common_Resultado.h"

/*
 * Clase Simulador
 * Se encarga de la simulacion y calculo de los tiempos
 */

class Simulador {

public:

	/*
	 * Simula y calcula los tiempos de un circuito
	 * circuito= circuito a simular
	 * Retorna el resultado de la simulacion
	 */
	Resultado* simular(Circuito &circuito);

private:

	/*
	 * Genera las entradas para la siguiente simulacion
	 */
	bool* generarEntradas(int i, unsigned int cantidadEntradas,const bool* entradasAnt);
	/*
	 * Calcula la simulacion
	 */
	std::vector<ResultadoSimulacion*>* calcularSimulacion(Circuito &circuito);
	/*
	 * Calcula los tiempos
	 */
	ResultadoTiempo* calcularTiempo(Circuito &circuito);

	/*
	 * Libera el resultado simulacion en caso de que se produzca un error al simular
	 */
	void vaciarResultadoSimulacion(std::vector<ResultadoSimulacion*>* resultado);
};

#endif /* COMMON_SIMULADOR_H_ */
