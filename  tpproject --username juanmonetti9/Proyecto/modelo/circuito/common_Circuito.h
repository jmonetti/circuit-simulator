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

	void rotar(int idCompuerta,DIRECCION direccion);

	void mover(int idCompuerta,Posicion posicion);

	int agregarCompuerta(Compuerta* compuerta);

	void eliminarCompuerta(int idCompuerta);

	unsigned int getCantidadEntradas() const;

	unsigned int getCantidadSalidas() const;

	int getContadorCompuertas() const;

	int getContadorEntradasCompuerta() const;

	int getContadorSalidasCompuerta() const;

	std::vector<Entrada*>& getEntradas();

	std::vector<Salida*>& getSalidas();

	std::vector<Compuerta*>& getCompuertas();

	int getId() const;

	std::string getNombre() const;

	void guardar(DOMDocument* doc) const;

	DOMElement* obtenerCircuito(DOMDocument* doc) const;

private:

	void agregarEntradasCompuerta(Compuerta* compuerta);
	void agregarSalidasCompuerta(Compuerta* compuerta);


	Compuerta* obtenerCompuerta(int idCompuerta);

	void setearEntradas(bool* entradas);
	void reset();

	void verificarConexiones(Compuerta* compuerta);
	void establecerConexion(EntradaCompuerta* entrada);
	void establecerConexion(SalidaCompuerta* salida);

	void eliminarEntradasCompuerta(Compuerta* compuerta);
	void eliminarSalidasCompuerta(Compuerta* compuerta);
	void eliminarEntradaCompuerta(EntradaCompuerta* entrada);
	void eliminarSalidaCompuerta(SalidaCompuerta* salida);

	void eliminarEntrada(Entrada* entrada);
	void eliminarSalida(Salida* salida);

	std::vector<Compuerta*> compuertas;
	std::vector<EntradaCompuerta*> entradasCompuerta;
	std::vector<SalidaCompuerta*> salidasCompuerta;
	std::vector<Entrada*> entradas;
	std::vector<Salida*> salidas;

	int id;
	std::string nombre;
	int contadorCompuertas;

};

#endif /* COMMON_CIRCUITO_H_ */
