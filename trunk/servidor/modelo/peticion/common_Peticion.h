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
#include "../circuito/common_Circuito.h"
#include "common_Mensajes.h"
#include "../../socket/common_Protocolo.h"

class CajaNegra;

class Peticion {
public:

	bool* simular(const std::string &nombreCircuito,Servidor servidor,bool* entradas,int cantidad);

	int* calcularTiempoTransicion(const std::string &nombreCircuito,Servidor servidor, int* tiempos,int cantidad);

	static std::string generarPedido (const std::string &nombreCircuito,int cantEntradas, bool* entradas);

	static std::string generarPedido (const std::string &nombreCircuito,int cantEntradas, int* entradas);

	static std::string generarRespuesta (int cantSalidas, bool* salidas);

	static std::string generarRespuesta (int cantSalidas, int* salidas);

	std::string generarRespuesta(int cantEntradas, int cantSalidas);

	std::string generarListaCircuitos(std::vector<Circuito*> circuitos);

private:

	Protocolo protocolo;

	void conectar(Servidor servidor);
	void enviarPedido(const std::string &ruta);
	std::string recibirRespuesta();

	void enviarRespuesta(const std::string &ruta);

	bool* recuperarDatosSimular(const std::string &ruta);

	int* recuperarDatosTiempos(const std::string &ruta);
;


};

#endif /* COMMON_PETICION_H_ */
