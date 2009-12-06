
#ifndef COMMON_PUBLICACION_H_
#define COMMON_PUBLICACION_H_

#include "common_Servidor.h"
#include <vector>
#include "../circuito/common_Circuito.h"
#include "../simulacion/common_ResultadoSimulacion.h"

class CajaNegra;

class Publicacion {

public:

	void enviar(const std::string &nombreCircuito,Servidor servidor);

	bool* simular(const std::string &nombreCircuito,Servidor servidor,bool* entradas,int cantidad);

	int* calcularTiempoTransicion(const std::string &nombreCircuito,Servidor servidor, int* tiempos,int cantidad);

	int recibir(const std::string &nombreCircuito,Servidor servidor,Circuito* circuito);

	std::vector<char*>* obtenerCircuitos(Servidor servidor);


};

#endif /* COMMON_PUBLICACION_H_ */
