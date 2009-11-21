
#ifndef COMMON_PUBLICACION_H_
#define COMMON_PUBLICACION_H_

#include "common_Servidor.h"
#include <vector>
#include "common_ResultadoSimulacion.h"
#include "../circuito/compuertas/common_CajaNegra.h"

class Publicacion {

public:

	void enviar(const std::string &nombreCircuito, const Servidor &servidor);

	std::vector<ResultadoSimulacion*>* simular(const std::string &nombreCircuito,const Servidor &servidor);

	CajaNegra* recibir(const std::string &nombreCircuito,const Servidor &servidor);


};

#endif /* COMMON_PUBLICACION_H_ */
