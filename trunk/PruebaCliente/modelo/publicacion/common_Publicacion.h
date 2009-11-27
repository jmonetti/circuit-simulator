
#ifndef COMMON_PUBLICACION_H_
#define COMMON_PUBLICACION_H_

#include "common_Servidor.h"
#include <vector>
#include "../simulacion/common_ResultadoSimulacion.h"

class CajaNegra;

class Publicacion {

public:

	void enviar(const std::string &nombreCircuito,Servidor servidor);

	bool* simular(const std::string &nombreCircuito,Servidor servidor,bool* entradas);

	int* calcularTiempoTransicion(const std::string &nombreCircuito,Servidor servidor, int* tiempos);

	CajaNegra* recibir(const std::string &nombreCircuito,Servidor servidor);


};

#endif /* COMMON_PUBLICACION_H_ */
