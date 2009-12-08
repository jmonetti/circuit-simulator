/**************************   Clase Protocolo **************************************/
/**************************       Grupo 8     **************************************/

#ifndef CLASS_PROTOCOLO_H_
#define CLASS_PROTOCOLO_H_

#include <string>
#include "common_Socket.h"
#include "../modelo/publicacion/common_Servidor.h"

class Protocolo {

public:

	Protocolo();

	void conectar(Servidor servidor);

	void desconectar();

	virtual ~Protocolo();

	void recibirMensaje(std::string &mensaje);

	void enviarMensaje(const std::string &mensaje);

	void shutdown();

private:

	Socket socket;
	std::string mensajeSiguiente;
	static const unsigned int SIZE_RECIBIR = 10;

};

#endif
