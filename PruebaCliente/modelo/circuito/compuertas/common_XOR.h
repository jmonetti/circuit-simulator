
#ifndef COMMON_XOR_H_
#define COMMON_XOR_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"

class XOR: public Compuerta {

public:

	XOR(int id, int tiempoTransicion,EntradaCompuerta* entrada1,EntradaCompuerta* entrada2, SalidaCompuerta* salida, Posicion posicion, SENTIDO sentido);

	virtual ~XOR();

	void calcularTiempoTransicion();

	void simular();

	TIPO_COMPUERTA getTipo() const;

	EntradaCompuerta** getEntradas();

	SalidaCompuerta** getSalidas();

	int getCantidadEntradas();

	int getCantidadSalidas();

	void guardar(DOMDocument* doc, DOMNode* padre);

protected:

	void actualizarEntradas();
	void actualizarSalidas();

private:

	EntradaCompuerta* entradas[2];
	SalidaCompuerta* salida;
	int tiempoTransicion;

};

#endif /* COMMON_XOR_H_ */
