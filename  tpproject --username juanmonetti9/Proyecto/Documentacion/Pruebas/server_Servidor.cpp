
#include "server_Servidor.h"


Servidor::Servidor(unsigned int puerto)
{
	this->puerto = puerto;
}

Servidor::~Servidor() {
}

void Servidor::bind(){
   try{
		this->server_socket.bind(this->puerto);
	}
   catch(std::runtime_error &e){
	   throw e;
	}
}

void Servidor::listen(unsigned int clientes){
	try{
		this->server_socket.listen(clientes);
	}
	catch(std::runtime_error &e){
	   throw e;
	}
}

int Servidor::iniciarConversacion()
{
	try{
		Socket *socketCliente;

		std::string Datos = "HOLA\n";

		std::string datosIN;

		socketCliente = this->server_socket.accept();

		if(socketCliente != NULL){

			protocolo = new Protocolo(socketCliente);

			while (true){

				this->protocolo->enviarMensaje(Datos);

				this->protocolo->recibirMensaje(datosIN);

				cout << datosIN;

				if(datosIN == "FIN\n"){
					this->protocolo->enviarMensaje(datosIN);
					delete protocolo;
					return 0;
				}

				Datos = this->in_mensaje();

				Datos.append("\n");
			}
		}
	}
	catch(std::runtime_error &e){
		delete protocolo;
	    throw e;
	}
	return 1;
}

std::string Servidor::in_mensaje(){

	std::string mensaje;

	char charAux=std::cin.get();

	while( (charAux != '\n') ){
		mensaje+=charAux;
		charAux=std::cin.get();
	}

	return mensaje;
}

void Servidor::terminar()
{
	this->server_socket.close();
}
