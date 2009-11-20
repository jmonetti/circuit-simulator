
#ifndef COMMON_SIMULADOR_H_
#define COMMON_SIMULADOR_H_

#include "common_Circuito.h"
#include "common_Resultado.h"
#include <vector>

class Simulador {

public:

	static std::vector<Resultado*>* simular(Circuito &circuito);

private:

	static bool* generarEntradas(int i, unsigned int cantidadEntradas,const bool* entradasAnt);
};

#endif /* COMMON_SIMULADOR_H_ */
