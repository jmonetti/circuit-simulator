
#ifndef COMMON_AND_H_
#define COMMON_AND_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"

class AND: public Compuerta {

public:

	AND();

	virtual ~AND();

	int getTiempoTransicion();

	void eliminar();

	bool simular();

private:

	EntradaCompuerta* entradas[2];
	SalidaCompuerta salida;

};

#endif /* COMMON_AND_H_ */
