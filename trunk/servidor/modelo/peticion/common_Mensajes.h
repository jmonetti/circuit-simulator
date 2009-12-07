
#ifndef COMMON_MENSAJES_H_
#define COMMON_MENSAJES_H_

#include "../persistencia/common_Persistencia.h"

class Circuito;

class Mensajes {
public:

	static DOMElement* GetSimular(DOMDocument* doc,std::string &nombreCircuito,int cantEntradas, bool* entradas);

	static DOMElement* GetTiempoSimulacion(DOMDocument* doc,std::string &nombreCircuito);

	static DOMElement* GetSimularResponse(DOMDocument* doc,int cantSalidas, bool* salidas);

	static DOMElement* GetTiempoSimulacionResponse(DOMDocument* doc,int cantSalidas, int* salidas);

	static DOMElement* PublicarCircuitoResponse(DOMDocument* doc);

	static DOMElement* GetListaCircuitosResponse(DOMDocument* doc, std::vector<Circuito*> circuitos);

};

#endif /* COMMON_MENSAJES_H_ */
