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


bool Modelo_vista_circuito::agregar_compuerta(int* x,int* y,EstadoCelda _estado){
	bool agregada;
	int fila= de_pixel_a_fila(*y);
	int col= de_pixel_a_col(*x);
	Celda* aux= modelo_grilla[fila][col];

	*y= (fila*13)+7; //TODO
	*x= col*13+7;  //TODO

	//TODO case con _estado
	agregada=aux->agregar_compuerta_XOR();

	//fin TODO

	return agregada;
}

Modelo_vista_circuito::~Modelo_vista_circuito() {

	for (int i = 0; i < FILAS_MODELO; i++){
		for (int j = 0; j < COLUMNAS_MODELO; j++){
			delete modelo_grilla[i][j];
		}
	}
}
