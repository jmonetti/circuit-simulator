
#ifndef COMMON_PUBLICACION_H_
#define COMMON_PUBLICACION_H_

#include "common_Servidor.h"
#include <vector>
#include "common_ResultadoSimulacion.h"

class CajaNegra;

class Publicacion {

public:

	void enviar(const std::string &nombreCircuito, const Servidor &servidor);

	bool* simular(const std::string &nombreCircuito,const Servidor &servidor,bool* entradas);

	CajaNegra* recibir(const std::string &nombreCircuito,const Servidor &servidor);


};

#endif /* COMMON_PUBLICACION_H_ */
