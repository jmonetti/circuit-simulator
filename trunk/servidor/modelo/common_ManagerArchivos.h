
#ifndef COMMON_MANAGERARCHIVOS_H_
#define COMMON_MANAGERARCHIVOS_H_

#include <string>
#include <sstream>
#include <stdio.h>

#include "../common/constantes.h"
#include "../thread/common_Mutex.h"

class ManagerArchivos {

public:

	static ManagerArchivos* crearInstancia();

	static ManagerArchivos* getInstancia();

	virtual ~ManagerArchivos();

	std::string getNombrePedido();

	std::string getNombreRespuesta();

	void removerArchivo(std::string &archivo);

private:

	static ManagerArchivos* instancia;

	ManagerArchivos();

	int contPedidos;

	int contRespuestas;

	Mutex mutexPedidos;

	Mutex mutexRespuestas;

};

#endif /* COMMON_MANAGERARCHIVOS_H_ */
