
#ifndef COMMON_COMPUERTA_H_
#define COMMON_COMPUERTA_H_

#include <stdlib.h>
#include "common_EntradaCompuerta.h"

class EntradaCompuerta;
class Entrada;
class Salida;

class Compuerta {

public:

	Compuerta(int id);

	virtual Entrada* getEntrada();

	virtual Salida* getSalida();

	virtual void simular();

	virtual void calcularTiempoTransicion();

	int getId();

protected:

	virtual void actuarSimular(bool* entradas)= 0;

	virtual void actuarTiempo(int tiempo) = 0;

	virtual EntradaCompuerta** getEntradasCompuerta() = 0;

	virtual int getCantidadEntradas() = 0;

private:

	int id;

};

#endif /* COMMON_COMPUERTA_H_ */
