#ifndef COMMON_CONEXIONVERTICE_H_
#define COMMON_CONEXIONVERTICE_H_

#include "../../common/constantes.h"
#include "../../common/common_Posicion.h"

/*
 * Clase ConexionVertice
 * Encapsula la conexion perpendicular
 */

class ConexionVertice {

public:

	/*
	 * Constructor
	 * posicion= posicion de la conexion perpendicular
	 * sentido= sentido de la conexion perpendicular
	 */
	ConexionVertice(Posicion posicion, SENTIDO sentido);

	/*
	 * Retorna la posicion
	 */
	Posicion getPosicion()const;

	/*
	 * Retorna el sentido
	 */
	SENTIDO getSentido()const;

private:

	Posicion posicion;
	SENTIDO sentido;

};

#endif /* COMMON_CONEXIONVERTICE_H_ */
