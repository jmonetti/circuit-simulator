
#ifndef COMMON_RESULTADO_H_
#define COMMON_RESULTADO_H_

#include "common_ResultadoSimulacion.h"
#include "common_ResultadoTiempo.h"
#include <vector>

class Resultado {

public:

	Resultado(std::vector<ResultadoSimulacion*>* resultadoSimulacion,ResultadoTiempo* resultadoTiempo);

	virtual ~Resultado();

	std::vector<ResultadoSimulacion*>* getResultadoSimulacion();

	ResultadoTiempo* getResultadoTiempo();

private:

	std::vector<ResultadoSimulacion*>* resultadoSimulacion;

	ResultadoTiempo* resultadoTiempo;

};

#endif /* COMMON_RESULTADO_H_ */
