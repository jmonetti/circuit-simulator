/**************************   Clase Pista **************************************/
/**************************     Grupo 8   **************************************/

#ifndef COMMON_PISTA_H_
#define COMMON_PISTA_H_

#include "common_Compuerta.h"

class Pista: public Compuerta {

public:

	Pista();

	virtual ~Pista();

	int getTiempoTransicion();

	void eliminar();

	bool simular();

};

#endif /* COMMON_PISTA_H_ */
