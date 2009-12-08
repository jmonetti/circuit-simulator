
#ifndef COMMON_MANAGERCONEXIONES_H_
#define COMMON_MANAGERCONEXIONES_H_

#include "compuertas/common_EntradaCompuerta.h"
#include "compuertas/common_SalidaCompuerta.h"
#include "compuertas/common_Compuerta.h"
#include "../../common/constantes.h"
#include "../../common/common_Posicion.h"
#include <vector>
#include "common_ConexionVertice.h"

class ManagerConexiones {

public:

	static bool conectar(EntradaCompuerta* entrada,SalidaCompuerta* salida);

	static void desconectar(Compuerta* compuerta);

	static void obtenerConexionVertice(EntradaCompuerta* entrada, SalidaCompuerta* salida, std::vector<ConexionVertice>* conexiones);

private:

	static bool hayConexion(Posicion posicionEntrada,SENTIDO sentidoEntrada, Posicion posicionSalida,SENTIDO sentidoSalida);

	static void desconectar(EntradaCompuerta* entrada);

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
