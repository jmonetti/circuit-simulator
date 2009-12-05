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
	matrizActual= NULL;

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

	if(matrizActual->hay_componente(&_pos_x,&_pos_y,&_tipo)){

		//obtengo la celda origen para obtener el sentido
		Celda* celda_origen=matrizActual->get_celda_px(_pos_x,_pos_y);
		//intento agregar la compuerta en la celda destino

		bool agregadoModelo= true;
		bool agregadoVista= true;

		try {
			Posicion posicion(matrizActual->de_pixel_a_col(_x),matrizActual->de_pixel_a_fila(_y));
			modeloCliente->mover(celda_origen->get_id(),posicion);
			matrizActual->agregar_componente(&_x,&_y,_tipo,celda_origen->get_id(),celda_origen->get_sentido());

		} catch (ConexionException e) {

			agregadoModelo= false;
		}

		if(agregadoVista && agregadoModelo){
			//obtengo la celda destino para intentar agregar la compuerta
			Celda* celda_destino=matrizActual->get_celda_px(_x,_y);

			celda_destino->set_sentido(celda_origen->get_sentido());
			fachada_vista->dibujar_componente(_x, _y,_tipo,celda_destino->get_sentido());
			matrizActual->eliminar_componente(_pos_x,_pos_y);
			fachada_vista->borrar_componente(_pos_x,_pos_y,_tipo,celda_origen->get_sentido());
		}else if (!agregadoVista) {

			Posicion posicion(matrizActual->de_pixel_a_col(_pos_x),matrizActual->de_pixel_a_fila(_pos_y));
			modeloCliente->mover(celda_origen->get_id(),posicion);

		}

	}

}
/*----------------------------------------------------------------------------*/

void Controlador::agregar_componente(int x,int y,TIPO_COMPUERTA _tipo,SENTIDO sentido){

	int _x=x;
	int _y=y;
	Celda* celda= NULL;
	bool agregadaModelo= true;
	bool agregadaVista;
	int id;

	switch(_tipo){

	case T_ENTRADA:	{
					try {

						Posicion posicion(matrizActual->de_pixel_a_col(x),matrizActual->de_pixel_a_fila(y));
						std::string nom="ENTRADA";
						id= modeloCliente->agregarEntrada(posicion,nom,sentido);
						agregadaVista=matrizActual->agregar_componente(&_x,&_y,_tipo,id,sentido);
						celda=matrizActual->get_celda_px(_x,_y);

					} catch (ConexionException e) {

						agregadaModelo= false;

					}

					break;

					}

	case T_SALIDA:	{

					try {

						Posicion posicion(matrizActual->de_pixel_a_col(x),matrizActual->de_pixel_a_fila(y));
						std::string nom="SALIDA";
						id= modeloCliente->agregarSalida(posicion,nom,sentido);
						agregadaVista= matrizActual->agregar_componente(&_x,&_y,_tipo,id,sentido);
						celda=matrizActual->get_celda_px(_x,_y);

					} catch (ConexionException e) {

						agregadaModelo= false;

					}

				     break;

					}

	case T_PISTA: 	{

					try {

						g_print("Por agregar componente\n");//TODO
						Posicion posicion(matrizActual->de_pixel_a_col(x),matrizActual->de_pixel_a_fila(y));
						id= modeloCliente->agregarCompuerta(_tipo,posicion,sentido);
						g_print("Agrege en modelo\n");//TODO
						agregadaVista= matrizActual->agregar_componente(&_x,&_y,_tipo,id,sentido);
						if(agregadaVista)
							g_print("Agrege en vista\n");//TODO
						else
							g_print("NOOOO Agrege en vista\n");//TODO
						celda=matrizActual->get_celda_px(_x,_y);

					} catch (ConexionException e) {
						g_print("EXCEPTION\n");//TODO
						agregadaModelo= false;

					}

					 break;

	}

	default:
			{

			try {

				Posicion posicion(matrizActual->de_pixel_a_col(x),matrizActual->de_pixel_a_fila(y));
				id= modeloCliente->agregarCompuerta(_tipo,posicion,sentido);

				agregadaVista= matrizActual->agregar_componente(&_x,&_y,_tipo,id,sentido);
				celda=matrizActual->get_celda_px(_x,_y);

			} catch (ConexionException e) {

				agregadaModelo= false;

			}

			break;

			}
	}

	if(agregadaModelo && celda && agregadaVista && _tipo == T_PISTA){

		int fila_sec;
		int col_sec;
		int Id;

		if(celda->get_celda_sec(&fila_sec,&col_sec,&Id)){

			Celda* aux_celda= matrizActual->get_celda(fila_sec,col_sec);
			fachada_vista->dibujar_componente(matrizActual->de_col_a_pixel(col_sec),matrizActual->de_fila_a_pixel(fila_sec),_tipo,aux_celda->get_sentido_multiple(Id));

		}else
			fachada_vista->dibujar_componente(_x,_y,_tipo,celda->get_sentido());

	}
	else if(agregadaModelo && celda && agregadaVista){

		fachada_vista->dibujar_componente(_x,_y,_tipo,celda->get_sentido());

	}else if (!agregadaVista) {

		modeloCliente->eliminarCompuerta(id);
	}

}

void Controlador::rotar_left(int x,int y){

	int _x=x;
	int _y=y;
	TIPO_COMPUERTA _tipo;

	if(matrizActual->hay_componente(&_x,&_y,&_tipo)){
		//Obtengo la celda padre la que representa la compuerta
		Celda* celda=matrizActual->get_celda_px(_x,_y);

		if(_tipo != T_ENTRADA && _tipo != T_SALIDA && _tipo != T_PISTA){

			try {

				modeloCliente->rotar(celda->get_id(),IZQUIERDA);
				fachada_vista->dibujar_componente(_x,_y,T_VACIA,celda->get_sentido());
				celda->rotar_izq();
				fachada_vista->dibujar_componente(_x,_y,_tipo,celda->get_sentido());
			} catch (ConexionException e) {
				g_print("NO ROTO");//TODO
			}

		}else if(_tipo == T_PISTA) {

			//Obtengo la celda padre la que representa la compuerta
			Celda* celda=matrizActual->get_celda_px(_x,_y);


			if(! celda->hay_pista_secundaria() && celda->puede_rotar_pista()){

				SENTIDO sent_=celda->get_sentido();
				int id_ = celda->get_id();

				try {

					modeloCliente->rotar(celda->get_id(),IZQUIERDA);

					fachada_vista->borrar_pista(_x,_y,celda->get_sentido());

					celda->eliminar_pista_principal(celda->get_id());
					matrizActual->agregar_componente(&_x,&_y,T_PISTA,id_,celda->rotar_izq(sent_));
					fachada_vista->dibujar_componente(_x,_y,_tipo,celda->rotar_izq(sent_));


				} catch (ConexionException e) {
					g_print("NO ROTO");//TODO
				}


			}

		}

	}

}

void Controlador::rotar_right(int x,int y){


	int _x=x;
	int _y=y;
	TIPO_COMPUERTA _tipo;

	if(matrizActual->hay_componente(&_x,&_y,&_tipo)){

		if(_tipo != T_ENTRADA && _tipo != T_SALIDA && _tipo != T_PISTA){

			//Obtengo la celda padre la que representa la compuerta
			Celda* celda=matrizActual->get_celda_px(_x,_y);
			try {
				modeloCliente->rotar(celda->get_id(),DERECHA);
				fachada_vista->dibujar_componente(_x,_y,T_VACIA,celda->get_sentido());
				celda->rotar_derecha();
				fachada_vista->dibujar_componente(_x,_y,_tipo,celda->get_sentido());

			} catch (ConexionException e) {
				g_print("NO ROTO");//TODO
			}
		}
		else if(_tipo == T_PISTA){

			//Obtengo la celda padre la que representa la compuerta
			Celda* celda=matrizActual->get_celda_px(_x,_y);


			if(! celda->hay_pista_secundaria() && celda->puede_rotar_pista()){

				SENTIDO sent_=celda->get_sentido();
				int id_ = celda->get_id();

				try {

					modeloCliente->rotar(celda->get_id(),DERECHA);

					fachada_vista->borrar_pista(_x,_y,celda->get_sentido());

					celda->eliminar_pista_principal(celda->get_id());
					matrizActual->agregar_componente(&_x,&_y,T_PISTA,id_,celda->rotar_der(sent_));
					fachada_vista->dibujar_componente(_x,_y,_tipo,celda->rotar_der(sent_));


				} catch (ConexionException e) {
					g_print("NO ROTO");//TODO
				}


			}
		}

	}

}
/*----------------------------------------------------------------------------*/

void Controlador::eliminar_componente(int x,int y){

	int _x=x;
	int _y=y;
	TIPO_COMPUERTA _tipo;

	if(matrizActual->hay_componente(&_x,&_y,&_tipo)){

		Celda* celda=matrizActual->get_celda_px(_x,_y);
		SENTIDO sent=celda->get_sentido();
		modeloCliente-> eliminarCompuerta(celda->get_id());
		matrizActual->eliminar_componente(_x,_y);
		fachada_vista->borrar_componente(_x,_y,_tipo,sent);

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

	try {

		modeloCliente->guardar();

	} catch (CircuitoException e) {

		fachada_vista->mostrar_error(e.getMensaje());

	}

}

void Controlador::crear_circuito(){

	std::string nombre= "Circuito";
	int id= modeloCliente->crearNuevo(nombre);
	matrizActual= new Modelo_vista_circuito();
	matrices.insert(make_pair(id,matrizActual));
	fachada_vista->agregar_grilla(id);

}

void Controlador::cambiar_circuito(int index){

	if (index >= 0) {

		int id= fachada_vista->cambiar_grilla(index);
		try {

			modeloCliente->cambiarCircuitoActual(id);
			matrizActual= matrices[id];

		} catch (CircuitoException e) {

		}

	}


}

void Controlador::eliminar_circuito(){

	if (!matrices.empty()) {

		modeloCliente->eliminar();

		matrices.erase(fachada_vista->getIdActual());

		matrizActual = NULL;

		fachada_vista->eliminar_grilla();

	}



}

void Controlador::abrir_circuito() {

	if (!fachada_vista->abriendo()) {

		fachada_vista->mostrar_ventana_abrir();
		fachada_vista->agregar_grilla(modeloCliente->getId());

	}

}


void Controlador::simular(){

	try {

		Resultado* resultado=modeloCliente->simular();
		fachada_vista->completar_grilla(resultado);

	} catch (CircuitoException e) {

		fachada_vista->mostrar_error(e.getMensaje());

	}

}

bool Controlador::get_arrastre_activo()const{

	return arrstre_activo;

}

void Controlador::aceptar_error() {

	fachada_vista->aceptar_error();

}

void Controlador::aceptar_abrir() {

	if (fachada_vista->getCircuitoAbrir()) {

		std::string nombreCircuito(fachada_vista->getCircuitoAbrir());

		Circuito* circuito= modeloCliente->recuperar(nombreCircuito);

		matrizActual= new Modelo_vista_circuito();
		matrices.insert(make_pair(circuito->getId(),matrizActual));

		generarCircuito(circuito);

		fachada_vista->aceptar_abrir();

	}

}

void Controlador::cancelar_abrir() {

	fachada_vista->cancelar_abrir();

	fachada_vista->eliminar_grilla();
}

/*----------------------------------------------------------------------------*/

Controlador::~Controlador() {

	if(accion){
	//libero la memoria reservada por la accion actual
	delete(accion);
	}

}

void Controlador::generarCircuito(Circuito* circuito) {

	std::vector<Compuerta*> compuertas= circuito->getCompuertas();

	for (unsigned int var = 0; var < compuertas.size(); ++var) {

		Compuerta* compuerta= compuertas[var];
		Posicion posicion= compuerta->getPosicion();

		int x= matrizActual->de_col_a_pixel(posicion.getX());
		int y= matrizActual->de_fila_a_pixel(posicion.getY());

		matrizActual->agregar_componente(&x,&y,compuerta->getTipo(),compuerta->getId(),compuerta->getSentido());


		fachada_vista->dibujar_componente(x,y,compuerta->getTipo(),compuerta->getSentido());

	}
}
