
#ifndef COMMON_XOR_H_
#define COMMON_XOR_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"

class XOR: public Compuerta {

public:

	XOR();

	virtual ~XOR();

	int getTiempoTransicion();

	void eliminar();

	bool simular();

private:

	EntradaCompuerta* entradas[2];
	SalidaCompuerta* salida;

};

#endif /* COMMON_XOR_H_ */
