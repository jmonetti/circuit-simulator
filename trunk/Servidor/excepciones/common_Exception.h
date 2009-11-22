
#ifndef COMMON_EXCEPTION_H_
#define COMMON_EXCEPTION_H_

#include <string>

class Exception {

public:

	Exception(const std::string &mensaje) : mensaje(mensaje){
	};

	virtual ~Exception() {};

	std::string getMensaje() const {

		return mensaje;

	};

private:

	std::string mensaje;

};

#endif /* COMMON_EXCEPTION_H_ */
