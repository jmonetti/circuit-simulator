
#ifndef COMMON_CAJANEGRA_H_
#define COMMON_CAJANEGRA_H_

#include "common_Compuerta.h"

class CajaNegra: public Compuerta {

public:

	CajaNegra();

	virtual ~CajaNegra();

	int getTiempoTransicion();

	void eliminar();

	bool simular();

};

#endif /* COMMON_CAJANEGRA_H_ */
