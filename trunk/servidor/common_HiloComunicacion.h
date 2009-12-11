
#ifndef COMMON_HILOCOMUNICACION_H_
#define COMMON_HILOCOMUNICACION_H_

#include "thread/common_Thread.h"
#include "socket/common_ProtocoloServidor.h"
#include "modelo/common_ModeloServidor.h"

class Circuito;


class HiloComunicacion: public Thread {

public:

	/*
	 * Constructor
	 */
	HiloComunicacion(ModeloServidor *modeloServidor, ProtocoloServidor* protocolo, int &contPedidos);

	/*
	 * Destructor
	 */
	virtual ~HiloComunicacion();

	/*
	 * Termina el hilo
	 */
	void terminar();

	std::string recibirPedido(int &codigoError);

	void enviarRespuesta(const std::string &ruta, int &codigoError);



protected:

	virtual void* run();

private:

	int *contPedidos;

	ProtocoloServidor* protocolo;

	ModeloServidor* modelo;

};

#endif /* COMMON_HILOCOMUNICACION_H_ */
