
#ifndef COMMON_POSICION_H_
#define COMMON_POSICION_H_

/*
 * Clase que encapsula la posicion del componente en la matriz.
 *
 * X= Columna
 * Y= Fila
 */

class Posicion {

public:

	/*
	 * Constructor. Minimo valor para cada coordenada es 1. Si se pasa 0, se setea
	 * la coordenada en 1.
	 */

	Posicion(unsigned int x= 1,unsigned int y= 1);

	/*
	 * Retorna el valor de la coordenada x
	 */
	unsigned int getX() const;

	/*
	 * Retorna el valor de la coordenada y
	 */
	unsigned int getY() const;

	/*
	 * Operador igual. Retorna true cuando ambas coordenadas son iguales
	 */
	bool operator==(const Posicion &posicion) const;

	/*
	 * Operador asignacion.
	 */
	Posicion& operator=(const Posicion &posicion);

private:

	//Coordenada columna
	unsigned int x;
	//Coordenada fila
	unsigned int y;

};

#endif /* COMMON_POSICION_H_ */
