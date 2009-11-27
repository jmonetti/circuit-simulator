
#ifndef COMMON_SALIDA_H_
#define COMMON_SALIDA_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include <string>

class Salida: public Compuerta {

public:

	Salida(int id, EntradaCompuerta* entrada,Posicion posicion,SENTIDO sentido,const std::string &nombre);

	virtual ~Salida();

	void calcularTiempoTransicion();

	Salida* getSalida();

	void simular();

	bool getValor();

	int getTiempoTransicion();

	TIPO_COMPUERTA getTipo() const;

	void guardar(DOMDocument* doc, DOMNode* padre);


private:

	EntradaCompuerta* entrada;
	bool valor;
	int tiempoTransicion;
	std::string nombre;

};

#endif /* COMMON_SALIDA_H_ */
