
#ifndef COMMON_COMPUERTA_H_
#define COMMON_COMPUERTA_H_

#include "common_Componente.h"
#include <stdlib.h>

class Entrada;
class Salida;

class Compuerta : public Componente{

public:

	Compuerta();

	virtual ~Compuerta();

	virtual Entrada* getEntrada();

	virtual Salida* getSalida();

private:

	int tiempoTransicion;

};

#endif /* COMMON_COMPUERTA_H_ */
