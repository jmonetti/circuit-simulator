/**************************   Clase Circuito **************************************/
/**************************      Grupo 8     **************************************/

#ifndef COMMON_CIRCUITO_H_
#define COMMON_CIRCUITO_H_

#include "common_Compuerta.h"
#include "common_Entrada.h"
#include "common_Salida.h"
#include <vector>

class Circuito {

public:

	Circuito();

	virtual ~Circuito();

	void simular(bool* entradas);

	void calcularTiempoTransicion();

	void agregarCompuerta(Compuerta* compuerta);

	void agregarEntradaCompuerta(EntradaCompuerta* entrada);

	void agregarSalidaCompuerta(SalidaCompuerta* salida);

	int getContadorCompuertas();

	int getContadorEntradasCompuerta();

	int getContadorSalidasCompuerta();

private:

	void setearEntradas(bool* entradas);
	void reset();

	std::vector<Compuerta*> compuertas;
	std::vector<EntradaCompuerta*> entradasCompuerta;
	std::vector<SalidaCompuerta*> salidasCompuerta;
	std::vector<Entrada*> entradas;
	std::vector<Salida*> salidas;

	int contadorCompuertas;
	int contadorEntradasCompuertas;
	int contadorSalidasCompuertas;

};

#endif /* COMMON_CIRCUITO_H_ */
