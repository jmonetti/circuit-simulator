/**************************   Clase Protocolo Cliente **************************************/
/**************************           Grupo 8         **************************************/

#ifndef CLASS_PROTOCOLOCLIENTE_H_
#define CLASS_PROTOCOLOCLIENTE_H_

#include <string>
#include "common_Socket.h"
#include "../modelo/peticion/common_Servidor.h"

class ProtocoloCliente {

public:

	void conectar(Servidor servidor);

	void desconectar();

	void recibirMensaje(std::string &mensaje);

	void enviarMensaje(const std::string &mensaje);

	void shutdown();

private:

	Socket socket;
	std::string mensajeSiguiente;
	static const unsigned int SIZE_RECIBIR = 10;

};

#endif
