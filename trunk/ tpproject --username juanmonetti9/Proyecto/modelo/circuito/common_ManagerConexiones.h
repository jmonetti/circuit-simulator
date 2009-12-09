
#ifndef COMMON_MANAGERCONEXIONES_H_
#define COMMON_MANAGERCONEXIONES_H_

#include "compuertas/common_EntradaCompuerta.h"
#include "compuertas/common_SalidaCompuerta.h"
#include "compuertas/common_Compuerta.h"
#include "../../common/constantes.h"
#include "../../common/common_Posicion.h"
#include <vector>
#include "common_ConexionVertice.h"

/*
 * Clase ManagerConexiones
 *
 * Realiza las conexiones y desconexiones
 */

class ManagerConexiones {

public:

	/*
	 * Conecta,si puede, una EntradaCompuerta con una SalidaCompuerta
	 * entrada= EntradaCompuerta a conectar
	 * salida= SalidaCompuerta a conectar
	 * Retorna true si se pudo conectar
	 */
	static bool conectar(EntradaCompuerta* entrada,SalidaCompuerta* salida);

	/*
	 * Desconectar una compuerta
	 * compuerta= compuerta a desconectar
	 */
	static void desconectar(Compuerta* compuerta);

	/*
	 * Obtiene, si hay, conexion perpendicular
	 * entrada= EntradaCompuerta conectada
	 * salida= SalidaCompuerta conectada
	 * conexiones= vector donde se carga la conexion perpendicular
	 */
	static void obtenerConexionVertice(EntradaCompuerta* entrada, SalidaCompuerta* salida, std::vector<ConexionVertice>* conexiones);

private:

	/*
	 * Verifica si hay conexion segun la posicion y sentido de la entrada y salida
	 */
	static bool hayConexion(Posicion posicionEntrada,SENTIDO sentidoEntrada, Posicion posicionSalida,SENTIDO sentidoSalida);

	/*
	 * Desconecta una EntradaCompuerta
	 */
	static void desconectar(EntradaCompuerta* entrada);

	/*
	 * Desconecta una SalidaCompuerta
	 */
	static void desconectar(SalidaCompuerta* salida);

	static bool verificarConexionNorte(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida);

	static bool verificarConexionEste(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida);

	static bool verificarConexionOeste(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida);

	static bool verificarConexionSur(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida);

	static void obtenerConexionVerticeNorte(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida, std::vector<ConexionVertice>* conexiones);

	static void obtenerConexionVerticeEste(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida, std::vector<ConexionVertice>* conexiones);

	static void obtenerConexionVerticeOeste(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida, std::vector<ConexionVertice>* conexiones);

	static void obtenerConexionVerticeSur(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida, std::vector<ConexionVertice>* conexiones);

};

#endif /* COMMON_MANAGERCONEXIONES_H_ */
