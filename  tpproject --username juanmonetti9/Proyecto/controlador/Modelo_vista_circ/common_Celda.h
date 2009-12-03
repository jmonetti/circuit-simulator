/**************************   Clase Celda      ***********************/
/**************************   	Grupo 8        ***********************/

#ifndef COMMON_CELDA_H_
#define COMMON_CELDA_H_


#include <list>
#include "../../common/constantes.h"



class Modelo_vista_circuito; //declaracion forward

class Celda {

private:

	Modelo_vista_circuito* grilla;//Grilla en la cual se encuentra la celda
	std::list<Celda*> entorno;	  //Entorno de la celda
	TIPO_COMPUERTA estado; //estado de la celda
	SENTIDO sentido;       //sentido del componente al que representa una celda
	unsigned int ID;
	unsigned int fila; 	//Fila de la celda
	unsigned int colum;	//columna de la celda
	unsigned int fila_padre;  	//Fila del padre de la celda
	unsigned int colum_padre;	//columna del padre de la celda




	bool agregar_entorno_compuerta(TIPO_COMPUERTA _tipo);

	bool agregar_entorno_entrada_salida(TIPO_COMPUERTA _tipo,SENTIDO sentido);

	void get_pos_entorno_ES(int* fila_entorno,int* col_entorno,SENTIDO sentido,TIPO_COMPUERTA tipo);

	bool agregar_entorno_pista(SENTIDO sentido);

	bool agregar_entorno_caja_negra(SENTIDO sentido);



public:

	Celda(Modelo_vista_circuito* _grilla,unsigned int _fila,unsigned int _col);

	/**
	 * Agrega una compuerta xor a la grilla, utilizando esta celda
	 * como celda padre, seteando su entorno y los valores de las
	 * celdas que integran el entorno
	 * @return (true) en caso de haber agregado la celda
	 * 		   (false) en caso de que no se pueda agregar
	 */
	bool agregar_compuerta(TIPO_COMPUERTA tipo,int id,SENTIDO sentido);

	bool agregar_pista(int id,SENTIDO sentido);

	bool agregar_caja_negra(int id,SENTIDO sentido);

	bool agregar_entrada(int id,SENTIDO sentido);

	bool agregar_salida(int id,SENTIDO sentido);

	void set_sentido(SENTIDO _sentido);

	void rotar_izq();

	void rotar_derecha();

	void eliminar_componente();

	void ocupar_celda_padre(TIPO_COMPUERTA _tipo,SENTIDO _sentido,int id,int filaPadre, int colPadre);

	void ocupar_celda(TIPO_COMPUERTA _tipo,int filaPadre, int colPadre);

	void desocupar_celda();

	int get_fila()const;

	int get_colum()const;

	int get_fila_padre()const;

	int get_colum_padre()const;

	SENTIDO get_sentido()const;

	TIPO_COMPUERTA get_tipo_celda()const;

	int get_id()const;

	void set_info_padre(int fila, int columna);

	bool esta_ocupada()const;

	void vaciar_entorno();

	virtual ~Celda();
};

#endif /* COMMON_CELDA_H_ */
