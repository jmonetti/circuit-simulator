
#ifndef COMMON_NOT_H_
#define COMMON_NOT_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"

class NOT: public Compuerta {

public:

	NOT(int id, EntradaCompuerta* entrada, SalidaCompuerta* salida);

	virtual ~NOT();

	void calcularTiempoTransicion();

	void simular();

	void guardar(DOMDocument* doc, DOMNode* padre);

private:

	EntradaCompuerta* entrada;
	SalidaCompuerta* salida;
	int tiempoTransicion;

};

#endif /* COMMON_NOT_H_ */
