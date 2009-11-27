
#ifndef COMMON_AND_H_
#define COMMON_AND_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"

class AND: public Compuerta {

public:

	AND(int id,int tiempoTransicion,EntradaCompuerta* entrada1,EntradaCompuerta* entrada2,SalidaCompuerta* salida, Posicion posicion,SENTIDO sentido);

	virtual ~AND();

	void calcularTiempoTransicion();

	void simular();

	void guardar(DOMDocument* doc, DOMNode* padre);

	TIPO_COMPUERTA getTipo() const;

	EntradaCompuerta** getEntradas();

	SalidaCompuerta** getSalidas();

	int getCantidadEntradas();

	int getCantidadSalidas();


private:

	EntradaCompuerta* entradas[2];
	SalidaCompuerta* salida;
	int tiempoTransicion;

};

#endif /* COMMON_AND_H_ */
