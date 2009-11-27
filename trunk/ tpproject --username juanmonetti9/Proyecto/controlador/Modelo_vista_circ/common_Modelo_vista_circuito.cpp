/**************************   Modelo Circuito  ***********************/
/**************************   	Grupo 8        ***********************/


#include "common_Modelo_vista_circuito.h"


Modelo_vista_circuito::Modelo_vista_circuito() {

	//Creo las celdas
	for (int i = 0; i < FILAS_MODELO; i++){
		for (int j = 0; j < COLUMNAS_MODELO; j++){
			modelo_grilla[i][j] = new Celda(this,(unsigned int)i+1,(unsigned int)j+1);
		}
	}

}

int Modelo_vista_circuito::de_pixel_a_fila(int y){

	int fila=(y*FILAS_MODELO)/PIXELES_HEIGHT;
	return fila;
}

int Modelo_vista_circuito::de_pixel_a_col(int x){

	int columna = (x*COLUMNAS_MODELO)/PIXELES_WIDTH;
	return columna;
}

Celda* Modelo_vista_circuito::get_celda(int fila,int colum){


	if(fila>=1 && colum>=1){

		return modelo_grilla[fila-1][colum-1];
	}
	else
		return NULL;

}

bool Modelo_vista_circuito::hay_componente(int* x,int* y){



	int fila= de_pixel_a_fila(*y);
	int col= de_pixel_a_col(*x);
	Celda* aux= modelo_grilla[fila][col];
	bool retorno=aux->esta_ocupada();

	if(retorno){

		*y= (aux->get_fila_padre()*12)+6; //TODO
		*x= aux->get_colum_padre()*12+6;  //TODO

	}

	return aux->esta_ocupada();
}
bool Modelo_vista_circuito::eliminar_componente(int x,int y){

	int fila= de_pixel_a_fila(y);
	int col= de_pixel_a_col(x);
	Celda* aux= modelo_grilla[fila][col];
	aux->eliminar_componente();

	return true;//TODO

}

bool Modelo_vista_circuito::agregar_compuerta(int* x,int* y,Tipo_Celda _tipo){
	bool agregada;
	int fila= de_pixel_a_fila(*y);
	int col= de_pixel_a_col(*x);
	Celda* aux= modelo_grilla[fila][col];

	*y= (fila*12)+6; //TODO
	*x= col*12+6;  //TODO

	agregada=aux->agregar_compuerta(_tipo);

	return agregada;
}

Modelo_vista_circuito::~Modelo_vista_circuito() {

	for (int i = 0; i < FILAS_MODELO; i++){
		for (int j = 0; j < COLUMNAS_MODELO; j++){
			delete modelo_grilla[i][j];
		}
	}
}
