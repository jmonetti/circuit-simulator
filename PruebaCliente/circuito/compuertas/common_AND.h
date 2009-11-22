
#ifndef COMMON_AND_H_
#define COMMON_AND_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"

class AND: public Compuerta {

public:

	AND(int id,int tiempoTransicion,EntradaCompuerta* entrada1,EntradaCompuerta* entrada2,SalidaCompuerta* salida);

	virtual ~AND();

protected:

	virtual void actuarSimular(bool* entradas);

	virtual void actuarTiempo(int tiempo);

	virtual EntradaCompuerta** getEntradasCompuerta();

	virtual int getCantidadEntradas();

private:

	EntradaCompuerta* entradas[2];
	SalidaCompuerta* salida;
	int tiempoTransicion;

};

#endif /* COMMON_AND_H_ */
