
#ifndef COMMON_ENTRADACOMPUERTA_H_
#define COMMON_ENTRADACOMPUERTA_H_

#include "common_Componente.h"
#include "common_SalidaCompuerta.h"
#include "common_Compuerta.h"

class EntradaCompuerta: public Componente {

public:

	EntradaCompuerta();

	virtual ~EntradaCompuerta();

	int getTiempoTransicion();

	void eliminar();

	bool simular();

private:

	Compuerta* compuerta;
	SalidaCompuerta* entrada;

};

#endif /* COMMON_ENTRADACOMPUERTA_H_ */
