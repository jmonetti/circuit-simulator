/**************************   Clase Controlador         *************/
/**************************   	Grupo 8                 *************/
#include "common_Controlador.h"


/*----------------------------------------------------------------------------*/
//instancia del singleton
Controlador* Controlador::instancia=NULL;

/*----------------------------------------------------------------------------*/

Controlador::Controlador(Fachada_vista* fachada) {

	fachada_vista=fachada;
	accion=new Accion_NULA(this);
	arrstre_activo=false;

}

/*----------------------------------------------------------------------------*/

void Controlador::agregar_accion(Accion* nueva_accion){

	if(accion){
		//libero la memoria reservada por la accion actual
		delete(accion);
	}
	accion=nueva_accion;
}

void Controlador::ejecutar_accion(gdouble x,gdouble y){

	if(accion)
		accion->ejecutar(x,y);

}

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

void Controlador::arrastrar(gdouble x, gdouble y){

	int _x=x;
	int _y=y;
	int _pos_x=pos_x;
	int _pos_y=pos_y;
	TIPO_COMPUERTA _tipo;

	if(matriz.hay_componente(&_pos_x,&_pos_y,&_tipo)){

		bool agregado= matriz.agregar_compuerta(&_x,&_y,_tipo);
		if(agregado){
			fachada_vista->dibujar_componente(_x, _y,_tipo);
			matriz.eliminar_componente(_pos_x,_pos_y);
			fachada_vista->dibujar_componente(_pos_x,_pos_y,T_VACIA);

		}
	}

}
/*----------------------------------------------------------------------------*/

void Controlador::agregar_componente(int x,int y,TIPO_COMPUERTA _tipo){

	int _x=x;
	int _y=y;

	bool agregada= matriz.agregar_compuerta(&_x,&_y,_tipo);

	if(agregada){
	  fachada_vista->dibujar_componente(_x,_y,_tipo);
	}
}
/*----------------------------------------------------------------------------*/

void Controlador::eliminar_componente(int x,int y){

	int _x=x;
	int _y=y;
	TIPO_COMPUERTA _tipo;

	if(matriz.hay_componente(&_x,&_y,&_tipo)){

		matriz.eliminar_componente(_x,_y);
		fachada_vista->dibujar_componente(_x,_y,T_VACIA);

	}


}

void Controlador::conectar_drag_drop(){

	if(!arrstre_activo){
		fachada_vista->activar_dnd();
		arrstre_activo=true;
	}
}

void Controlador::desconectar_drag_drop(){

	if(arrstre_activo){
		fachada_vista->desactivar_dnd();
		arrstre_activo=false;
	}
}

bool Controlador::get_arrastre_activo()const{

	return arrstre_activo;

}
/*----------------------------------------------------------------------------*/

Controlador::~Controlador() {

	if(accion){
	//libero la memoria reservada por la accion actual
	delete(accion);
	}

}
