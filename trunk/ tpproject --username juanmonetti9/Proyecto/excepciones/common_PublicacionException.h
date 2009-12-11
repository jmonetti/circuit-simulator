#ifndef COMMON_PUBLICACIONEXCEPTION_H_
#define COMMON_PUBLICACIONEXCEPTION_H_

#include "common_Exception.h"

class PublicacionException: public Exception {

public:

	PublicacionException(const std::string &mensaje) : Exception(mensaje) {

	};

	virtual ~PublicacionException(){

	};


};


#endif /* COMMON_PUBLICACIONEXCEPTION_H_ */
