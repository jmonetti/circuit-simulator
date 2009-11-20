
#ifndef COMMON_PUBLICACION_H_
#define COMMON_PUBLICACION_H_

#include "common_Servidor.h"
#include <vector>
#include "common_Resultado.h"
#include "../circuito/common_Circuito.h"

class Publicacion {

public:

	Publicacion();

	virtual ~Publicacion();

	void enviar(const std::string &nombreCircuito, Servidor servidor);

	std::vector<Resultado*>* simular(const std::string &nombreCircuito, Servidor servidor);

	Circuito* recibir(const std::string &nombreCircuito,Servidor servidor);


};

#endif /* COMMON_PUBLICACION_H_ */
