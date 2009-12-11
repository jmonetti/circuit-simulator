/**************************   Clase Protocolo **************************************/
/**************************       Grupo 8     **************************************/

#include "common_ProtocoloServidor.h"
#include <iostream>
#include "../excepciones/common_SocketException.h"
using namespace std;

ProtocoloServidor::ProtocoloServidor(Socket *socket) {

	this->socket= socket;

}

ProtocoloServidor::~ProtocoloServidor() {

	if (socket) {

		delete socket;

	}

}

void ProtocoloServidor::desconectar() {

	socket->close();

}

void ProtocoloServidor::recibirMensaje(std::string &mensaje) {

	char stream[SIZE_RECIBIR];

	try{
		while (true) {

			std::string::size_type index = this->mensajeSiguiente.find_first_of('\n');

			if ( index != std::string::npos ) {

				mensaje.assign(this->mensajeSiguiente,0,index+1);

				this->mensajeSiguiente= mensajeSiguiente.erase(0,index+1);

				return;

			}

			int aux= 0;

			aux= this->socket->receive(stream,SIZE_RECIBIR);

			this->mensajeSiguiente.append(stream,aux);

		}
	}
	catch(SocketException &e)
	{
		throw SocketException("Error al intentar recibir mensaje");
	}

}

void ProtocoloServidor::enviarMensaje(const std::string &mensaje) {

	std::string::size_type size= mensaje.size();

	const char* stream= mensaje.c_str();

	//Cantidad de datos escritos
	unsigned cantidadEscrito= 0;
	//Valor devuelto por enviar
	int aux=0;
	try{
		while (cantidadEscrito < size) {

			aux= this->socket->send(stream + cantidadEscrito, size - cantidadEscrito);
			cantidadEscrito+= aux;

		}
	}
	catch(SocketException &e)
	{
		throw SocketException("Error al intentar enviar mensaje");
	}


}

void ProtocoloServidor::shutdown() {

	socket->shutdown();

}
