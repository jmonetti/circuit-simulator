
#include "common_Servidor.h"

Servidor::Servidor(const std::string &ipServidor) : ip(ipServidor) {


}

std::string Servidor::getIp() const{

	return this->ip;

}
