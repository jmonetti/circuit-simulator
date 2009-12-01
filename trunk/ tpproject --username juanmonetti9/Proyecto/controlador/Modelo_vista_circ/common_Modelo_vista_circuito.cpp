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

	int fila=((y*FILAS_MODELO)/PIXELES_HEIGHT)+1;
	return fila;
}

int Modelo_vista_circuito::de_pixel_a_col(int x){

	int columna = ((x*COLUMNAS_MODELO)/PIXELES_WIDTH)+1;
	return columna;
}

int Modelo_vista_circuito::de_col_a_pixel(int col){

	int x = ((col)*CELDA_WIDTH)-(CELDA_WIDTH/2);
	return x;
}
int Modelo_vista_circuito::de_fila_a_pixel(int fila){

	int y = ((fila)*CELDA_WIDTH)-(CELDA_WIDTH/2);
	return y;
}



Celda* Modelo_vista_circuito::get_celda(int fila,int colum){


	if(fila>=1 && colum>=1){

		return modelo_grilla[fila-1][colum-1];
	}
	else
		return NULL;

}
Celda* Modelo_vista_circuito::get_celda_px(int x,int y){


	int fila= de_pixel_a_fila(y);
	int col= de_pixel_a_col(x);

	return modelo_grilla[fila-1][col-1];

}


bool Modelo_vista_circuito::hay_componente(int* x,int* y,TIPO_COMPUERTA* tipo){



	int fila= de_pixel_a_fila(*y);
	int col= de_pixel_a_col(*x);
	Celda* aux= modelo_grilla[fila-1][col-1];
	bool retorno=aux->esta_ocupada();

	if(retorno){

		*y= de_fila_a_pixel(aux->get_fila_padre());
		*x= de_col_a_pixel(aux->get_colum_padre());
		g_print("Hay componente en (%d,%d)\n",*x,*y);
	}


	*tipo=aux->get_tipo_celda();

	return aux->esta_ocupada();
}
bool Modelo_vista_circuito::eliminar_componente(int x,int y){

	int fila= de_pixel_a_fila(y);
	int col= de_pixel_a_col(x);
	Celda* aux= modelo_grilla[fila-1][col-1];
	aux->eliminar_componente();

	return true;//TODO

}

bool Modelo_vista_circuito::agregar_compuerta(int* x,int* y,TIPO_COMPUERTA _tipo){

	bool agregada=true;


	//ubico la fila y col que corresponda y centro los valorees de *x e *y
	int fila= de_pixel_a_fila(*y);
	int col= de_pixel_a_col(*x);
	*y=de_fila_a_pixel(fila);
	*x=de_col_a_pixel(col);

	//obtengo la celda
	Celda* aux= get_celda(fila,col);
	//intento agregarle una compuerta

	agregada=aux->agregar_compuerta(_tipo);
	if(agregada)
		g_print("Agregada en (%d,%d)\n",*x,*y);


	return agregada;
}

bool Modelo_vista_circuito::agregar_entrada(int* x,int* y){

	bool agregada;
	//ubico la fila y col que corresponda y centro los valorees de *x e *y
	int fila= de_pixel_a_fila(*y);
	int col= de_pixel_a_col(*x);
	*y=de_fila_a_pixel(fila);
	*x=de_col_a_pixel(col);

	//obtengo la celda
	Celda* aux= get_celda(fila,col);
	//intento agregarle una compuerta
	agregada=aux->agregar_entrada();

	return agregada;

}

bool Modelo_vista_circuito::agregar_salida(int* x,int* y){

	bool agregada;
	//ubico la fila y col que corresponda y centro los valorees de *x e *y
	int fila= de_pixel_a_fila(*y);
	int col= de_pixel_a_col(*x);
	*y=de_fila_a_pixel(fila);
	*x=de_col_a_pixel(col);

	//obtengo la celda
	Celda* aux= get_celda(fila,col);
	//intento agregarle una compuerta

	agregada=aux->agregar_salida();

	return agregada;

}
Modelo_vista_circuito::~Modelo_vista_circuito() {

	for (int i = 0; i < FILAS_MODELO; i++){
		for (int j = 0; j < COLUMNAS_MODELO; j++){
			delete modelo_grilla[i][j];
		}
	}
}
