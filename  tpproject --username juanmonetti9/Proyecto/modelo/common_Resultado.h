
#ifndef COMMON_RESULTADO_H_
#define COMMON_RESULTADO_H_

class Resultado {

public:

	Resultado(bool* entradas,bool* salidas);

	virtual ~Resultado();


	bool* getEntradas();

	bool* getSalidas();

private:

	bool* entradas;
	bool* salidas;

};

#endif /* COMMON_RESULTADO_H_ */
