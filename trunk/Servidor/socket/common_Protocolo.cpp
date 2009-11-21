/**************************   Clase Protocolo **************************************/
/**************************       Grupo 8     **************************************/

#include "common_Protocolo.h"
#include <iostream>
using namespace std;

Protocolo::Protocolo(Socket *socket) {

	this->socket->close();
	this->socket= socket;

}

Protocolo::~Protocolo() {

	delete socket;

}

void Protocolo::recibirMensaje(std::string &mensaje) {

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
	catch(std::runtime_error &e)
	{
		throw std::runtime_error("Error al intentar recibir mensaje");
	}

}

void Protocolo::enviarMensaje(const std::string &mensaje) {

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
	catch(std::runtime_error &e)
	{
		throw std::runtime_error("Error al intentar enviar mensaje");
	}


}

void Protocolo::shutdown() {

	socket->shutdown();

}
