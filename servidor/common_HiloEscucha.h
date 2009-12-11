
#ifndef COMMON_HILOESCUCHA_H_
#define COMMON_HILOESCUCHA_H_

#include "thread/common_Thread.h"
#include "common_HiloComunicacion.h"
#include "socket/common_Socket.h"
#include <vector>
#include <iterator>

class HiloEscucha: public Thread {

public:

	/*
	 * Constructor
	 */
	HiloEscucha(ModeloServidor &modeloServidor);

	/*
	 * Destructor
	 */
	virtual ~HiloEscucha();

	/*
	 * Comienza a escuchar por el puerto port
	 */
	void escuchar(unsigned int port);

	/*
	 * Terminar hilo
	 */
	void terminar();


protected:

	virtual void* run();

private:
	/*
	 * Contador de pedidos del Servidor.
	 */
	int contPedidos;

	Socket* socketEscuchando;

	/*
	 * Modelo del Servidor.
	 */
	ModeloServidor *modelo;

	/*
	 * Hilos para comunicarse con el cliente
	 */
	std::vector<HiloComunicacion*> hilosComunicacion;

	/*
	 * Libera los hilos que terminaron
	 */
	void vaciarHilos();

	/*
	 * Termina los hilos
	 */
	void terminarHilos();

};

#endif /* COMMON_HILOESCUCHA_H_ */
