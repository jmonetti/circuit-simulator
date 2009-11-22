
#ifndef COMMON_ENTRADACOMPUERTA_H_
#define COMMON_ENTRADACOMPUERTA_H_

#include "common_SalidaCompuerta.h"

class SalidaCompuerta;

class Compuerta;

class EntradaCompuerta {

public:

	EntradaCompuerta(int id);

	int calcularTiempoTransicion();

	bool simular();

	void setCompuerta(Compuerta* compuerta);

	void setEntrada(SalidaCompuerta* entrada);

	int getId();

private:

	Compuerta* compuerta;
	SalidaCompuerta* entrada;
	int id;

};

#endif /* COMMON_ENTRADACOMPUERTA_H_ */
