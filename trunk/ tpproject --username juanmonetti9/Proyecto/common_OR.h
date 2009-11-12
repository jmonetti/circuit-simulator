#ifndef COMMON_OR_H_
#define COMMON_OR_H_

#include "common_Compuerta.h"

class OR: public Compuerta {

public:

	OR();

	virtual ~OR();

	int getTiempoTransicion();

	void eliminar();

	bool simular();

};

#endif /* COMMON_OR_H_ */
