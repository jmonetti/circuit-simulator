/**************************   Clase Socket  ***********************************/
/**************************   Grupo 8       ***********************************/


#include "Socket.h"

/*----------------------------------------------------------------------------*/
Socket::Socket(){

	//creo un descriptor, si hubo problemas, lanza una excepcion
	this->fd = socket (AF_INET,SOCK_STREAM, 0);
	//si el fd es -1 lanzo una excepcion
	if(this->fd == -1){
		std::string mensaje_error = "Error Socket(): ";
		mensaje_error += strerror(errno);
		throw std::runtime_error(mensaje_error.c_str());
	}
	else{
		this->valido=true;
	}

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

void Socket::listen(unsigned int nro_Cliente){

	if( es_valido() ){

		int error=::listen(this->fd,nro_Cliente);
		//si la variable error en -1 lanzo una excepcion
		if(error==-1){
			std::string strError="Error Socket -Listen():";
			strError += strerror(errno);
			throw std::runtime_error(strError.c_str());
		}
	}
	else
		throw std::runtime_error("Error Socket -Listen(): Socket invalido");
}
/*----------------------------------------------------------------------------*/

void Socket::bind(unsigned short int puerto){

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
				throw std::runtime_error(mensaje_error.c_str());;
			}
		}
		else
			throw std::runtime_error("Error Socket -bind(): Socket invalido");

}
/*----------------------------------------------------------------------------*/

void Socket::connect(const std::string& host, unsigned int port){

	if(es_valido()){

		struct sockaddr_in servidor;

		servidor.sin_family = AF_INET;
		//pone la direccion
		servidor.sin_addr.s_addr = inet_addr(host.c_str());
		//pone el puerto
		servidor.sin_port = htons(port);
		//completa con 0
		bzero(&(servidor.sin_zero),8);

		//se conecta y recibe el error
		int error =::connect (this->fd, (struct sockaddr *)&servidor,sizeof(struct sockaddr));
		//si la variable error en -1 lanzo una excepcion
		if( error == -1){
			std::string strError = "Error Socket -connect(): ";
			strError += strerror(errno);
			throw std::runtime_error(strError.c_str());
		}
	}
	else
		throw std::runtime_error("Error Socket -connect(): Socket invalido");
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
			throw std::runtime_error(strError.c_str());
		}
	}
	else
		throw std::runtime_error("Error Socket -accept(): Socket Invalido");
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

int Socket::recive(char* stream,unsigned int size){

	if(es_valido() && size>0){

		unsigned int cant_recibidos =0;
		int aux_cant=0;

		do{
			//recibo un caracter
			aux_cant = ::recv(this->fd, stream + cant_recibidos,1, MSG_NOSIGNAL);
			//si devolvio -1 lanzo la excepcion
			if(aux_cant == -1 ){
				std::string strError = "Error Socket -recive() -valor de recv(-1):";
				strError += strerror(errno);
				throw std::runtime_error(strError.c_str());
			}
			//si devolvio 0 lanzo excepcion
			if(aux_cant == 0 ){
				throw std::runtime_error("Error Socket -recive(): Fichero cerrado");
			}

			cant_recibidos++;

		}while(cant_recibidos < size && (stream[cant_recibidos-1]!='\0'));

		//si el ultimo caracter recibido no es un fin de cadena lo remplazo por uno
		if(stream[cant_recibidos-1]!='\0'){
			stream[cant_recibidos-1]='\0';
		}

		return aux_cant;
	}
	else
		throw std::runtime_error("Error Socket -recive(): Socket invalido");


}

/*----------------------------------------------------------------------------*/

int Socket::send(const char* stream,unsigned int size){

	if(es_valido() && size>0){

		unsigned int cant_enviados=0;
		int cantidad_aux=0;

		do{
			//mando el mensaje
			cantidad_aux = ::send(this->fd, stream + cant_enviados,1, MSG_NOSIGNAL);

			//si devolvio -1 lanzo la excepcion
			if(cantidad_aux == -1){
				std::string strError = "Error en send: ";
				strError += strerror(errno);
				throw std::runtime_error(strError.c_str());
			}
			//si devolvio 0 lanzo excepcion
			if(cantidad_aux == 0 ){
				throw std::runtime_error("Error Socket - send(): Fichero cerrado");

			}
			cant_enviados++;


		}while(cant_enviados < size && (stream[cant_enviados-1]!='\0'));

		return cant_enviados;

	}
	else
		throw std::runtime_error("Error Socket -Send(): (Socket invalido) o (size<=0)");
}
/*----------------------------------------------------------------------------*/

void Socket::shutdown(){

	if(es_valido()){

		int error=::shutdown(fd,SHUT_RDWR);
		//si la variable error es -1 lanzo una excepcion
		if(error==-1){
			throw std::runtime_error("Error Socket -cancelar_socket() -valor recibido(-1)");
		}
	}
	else{

		throw std::runtime_error("Error Socket -cancelar_socket(): Socket invalido");
	}
}

/*----------------------------------------------------------------------------*/

//Se utiliza para que se redefina en caso de ser necesario al usar herencia
Socket::~Socket(){}

/*----------------------------------------------------------------------------*/
