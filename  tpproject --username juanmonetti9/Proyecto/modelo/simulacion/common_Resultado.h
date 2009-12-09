
#ifndef COMMON_RESULTADO_H_
#define COMMON_RESULTADO_H_

#include "common_ResultadoSimulacion.h"
#include "common_ResultadoTiempo.h"
#include <vector>
#include <string>

/*
 * Clase Resultado.
 * Encapsula el resultado de la simulacion con los tiempos de transicion
 */

class Resultado {

public:

	/*
	 * Constructor
	 * resultadoSimulacion= resultado de la simulacion
	 * resultadoTiempo= resultado de los tiempos de cada salida
	 * nombreEntradas= nombre de las entradas del circuito
	 * nombreSalidas= nombre de las salidas del circuito
	 */
	Resultado(std::vector<ResultadoSimulacion*>* resultadoSimulacion,ResultadoTiempo* resultadoTiempo,
std::vector<std::string>* nombreEntradas, std::vector<std::string>* nombreSalidas);

	/*
	 * Destructor
	 */
	virtual ~Resultado();

	/*
	 * Retorna el resultado de la simulacion
	 */
	std::vector<ResultadoSimulacion*>* getResultadoSimulacion();

	/*
	 * Retorna el resultado de los tiempos
	 */
	ResultadoTiempo* getResultadoTiempo();

	/*
	 * Retorna los nombres de las entradas
	 */
	std::vector<std::string>* getNombreEntradas();

	/*
	 * Retorna los nombres de las salidas
	 */
	std::vector<std::string>* getNombreSalidas();

private:

	std::vector<ResultadoSimulacion*>* resultadoSimulacion;

	ResultadoTiempo* resultadoTiempo;

	std::vector<std::string>* nombreEntradas;

	std::vector<std::string>* nombreSalidas;

};

#endif /* COMMON_RESULTADO_H_ */
