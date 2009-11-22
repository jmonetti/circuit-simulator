
#ifndef COMMON_SALIDA_H_
#define COMMON_SALIDA_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"

class Salida: public Compuerta {

public:

	Salida(int id, EntradaCompuerta* entrada);

	virtual ~Salida();

	Salida* getSalida();

	bool getValor();

	int getTiempoTransicion();


private:

	virtual void actuarSimular(bool* entradas);

	virtual void actuarTiempo(int tiempo);

	virtual EntradaCompuerta** getEntradasCompuerta();

	virtual int getCantidadEntradas();


	EntradaCompuerta* entrada;
	bool valor;
	int tiempoTransicion;

};

#endif /* COMMON_SALIDA_H_ */
