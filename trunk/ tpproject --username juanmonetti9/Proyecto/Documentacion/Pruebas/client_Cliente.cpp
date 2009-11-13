
#include "client_Cliente.h"

Cliente::Cliente(): protocolo(&client_socket){
}

Cliente::~Cliente() {
}

void Cliente::conectar(const std::string& host,unsigned int port){
	try{
		client_socket.connect(host,port);

	}
	catch(std::runtime_error &e)
	{
		client_socket.close();

		//TODO
		std::cout<<e.what()<<"\n";
		//fin TODO

		throw std::runtime_error("Constructor Cliente: Error al conectar");
	}

}

int Cliente::iniciarConversacion()
{
	std::string datosIN;

	try{

		while(true){

			std::string mensaje;

			this->protocolo.recibirMensaje(datosIN);

			cout <<datosIN;

			if(datosIN == "FIN\n"){
				return 0;
			}

			mensaje = this->in_mensaje();

			mensaje.append("\n");

			this->protocolo.enviarMensaje(mensaje);
		}
	}
	catch(std::runtime_error &e)
	{
		return 1;
	}

}

std::string Cliente::in_mensaje(){

	std::string mensaje;

	char charAux=std::cin.get();

	while( (charAux != '\n') ){
		mensaje+=charAux;
		charAux=std::cin.get();
	}

	return mensaje;
}

void Cliente::terminar()
{
	this->client_socket.close();
}


