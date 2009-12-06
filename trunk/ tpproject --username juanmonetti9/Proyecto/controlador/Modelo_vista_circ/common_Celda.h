/**************************   Clase Celda      ***********************/
/**************************   	Grupo 8        ***********************/

#ifndef COMMON_CELDA_H_
#define COMMON_CELDA_H_


#include <list>
#include "../../common/constantes.h"
#include "common_Datos_celda.h"



class Modelo_vista_circuito; //declaracion forward

class Celda {

private:

	//Grilla en la cual se encuentra la celda
	Modelo_vista_circuito* grilla;

	unsigned int fila; 	//Fila de la celda
	unsigned int colum;	//columna de la celda

	Datos_celda componente;
	Datos_celda componente_secundario;


	bool agregar_entorno_compuerta(TIPO_COMPUERTA _tipo,int _id,SENTIDO nuevo_sentido);

	bool agregar_entorno_ES(TIPO_COMPUERTA _tipo,SENTIDO _sentido,int _id);

	void get_entorno_ES(int* fila_entorno,int* col_entorno,SENTIDO _sentido,TIPO_COMPUERTA tipo);

	bool agregar_entorno_pista(SENTIDO _sentido,int _id);

	bool agregar_entorno_caja_negra(int cant_entradas,int cant_salidas,int _id);

	void vaciar_entorno(int identificador);

	void desocupar_componente(int identificador);


public:

	Celda(Modelo_vista_circuito* nueva_grilla,unsigned int nueva_fila,unsigned int nueva_col);

	int get_fila()const;

	int get_columna()const;

	Datos_celda* get_datos();

	Datos_celda* get_datos_secundarios();

	void set_componente(TIPO_COMPUERTA n_tipo,SENTIDO n_sentido,int n_id,int n_fila_ppal, int n_col_ppal);

	void set_secundario(TIPO_COMPUERTA n_tipo,SENTIDO n_sentido,int n_id,int n_fila_ppal, int n_col_ppal);

	bool esta_ocupada()const;

	bool hay_secundario()const;

	bool acepta_secundario(SENTIDO _sent)const;

	bool puede_rotar()const; ///todo solo para pistas

	void rotar(DIRECCION direcc);

	/* Metodos para agregar un componente a la celda */

	bool agregar_compuerta(TIPO_COMPUERTA nuevo_tipo,int nuevo_id,SENTIDO nuevo_sentido);

	bool agregar_pista(int nuevo_id,SENTIDO nuevo_sentido);

	bool agregar_caja_negra(int nuevo_id,int cant_entradas,int cant_salidas);

	bool agregar_entrada(int nuevo_id,SENTIDO nuevo_sentido);

	bool agregar_salida(int nuevo_id,SENTIDO nuevo_sentido);

	/* Metodos para eliminar un componente */

	void eliminar_componente();

	void eliminar_componente(int identificador);

	/* Metodos estaticos para obtener el valor del sentido al rotar */

	static SENTIDO turn_right(SENTIDO _sent);

	static SENTIDO turn_left(SENTIDO _sent);

	//Destructor virtual
	virtual ~Celda();
};

#endif /* COMMON_CELDA_H_ */
