
#ifndef COMMON_COMPUERTA_H_
#define COMMON_COMPUERTA_H_

#include <stdlib.h>

class Entrada;
class Salida;

class Compuerta {

public:

	Compuerta(int id);

	virtual Entrada* getEntrada();

	virtual Salida* getSalida();

	virtual void simular() = 0;

	virtual void calcularTiempoTransicion() = 0;

	int getId();

private:

	int id;

};

#endif /* COMMON_COMPUERTA_H_ */
