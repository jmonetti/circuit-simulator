/**************************   Clase Controlador         *************/
/**************************   	Grupo 8                 *************/
#include "common_Controlador.h"
#include "../excepciones/common_ConexionException.h"
#include "../excepciones/common_CircuitoException.h"
#include "../modelo/simulacion/common_Resultado.h"
#include <string>


/*----------------------------------------------------------------------------*/
//instancia del singleton
Controlador* Controlador::instancia=NULL;

/*----------------------------------------------------------------------------*/

Controlador::Controlador(Fachada_vista* fachada, ModeloCliente *modeloCliente) {

	fachada_vista=fachada;
	accion=new Accion_NULA(this);
	arrstre_activo=false;
	this->modeloCliente= modeloCliente;
	std::string nombre="Circuito";
	modeloCliente->crearNuevo(nombre);//TODO

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

		g_print("AGREGARENTRADAqqqqq\n");
	if(accion) {
		accion->ejecutar(x,y);
	}
}

Controlador* Controlador::crear_instancia(Fachada_vista* fachada, ModeloCliente* modeloCliente){

	if(instancia == NULL){

		instancia= new Controlador(fachada,modeloCliente);
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

		bool agregadoModelo= true;
		bool agregadoVista= true;

		try {
			Posicion posicion(matriz.de_pixel_a_col(_x),matriz.de_pixel_a_fila(_y));
			modeloCliente->mover(celda_origen->get_id(),posicion);
			agregadoVista= matriz.agregar_compuerta(&_x,&_y,_tipo,celda_origen->get_id());

		} catch (ConexionException e) {

			agregadoModelo= false;

		}

		if(agregadoVista && agregadoModelo){
			//obtengo la celda destino para intentar agregar la compuerta
			Celda* celda_destino=matriz.get_celda_px(_x,_y);

			celda_destino->set_sentido(celda_origen->get_sentido());
			fachada_vista->dibujar_componente(_x, _y,_tipo,celda_destino->get_sentido());
			matriz.eliminar_componente(_pos_x,_pos_y);
			fachada_vista->dibujar_componente(_pos_x,_pos_y,T_VACIA,celda_origen->get_sentido());
		}else if (!agregadoVista) {

			Posicion posicion(matriz.de_pixel_a_col(_pos_x),matriz.de_pixel_a_fila(_pos_y));
			modeloCliente->mover(celda_origen->get_id(),posicion);

		}

	}

}
/*----------------------------------------------------------------------------*/

void Controlador::agregar_componente(int x,int y,TIPO_COMPUERTA _tipo){

	int _x=x;
	int _y=y;
	Celda* celda= NULL;
	bool agregadaModelo= true;
	bool agregadaVista;
	int id;

	switch(_tipo){

	case T_ENTRADA:	{
					try {

						Posicion posicion(matriz.de_pixel_a_col(x),matriz.de_pixel_a_fila(y));
						std::string nom="";
						id= modeloCliente->agregarEntrada(posicion,nom,ESTE);
						agregadaVista=matriz.agregar_entrada(&_x,&_y,id);
						celda=matriz.get_celda_px(_x,_y);

					} catch (ConexionException e) {

						agregadaModelo= false;

					}

					break;

					}

	case T_SALIDA:	{

					try {

						Posicion posicion(matriz.de_pixel_a_col(x),matriz.de_pixel_a_fila(y));
						std::string nom="";
						id= modeloCliente->agregarSalida(posicion,nom,ESTE);
						g_print("(%d,%d)\n",_x,_y);
						agregadaVista= matriz.agregar_salida(&_x,&_y,id);
						g_print("(%d,%d)\n",_x,_y);
						celda=matriz.get_celda_px(_x,_y);

					} catch (ConexionException e) {

						agregadaModelo= false;

					}

				     break;

					}

	case T_PISTA: 	{break;}

	default:
					{

					try {

						Posicion posicion(matriz.de_pixel_a_col(x),matriz.de_pixel_a_fila(y));
						id= modeloCliente->agregarCompuerta(_tipo,posicion,ESTE);

						agregadaVista= matriz.agregar_compuerta(&_x,&_y,_tipo,id);
						celda=matriz.get_celda_px(_x,_y);

					} catch (ConexionException e) {

						agregadaModelo= false;

					}

					break;

					}
	}

	if(agregadaModelo && celda && agregadaVista){

		fachada_vista->dibujar_componente(_x,_y,_tipo,celda->get_sentido());

	}else if (!agregadaVista) {

		modeloCliente->eliminarCompuerta(id);

	}

}

void Controlador::rotar_left(int x,int y){

	int _x=x;
	int _y=y;
	TIPO_COMPUERTA _tipo;

	if(matriz.hay_componente(&_x,&_y,&_tipo)){

		//Obtengo la celda padre la que representa la compuerta
		Celda* celda=matriz.get_celda_px(_x,_y);

		try {
			g_print("POR PINCHAR");
			g_print("%d\n",celda->get_id());
			modeloCliente->rotar(celda->get_id(),IZQUIERDA);
			fachada_vista->dibujar_componente(_x,_y,T_VACIA,celda->get_sentido());
			celda->rotar_lef();
			fachada_vista->dibujar_componente(_x,_y,_tipo,celda->get_sentido());
		} catch (ConexionException e) {
			g_print("NO ROTO");//TODO
		}


	}

}

void Controlador::rotar_right(int x,int y){


	int _x=x;
	int _y=y;
	TIPO_COMPUERTA _tipo;

	if(matriz.hay_componente(&_x,&_y,&_tipo)){
		//Obtengo la celda padre la que representa la compuerta
		Celda* celda=matriz.get_celda_px(_x,_y);
		try {
			modeloCliente->rotar(celda->get_id(),DERECHA);
			fachada_vista->dibujar_componente(_x,_y,T_VACIA,celda->get_sentido());
			celda->rotar_right();
			fachada_vista->dibujar_componente(_x,_y,_tipo,celda->get_sentido());

		} catch (ConexionException e) {
			g_print("NO ROTO");//TODO
		}


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
		modeloCliente-> eliminarCompuerta(celda->get_id());
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

void Controlador::guardar(){

	modeloCliente->guardar();

}

void Controlador::simular(){

	try {

		Resultado* resultado=modeloCliente->simular();
		fachada_vista->completar_grilla(resultado);

	} catch (CircuitoException e) {

		g_print("No se pudo simular");

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
