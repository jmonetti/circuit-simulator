
#ifndef COMMON_SERVIDOR_H_
#define COMMON_SERVIDOR_H_

#include <string>

class Servidor {

public:

	Servidor(const std::string &ipServidor);

	std::string getIp() const;

private:

	std::string ip;

};

#endif /* COMMON_SERVIDOR_H_ */
