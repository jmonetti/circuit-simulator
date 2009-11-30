
#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "modelo/common_ModeloCliente.h"
#include <vector>
#include "modelo/simulacion/common_ResultadoSimulacion.h"
#include "modelo/simulacion/common_ResultadoTiempo.h"


class Cliente {

public:

	Cliente();

	virtual ~Cliente();

	void crearCircuitos();

	Resultado* simularCircuitosSeparados();
	Resultado* simularSumaDeUnBit();
	Resultado* simularSumaTresEntradas();
	Resultado* simularAlarmas();
	Resultado* simularTablero();
	Resultado* simularCircuitoNuevo();

	void guardarCircuitosSeparados();
	void guardarSumaDeUnBit();
	void guardarSumaTresEntradas();
	void guardarAlarmas();
	void guardarTablero();

	void recuperarCircuito(std::string &ruta);
	Resultado* simularActual();

private:

	ModeloCliente modelo;

	int idCircuitos[10];

	int crearCircuitosSeparados();
	int crearSumaDeUnBit();
	int crearSumaTresEntradas();
	int crearAlarmas();
	int crearTablero();

};

#endif /* CLIENTE_H_ */
