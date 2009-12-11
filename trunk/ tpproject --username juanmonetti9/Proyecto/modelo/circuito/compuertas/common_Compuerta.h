
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

/*
 * Clase Compuerta
 */

class Compuerta {

public:

	/*
	 * Constructor
	 * id= id de la compuerta
	 * posicion= posicion de la compuerta
	 * sentido= sentido de la compuerta
	 */
	Compuerta(int id,Posicion posicion,SENTIDO sentido);

	virtual ~Compuerta();

	/*
	 * Metodo tipo casteo para Entrada
	 */
	virtual Entrada* getEntrada();

	/*
	 * Metodo tipo casteo para Salida
	 */
	virtual Salida* getSalida();

	/*
	 * Simula
	 */
	virtual void simular();

	/*
	 * Calcula el tiempo transicion
	 */
	virtual void calcularTiempoTransicion();

	/*
	 * Mueve la compuerta
	 * posicion= posicion a la cual se va a mover
	 */
	void mover(Posicion posicion);

	/*
	 * Rota la compuerta
	 * direccion= direccion hacia donde se rota
	 */
	void rotar(DIRECCION direccion);

	/*
	 * Retorna las EntradaCompuerta
	 */
	virtual EntradaCompuerta** getEntradas() = 0;

	/*
	 * Retorna las SalidaCompuerta
	 */
	virtual SalidaCompuerta** getSalidas() = 0;

	/*
	 * Retorna la cantidad de entradas
	 */
	virtual int getCantidadEntradas() = 0;

	/*
	 * Retorna la cantidad de salidas
	 */
	virtual int getCantidadSalidas() = 0;

	/*
	 * Retorna el tipo de compuerta
	 */
	virtual TIPO_COMPUERTA getTipo() const = 0;

	/*
	 * Retorna el id
	 */
	int getId();

	/*
	 * Guarda la compuerta
	 */
	virtual void guardar(DOMDocument* doc, DOMNode* padre) = 0;

	/*
	 * Retorna la posicion
	 */
	Posicion getPosicion() const;

	/*
	 * Retorna el sentido
	 */
	SENTIDO getSentido() const;

protected:

	/*
	 * Actualiza la posicion y sentido de las EntradasCompuerta
	 */
	virtual void actualizarEntradas() = 0;
	/*
	 * Acutaliza la posicion y sentido de las SalidaCompuerta
	 */
	virtual void actualizarSalidas() = 0;
	/*
	 * Actuar simular
	 */
	virtual void actuarSimular(bool* valores) = 0;
	/*
	 * Actuar tiempo
	 */
	virtual void actuarTiempo(int* tiempos) = 0;

private:

	/*
	 * Rota hacia izquierda
	 */
	void rotarIzquierda();
	/*
	 * Rota hacia derecha
	 */
	void rotarDerecha();


	int id;
	Posicion posicion;
	SENTIDO sentido;

};

#endif /* COMMON_COMPUERTA_H_ */
