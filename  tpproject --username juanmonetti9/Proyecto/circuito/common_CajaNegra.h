
#ifndef COMMON_CAJANEGRA_H_
#define COMMON_CAJANEGRA_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"
#include <vector>

class CajaNegra: public Compuerta {

public:

	CajaNegra();

	virtual ~CajaNegra();

	int getTiempoTransicion();

	void eliminar();

	bool simular();

private:

	std::vector<EntradaCompuerta*> entradas;
	std::vector<SalidaCompuerta*> salidas;

};

#endif /* COMMON_CAJANEGRA_H_ */
