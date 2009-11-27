/**************************   Clase Pista **************************************/
/**************************     Grupo 8   **************************************/

#ifndef COMMON_PISTA_H_
#define COMMON_PISTA_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"

class Pista: public Compuerta {

public:

	Pista(int id, EntradaCompuerta* entrada,SalidaCompuerta* salida,Posicion posicion,SENTIDO sentido);

	virtual ~Pista();

	void calcularTiempoTransicion();

	void simular();

	TIPO_COMPUERTA getTipo() const;

	EntradaCompuerta** getEntradas();

	SalidaCompuerta** getSalidas();

	int getCantidadEntradas();

	int getCantidadSalidas();


	void guardar(DOMDocument* doc, DOMNode* padre);

private:

	EntradaCompuerta* entrada;
	SalidaCompuerta* salida;

};

#endif /* COMMON_PISTA_H_ */
