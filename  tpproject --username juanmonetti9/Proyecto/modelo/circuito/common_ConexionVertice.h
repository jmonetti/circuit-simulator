#ifndef COMMON_CONEXIONVERTICE_H_
#define COMMON_CONEXIONVERTICE_H_

#include "../../common/constantes.h"
#include "../../common/common_Posicion.h"

class ConexionVertice {

public:

	ConexionVertice(Posicion posicion, SENTIDO sentido);

	virtual ~ConexionVertice();

	Posicion getPosicion()const;

	SENTIDO getSentido()const;

private:

	Posicion posicion;
	SENTIDO sentido;

};

#endif /* COMMON_CONEXIONVERTICE_H_ */
