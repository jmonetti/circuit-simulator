
#ifndef COMMON_AND_H_
#define COMMON_AND_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"

class AND: public Compuerta {

public:

	AND(int id,EntradaCompuerta* entrada1,EntradaCompuerta* entrada2,SalidaCompuerta* salida);

	virtual ~AND();

	void calcularTiempoTransicion();

	void simular();

	void guardar(DOMDocument* doc, DOMNode* padre);

private:

	EntradaCompuerta* entradas[2];
	SalidaCompuerta* salida;
	int tiempoTransicion;

};

#endif /* COMMON_AND_H_ */
