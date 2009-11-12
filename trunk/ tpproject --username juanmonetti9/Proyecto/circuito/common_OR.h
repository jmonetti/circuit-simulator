#ifndef COMMON_OR_H_
#define COMMON_OR_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"

class OR: public Compuerta {

public:

	OR();

	virtual ~OR();

	int getTiempoTransicion();

	void eliminar();

	bool simular();

private:

	EntradaCompuerta* entradas[2];
	SalidaCompuerta* salida;

};

#endif /* COMMON_OR_H_ */
