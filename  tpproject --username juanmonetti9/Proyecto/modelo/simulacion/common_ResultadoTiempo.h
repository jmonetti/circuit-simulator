
#ifndef COMMON_RESULTADOTIEMPO_H_
#define COMMON_RESULTADOTIEMPO_H_

/*
 * Clase ResultadoTiempo
 * Encapsula el resultado de los tiempos
 */

class ResultadoTiempo {

public:

	/*
	 * Constructor
	 * tiempos= tiempos calculados
	 * cantidad= cantidad de tiempos
	 */
	ResultadoTiempo(int* tiempos,unsigned int cantidad);

	/*
	 * Destructor
	 */
	virtual ~ResultadoTiempo();

	/*
	 * Retorna los tiempos
	 */
	int* getTiempos();

	/*
	 * Retorna la cantidad de tiempos
	 */
	unsigned int getCantidad() const;

private:

	unsigned int cantidad;
	int* tiempos;
};

#endif /* COMMON_RESULTADOTIEMPO_H_ */
