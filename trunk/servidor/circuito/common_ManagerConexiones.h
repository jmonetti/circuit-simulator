
#ifndef COMMON_MANAGERCONEXIONES_H_
#define COMMON_MANAGERCONEXIONES_H_

#include "compuertas/common_EntradaCompuerta.h"
#include "compuertas/common_SalidaCompuerta.h"
#include "compuertas/common_Compuerta.h"
#include "../common/constantes.h"
#include "../common/common_Posicion.h"

class ManagerConexiones {

public:

	static bool conectar(EntradaCompuerta* entrada,SalidaCompuerta* salida);

	static void desconectar(Compuerta* compuerta);

private:

	static bool hayConexion(Posicion posicionEntrada,SENTIDO sentidoEntrada, Posicion posicionSalida,SENTIDO sentidoSalida);

	static void desconectar(EntradaCompuerta* entrada);

	static void desconectar(SalidaCompuerta* salida);

	static bool verificarConexionNorte(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida);

	static bool verificarConexionEste(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida);

	static bool verificarConexionOeste(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida);

	static bool verificarConexionSur(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida);
};

#endif /* COMMON_MANAGERCONEXIONES_H_ */
