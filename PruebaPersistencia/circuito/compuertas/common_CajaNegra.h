
#ifndef COMMON_CAJANEGRA_H_
#define COMMON_CAJANEGRA_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"
#include <vector>

class CajaNegra: public Compuerta {

public:

	CajaNegra(int id,std::vector<EntradaCompuerta*> &entradas, std::vector<SalidaCompuerta*> &salidas);

	virtual ~CajaNegra();

	void calcularTiempoTransicion();

	void simular();

	void guardar(DOMDocument* doc, DOMNode* padre){}

private:

	std::vector<EntradaCompuerta*> entradas;
	std::vector<SalidaCompuerta*> salidas;

};

#endif /* COMMON_CAJANEGRA_H_ */
