/**************************   Clase Circuito **************************************/
/**************************      Grupo 8     **************************************/

#ifndef COMMON_CIRCUITO_H_
#define COMMON_CIRCUITO_H_

#include "compuertas/common_Compuerta.h"
#include "compuertas/common_Entrada.h"
#include "compuertas/common_Salida.h"
#include <vector>

#include <xercesc/dom/DOMDocument.hpp>

using namespace std;

class Circuito {

public:

	Circuito(int id);

	virtual ~Circuito();

	bool* simular(bool* entradas);

	int* calcularTiempoTransicion();

	void agregarCompuerta(Compuerta* compuerta);

	void agregarEntradaCompuerta(EntradaCompuerta* entrada);

	void agregarSalidaCompuerta(SalidaCompuerta* salida);

	unsigned int getCantidadEntradas() const;

	unsigned int getCantidadSalidas() const;

	int getContadorCompuertas();

	int getContadorEntradasCompuerta();

	int getContadorSalidasCompuerta();

	void conectar(int idSalida,int idEntrada);

	int getId() const;

	void guardar(DOMDocument* doc, DOMNode* padre) const;

private:

	void setearEntradas(bool* entradas);
	void reset();

	std::vector<Compuerta*> compuertas;
	std::vector<EntradaCompuerta*> entradasCompuerta;
	std::vector<SalidaCompuerta*> salidasCompuerta;
	std::vector<Entrada*> entradas;
	std::vector<Salida*> salidas;

	int id;
	int contadorCompuertas;
	int contadorEntradasCompuertas;
	int contadorSalidasCompuertas;

};

#endif /* COMMON_CIRCUITO_H_ */
