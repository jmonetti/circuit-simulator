/**************************   Clase Pista **************************************/
/**************************     Grupo 8   **************************************/

#ifndef COMMON_PISTA_H_
#define COMMON_PISTA_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"

class Pista: public Compuerta {

public:

	Pista();

	virtual ~Pista();

	int getTiempoTransicion();

	void eliminar();

	bool simular();

private:

private:

	EntradaCompuerta* entrada;
	SalidaCompuerta* salida;



};

#endif /* COMMON_PISTA_H_ */
