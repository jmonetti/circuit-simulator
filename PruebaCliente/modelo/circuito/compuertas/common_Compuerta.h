
#ifndef COMMON_COMPUERTA_H_
#define COMMON_COMPUERTA_H_

#include <stdlib.h>
#include <string>
#include <sstream>
#include <xercesc/dom/DOMDocument.hpp>

#include "../../persistencia/common_Persistencia.h"
#include "../../../common/common_Posicion.h"
#include "../../../common/constantes.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"


class Entrada;
class Salida;

class Compuerta {

public:

	Compuerta(int id,Posicion posicion,SENTIDO sentido);

	virtual Entrada* getEntrada();

	virtual Salida* getSalida();

	virtual void simular() = 0;

	virtual void calcularTiempoTransicion() = 0;

	void mover(unsigned int x,unsigned int y);

	void rotarIzquierda();

	void rotarDerecha();

	virtual EntradaCompuerta** getEntradas() = 0;

	virtual SalidaCompuerta** getSalidas() = 0;

	virtual int getCantidadEntradas() = 0;

	virtual int getCantidadSalidas() = 0;

	virtual TIPO_COMPUERTA getTipo() const = 0;

	int getId();

	virtual void guardar(DOMDocument* doc, DOMNode* padre) = 0;

private:

	int id;
	Posicion posicion;
	SENTIDO sentido;

};

#endif /* COMMON_COMPUERTA_H_ */
