
#ifndef COMMON_CONEXIONEXCEPTION_H_
#define COMMON_CONEXIONEXCEPTION_H_

#include "common_Exception.h"

class ConexionException : public Exception{

public:

	ConexionException(const std::string &mensaje) : Exception(mensaje){

	};

	virtual ~ConexionException(){

	};


};

#endif /* COMMON_CONEXIONEXCEPTION_H_ */
