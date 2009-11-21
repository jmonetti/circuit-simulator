
#ifndef COMMON_PERSISTENCIA_H_
#define COMMON_PERSISTENCIA_H_

#include "../circuito/common_Circuito.h"
#include <string>

class Persistencia {

public:

	Persistencia();

	virtual ~Persistencia();

	void guardar(const Circuito &circuito);

	Circuito* recuperar(const std::string &nombreCircuito);



};

#endif /* COMMON_PERSISTENCIA_H_ */
