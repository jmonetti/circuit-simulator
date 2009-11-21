
#ifndef COMMON_MODELOSERVIDOR_H_
#define COMMON_MODELOSERVIDOR_H_

#include <string>
#include "common_Persistencia.h"

class ModeloServidor {

public:

	ModeloServidor();

	virtual ~ModeloServidor();

	void guardar();

	void recuperar();

	bool* simular(const std::string &nombreCircuito, bool* entradas);

	int* calcularTiempoTransicion(const std::string &nombreCircuito);

private:

	Persistencia persistencia;

};

#endif /* COMMON_MODELOSERVIDOR_H_ */
