
#include "common_Servidor.h"

Servidor::Servidor(const std::string &host, int puerto) : host(host) {

	this->puerto= puerto;

}

std::string Servidor::getHost() const{

	return this->host;

}

int Servidor::getPuerto() const{

	return this->puerto;

}
