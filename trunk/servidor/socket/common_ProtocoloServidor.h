/**************************   Clase Protocolo Servidor **************************************/
/**************************          Grupo 8     	   **************************************/

#ifndef CLASS_PROTOCOLOSERVIDOR_H_
#define CLASS_PROTOCOLOSERVIDOR_H_

#include <string>
#include "common_Socket.h"
#include "../modelo/peticion/common_Servidor.h"

class ProtocoloServidor {

public:

	ProtocoloServidor(Socket* socket);

	virtual ~ProtocoloServidor();

	void desconectar();

	void recibirMensaje(std::string &mensaje);

	void enviarMensaje(const std::string &mensaje);

	void shutdown();

private:

	Socket* socket;
	std::string mensajeSiguiente;
	static const unsigned int SIZE_RECIBIR = 10;

};

#endif
