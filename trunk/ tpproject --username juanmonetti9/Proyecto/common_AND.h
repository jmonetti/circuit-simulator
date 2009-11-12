
#ifndef COMMON_AND_H_
#define COMMON_AND_H_

#include "common_Compuerta.h"

class AND: public Compuerta {

public:

	AND();

	virtual ~AND();

	int getTiempoTransicion();

	void eliminar();

	bool simular();

};

#endif /* COMMON_AND_H_ */
