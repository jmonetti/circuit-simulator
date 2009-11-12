/**************************   Clase Componente **************************************/
/**************************       Grupo 8      **************************************/

#ifndef COMMON_COMPONENTE_H_
#define COMMON_COMPONENTE_H_

#include "common_Posicion.h"

class Componente {

public:

	Componente();

	virtual ~Componente();

	virtual int getTiempoTransicion() = 0;

	virtual void eliminar() = 0;

	//TODO ver el tipo de direccion
	virtual void rotar(int direccion);

	/*
	 * Mueve el componente a la posicion
	 */
	virtual void mover(Posicion posicion);

	virtual bool simular() = 0;

private:

	int id;
	Posicion posicion;
	int sentido;

};

#endif /* COMMON_COMPONENTE_H_ */
