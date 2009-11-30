
#ifndef COMMON_SOCKETEXCEPTION_H_
#define COMMON_SOCKETEXCEPTION_H_

#include "common_Exception.h"

class SocketException : public Exception{

public:

	SocketException(const std::string &mensaje) : Exception(mensaje) {

	};

	virtual ~SocketException() {

	};

};

#endif /* COMMON_SOCKETEXCEPTION_H_ */
