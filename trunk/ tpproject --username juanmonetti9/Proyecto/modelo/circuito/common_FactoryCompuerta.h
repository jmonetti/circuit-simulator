
#ifndef COMMON_FACTORYCOMPUERTA_H_
#define COMMON_FACTORYCOMPUERTA_H_

#include "compuertas/common_Compuerta.h"
#include "common_Circuito.h"
#include "../../common/constantes.h"
#include "../../common/common_Posicion.h"
#include <string>
#include "../../common/common_TamanioCajaNegra.h"
#include "../publicacion/common_Servidor.h"
/*
 * Clase FactoryCompuerta
 *
 * Crea las compuertas
 */

class FactoryCompuerta {

public:

	/*
	 * Crea una compuerta
	 * tipo= tipo de compuerta
	 * circuito= circuito donde agregar la compuerta
	 * posicion= posicion de la compuerta
	 * sentido= sentido de la compuerta
	 * Retorna el id de la compuerta
	 */
	static int crearCompuerta(TIPO_COMPUERTA tipo, Circuito &circuito, Posicion posicion,SENTIDO sentido);

	/*
	 * Crea una entrada
	 * circuito= circuito donde agregar la entrada
	 * posicion= posicion de la entrada
	 * nombre= nombre de la entrada
	 * sentido= sentido de la entrada
	 * Retorna el id de la entrada
	 */
	static int crearEntrada(Circuito &circuito, Posicion posicion, const std::string &nombre, SENTIDO sentido);

	/*
	 * Crea una salida
	 * circuito= circuito donde agregar la salida
	 * posicion= posicion de la salida
	 * nombre= nombre de la salida
	 * sentido= sentido de la salida
	 * Retorna el id de la salida
	 */
	static int crearSalida(Circuito &circuito, Posicion posicion, const std::string &nombre, SENTIDO sentido);

	/*
	 * Crea una caja negra
	 * circuito= circuito donde agregar la caja negra
	 * posicion= posicion de la caja negra
	 * nombre= nombre de la caja negra
	 * sentido= sentido de la caja negra
	 * Retorna el id de la caja negra
	 */
	static int crearCajaNegra(Circuito &circuito, Posicion posicion, const std::string &nombre, SENTIDO sentido, Servidor servidor,TamanioCajaNegra tamanio);

private:

	/*
	 * Crea una and
	 */
	static int crearAND(Circuito &circuito,Posicion posicion, SENTIDO sentido);
	/*
	 * Crea una or
	 */
	static int crearOR(Circuito &circuito,Posicion posicion, SENTIDO sentido);
	/*
	 * Crea una not
	 */
	static int crearNOT(Circuito &circuito,Posicion posicion, SENTIDO sentido);
	/*
	 * crea una xor
	 */
	static int crearXOR(Circuito &circuito,Posicion posicion, SENTIDO sentido);
	/*
	 * crea una pista
	 */
	static int crearPISTA(Circuito &circuito,Posicion posicion, SENTIDO sentido);

};

#endif /* COMMON_FACTORYCOMPUERTA_H_ */
