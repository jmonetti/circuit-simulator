/**************************   Clase Protocolo **************************************/
/**************************       Grupo 8     **************************************/

#ifndef CLASS_PROTOCOLO_H_
#define CLASS_PROTOCOLO_H_

#include <string>
#include "common_Socket.h"

class Protocolo {

public:

	Protocolo(Socket* socket);

	int recibirMensaje(std::string &mensaje);

	int enviarMensaje(const std::string &mensaje);

private:

	Socket* socket;
	std::string mensajeSiguiente;
	static const unsigned int SIZE_RECIBIR = 5;

};

#endif
