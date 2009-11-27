
#ifndef COMMON_SALIDACOMPUERTA_H_
#define COMMON_SALIDACOMPUERTA_H_

#include "common_Compuerta.h"

class EntradaCompuerta;

class SalidaCompuerta {

public:

	SalidaCompuerta(int id);

	int calcularTiempoTransicion();

	bool simular();

	void reset();

	void setValorSalida(bool valor);

	void setTiempoTransicion(int valor);

	void setCompuerta(Compuerta* compuerta);

	void setSalida(EntradaCompuerta* salida);

	int getId();

	int getConexion();

private:

	int id;

	Compuerta* compuerta;
	EntradaCompuerta* salida;

	bool valor;
	bool validoValor;

	bool validoTiempo;
	int tiempoTransicion;

};

#endif /* COMMON_SALIDACOMPUERTA_H_ */
