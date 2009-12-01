
#ifndef FACTORYPARSER_H_
#define FACTORYPARSER_H_

#include "compuertas/common_Compuerta.h"
#include "common_Circuito.h"
#include "../../common/constantes.h"
#include "../../common/common_Posicion.h"
#include <string>

class FactoryParser {
public:

	static void crearCompuerta(TIPO_COMPUERTA tipo, Circuito &circuito, Posicion posicion,SENTIDO sentido,int idCompuerta);

	static void crearEntrada(Circuito &circuito,int idCompuerta,Posicion posicion, const std::string &nombre, SENTIDO sentido);

	static void crearSalida(Circuito &circuito,int idCompuerta, Posicion posicion, const std::string &nombre, SENTIDO sentido);

private:

	static void crearAND(Circuito &circuito,int idCompuerta,Posicion posicion,SENTIDO sentido);
	static void crearOR(Circuito &circuito,int idCompuerta,Posicion posicion,SENTIDO sentido);
	static void crearNOT(Circuito &circuito,int idCompuerta,Posicion posicion,SENTIDO sentido);
	static void crearXOR(Circuito &circuito,int idCompuerta,Posicion posicion,SENTIDO sentido);
	static void crearPISTA(Circuito &circuito,int idCompuerta,Posicion posicion,SENTIDO sentido);
	static void crearENTRADA(Circuito &circuito,int idCompuerta,Posicion posicion,SENTIDO sentido,const std::string &nombre);
	static void crearSALIDA(Circuito &circuito,int idCompuerta,Posicion posicion,SENTIDO sentido,const std::string &nombre);
};


#endif /* FACTORYPARSER_H_ */
