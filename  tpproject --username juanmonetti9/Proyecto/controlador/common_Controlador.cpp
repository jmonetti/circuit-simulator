/**************************   Clase Controlador         *************/
/**************************   	Grupo 8                 *************/
#include "common_Controlador.h"


/*----------------------------------------------------------------------------*/
//instancia del singleton
Controlador* Controlador::instancia=NULL;

/*----------------------------------------------------------------------------*/

Controlador::Controlador(Fachada_vista* fachada) {

	fachada_vista=fachada;
}

/*----------------------------------------------------------------------------*/

Controlador* Controlador::crear_instancia(Fachada_vista* fachada){

	if(instancia == NULL){

		instancia= new Controlador(fachada);
	}

	return instancia;

}
/*----------------------------------------------------------------------------*/

Controlador* Controlador::get_instancia(){

	return instancia;
}
/*----------------------------------------------------------------------------*/

void Controlador::set_pos_x_click(int x){

	pos_x=x;
}
/*----------------------------------------------------------------------------*/

void  Controlador::set_pos_y_click(int y){

	pos_y=y;
}
/*----------------------------------------------------------------------------*/

void Controlador::agregar_componente(int x,int y,Tipo_Celda _tipo){

	int _x=x;
	int _y=y;

	bool agregada= matriz.agregar_compuerta(&_x,&_y,TXOR);

	if(agregada){
	  fachada_vista->dibujar_componente(_x,_y,TXOR);
	}
}
/*----------------------------------------------------------------------------*/

void Controlador::eliminar_componente(int x,int y){

}
/*----------------------------------------------------------------------------*/

Controlador::~Controlador() {

}
