
#ifndef COMMON_NOT_H_
#define COMMON_NOT_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"

class NOT: public Compuerta {

public:

	NOT();

	virtual ~NOT();

	int getTiempoTransicion();

	void eliminar();

	bool simular();

private:

	EntradaCompuerta* entrada;
	SalidaCompuerta* salida;

};

#endif /* COMMON_NOT_H_ */
