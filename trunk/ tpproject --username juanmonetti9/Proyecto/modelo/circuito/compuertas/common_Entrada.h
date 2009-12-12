
#ifndef COMMON_ENTRADA_H_
#define COMMON_ENTRADA_H_


#include "common_SalidaCompuerta.h"
#include <string>

class Compuerta;

class Entrada: public Compuerta {

public:

	Entrada(int id,SalidaCompuerta* salida, Posicion posicion, SENTIDO sentido, const std::string &nombre);

	virtual ~Entrada();

	Entrada* getEntrada();

	void setValorEntrada(bool valor);

	bool getValorEntrada() const;

	std::string getNombre() const;

	TIPO_COMPUERTA getTipo() const;

	EntradaCompuerta** getEntradas();

	SalidaCompuerta** getSalidas();

	int getCantidadEntradas();

	int getCantidadSalidas();

	void guardar(DOMDocument* doc, DOMNode* padre);

protected:

	void actualizarEntradas();
	void actualizarSalidas();

	void actuarSimular(bool* valores);
	void actuarTiempo(int* tiempos);

private:

	SalidaCompuerta* salida;
	bool valor;
	std::string nombre;

};

#endif /* COMMON_ENTRADA_H_ */
