
#ifndef COMMON_CIRCUITOEXCEPTION_H_
#define COMMON_CIRCUITOEXCEPTION_H_

#include "common_Exception.h"

class CircuitoException: public Exception {

public:

	CircuitoException(const std::string &mensaje) : Exception(mensaje) {

	};

	virtual ~CircuitoException(){

	};


};

#endif /* COMMON_CIRCUITOEXCEPTION_H_ */
