/**************************   Clase Circuito **************************************/
/**************************      Grupo 8     **************************************/

#ifndef COMMON_CIRCUITO_H_
#define COMMON_CIRCUITO_H_

#include "compuertas/common_Compuerta.h"
#include "compuertas/common_Entrada.h"
#include "compuertas/common_Salida.h"
#include <string>
#include <vector>

/*
 * Clase Circuito
 */

class Circuito {

public:

	/*
	 * Constructor
	 * id= id del circuito
	 * nombre= nombre del circuito
	 */
	Circuito(int id,const std::string &nombre);

	/*
	 * Destructor
	 */
	virtual ~Circuito();

	/*
	 * Simula el circuito
	 * entradas= los valores de las entradas
	 * Retorna los valores de las salidas
	 */
	bool* simular(bool* entradas);

	/*
	 * Calcula los tiempos de transicion para cada salida
	 * Retorna los tiempos de transicion para cada salida
	 */
	int* calcularTiempoTransicion();

	/*
	 * Rota una compuerta
	 * idCompuerta= id de la compuerta a rotar
	 * direccion= direccion hacia donde se va a rotar la compuerta
	 */
	void rotar(int idCompuerta,DIRECCION direccion);

	/*
	 * Mueve una compuerta
	 * idCompuerta= id de la compuerta a mover
	 * posicion= posicion a la que se va a mover la compuerta
	 */
	void mover(int idCompuerta,Posicion posicion);

	/*
	 * Agrega una compuerta
	 * compuerta= compuerta que se va a agregar
	 * Retorna el id de la compuerta
	 */
	int agregarCompuerta(Compuerta* compuerta);

	/*
	 * Elimina una compuerta
	 * idCompuerta= id de la compuerta a eliminar
	 */
	void eliminarCompuerta(int idCompuerta);

	/*
	 * Retorna la cantidad de entradas
	 */
	unsigned int getCantidadEntradas() const;

	/*
	 * Retorna la cantidad de salidas
	 */
	unsigned int getCantidadSalidas() const;

	/*
	 * Retorna el contador de compuertas
	 */
	int getContadorCompuertas() const;

	/*
	 * Retorna las entradas
	 */
	std::vector<Entrada*>& getEntradas();

	/*
	 * Retorna las salidas
	 */
	std::vector<Salida*>& getSalidas();

	/*
	 * Retorna las compuertas (incluya entradas y salidas)
	 */
	std::vector<Compuerta*>& getCompuertas();

	/*
	 * Retorna el id
	 */
	int getId() const;

	/*
	 * Retorna el nombre
	 */
	std::string getNombre() const;

	/*
	 * Guarda el circuito
	 */
	void guardar(DOMDocument* doc) const;

	/*
	 * Obtiene el nombre del circuito
	 */
	DOMElement* obtenerElemCircuito(DOMDocument* doc) const;

private:

	/*
	 * Agrega EntradaCompuerta de una compuerta
	 * compuerta= compuerta de las EntradaCompuerta
	 */
	void agregarEntradasCompuerta(Compuerta* compuerta);

	/*
	 * Agrega SalidaCompuerta de una compuerta
	 * compuerta= compuerta de las SalidaCompuerta
	 */
	void agregarSalidasCompuerta(Compuerta* compuerta);

	/*
	 * Obtiene una compuerta
	 * idCompuerta= id de la compuerta a obtener
	 * Retorna la compuerta obtenida
	 */
	Compuerta* obtenerCompuerta(int idCompuerta);

	/*
	 * Setea los valores a las entradas
	 * entradas= valores a setear
	 */
	void setearEntradas(bool* entradas);

	/*
	 * Resetea el circuito para simular
	 */
	void reset();

	/*
	 * Conecta una compuerta
	 * compuerta= compuerta a conectar
	 */
	void conectarCompuerta(Compuerta* compuerta);

	/*
	 * Establece la conexion para una EntradaCompuerta
	 * entrada= entrada a conectar
	 */
	void establecerConexion(EntradaCompuerta* entrada);

	/*
	 * Establece la conexion para una SalidaCompuerta
	 * salida= salida a conectar
	 */
	void establecerConexion(SalidaCompuerta* salida);

	/*
	 * Elimina las EntradaCompuerta de una compuerta
	 * compuerta= compuerta de las EntradaCompuerta
	 */
	void eliminarEntradasCompuerta(Compuerta* compuerta);
	/*
	 * Elimina las SalidaCompuerta de una compuerta
	 * compuerta= compuerta de las SalidaCompuerta
	 */
	void eliminarSalidasCompuerta(Compuerta* compuerta);
	/*
	 * Elimina una EntradaCompuerta
	 * entrada= EntradaCompuerta a eliminar
	 */
	void eliminarEntradaCompuerta(EntradaCompuerta* entrada);
	/*
	 * Elimina una SalidaCompuerta
	 * salida= SalidaCompuerta a eliminar
	 */
	void eliminarSalidaCompuerta(SalidaCompuerta* salida);

	/*
	 * Elimina una entrada
	 * entrada= entrada a eliminar
	 */
	void eliminarEntrada(Entrada* entrada);
	/*
	 * Elimina una salida
	 * salida= salida a eliminar
	 */
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
