
#ifndef SERVIDOR_H_
#define SERVIDOR_H_

#include <stdlib.h>
using namespace std;
#include "../../socket/common_Protocolo.h"
#include "../../socket/common_Socket.h"

class Servidor {
private:

	Socket server_socket;

	unsigned int puerto;

	Protocolo* protocolo;

public:

	Servidor(unsigned int puerto);

	virtual ~Servidor();

	void bind();

	void listen(unsigned int clientes);

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

#endif /* SERVIDOR_H_ */
