
#ifndef COMMON_NOT_H_
#define COMMON_NOT_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"

class NOT: public Compuerta {

public:

	NOT(int id,int tiempoTransicion, EntradaCompuerta* entrada, SalidaCompuerta* salida, Posicion posicion, SENTIDO sentido);

	virtual ~NOT();

	void calcularTiempoTransicion();

	void simular();

	TIPO_COMPUERTA getTipo() const;

	EntradaCompuerta** getEntradas();

	SalidaCompuerta** getSalidas();

	int getCantidadEntradas();

	int getCantidadSalidas();


	void guardar(DOMDocument* doc, DOMNode* padre);

private:

	EntradaCompuerta* entrada;
	SalidaCompuerta* salida;
	int tiempoTransicion;

};

#endif /* COMMON_NOT_H_ */
