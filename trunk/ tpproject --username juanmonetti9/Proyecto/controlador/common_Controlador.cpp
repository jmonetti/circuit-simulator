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
bool Controlador::agregar_componente(int *x,int *y,TIPO_COMPUERTA n_tipo,int n_id,SENTIDO n_sentido){

	bool retorno;
	switch(n_tipo){

	case T_ENTRADA:{
		retorno = matrizActual->agregar_entrada(x,y,n_id,n_sentido);
		break;
	}
	case T_SALIDA:{
		retorno = matrizActual->agregar_salida(x,y,n_id,n_sentido);
			break;
		}
	case T_PISTA:{
		retorno = false;
			break;
	}
	case T_CAJANEGRA:{
		retorno = false;
			break;
	}
	default:{
		retorno = matrizActual->agregar_compuerta(x,y,n_tipo,n_id,n_sentido);
		}

	}

	return retorno;
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
						std::string nom="";
						id= modeloCliente->agregarEntrada(posicion,nom,sentido);
						agregadaVista=matrizActual->agregar_entrada(&_x,&_y,id,sentido);
						celda=matrizActual->get_celda_px(_x,_y);

					} catch (ConexionException e) {

						agregadaModelo= false;

					}

					break;

					}

	case T_SALIDA:	{

					try {

						Posicion posicion(matrizActual->de_pixel_a_col(x),matrizActual->de_pixel_a_fila(y));
						std::string nom="";
						id= modeloCliente->agregarSalida(posicion,nom,sentido);
						agregadaVista= matrizActual->agregar_salida(&_x,&_y,id,sentido);
						celda=matrizActual->get_celda_px(_x,_y);

					} catch (ConexionException e) {

						agregadaModelo= false;

					}

				     break;

					}

	case T_PISTA: 	{break;}

	default:
					{

					try {

						Posicion posicion(matrizActual->de_pixel_a_col(x),matrizActual->de_pixel_a_fila(y));
						id= modeloCliente->agregarCompuerta(_tipo,posicion,sentido);

						agregadaVista= matrizActual->agregar_compuerta(&_x,&_y,_tipo,id,sentido);
						celda=matrizActual->get_celda_px(_x,_y);

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

	if(matrizActual->hay_componente(&_x,&_y,&_tipo)){

		if(_tipo != T_ENTRADA && _tipo != T_SALIDA){
			//Obtengo la celda padre la que representa la compuerta
			Celda* celda=matrizActual->get_celda_px(_x,_y);

			try {

				modeloCliente->rotar(celda->get_id(),IZQUIERDA);
				fachada_vista->dibujar_componente(_x,_y,T_VACIA,celda->get_sentido());
				celda->rotar_lef();
				fachada_vista->dibujar_componente(_x,_y,_tipo,celda->get_sentido());
			} catch (ConexionException e) {
				g_print("NO ROTO");//TODO
			}
		}

	}

}

void Controlador::rotar_right(int x,int y){


	int _x=x;
	int _y=y;
	TIPO_COMPUERTA _tipo;

	if(matrizActual->hay_componente(&_x,&_y,&_tipo)){

		if(_tipo != T_ENTRADA && _tipo != T_SALIDA){

			//Obtengo la celda padre la que representa la compuerta
			Celda* celda=matrizActual->get_celda_px(_x,_y);
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

}
/*----------------------------------------------------------------------------*/

void Controlador::eliminar_componente(int x,int y){

	int _x=x;
	int _y=y;
	TIPO_COMPUERTA _tipo;

	Celda* celda=matrizActual->get_celda_px(x,y);
	if(matrizActual->hay_componente(&_x,&_y,&_tipo) && celda){

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

		g_print("No hay circuito para guardar\n");

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
		modeloCliente->cambiarCircuitoActual(id);
		matrizActual= matrices[id];

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

	std::string nombre= "Circuito";
	Circuito* circuito= modeloCliente->recuperar(nombre);

	fachada_vista->agregar_grilla(circuito->getId());

	matrizActual= new Modelo_vista_circuito();
	matrices.insert(make_pair(circuito->getId(),matrizActual));

	generarCircuito(circuito);


}


void Controlador::simular(){

	try {

		Resultado* resultado=modeloCliente->simular();
		fachada_vista->completar_grilla(resultado);

	} catch (CircuitoException e) {

		g_print("No se pudo simular\n");

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

void Controlador::generarCircuito(Circuito* circuito) {

	std::vector<Compuerta*> compuertas= circuito->getCompuertas();

	for (unsigned int var = 0; var < compuertas.size(); ++var) {

		Compuerta* compuerta= compuertas[var];
		Posicion posicion= compuerta->getPosicion();

		int x= matrizActual->de_col_a_pixel(posicion.getX());
		int y= matrizActual->de_fila_a_pixel(posicion.getY());

		if (compuerta -> getEntrada()) {

			matrizActual->agregar_entrada(&x,&y,compuerta->getId(),compuerta->getSentido());


		}else if (compuerta -> getSalida()) {

			matrizActual->agregar_salida(&x,&y,compuerta->getId(),compuerta->getSentido());

		}else {

			if (compuerta->getTipo() == T_PISTA) {


			}else {

				matrizActual->agregar_compuerta(&x,&y,compuerta->getTipo(),compuerta->getId(),compuerta->getSentido());


			}

		}

		fachada_vista->dibujar_componente(x,y,compuerta->getTipo(),compuerta->getSentido());

	}
}
