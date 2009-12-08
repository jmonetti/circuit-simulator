
#ifndef COMMON_MENSAJES_H_
#define COMMON_MENSAJES_H_

#include "../persistencia/common_Persistencia.h"

class Circuito;

class Mensajes {
public:

	static DOMElement* GetSimular(DOMDocument* doc,std::string &nombreCircuito,int cantEntradas, bool* entradas);

	static DOMElement* GetTiempoSimulacion(DOMDocument* doc,std::string &nombreCircuito,int cantEntradas, int* entradas);

	static DOMElement* GetListaCircuitos(DOMDocument* doc);

	static DOMElement* GetCircuito(DOMDocument* doc, std::string &nombreCircuito);

};

#endif /* COMMON_MENSAJES_H_ */
