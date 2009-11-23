/**************************   Clase GRILLA   *************************/
/**************************   	Grupo 8      *************************/


#include "common_Modelo_vista_circuito.h"
// todo #include "common_Celda.h"

Modelo_vista_circuito::Modelo_vista_circuito() {

	//Creo las celdas
	for (int i = 0; i < FILAS_MODELO; i++){
		for (int j = 0; j < COLUMNAS_MODELO; j++){
			modelo_grilla[i][j] = new Celda(this,(unsigned int)i+1,(unsigned int)j+1);
		}
	}

}

int Modelo_vista_circuito::de_pixel_a_fila(int x){

	int fila=(x*FILAS_MODELO)/PIXELES_WIDTH;
	return fila;
}

int Modelo_vista_circuito::de_pixel_a_col(int y){

	int columna = (y*COLUMNAS_MODELO)/PIXELES_HEIGHT;
	return columna;
}

Celda* Modelo_vista_circuito::get_celda(int fila,int colum){


	if(fila>=1 && colum>=1){

		return modelo_grilla[fila-1][colum-1];
	}
	else
		return NULL;

}


bool Modelo_vista_circuito::agregar_compuerta(int x,int y,EstadoCelda _estado){
	bool agregada;
	Celda* aux= modelo_grilla[de_pixel_a_fila(x)][de_pixel_a_col(y)];


	//TODO case con _estado
	agregada=aux->agregar_compuerta_XOR();
	//TODO
	if(agregada)
		g_print("Agregada TRUE en agregar compuerta modelo XOR \n");
	else
		g_print("Agregada FALSE en agregar compuerta Modelo \n");
	//fin TODO
	//fin TODO

	return agregada;
}

Modelo_vista_circuito::~Modelo_vista_circuito() {

}
