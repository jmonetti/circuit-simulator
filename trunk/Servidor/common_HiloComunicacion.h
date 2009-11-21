
#ifndef COMMON_HILOCOMUNICACION_H_
#define COMMON_HILOCOMUNICACION_H_

#include "thread/common_Thread.h"
#include "socket/common_Protocolo.h"

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


protected:

	virtual void* run();

private:

	Protocolo* protocolo;

};

#endif /* COMMON_HILOCOMUNICACION_H_ */
