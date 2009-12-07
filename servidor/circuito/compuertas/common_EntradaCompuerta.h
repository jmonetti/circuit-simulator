
#ifndef COMMON_ENTRADACOMPUERTA_H_
#define COMMON_ENTRADACOMPUERTA_H_

#include "common_Compuerta.h"
#include "../../common/common_Posicion.h"
#include "../../common/constantes.h"

class SalidaCompuerta;

class EntradaCompuerta {

public:

	EntradaCompuerta();

	int calcularTiempoTransicion();

	bool simular();

	void mover(Posicion posicion);

	void rotar(SENTIDO sentido);

	void conectar(SalidaCompuerta* salida);

	void desconectar();

	SalidaCompuerta* getConexion();

	Posicion getPosicion() const;

	SENTIDO getSentido() const;

private:

	Posicion posicion;
	SENTIDO sentido;
	SalidaCompuerta* entrada;

};

#endif /* COMMON_ENTRADACOMPUERTA_H_ */
