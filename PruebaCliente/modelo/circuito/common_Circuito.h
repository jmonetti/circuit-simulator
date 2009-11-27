/**************************   Clase Circuito **************************************/
/**************************      Grupo 8     **************************************/

#ifndef COMMON_CIRCUITO_H_
#define COMMON_CIRCUITO_H_

#include "compuertas/common_Compuerta.h"
#include "compuertas/common_Entrada.h"
#include "compuertas/common_Salida.h"
#include <string>
#include <vector>


class Circuito {

public:

	Circuito(int id,const std::string &nombre);

	virtual ~Circuito();

	bool* simular(bool* entradas);

	int* calcularTiempoTransicion();

	void agregarCompuerta(Compuerta* compuerta);

	void eliminarCompuerta(int idCompuerta);

	void agregarEntradaCompuerta(EntradaCompuerta* entrada);

	void agregarSalidaCompuerta(SalidaCompuerta* salida);

	unsigned int getCantidadEntradas() const;

	unsigned int getCantidadSalidas() const;

	int getContadorCompuertas() const;

	int getContadorEntradasCompuerta() const;

	int getContadorSalidasCompuerta() const;

	void conectar(int idSalida,int idEntrada);

	void desconectar(int idSalida,int idEntrada);

	int getId() const;

	std::string getNombre() const;

	void guardar(DOMDocument* doc, DOMNode* padre) const;

private:

	EntradaCompuerta* obtenerEntradaCompuerta(int idEntrada);
	SalidaCompuerta* obtenerSalidaCompuerta(int idSalida);

	void setearEntradas(bool* entradas);
	void reset();

	std::vector<Compuerta*> compuertas;
	std::vector<EntradaCompuerta*> entradasCompuerta;
	std::vector<SalidaCompuerta*> salidasCompuerta;
	std::vector<Entrada*> entradas;
	std::vector<Salida*> salidas;

	int id;
	std::string nombre;
	int contadorCompuertas;
	int contadorEntradasCompuertas;
	int contadorSalidasCompuertas;

};

#endif /* COMMON_CIRCUITO_H_ */
