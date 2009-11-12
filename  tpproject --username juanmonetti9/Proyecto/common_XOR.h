
#ifndef COMMON_XOR_H_
#define COMMON_XOR_H_

#include "common_Compuerta.h"

class XOR: public Compuerta {

public:

	XOR();

	virtual ~XOR();

	int getTiempoTransicion();

	void eliminar();

	bool simular();

};

#endif /* COMMON_XOR_H_ */
