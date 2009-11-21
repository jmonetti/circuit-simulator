
#ifndef COMMON_RESULTADO_H_
#define COMMON_RESULTADO_H_

class Resultado {

public:

	Resultado(bool* entradas,bool* salidas, unsigned int cantEntradas,unsigned int cantSalidas);

	virtual ~Resultado();


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

#endif /* COMMON_RESULTADO_H_ */
