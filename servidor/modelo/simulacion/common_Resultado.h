
#ifndef COMMON_RESULTADO_H_
#define COMMON_RESULTADO_H_

#include "common_ResultadoSimulacion.h"
#include "common_ResultadoTiempo.h"
#include <vector>
#include <string>

class Resultado {

public:

	Resultado(std::vector<ResultadoSimulacion*>* resultadoSimulacion,ResultadoTiempo* resultadoTiempo,
std::vector<std::string>* nombreEntradas, std::vector<std::string>* nombreSalidas);

	virtual ~Resultado();

	std::vector<ResultadoSimulacion*>* getResultadoSimulacion();

	ResultadoTiempo* getResultadoTiempo();

	std::vector<std::string>* getNombreEntradas();

	std::vector<std::string>* getNombreSalidas();

private:

	std::vector<ResultadoSimulacion*>* resultadoSimulacion;

	ResultadoTiempo* resultadoTiempo;

	std::vector<std::string>* nombreEntradas;

	std::vector<std::string>* nombreSalidas;

};

#endif /* COMMON_RESULTADO_H_ */
