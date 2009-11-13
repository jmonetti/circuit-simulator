
#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <stdlib.h>
using namespace std;
#include "../../socket/common_Protocolo.h"
#include "../../socket/common_Socket.h"

class Cliente {
private:

	Socket client_socket;

	unsigned int port;

	Protocolo protocolo;

public:

	Cliente();

	virtual ~Cliente();

	void conectar(const std::string& host, unsigned int port);

	int iniciarConversacion();

	/*
	 * Carga un mensaje desde cin. Devuelve el mensaje.
	 */
	std::string in_mensaje();

	/*
	 * Termina la conexion del socket.
	 */
	void terminar();

};

#endif /* CLIENTE_H_ */
