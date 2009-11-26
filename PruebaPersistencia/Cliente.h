
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

	std::vector<Resultado*>* simularCircuitoBasico();

	std::vector<Resultado*>* simularCircuitoNOT();

	std::vector<Resultado*>* simularCircuitoAND();

	std::vector<Resultado*>* simularSumaDeUnBit();

	std::vector<Resultado*>* simularCircuitosSeparados();

	std::vector<Resultado*>* simularSumaTresEntradas();

	int* calcularTiempoCircuitoBasico();

	void guardarCircuitoBasico(std::string &ruta);

	void guardarCircuitoNOT(std::string &ruta);

	void guardarCircuitoAND(std::string &ruta);

	void guardarSumaDeUnBit(std::string &ruta);

	void guardarCircuitosSeparados(std::string &ruta);

	void guardarSumaTresEntradas(std::string &ruta);

	void recuperarCircuito(std::string &ruta);
;

private:

	ModeloCliente modelo;

	int idCircuitos[6];

	int crearCircuitoBasico();

	int crearCircuitoNOT();

	int crearCircuitoAND();

	int crearSumaDeUnBit();

	int crearCircuitosSeparados();

	int crearSumaTresEntradas();

};

#endif /* CLIENTE_H_ */
