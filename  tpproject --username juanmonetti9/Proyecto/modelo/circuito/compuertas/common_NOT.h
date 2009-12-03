
#ifndef COMMON_NOT_H_
#define COMMON_NOT_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"

class NOT: public Compuerta {

public:

	NOT(int id,int tiempoTransicion, EntradaCompuerta* entrada, SalidaCompuerta* salida, Posicion posicion, SENTIDO sentido);

	virtual ~NOT();

	TIPO_COMPUERTA getTipo() const;

	EntradaCompuerta** getEntradas();

	SalidaCompuerta** getSalidas();

	int getCantidadEntradas();

	int getCantidadSalidas();


	void guardar(DOMDocument* doc, DOMNode* padre);

protected:

	void actualizarEntradas();
	void actualizarSalidas();

	void actuarSimular(bool* valores);
	void actuarTiempo(int* tiempos);

private:

	EntradaCompuerta* entrada;
	SalidaCompuerta* salida;
	int tiempoTransicion;

};

#endif /* COMMON_NOT_H_ */
