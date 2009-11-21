
#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "modelo/common_ModeloCliente.h"
#include <vector>
#include "modelo/common_Resultado.h"

class Cliente {

public:

	Cliente();

	virtual ~Cliente();

	void crearCircuitos();

	std::vector<Resultado*>* simularCircuitosSeparados();
	std::vector<Resultado*>* simularSumaDeUnBit();
	std::vector<Resultado*>* simularSumaTresEntradas();
	std::vector<Resultado*>* simularAlarmas();
	std::vector<Resultado*>* simularTablero();

	int* calcularTiempoCircuitosSeparados();
	int* calcularTiempoSumaDeUnBit();
	int* calcularTiempoSumaTresEntradas();
	int* calcularTiempoAlarmas();
	int* calcularTablero();

private:

	ModeloCliente modelo;

	int idCircuitos[5];

	int crearCircuitosSeparados();
	int crearSumaDeUnBit();
	int crearSumaTresEntradas();
	int crearAlarmas();
	int crearTablero();

};

#endif /* CLIENTE_H_ */
