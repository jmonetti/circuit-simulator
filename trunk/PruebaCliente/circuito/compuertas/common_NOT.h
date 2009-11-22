
#ifndef COMMON_NOT_H_
#define COMMON_NOT_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"

class NOT: public Compuerta {

public:

	NOT(int id,int tiempoTransicion, EntradaCompuerta* entrada, SalidaCompuerta* salida);

	virtual ~NOT();

protected:

	virtual void actuarSimular(bool* entradas);

	virtual void actuarTiempo(int tiempo);

	virtual EntradaCompuerta** getEntradasCompuerta();

	virtual int getCantidadEntradas();

private:

	EntradaCompuerta* entrada;
	SalidaCompuerta* salida;
	int tiempoTransicion;

};

#endif /* COMMON_NOT_H_ */
