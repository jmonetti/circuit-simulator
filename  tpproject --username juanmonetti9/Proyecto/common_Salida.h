
#ifndef COMMON_SALIDA_H_
#define COMMON_SALIDA_H_

#include "common_Compuerta.h"

class Salida: public Compuerta {

public:

	Salida();

	virtual ~Salida();

	int getTiempoTransicion();

	void eliminar();

	Salida* getSalida();

	bool simular();

};

#endif /* COMMON_SALIDA_H_ */
