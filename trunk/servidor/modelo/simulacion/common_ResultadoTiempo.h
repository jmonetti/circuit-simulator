
#ifndef COMMON_RESULTADOTIEMPO_H_
#define COMMON_RESULTADOTIEMPO_H_

class ResultadoTiempo {

public:

	ResultadoTiempo(int* tiempos,unsigned int cantidad);

	virtual ~ResultadoTiempo();

	int* getTiempos();

	unsigned int getCantidad() const;

private:

	unsigned int cantidad;
	int* tiempos;
};

#endif /* COMMON_RESULTADOTIEMPO_H_ */
