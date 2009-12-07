
#ifndef COMMON_RESULTADOSIMULACION_H_
#define COMMON_RESULTADOSIMULACION_H_

class ResultadoSimulacion {

public:

	ResultadoSimulacion(bool* entradas,bool* salidas, unsigned int cantEntradas,unsigned int cantSalidas);

	virtual ~ResultadoSimulacion();


	bool* getEntradas();

	bool* getSalidas();

	unsigned int getCantidadEntradas() const;

	unsigned int getCantidadSalidas() const;

private:

	bool* entradas;
	bool* salidas;

	unsigned int cantEntradas;
	unsigned int cantSalidas;

};

#endif /* COMMON_RESULTADOSIMULACION_H_ */
