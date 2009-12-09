
#ifndef COMMON_RESULTADOSIMULACION_H_
#define COMMON_RESULTADOSIMULACION_H_

/*
 * Clase ResultadoSimulacion
 * Encapsula el resultado de la simulacion
 */

class ResultadoSimulacion {

public:

	/*
	 * Constructor
	 * entradas= valores de entrada
	 * salidas= valores de salida
	 * cantEntradas= cantidad de entradas
	 * cantSalidas= cantidad de salidas
	 */
	ResultadoSimulacion(bool* entradas,bool* salidas, unsigned int cantEntradas,unsigned int cantSalidas);

	/*
	 * Destructor
	 */
	virtual ~ResultadoSimulacion();

	/*
	 * Retorna los valores de entrada
	 */
	bool* getEntradas();

	/*
	 * Retorna los valores de salida
	 */
	bool* getSalidas();

	/*
	 * Retorna la cantidad de entradas
	 */
	unsigned int getCantidadEntradas() const;

	/*
	 * Retorna la cantidad de salidas
	 */
	unsigned int getCantidadSalidas() const;

private:

	bool* entradas;
	bool* salidas;

	unsigned int cantEntradas;
	unsigned int cantSalidas;

};

#endif /* COMMON_RESULTADOSIMULACION_H_ */
