
#ifndef COMMON_MANAGERARCHIVOS_H_
#define COMMON_MANAGERARCHIVOS_H_

#include <string>
#include <sstream>
#include <stdio.h>

#include "../common/constantes.h"

using namespace std;

class ManagerArchivos {
public:

	static int contPedidos;

	static int contRespuestas;

	static std::string getNombrePedido();

	static std::string getNombreRespuesta();

	static void removerArchivo(std::string &archivo);
};

#endif /* COMMON_MANAGERARCHIVOS_H_ */
