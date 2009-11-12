/**************************   Clase Circuito **************************************/
/**************************      Grupo 8     **************************************/

#ifndef COMMON_CIRCUITO_H_
#define COMMON_CIRCUITO_H_

#include "common_Componente.h"

class Circuito {

public:

	Circuito();

	virtual ~Circuito();

	void simular();

	int getTiempoTransicion();

};

#endif /* COMMON_CIRCUITO_H_ */
