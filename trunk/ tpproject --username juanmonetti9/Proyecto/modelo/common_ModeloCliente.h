
#ifndef COMMON_MODELOCLIENTE_H_
#define COMMON_MODELOCLIENTE_H_

#include <vector>
#include <string>

#include "circuito/common_Circuito.h"
#include "publicacion/common_Servidor.h"
#include "persistencia/common_Persistencia.h"
#include "publicacion/common_Publicacion.h"
#include "simulacion/common_Simulador.h"
#include "../common/constantes.h"
#include "../common/common_Posicion.h"
#include "../common/common_TamanioCajaNegra.h"
#include "simulacion/common_Resultado.h"
#include "circuito/common_ConexionVertice.h"

class ModeloCliente {

public:

	/*
	 * Constructor
	 */
	ModeloCliente();

	/*
	 * Destructor
	 */
	virtual ~ModeloCliente();

	/*
	 * Crea un circuito nuevo.
	 * nombre: nombre del circuito
	 * Retorna el id.
	 */

	int crearNuevo(const std::string &nombre);

	/*
	 * Cambia el circuito actual
	 * idCircuito= id del circuito
	 */
	void cambiarCircuitoActual(int idCircuito);

	/*
	 * Elimina el circuito actual
	 */
	void eliminar();

	/*
	 * Agrega una compuerta al circuito actual
	 * tipo= Tipo de la compuerta
	 * posicion= posicion de la compuerta en la matriz
	 * sentido= sentido de la compuerta
	 * Retorna el id de la compuerta
	 */
	int agregarCompuerta(TIPO_COMPUERTA tipo,Posicion posicion,SENTIDO sentido);

	/*
	 * Agrega una entrada al circuito actual
	 * posicion= posicion de la entrada en la matriz
	 * nombre= nombre de la entrada
	 * sentido= sentido de la entrada
	 * Retorna el id de la entrada
	 */
	int agregarEntrada(Posicion posicion,const std::string &nombre, SENTIDO sentido);

	/*
	 * Agrega una salida al circuito actual
	 * posicion= posicion de la salida en la matriz
	 * nombre= nombre de la salida
	 * sentido= sentido de la salida
	 * Retorna el id de la salida
	 */
	int agregarSalida(Posicion posicion,const std::string &nombre, SENTIDO sentido);

	/*
	 * Agrega una caja negra al circuito actual
	 * posicion= posicion de la caja negra en la matriz
	 * nombre= nombre del circuito
	 * sentido= sentido de la caja negra
	 * servidor= servidor donde se encuentra el circuito
	 * tamanio= tamanio de la caja negra
	 * Retorna el id de la caja negra
	 */
	int agregarCajaNegra(Posicion posicion,const std::string &nombre, SENTIDO sentido,Servidor servidor, TamanioCajaNegra tamanio);

	/*
	 * Elimina una compuerta del circuito actual
	 * idCompuerta= id de la compuerta a eliminar
	 */
	void eliminarCompuerta(int idCompuerta);

	/*
	 * Simula el circuito actual
	 * Retorna el resultado de la simulacion
	 */
	Resultado* simular();

	/*
	 * Rota una compuerta del circuito actual
	 * idCompuerta= id de la compuerta a rotar
	 * direccion= direccion hacia donde se va a rotar la compuerta
	 */
	void rotar(int idCompuerta,DIRECCION direccion);

	/*
	 * Mueve una compuerta del circuito actual
	 * idCompuerta= id de la compuerta a mover
	 * posicion= posicion a la que se va a mover la compuerta
	 */
	void mover(int idCompuerta,Posicion posicion);

	/*
	 * Guarda el circuito actual
	 */
	void guardar();

	/*
	 * Obtiene los circuitos guardados
	 * Retorna los nombres de los circuitos guardados
	 */
	std::vector<char*>* obtenerCircuitosGuardados();

	/*
	 * Obtiene los circuitos del servidor
	 * servidor= servidor que contiene los circuitos a obtener
	 * circuitos= vector donde se cargan los nombres de los circuitos del servidor
	 */
	void obtenerCircuitosServidor(Servidor servidor, std::vector<char*>* circuitos);

	/*
	 * Recupera un circuito guardado
	 * nombreCircuito= nombre del circuito a recuperar
	 * Retorna el circuito recuperado
	 */
	Circuito* recuperar(const std::string &nombreCircuito);

	/*
	 * Envia un circuito (debe estar guardado) a un servidor
	 * nombreCircuito= nombre del circuito a enviar
	 * servidor= servidor al cual se le envia el circuito
	 */
	void enviar(const std::string &nombreCircuito,Servidor servidor);

	/*
	 * Recibe un circuito de un servidor
	 * nombreCircuito= nombre del circuito a recibir
	 * servidor= servidor desde el cual se recibe el circuito
	 * Retorna el tamanio del circuito
	 */
	TamanioCajaNegra recibir(const std::string &nombreCircuito,Servidor servidor);

	/*
	 * Retorna el id del proximo circuito a agregar
	 */
	int getId();

	/*
	 * Retorna true si hay circuito actual
	 */
	bool hayCircuito();

	/*
	 * Obtiene las conexiones perpendiculares del circuito actual
	 * conexiones= vector donde se cargan las conexiones perpendiculares
	 */
	void getConexionVertice(std::vector<ConexionVertice>* conexiones);

	/*
	 * Retorna las compuertas del circuito actual
	 */
	std::vector<Compuerta*>& getCompuertas();



private:

	// Vector de circuitos
	std::vector<Circuito*> circuitos;

	// Circuito actual
	Circuito* circuitoActual;

	Persistencia persistencia;
	Publicacion publicacion;
	Simulador simulador;

	//contador para el id de los circuitos
	int contadorId;

	/*
	 * Obtiene un circuito del vector de circuitos
	 * idCircuito= id del circuito a obtener
	 * Retorna el circuito obtenido
	 */
	Circuito* obtenerCircuito(int idCircuito);



};

#endif /* COMMON_MODELOCLIENTE_H_ */
