
#ifndef COMMON_SALIDACOMPUERTA_H_
#define COMMON_SALIDACOMPUERTA_H_

#include "common_Componente.h"
#include "common_Compuerta.h"

class EntradaCompuerta;

class SalidaCompuerta: public Componente {

public:

	SalidaCompuerta();

	virtual ~SalidaCompuerta();

	int getTiempoTransicion();

	void eliminar();

	bool simular();

	void setValorSalida(bool valor);

private:

	Compuerta* compuerta;
	EntradaCompuerta* salida;

	bool valor;
	bool valido;

};

#endif /* COMMON_SALIDACOMPUERTA_H_ */
