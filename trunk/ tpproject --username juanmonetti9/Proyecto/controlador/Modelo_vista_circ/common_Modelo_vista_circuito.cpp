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

bool Modelo_vista_circuito::hay_componente(int* x,int* y,TIPO_COMPUERTA* tipo){


	Celda* aux=get_celda_px(x,y);
	*tipo=aux->get_datos()->get_tipo();
	bool retorno=aux->esta_ocupada();

	if(retorno){
		//Si hay componente
		*y= de_fila_a_pixel(aux->get_datos()->get_fila_ppal());
		*x= de_col_a_pixel(aux->get_datos()->get_col_ppal());
	}

	return retorno;
}

void Modelo_vista_circuito::eliminar_componente(int x,int y){

	Celda* aux= get_celda_px(x,y);

	if(aux)
		aux->eliminar_componente();
}
bool Modelo_vista_circuito::agregar_caja_negra(int* x,int* y,int id,int cant_entradas,int cant_salidas){


	//obtengo la celda y los valores de x e y modificados con
	//los valores del coentro de la celda
	Celda* celda= get_celda_px(x,y);

	return celda->agregar_caja_negra(id,cant_entradas,cant_salidas);


}
bool Modelo_vista_circuito::agregar_componente(int* x,int* y,TIPO_COMPUERTA _tipo,int id,SENTIDO sentido){

	int agregado=false;

	//obtengo la celda y los valores de x e y modificados con
	//los valores del coentro de la celda
	Celda* celda= get_celda_px(x,y);

	if (celda){

		switch(_tipo){

			case T_ENTRADA: {
							agregado = celda->agregar_entrada(id,sentido);
							break;
							}

			case T_SALIDA:  {
						    agregado = celda->agregar_salida(id,sentido);
						    break;
						    }

			case T_PISTA:   {
						    agregado = celda->agregar_pista(id,sentido);
						    break;
						    }

			case T_CAJANEGRA:
							break;


			default:
					agregado = celda->agregar_compuerta(_tipo,id,sentido);
		}
	}

	return agregado;
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
Celda* Modelo_vista_circuito::get_celda_px(int* x,int* y){

	int fila= de_pixel_a_fila(*y);
	int col= de_pixel_a_col(*x);
	*y=de_fila_a_pixel(fila);
	*x=de_col_a_pixel(col);

	return modelo_grilla[fila-1][col-1];

}

Modelo_vista_circuito::~Modelo_vista_circuito() {

	for (int i = 0; i < FILAS_MODELO; i++){
		for (int j = 0; j < COLUMNAS_MODELO; j++){
			delete modelo_grilla[i][j];
		}
	}
}
