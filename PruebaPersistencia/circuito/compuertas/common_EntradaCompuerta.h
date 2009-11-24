
#ifndef COMMON_ENTRADACOMPUERTA_H_
#define COMMON_ENTRADACOMPUERTA_H_

#include "common_SalidaCompuerta.h"
#include "common_Compuerta.h"

class SalidaCompuerta;

class EntradaCompuerta {

public:

	EntradaCompuerta(int id);

	int calcularTiempoTransicion();

	bool simular();

	void setEntrada(SalidaCompuerta* entrada);

	int getId();

	int getConexion();

	void guardar(DOMDocument* doc, DOMNode* padre);

private:

	SalidaCompuerta* entrada;
	int id;

};

#endif /* COMMON_ENTRADACOMPUERTA_H_ */
