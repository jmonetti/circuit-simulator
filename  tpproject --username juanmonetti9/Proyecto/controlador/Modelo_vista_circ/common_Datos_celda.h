
#ifndef COMMON_DATOS_CELDA_H_
#define COMMON_DATOS_CELDA_H_

#include "../../common/constantes.h"
#include <list>

class Celda; // forward declaration

class Datos_celda {

private:

	bool ocupada;		//representa el estado de ocupacion de una celda
	bool celda_ppal;	//booleano que representa si la celda es una celda ppal
	int id;				//id del componente
	int fila_ppal; 		//Fila del padre del componente
	int colum_ppal;		//columna del padre del componente
	SENTIDO sentido;    //sentido del componente al que representa una celda
	TIPO_COMPUERTA tipo;//estado de la celda

	//Entorno de la celda
	std::list<Celda*> entorno;

public:

	std::list<Celda*>& get_entorno();

	Datos_celda();

	TIPO_COMPUERTA get_tipo()const;

	void set_tipo(TIPO_COMPUERTA nuevo_tipo);

	SENTIDO get_sentido()const;

	void set_sentido(SENTIDO nuevo_sentido);

	int get_id()const;

	void set_id(int nuevo_id);

	int get_fila_ppal()const;

	void set_fila_ppal(int nueva_fila_ppal);

	int get_col_ppal()const;

	void set_col_ppal(int nueva_col_ppal);

	bool esta_ocupada()const;

	void ocupar();

	void desocupar();

	bool es_principal()const;

	void set_ppal(bool nueva_ppal);

	void agregar_a_entorno(Celda* nueva_celda);

	void vaciar_entorno();


	virtual ~Datos_celda();
};

#endif /* COMMON_DATOS_CELDA_H_ */
