
#ifndef COMMON_SERVIDOR_H_
#define COMMON_SERVIDOR_H_

#include <string>

/*
 * Clase Servidor.
 * Encapsula los datos de un servidor
 */

class Servidor {

public:

	/*
	 * Constructor
	 * host= host del servidor
	 * puerto= puerto del servidor
	 */
	Servidor(const std::string &host, int puerto);

	/*
	 * Retorno el host
	 */
	std::string getHost() const;

	/*
	 * Retorna el puerto
	 */
	int getPuerto() const;

private:

	std::string host;
	int puerto;

};

#endif /* COMMON_SERVIDOR_H_ */
