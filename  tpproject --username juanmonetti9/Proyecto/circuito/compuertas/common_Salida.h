
#ifndef COMMON_SALIDA_H_
#define COMMON_SALIDA_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"

class Salida: public Compuerta {

public:

	Salida(int id, EntradaCompuerta* entrada);

	virtual ~Salida();

	void calcularTiempoTransicion();

	Salida* getSalida();

	void simular();

	bool getValor();

	int getTiempoTransicion();

	void guardar(DOMDocument* doc, DOMNode* padre);


private:

	EntradaCompuerta* entrada;
	bool valor;
	int tiempoTransicion;

};

#endif /* COMMON_SALIDA_H_ */
