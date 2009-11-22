
#ifndef COMMON_ENTRADA_H_
#define COMMON_ENTRADA_H_

#include "common_Compuerta.h"
#include "common_SalidaCompuerta.h"

class Entrada: public Compuerta {

public:

	Entrada(int id,SalidaCompuerta* salida);

	virtual ~Entrada();

	Entrada* getEntrada();

	void setValorEntrada(bool valor);

protected:

	virtual void actuarSimular(bool* entradas);

	virtual void actuarTiempo(int tiempo);

	virtual EntradaCompuerta** getEntradasCompuerta();

	virtual int getCantidadEntradas();


private:

	SalidaCompuerta* salida;
	bool valor;

};

#endif /* COMMON_ENTRADA_H_ */
