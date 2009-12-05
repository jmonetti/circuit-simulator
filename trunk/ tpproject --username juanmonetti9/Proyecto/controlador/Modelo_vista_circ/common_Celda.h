/**************************   Clase Celda      ***********************/
/**************************   	Grupo 8        ***********************/

#ifndef COMMON_CELDA_H_
#define COMMON_CELDA_H_


#include <list>
#include "../../common/constantes.h"



class Modelo_vista_circuito; //declaracion forward

class Celda {

private:

	//Grilla en la cual se encuentra la celda
	Modelo_vista_circuito* grilla;

	unsigned int fila; 	//Fila de la celda
	unsigned int colum;	//columna de la celda

	/** atributos de el componente de la celda **/
	std::list<Celda*> entorno;	//Entorno de la celda
	TIPO_COMPUERTA estado; 		//estado de la celda
	SENTIDO sentido;       		//sentido del componente al que representa una celda
	unsigned int ID;			//id del componente
	unsigned int fila_padre;  	//Fila del padre del componente
	unsigned int colum_padre;	//columna del padre del componente


	/** atributos de la pista secundaria que podra tener la celda **/
	std::list<Celda*> entorno_sec;	//Entorno de la celda sec
	TIPO_COMPUERTA estado_sec; 		//estado de la cel sec
	SENTIDO sentido_sec;       		//sentido de la pista sec
	unsigned int ID_sec;			//id del componente sec
	unsigned int fila_padre_sec;  	//Fila del padre del componente sec
	unsigned int colum_padre_sec;	//columna del padre del componente sec



	bool agregar_entorno_compuerta(TIPO_COMPUERTA _tipo,int _id);

	bool agregar_entorno_entrada_salida(TIPO_COMPUERTA _tipo,SENTIDO _sentido,int _id);

	void get_pos_entorno_ES(int* fila_entorno,int* col_entorno,SENTIDO _sentido,TIPO_COMPUERTA tipo);

	bool agregar_entorno_pista(SENTIDO _sentido,int _id);

	bool agregar_entorno_caja_negra(SENTIDO _sentido,int _id);

public:

	Celda(Modelo_vista_circuito* _grilla,unsigned int _fila,unsigned int _col);

	/**
	 * Agrega una compuerta xor a la grilla, utilizando esta celda
	 * como celda padre, seteando su entorno y los valores de las
	 * celdas que integran el entorno
	 * @return (true) en caso de haber agregado la celda
	 * 		   (false) en caso de que no se pueda agregar
	 */
	bool agregar_compuerta(TIPO_COMPUERTA tipo,int id,SENTIDO _sentido);

	bool agregar_pista(int id,SENTIDO _sentido);

	bool agregar_caja_negra(int id,SENTIDO _sentido);

	bool agregar_entrada(int id,SENTIDO _sentido);

	bool agregar_salida(int id,SENTIDO _sentido);

	void set_sentido(SENTIDO _sentido);

	void rotar_izq();

	void rotar_derecha();

	void eliminar_componente();

	void eliminar_entorno_pista(int _id);

	void eliminar_pista_principal(int _id);

	void ocupar_celda_padre(TIPO_COMPUERTA _tipo,SENTIDO _sentido,int id,int filaPadre, int colPadre);

	void ocupar_celda(TIPO_COMPUERTA _tipo,int filaPadre, int colPadre,int _id);

	void ocupar_celda_pista(SENTIDO _sentido,TIPO_COMPUERTA _tipo,int filaPadre, int colPadre,int _id);

	void ocupar_celda_secundaria(TIPO_COMPUERTA _tipo,SENTIDO _sentido,int filaPadre, int colPadre,int _id);

	bool get_celda_sec(int* fila_padr_sec,int* col_padr_sec,int* _id );

	SENTIDO get_sentido_multiple(unsigned int _id);

	bool es_padre();

	void desocupar_celda();

	int get_fila()const;

	int get_colum()const;

	int get_fila_padre()const;

	int get_colum_padre()const;

	SENTIDO get_sentido();

	TIPO_COMPUERTA get_tipo_celda()const;

	int get_id()const;

	void set_info_padre(int fila, int columna);

	void set_info_padre_sec(int fila_sec_p, int columna_sec_p);

	bool esta_ocupada()const;

	bool hay_pista_secundaria()const;

	bool puede_rotar_pista();

	bool acepta_pista_secundaria(SENTIDO _sent)const;

	void vaciar_entorno();

	SENTIDO rotar_izq(SENTIDO _sent);
	SENTIDO rotar_der(SENTIDO _sent);

	virtual ~Celda();
};

#endif /* COMMON_CELDA_H_ */
