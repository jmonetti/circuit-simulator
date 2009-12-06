/**************************   Clase Controlador         *************/
/**************************   	Grupo 8                 *************/
#include "common_Controlador.h"
#include "../excepciones/common_ConexionException.h"
#include "../excepciones/common_CircuitoException.h"
#include "../modelo/simulacion/common_Resultado.h"
#include "Acciones/common_Accion_Draw_Caja_Negra.h"
#include <string>
#include <stdlib.h>

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
/*----------------------------------------------------------------------------*/

void Controlador::ejecutar_accion(gdouble x,gdouble y){

	if(accion) {
		accion->ejecutar(x,y);
	}
}
/*----------------------------------------------------------------------------*/

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

void Controlador::mostrar_upload() {

	if (!fachada_vista->upload_activo()) {

		fachada_vista->mostrar_ventana_upload(modeloCliente->obtenerCircuitosGuardados());

	}


}

void Controlador::ejecutar_upload() {

	if (fachada_vista->get_circuito_upload()) {

		std::string host= fachada_vista->get_host_upload();
		int puerto= atoi(fachada_vista->get_puerto_upload());

		Servidor servidor(host,puerto);

		modeloCliente->enviar(fachada_vista->get_circuito_upload(),servidor);

		fachada_vista->ocultar_upload();

	}


}

void Controlador::mostrar_download() {

	if (modeloCliente->hayCircuito()) {

		if (!fachada_vista->download_activo()) {

			fachada_vista->mostrar_ventana_download();

		}

	}

}

void Controlador::ejecutar_download() {

	if (fachada_vista->get_circuito_download()) {

		accion= new Accion_Draw_Caja_Negra(this);
		fachada_vista->ocultar_download();

	}


}

void Controlador::conectar() {

	std::string host= fachada_vista->get_host_download();
	int puerto= atoi(fachada_vista->get_puerto_download());
	Servidor servidor(host,puerto);

	std::vector<char*>* circuitos= modeloCliente->obtenerCircuitosServidor(servidor);

	fachada_vista->mostrar_circuitos_servidor(circuitos);

}

/*----------------------------------------------------------------------------*/

void Controlador::agregar_componente(int x,int y,TIPO_COMPUERTA _tipo,SENTIDO sentido){

	int _x=x;
	int _y=y;
	//variables que representaran si se pudo agregr en el modelo y la vista
	bool agregadaModelo= true;
	bool agregadaVista = false;
	//puntero a celda donde agrego e id del componente a agregar
	Celda* celda= NULL;
	int id;

	switch(_tipo){

	case T_ENTRADA:	{
						try {
							Posicion posicion(Modelo_vista_circuito::de_pixel_a_col(x),Modelo_vista_circuito::de_pixel_a_fila(y));
							std::string nom= fachada_vista->get_nombre_entrada();
							id= modeloCliente->agregarEntrada(posicion,nom,sentido);
							agregadaVista=matrizActual->agregar_componente(&_x,&_y,_tipo,id,sentido);
							celda=matrizActual->get_celda_px(_x,_y);

						} catch (ConexionException e) {

							agregadaModelo= false;
						}
						accion= new Accion_NULA(this);
						break;
					}

	case T_SALIDA:	{

					try {

						Posicion posicion(Modelo_vista_circuito::de_pixel_a_col(x),Modelo_vista_circuito::de_pixel_a_fila(y));
						std::string nom= fachada_vista->get_nombre_salida();
						id= modeloCliente->agregarSalida(posicion,nom,sentido);
						agregadaVista= matrizActual->agregar_componente(&_x,&_y,_tipo,id,sentido);
						celda=matrizActual->get_celda_px(_x,_y);

					} catch (ConexionException e) {

						agregadaModelo= false;

					}

					accion= new Accion_NULA(this);

				    break;

					}

	case T_CAJANEGRA:	{

					try {

						Posicion posicion(Modelo_vista_circuito::de_pixel_a_col(x),Modelo_vista_circuito::de_pixel_a_fila(y));
						std::string nombre= fachada_vista->get_circuito_download();
						std::string host= fachada_vista->get_host_download();
						int puerto= atoi(fachada_vista->get_puerto_download());
						Servidor servidor(host,puerto);
						int id= modeloCliente->recibir(nombre,servidor); //TODO
						//TODO integrar con modelo... hardcodear para poder dibujar, vas a tener q hacer un agregar caja negra
								//porque le tenes que pasar la cantidad de entradas y salidas
						agregadaVista= matrizActual->agregar_componente(&_x,&_y,_tipo,id,sentido);
						celda=matrizActual->get_celda_px(_x,_y);

					} catch (ConexionException e) {

						agregadaModelo= false;

					}

					accion= new Accion_NULA(this);

				    break;

					}


	case T_PISTA: 	{

					try {

						g_print("Por agregar componente\n");//TODO
						Posicion posicion(Modelo_vista_circuito::de_pixel_a_col(x),Modelo_vista_circuito::de_pixel_a_fila(y));
						id= modeloCliente->agregarCompuerta(_tipo,posicion,sentido);
						g_print("Agrege en modelo\n");//TODO
						agregadaVista= matrizActual->agregar_componente(&_x,&_y,_tipo,id,sentido);
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

				Posicion posicion(Modelo_vista_circuito::de_pixel_a_col(x),Modelo_vista_circuito::de_pixel_a_fila(y));
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

		if(celda->hay_secundario()){
			//como hay pista secundaria, obtengo sus datos
			Datos_celda* datos_secundario = celda->get_datos_secundarios();
			//obtengo la celda principal de la pista
			Celda* aux_celda= matrizActual->get_celda(datos_secundario->get_fila_ppal(),datos_secundario->get_col_ppal());
			//obtengo los datos del componente de la celda principal
			Datos_celda* datos = aux_celda->get_datos();
			//obtengo los datos de la celda principal
			if( id == datos->get_id()){

				fachada_vista->dibujar_componente(Modelo_vista_circuito::de_col_a_pixel(aux_celda->get_columna()),Modelo_vista_circuito::de_fila_a_pixel(aux_celda->get_fila()),_tipo,datos->get_sentido());

			}
			else{
				Datos_celda* datos_sec = aux_celda->get_datos_secundarios();
				fachada_vista->dibujar_componente(Modelo_vista_circuito::de_col_a_pixel(aux_celda->get_columna()),Modelo_vista_circuito::de_fila_a_pixel(aux_celda->get_fila()),_tipo,datos_sec->get_sentido());

			}



		}else
			fachada_vista->dibujar_componente(_x,_y,_tipo,celda->get_datos()->get_sentido());

	}
	else if(agregadaModelo && celda && agregadaVista){

		fachada_vista->dibujar_componente(_x,_y,_tipo,celda->get_datos()->get_sentido());

	}else if (!agregadaVista) {

		modeloCliente->eliminarCompuerta(id);
	}

}

void Controlador::rotar(int x,int y,DIRECCION n_direccion){

	int _x=x;
	int _y=y;
	TIPO_COMPUERTA _tipo;

	if(matrizActual->hay_componente(&_x,&_y,&_tipo)){

		if(_tipo == T_PISTA){

			//Obtengo la celda padre la que representa la compuerta
			Celda* celda=matrizActual->get_celda_px(_x,_y);
			Datos_celda* datos= celda->get_datos();

			if(celda->puede_rotar()){

				try {

					modeloCliente->rotar(datos->get_id(),n_direccion);
					fachada_vista->borrar_componente(_x,_y,T_PISTA,datos->get_sentido());
					celda->rotar(n_direccion);
					fachada_vista->dibujar_componente(_x,_y,_tipo,datos->get_sentido());

				} catch (ConexionException e) {
					g_print("NO ROTO");//TODO
				}
			}

		}else if(_tipo != T_ENTRADA && _tipo != T_SALIDA && _tipo != T_CAJANEGRA){

			//Obtengo la celda padre la que representa la compuerta
			Celda* celda=matrizActual->get_celda_px(_x,_y);
			Datos_celda* datos= celda->get_datos();
			try {
				modeloCliente->rotar(datos->get_id(),n_direccion);
				fachada_vista->dibujar_componente(_x,_y,T_VACIA,datos->get_sentido());
				celda->rotar(n_direccion);
				fachada_vista->dibujar_componente(_x,_y,_tipo,datos->get_sentido());

			} catch (ConexionException e) {
				g_print("NO ROTO");//TODO
			}
		}


	}


}

/*----------------------------------------------------------------------------*/
void Controlador::arrastrar(gdouble x, gdouble y){

	int _x=x;
	int _y=y;
	int _pos_x=pos_x;
	int _pos_y=pos_y;
	TIPO_COMPUERTA _tipo;

	if(matrizActual->hay_componente(&_pos_x,&_pos_y,&_tipo)){

		//obtengo la celda origen para obtener el sentido
		Celda* celda_origen=matrizActual->get_celda_px(_pos_x,_pos_y);
		Datos_celda* datos_origen=celda_origen->get_datos();

		//intento agregar la compuerta en la celda destino

		bool agregadoModelo= true;
		bool agregadoVista= true;

		try {
			Posicion posicion(Modelo_vista_circuito::de_pixel_a_col(_x),Modelo_vista_circuito::de_pixel_a_fila(_y));
			modeloCliente->mover(datos_origen->get_id(),posicion);
			agregadoVista = matrizActual->agregar_componente(&_x,&_y,_tipo,datos_origen->get_id(),datos_origen->get_sentido());

		} catch (ConexionException e) {

			agregadoModelo= false;
		}

		if(agregadoVista && agregadoModelo){

			//obtengo la celda destino para intentar agregar la compuerta
			Celda* celda_destino=matrizActual->get_celda_px(_x,_y);
			Datos_celda* datos_destino = celda_destino->get_datos();

			fachada_vista->borrar_componente(_pos_x,_pos_y,_tipo,datos_origen->get_sentido());
			fachada_vista->dibujar_componente(_x, _y,_tipo,datos_destino->get_sentido());
			matrizActual->eliminar_componente(_pos_x,_pos_y);

		}else if (!agregadoVista) {

			Posicion posicion(Modelo_vista_circuito::de_pixel_a_col(_pos_x),Modelo_vista_circuito::de_pixel_a_fila(_pos_y));
			modeloCliente->mover(datos_origen->get_id(),posicion);

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
		Datos_celda* datos = celda->get_datos();
		SENTIDO sent=datos->get_sentido();
		modeloCliente-> eliminarCompuerta(datos->get_id());
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
		fachada_vista->mostrar_confirmacion_guardar();

	} catch (CircuitoException e) {

		fachada_vista->mostrar_error(e.getMensaje());

	}

}

void Controlador::crear_circuito(){

	fachada_vista->mostrar_ventana_nuevo();

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

		fachada_vista->mostrar_ventana_abrir(modeloCliente->obtenerCircuitosGuardados());
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

void Controlador::crear_entrada() {

	if (modeloCliente->hayCircuito()) {

		fachada_vista->mostrar_ventana_entrada();

	}

}

void Controlador::crear_salida() {

	if (modeloCliente->hayCircuito()) {

		fachada_vista->mostrar_ventana_salida();

	}

}


void Controlador::aceptar_abrir() {

	if (fachada_vista->getCircuitoAbrir()) {

		std::string nombreCircuito(fachada_vista->getCircuitoAbrir());

		Circuito* circuito= modeloCliente->recuperar(nombreCircuito);

		matrizActual= new Modelo_vista_circuito();
		matrices.insert(make_pair(circuito->getId(),matrizActual));

		generarCircuito(circuito);

		fachada_vista->ocultar_abrir();

	}

}

void Controlador::cancelar_abrir() {

	fachada_vista->ocultar_abrir();

	fachada_vista->eliminar_grilla();

}

void Controlador::aceptar_nuevo() {

	std::string nombre(fachada_vista->getNombreNuevo());
	int id= modeloCliente->crearNuevo(nombre);
	matrizActual= new Modelo_vista_circuito();
	matrices.insert(make_pair(id,matrizActual));
	fachada_vista->agregar_grilla(id);

	fachada_vista->aceptar_nuevo();

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

		int x= Modelo_vista_circuito::de_col_a_pixel(posicion.getX());
		int y= Modelo_vista_circuito::de_fila_a_pixel(posicion.getY());

		matrizActual->agregar_componente(&x,&y,compuerta->getTipo(),compuerta->getId(),compuerta->getSentido());


		fachada_vista->dibujar_componente(x,y,compuerta->getTipo(),compuerta->getSentido());

	}
}
