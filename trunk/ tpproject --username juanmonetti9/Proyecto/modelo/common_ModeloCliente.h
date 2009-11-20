
#ifndef COMMON_MODELOCLIENTE_H_
#define COMMON_MODELOCLIENTE_H_

#include <vector>
#include <string>

#include "../circuito/common_Circuito.h"
#include "common_Resultado.h"
#include "common_Servidor.h"


class ModeloCliente {

public:

	std::vector<Resultado*>* simular(int idCircuito);

	void guardar(int idCircuito);

	void recuperar(const std::string &nombreCircuito);

	void enviar(const std::string &nombreCircuito, Servidor servidor);

	void recibir(const std::string &nombreCircuito,Servidor servidor);

private:

	std::vector<Circuito*> circuitos;

};

#endif /* COMMON_MODELOCLIENTE_H_ */
