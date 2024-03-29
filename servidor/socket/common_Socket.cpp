/**************************   Clase Socket  ***********************************/
/**************************   Grupo 8       ***********************************/


#include "common_Socket.h"
#include "../excepciones/common_SocketException.h"
#include <iostream>
/*----------------------------------------------------------------------------*/
Socket::Socket(){

	this->valido=false;

}
/*----------------------------------------------------------------------------*/

int Socket::get_fd()const{

	return this->fd;
}
/*----------------------------------------------------------------------------*/

Socket::Socket(int fileD){

	this->valido=true;
	this->fd=fileD;
}
/*----------------------------------------------------------------------------*/

Socket::Socket(const Socket& s){}

/*----------------------------------------------------------------------------*/

bool Socket::es_valido(){

	return this->valido;
}
/*----------------------------------------------------------------------------*/
void Socket::listen(unsigned short port, int backlog) {
	try{
		if (!es_valido()) {

			fd=::socket(AF_INET,SOCK_STREAM,0);

			valido= true;

			bind(port);

			int error = ::listen(fd,backlog);

			if(error==-1){
				valido = false;
				::close(fd);
				std::string strError="Error Socket -Listen():";
				strError += strerror(errno);
				throw SocketException(strError);
			}

		}
	}
	catch(SocketException &e){
		valido = false;
		::close(fd);
		throw SocketException("Error Socket - listen().");

	}

}

/*----------------------------------------------------------------------------*/

void Socket::bind(unsigned short puerto){

	if(es_valido()){

			struct sockaddr_in mi_socket;

			mi_socket.sin_family = AF_INET;
			//pone la direccion
			mi_socket.sin_addr.s_addr = INADDR_ANY;
			//pone el puerto
			mi_socket.sin_port = htons(puerto);
			//completa con 0
			bzero(&(mi_socket.sin_zero),8);

			//se conecta y recibe el error
			int error = ::bind (this->fd, (struct sockaddr *)&mi_socket, sizeof(struct sockaddr));
			//si la variable error en -1 lanzo una excepcion
			if( error == -1){

				std::string mensaje_error = "Error Socket -bind(): ";
				mensaje_error += strerror(errno);
				throw SocketException(mensaje_error.c_str());;
			}
		}
		else
			throw SocketException("Error Socket -bind(): Socket invalido");

}
/*----------------------------------------------------------------------------*/

void Socket::connect(const std::string& host, unsigned int port){

	if(!es_valido()){

		fd=::socket(AF_INET,SOCK_STREAM,0);

		valido = true;

		struct hostent *he;

		if (!(he= gethostbyname(host.c_str()))) {
			valido =false;
			::close(fd);
			throw SocketException ("Error Socket- connect() - gethostbyname().");

		}

		struct sockaddr_in servidor;

		servidor.sin_family = AF_INET;
		//pone la direccion
		servidor.sin_addr = *((struct in_addr *)he->h_addr);
		//pone el puerto
		servidor.sin_port = htons(port);
		//completa con 0
		bzero(&(servidor.sin_zero),8);

		//se conecta y recibe el error
		int error =::connect (this->fd, (struct sockaddr *)&servidor,sizeof(struct sockaddr));
		//si la variable error en -1 lanzo una excepcion
		if( error == -1){
			valido = false;
			std::string strError = "Error Socket -connect(): ";
			strError += strerror(errno);
			throw SocketException(strError.c_str());
		}
	}
	else{
		valido = false;
		throw SocketException("Error Socket -connect(): Socket invalido");
	}

}
/*----------------------------------------------------------------------------*/

Socket* Socket::accept(){

	struct sockaddr cliente;
	socklen_t long_cliente = sizeof(struct sockaddr);

	if(es_valido()){

		int descrip=::accept(this->fd,&cliente,&long_cliente);

		if(descrip!=-1){
			Socket* nSocket= new Socket(descrip);
			return(nSocket);
		}
		else{
			std::string strError="Error Socket -accept():";
			strError += strerror(errno);
			throw SocketException(strError.c_str());
		}
	}
	else
		throw SocketException("Error Socket -accept(): Socket Invalido");
}
/*----------------------------------------------------------------------------*/

void Socket::close(){

	if(es_valido()){

		::close(this->fd);
		this->fd = -1;
		this->valido=false;
	}

}
/*----------------------------------------------------------------------------*/

int Socket::receive(char* stream,unsigned int size){

	if(es_valido() && size>0){

		//recibo un caracter
		int aux_cant = ::recv(this->fd, stream, size, MSG_NOSIGNAL);

		//si devolvio -1 lanzo la excepcion
		if(aux_cant == -1 ){
			std::string strError = "Error Socket -recive() -valor de recv(-1):";
			strError += strerror(errno);
			throw SocketException(strError.c_str());
		}

		//si devolvio 0 lanzo excepcion
		if(aux_cant == 0 ){
			throw SocketException("Error Socket -recive(): Fichero cerrado");
		}

		return aux_cant;

	}
	else
		throw SocketException("Error Socket -recive(): Socket invalido");


}

/*----------------------------------------------------------------------------*/

int Socket::send(const char* stream,unsigned int size){

	if(es_valido() && size>0){

		//mando el mensaje
		int cantidad_aux = ::send(this->fd, stream, size, MSG_NOSIGNAL);

		//si devolvio -1 lanzo la excepcion
		if(cantidad_aux == -1){
			std::string strError = "Error en send: ";
			strError += strerror(errno);
			throw SocketException(strError.c_str());
		}

		//si devolvio 0 lanzo excepcion
		if(cantidad_aux == 0 ){
			throw SocketException("Error Socket - send(): Fichero cerrado");

		}

		return cantidad_aux;
	}
	else
		throw SocketException("Error Socket -Send(): (Socket invalido) o (size<=0)");
}
/*----------------------------------------------------------------------------*/

void Socket::shutdown(){

	if(es_valido()){

		int error=::shutdown(fd,SHUT_RDWR);
		//si la variable error es -1 lanzo una excepcion
		if(error==-1){
			std::cout<<"errorrr"<<std::endl;
			throw SocketException("Error Socket -cancelar_socket() -valor recibido(-1)");
		}
	}
	else{

		std::cout<<"acacaca"<<std::endl;
		throw SocketException("Error Socket -cancelar_socket(): Socket invalido");
	}
}

/*----------------------------------------------------------------------------*/

//Se utiliza para que se redefina en caso de ser necesario al usar herencia
Socket::~Socket(){}

/*----------------------------------------------------------------------------*/
