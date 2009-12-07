
#ifndef COMMON_HILOCOMUNICACION_H_
#define COMMON_HILOCOMUNICACION_H_

#include "thread/common_Thread.h"
#include "socket/common_Protocolo.h"
#include "modelo/common_ModeloServidor.h"

class Circuito;



class HiloComunicacion: public Thread {

public:

	/*
	 * Constructor
	 */
	HiloComunicacion(Protocolo* protocolo);

	/*
	 * Destructor
	 */
	virtual ~HiloComunicacion();

	/*
	 * Termina el hilo
	 */
	void terminar();

	std::string recibirPedido();

	void responder(std::string &respuesta);





protected:

	virtual void* run();

private:

	Protocolo* protocolo;

	ModeloServidor modelo;

};

#endif /* COMMON_HILOCOMUNICACION_H_ */
