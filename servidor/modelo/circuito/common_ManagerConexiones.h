
#ifndef COMMON_MANAGERCONEXIONES_H_
#define COMMON_MANAGERCONEXIONES_H_

#include "compuertas/common_EntradaCompuerta.h"
#include "compuertas/common_SalidaCompuerta.h"
#include "compuertas/common_Compuerta.h"
#include "../../common/constantes.h"
#include "../../common/common_Posicion.h"
#include <vector>

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

};

#endif /* COMMON_MANAGERCONEXIONES_H_ */
