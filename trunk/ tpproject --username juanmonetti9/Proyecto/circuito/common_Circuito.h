/**************************   Clase Circuito **************************************/
/**************************      Grupo 8     **************************************/

#ifndef COMMON_CIRCUITO_H_
#define COMMON_CIRCUITO_H_

#include "common_Componente.h"
#include "common_Entrada.h"
#include "common_Salida.h"
#include <list>

class Circuito {

public:

	Circuito();

	virtual ~Circuito();

	void simular();

	int getTiempoTransicion();

private:

	std::list<Componente*> componentes;
	std::list<Entrada*> entradas;
	std::list<Salida*> salidas;

};

#endif /* COMMON_CIRCUITO_H_ */
