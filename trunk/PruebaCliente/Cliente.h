
#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "modelo/common_ModeloCliente.h"
#include <vector>
#include "modelo/common_ResultadoSimulacion.h"
#include "modelo/common_ResultadoTiempo.h"


class Cliente {

public:

	Cliente();

	virtual ~Cliente();

	void crearCircuitos();

	std::vector<ResultadoSimulacion*>* simularCircuitosSeparados();
	std::vector<ResultadoSimulacion*>* simularSumaDeUnBit();
	std::vector<ResultadoSimulacion*>* simularSumaTresEntradas();
	std::vector<ResultadoSimulacion*>* simularAlarmas();
	std::vector<ResultadoSimulacion*>* simularTablero();

	ResultadoTiempo* calcularTiempoCircuitosSeparados();
	ResultadoTiempo* calcularTiempoSumaDeUnBit();
	ResultadoTiempo* calcularTiempoSumaTresEntradas();
	ResultadoTiempo* calcularTiempoAlarmas();
	ResultadoTiempo* calcularTiempoTablero();

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
