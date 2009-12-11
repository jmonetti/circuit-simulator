
#ifndef COMMON_MENSAJES_H_
#define COMMON_MENSAJES_H_

#include "../persistencia/common_Persistencia.h"

class Circuito;

class Mensajes {
public:

	static DOMElement* GetSimular(DOMDocument* doc,const std::string &nombreCircuito,int cantEntradas, bool* entradas);

	static DOMElement* GetTiempoSimulacion(DOMDocument* doc,const std::string &nombreCircuito, int cantEntradas, int* entradas);

	static DOMElement* GetSimularResponse(DOMDocument* doc,int cantSalidas, bool* salidas);

	static DOMElement* GetTiempoSimulacionResponse(DOMDocument* doc,int cantSalidas, int* salidas);

	static DOMElement* GetListaCircuitosResponse(DOMDocument* doc, std::vector<char*> circuitos);

	static DOMElement* GetCircuitoResponse(DOMDocument* doc, int cantEntradas, int cantSalidas);

};

#endif /* COMMON_MENSAJES_H_ */
