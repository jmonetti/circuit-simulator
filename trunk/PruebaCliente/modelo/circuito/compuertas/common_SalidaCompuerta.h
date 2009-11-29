
#ifndef COMMON_SALIDACOMPUERTA_H_
#define COMMON_SALIDACOMPUERTA_H_

#include "common_Compuerta.h"
#include "../../../common/common_Posicion.h"
#include <vector>
#include "../../../common/constantes.h"

class EntradaCompuerta;
class Compuerta;

class SalidaCompuerta {

public:

	SalidaCompuerta();

	int calcularTiempoTransicion();

	bool simular();

	void mover(Posicion posicion);

	void rotar(SENTIDO sentido);

	void conectar(EntradaCompuerta* salida);

	void desconectar(EntradaCompuerta* entrada= NULL);

	std::vector<EntradaCompuerta*>& getConexiones();

	void reset();

	void setValorSalida(bool valor);

	void setTiempoTransicion(int valor);

	void setCompuerta(Compuerta* compuerta);

	Posicion getPosicion() const;

	SENTIDO getSentido() const;

private:

	Posicion posicion;
	SENTIDO sentido;

	Compuerta* compuerta;
	std::vector<EntradaCompuerta*> salidas;

	bool valor;
	bool validoValor;

	bool validoTiempo;
	int tiempoTransicion;

};

#endif /* COMMON_SALIDACOMPUERTA_H_ */
