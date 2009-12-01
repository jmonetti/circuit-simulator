
#ifndef COMMON_SERVIDOR_H_
#define COMMON_SERVIDOR_H_

#include <string>

class Servidor {

public:

	Servidor(const std::string &host, int puerto);

	std::string getHost() const;

	int getPuerto() const;

private:

	std::string host;
	int puerto;

};

#endif /* COMMON_SERVIDOR_H_ */
