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
#include "../../socket/common_ProtocoloCliente.h"
#include "../../thread/common_Lock.h"
#include "../../thread/common_Mutex.h"
#include "../common_ManagerArchivos.h"

class CajaNegra;

class Peticion {
public:

	void simular(const std::string &nombreCircuito,Servidor servidor,bool* entradas,int cantidad,bool* salidas);

	void calcularTiempoTransicion(const std::string &nombreCircuito,Servidor servidor, int* tiempos,int cantidad,int* salidas);

	std::string generarPedido (const std::string &nombreCircuito,int cantEntradas, bool* entradas);

	std::string generarPedido (const std::string &nombreCircuito,int cantEntradas, int* entradas);

private:

	Mutex mutex;

	ProtocoloCliente protocolo;

	void conectar(Servidor servidor);
	void enviarPedido(const std::string &ruta);
	std::string recibirRespuesta();

	void recuperarDatosSimular(const std::string &ruta,bool* salidas);

	void recuperarDatosTiempos(const std::string &ruta,int* salidas);
;


};

#endif /* COMMON_PETICION_H_ */
