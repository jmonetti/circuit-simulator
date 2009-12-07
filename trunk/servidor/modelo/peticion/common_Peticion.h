/*
 * common_Peticion.h
 *
 *  Created on: 04/12/2009
 *      Author: giovanni
 */

#ifndef COMMON_PETICION_H_
#define COMMON_PETICION_H_

#include "common_Servidor.h"
#include <vector>
#include "../../circuito/common_Circuito.h"
#include "../simulacion/common_ResultadoSimulacion.h"
#include "common_Mensajes.h"

class CajaNegra;

class Peticion {
public:
	Peticion();
	virtual ~Peticion();

	bool* simular(const std::string &nombreCircuito,Servidor servidor,bool* entradas,int cantidad);

	int* calcularTiempoTransicion(const std::string &nombreCircuito,Servidor servidor, int* tiempos,int cantidad);

	static std::string generarPedido (std::string &nombreCircuito,int cantEntradas, bool* entradas);

	static std::string generarPedido (std::string &nombreCircuito,int cantEntradas, int* entradas);

	static std::string generarRespuesta (int cantSalidas, bool* salidas);

	static std::string generarRespuesta (int cantSalidas, int* salidas);

	static std::string generarRespuesta ();

	std::string generarListaCircuitos(std::vector<Circuito*> circuitos);
;


};

#endif /* COMMON_PETICION_H_ */
