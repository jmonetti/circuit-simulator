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

		//obtengo la celda origen para obtener el sentido
		Celda* celda_origen=matriz.get_celda_px(_pos_x,_pos_y);
		//intento agregar la compuerta en la celda destino
		bool agregado= matriz.agregar_compuerta(&_x,&_y,_tipo);

		if(agregado){
			//obtengo la celda destino para intentar agregar la compuerta
			Celda* celda_destino=matriz.get_celda_px(_x,_y);

			celda_destino->set_sentido(celda_origen->get_sentido());
			fachada_vista->dibujar_componente(_x, _y,_tipo,celda_destino->get_sentido());
			matriz.eliminar_componente(_pos_x,_pos_y);
			fachada_vista->dibujar_componente(_pos_x,_pos_y,T_VACIA,celda_origen->get_sentido());
		}

	}

}
/*----------------------------------------------------------------------------*/

void Controlador::agregar_componente(int x,int y,TIPO_COMPUERTA _tipo){

	int _x=x;
	int _y=y;
	Celda* celda;
	bool agregada;

	switch(_tipo){

	case T_ENTRADA:	{agregada=matriz.agregar_entrada(&_x,&_y);
					celda=matriz.get_celda_px(_x,_y);
					break;}
	case T_SALIDA:	{agregada= matriz.agregar_salida(&_x,&_y);
					 celda=matriz.get_celda_px(_x,_y);
				     break;}
	case T_PISTA: 	{break;}

	default: 		{agregada= matriz.agregar_compuerta(&_x,&_y,_tipo);
					celda=matriz.get_celda_px(_x,_y);
					break;}
	}

	if(agregada && celda){

		fachada_vista->dibujar_componente(_x,_y,_tipo,celda->get_sentido());
	}
}

void Controlador::rotar_left(int x,int y){


	g_print("Para rotar en (%d,%d)\n",x,y);
	int _x=x;
	int _y=y;
	TIPO_COMPUERTA _tipo;

	if(matriz.hay_componente(&_x,&_y,&_tipo)){
		g_print("Hay componente en (%d,%d)\n",_x,_y);
		//Obtengo la celda padre la que representa la compuerta
		Celda* celda=matriz.get_celda_px(_x,_y);
		g_print("Por tapar el componente\n");
		fachada_vista->dibujar_componente(_x,_y,T_VACIA,celda->get_sentido());
		g_print("Por rotar la celda\n");
		celda->rotar_lef();
		g_print("Por dibujar la celda invertida\n");
		fachada_vista->dibujar_componente(_x,_y,_tipo,celda->get_sentido());

	}

}

void Controlador::rotar_right(int x,int y){

	g_print("Para rotar en (%d,%d)\n",x,y);
	int _x=x;
	int _y=y;
	TIPO_COMPUERTA _tipo;

	if(matriz.hay_componente(&_x,&_y,&_tipo)){
		g_print("Hay componente en (%d,%d)\n",_x,_y);
		//Obtengo la celda padre la que representa la compuerta
		Celda* celda=matriz.get_celda_px(_x,_y);
		g_print("Por tapar el componente\n");
		fachada_vista->dibujar_componente(_x,_y,T_VACIA,celda->get_sentido());
		g_print("Por rotar la celda\n");
		celda->rotar_right();
		g_print("Por dibujar la celda invertida\n");
		fachada_vista->dibujar_componente(_x,_y,_tipo,celda->get_sentido());

	}

}
/*----------------------------------------------------------------------------*/

void Controlador::eliminar_componente(int x,int y){

	int _x=x;
	int _y=y;
	TIPO_COMPUERTA _tipo;

	Celda* celda=matriz.get_celda_px(x,y);
	if(matriz.hay_componente(&_x,&_y,&_tipo) && celda){
		SENTIDO sent=celda->get_sentido();
		matriz.eliminar_componente(_x,_y);
		fachada_vista->dibujar_componente(_x,_y,T_VACIA,sent);

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
