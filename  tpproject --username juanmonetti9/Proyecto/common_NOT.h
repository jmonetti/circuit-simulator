
#ifndef COMMON_NOT_H_
#define COMMON_NOT_H_

#include "common_Compuerta.h"

class NOT: public Compuerta {

public:

	NOT();

	virtual ~NOT();

	int getTiempoTransicion();

	void eliminar();

	bool simular();

};

#endif /* COMMON_NOT_H_ */
