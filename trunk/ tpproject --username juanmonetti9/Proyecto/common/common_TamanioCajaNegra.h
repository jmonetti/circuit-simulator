#ifndef COMMON_TAMANIOCAJANEGRA_H_
#define COMMON_TAMANIOCAJANEGRA_H_

/*
 * Clase que encapsula el tamanio de la caja negra.
 * Contiene la cantidad de entradas y salidas
 */

class TamanioCajaNegra {

public:

	/*
	 * Constructor.
	 */
	TamanioCajaNegra(int cantEntradas,int cantSalidas);

	/*
	 * Retorna la cantidad de entradas
	 */
	int getCantEntradas()const;

	/*
	 * Retorna la cantidad de salidas
	 */
	int getCantSalidas()const;

private:

	int cantEntradas;
	int cantSalidas;

};

#endif /* COMMON_TAMANIOCAJANEGRA_H_ */
