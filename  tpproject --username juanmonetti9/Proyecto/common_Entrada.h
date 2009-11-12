
#ifndef COMMON_ENTRADA_H_
#define COMMON_ENTRADA_H_

#include "common_Compuerta.h"

class Entrada: public Compuerta {

public:

	Entrada();

	virtual ~Entrada();

	int getTiempoTransicion();

	void eliminar();

	Entrada* getEntrada();

	bool simular();

};

#endif /* COMMON_ENTRADA_H_ */
