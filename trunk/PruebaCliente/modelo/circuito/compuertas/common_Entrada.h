
#ifndef COMMON_ENTRADA_H_
#define COMMON_ENTRADA_H_

#include "common_Compuerta.h"
#include "common_SalidaCompuerta.h"

class Entrada: public Compuerta {

public:

	Entrada(int id,SalidaCompuerta* salida);

	virtual ~Entrada();

	void calcularTiempoTransicion();

	Entrada* getEntrada();

	void simular();

	void setValorEntrada(bool valor);

	bool getValorEntrada() const;

	void guardar(DOMDocument* doc, DOMNode* padre);

private:

	SalidaCompuerta* salida;
	bool valor;

};

#endif /* COMMON_ENTRADA_H_ */
