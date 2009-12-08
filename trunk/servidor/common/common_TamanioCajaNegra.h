#ifndef COMMON_TAMANIOCAJANEGRA_H_
#define COMMON_TAMANIOCAJANEGRA_H_

class TamanioCajaNegra {

public:

	TamanioCajaNegra(int cantEntradas,int cantSalidas);

	virtual ~TamanioCajaNegra();

	int getCantEntradas()const;

	int getCantSalidas()const;

private:

	int cantEntradas;
	int cantSalidas;

};

#endif /* COMMON_TAMANIOCAJANEGRA_H_ */
