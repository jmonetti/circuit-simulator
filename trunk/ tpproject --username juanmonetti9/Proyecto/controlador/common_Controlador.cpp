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

	fachada_vista = fachada;
	accion = NULL;
	arrastre_activo = false;
	this->modeloCliente = modeloCliente;
	matrizActual = NULL;

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

		agregar_accion(new Accion_Draw_Caja_Negra(this));
		fachada_vista->ocultar_download();

	}


}

void Controlador::conectar() {

	std::string host= fachada_vista->get_host_download();
	int puerto= atoi(fachada_vista->get_puerto_download());
	Servidor servidor(host,puerto);

	std::vector<char*> circuitos;

	modeloCliente->obtenerCircuitosServidor(servidor, &circuitos);

	fachada_vista->mostrar_circuitos_servidor(&circuitos);

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
	std::vector<ConexionVertice> conexiones;

	switch(_tipo){

	case T_ENTRADA:	{
						try {
							Posicion posicion(Modelo_vista_circuito::de_pixel_a_col(x),Modelo_vista_circuito::de_pixel_a_fila(y));
							std::string nom= fachada_vista->get_nombre_entrada();
							id= modeloCliente->agregarEntrada(posicion,nom,sentido);
							modeloCliente->getConexionVertice(id,&conexiones);
							agregadaVista=matrizActual->agregar_componente(&_x,&_y,_tipo,id,sentido);
							celda=matrizActual->get_celda_px(_x,_y);
							if(agregadaVista){
								this->agregar_accion(NULL);
							}

						} catch (ConexionException e) {

							agregadaModelo= false;
						}
						break;
					}

	case T_SALIDA:	{

					try {

						Posicion posicion(Modelo_vista_circuito::de_pixel_a_col(x),Modelo_vista_circuito::de_pixel_a_fila(y));
						std::string nom= fachada_vista->get_nombre_salida();
						id= modeloCliente->agregarSalida(posicion,nom,sentido);
						modeloCliente->getConexionVertice(id,&conexiones);
						agregadaVista= matrizActual->agregar_componente(&_x,&_y,_tipo,id,sentido);
						celda=matrizActual->get_celda_px(_x,_y);
						if(agregadaVista)
							this->agregar_accion(NULL);

					} catch (ConexionException e) {

						agregadaModelo= false;

					}



				    break;

					}

	case T_PISTA: 	{

					try {

						Posicion posicion(Modelo_vista_circuito::de_pixel_a_col(x),Modelo_vista_circuito::de_pixel_a_fila(y));
						id= modeloCliente->agregarCompuerta(_tipo,posicion,sentido);
						modeloCliente->getConexionVertice(id,&conexiones);
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
				modeloCliente->getConexionVertice(id,&conexiones);
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

void Controlador::agregar_caja_negra(int x,int y){

	int _x=x;
	int _y=y;
	//variables que representaran si se pudo agregr en el modelo y la vista
	bool agregadaModelo= true;
	bool agregadaVista = false;
	//puntero a celda donde agrego e id del componente a agregar
	Celda* celda= NULL;
	int id;
	std::vector<ConexionVertice> conexiones;

	int cant_entradas;
	int cant_salidas;

	try {

		Posicion posicion(Modelo_vista_circuito::de_pixel_a_col(x),Modelo_vista_circuito::de_pixel_a_fila(y));
		std::string nom= fachada_vista->get_circuito_download();
		std::string host= fachada_vista->get_host_download();
		int puerto= atoi(fachada_vista->get_puerto_download());
		Servidor servidor(host,puerto);
		TamanioCajaNegra tamanio= modeloCliente->recibir(nom,servidor);
		cant_entradas= tamanio.getCantEntradas();
		cant_salidas= tamanio.getCantSalidas();
		id= modeloCliente->agregarCajaNegra(posicion,nom,ESTE,servidor,tamanio);
		modeloCliente->getConexionVertice(id,&conexiones);
		agregadaVista=matrizActual->agregar_caja_negra(&_x,&_y,id,cant_entradas,cant_salidas);
		celda=matrizActual->get_celda_px(_x,_y);
		if(agregadaVista)
			this->agregar_accion(NULL);

	} catch (ConexionException e) {

		agregadaModelo= false;
	}

	if(agregadaModelo && celda && agregadaVista){

		this->agregar_accion(NULL);
		fachada_vista->dibujar_caja_negra(_x,_y,cant_entradas,cant_salidas);

	}else if (!agregadaVista) {
		modeloCliente->eliminarCompuerta(id);
	}



}

void Controlador::rotar(int x,int y,DIRECCION n_direccion){

	int _x=x;
	int _y=y;
	TIPO_COMPUERTA _tipo;
	std::vector<ConexionVertice> conexiones;

	if(matrizActual->hay_componente(&_x,&_y,&_tipo)){

		if(_tipo == T_PISTA){

			//Obtengo la celda padre la que representa la compuerta
			Celda* celda=matrizActual->get_celda_px(_x,_y);
			Datos_celda* datos= celda->get_datos();

			if(celda->puede_rotar()){

				try {

					modeloCliente->rotar(datos->get_id(),n_direccion);
					modeloCliente->getConexionVertice(datos->get_id(),&conexiones);
					std::list<Posicion> vertices;
					std::list<SENTIDO>  sentidos;
					incluir_componentes_rdraw(vertices,sentidos,datos->get_fila_ppal(),datos->get_col_ppal(),datos->get_id());

					fachada_vista->borrar_componente(_x,_y,T_PISTA,datos->get_sentido());
					celda->rotar(n_direccion);
					fachada_vista->dibujar_componente(_x,_y,_tipo,datos->get_sentido());

					//redibujo los componentes debido a la superposicion
					std::list<Posicion>::const_iterator it_vertices = vertices.begin();
					std::list<SENTIDO>::const_iterator it_sentido = sentidos.begin();
					while( it_vertices != vertices.end() && it_sentido != sentidos.end()){

						int x_rd= Modelo_vista_circuito::de_col_a_pixel(it_vertices->getX());
						int y_rd= Modelo_vista_circuito::de_fila_a_pixel(it_vertices->getY());
						SENTIDO sent_r= *it_sentido;
						fachada_vista->dibujar_componente(x_rd,y_rd,T_PISTA,sent_r);
						//incremento los iteradores
						++it_vertices;
						++it_sentido;
					}


				} catch (ConexionException e) {

					if (n_direccion == IZQUIERDA) {

						modeloCliente->rotar(datos->get_id(),DERECHA);

					}
					if (n_direccion == DERECHA) {

						modeloCliente->rotar(datos->get_id(),IZQUIERDA);

					}

				}
			}

		}else if(_tipo != T_ENTRADA && _tipo != T_SALIDA && _tipo != T_CAJANEGRA){

			//Obtengo la celda padre la que representa la compuerta
			Celda* celda=matrizActual->get_celda_px(_x,_y);
			Datos_celda* datos= celda->get_datos();
			try {
				modeloCliente->rotar(datos->get_id(),n_direccion);
				modeloCliente->getConexionVertice(datos->get_id(),&conexiones);
				fachada_vista->dibujar_componente(_x,_y,T_VACIA,datos->get_sentido());
				celda->rotar(n_direccion);
				fachada_vista->dibujar_componente(_x,_y,_tipo,datos->get_sentido());


			} catch (ConexionException e) {

				if (n_direccion == IZQUIERDA) {

					modeloCliente->rotar(datos->get_id(),DERECHA);

				}
				if (n_direccion == DERECHA) {

					modeloCliente->rotar(datos->get_id(),IZQUIERDA);

				}

			}
		}


	}


}

/*----------------------------------------------------------------------------*/
void Controlador::arrastrar(gdouble x, gdouble y){



	//obtengo la celda origen
	Celda* celda_origen=matrizActual->get_celda_px(pos_x,pos_y);

	if(celda_origen->hay_secundario() || celda_origen->esta_ocupada()){

		Datos_celda* datos_origen = (celda_origen->hay_secundario())?celda_origen->get_datos_secundarios():celda_origen->get_datos();

		//variables usadas para identificar la posicion del destino
		int fila_destino = Modelo_vista_circuito::de_pixel_a_fila(y);
		int col_destino = Modelo_vista_circuito::de_pixel_a_col(x);
		int x_destino = x;
		int y_destino = y;

		//intento mover
		bool agregadoModelo= true;
		bool agregadoVista= true;
		std::vector<ConexionVertice> conexiones;

		try {
			Posicion posicion(col_destino,fila_destino);
			//muevo el componente en el modelo
			modeloCliente->mover(datos_origen->get_id(),posicion);
			modeloCliente->getConexionVertice(datos_origen->get_id(),&conexiones);
			//lo intento agregar en la nueva posicion
			if(datos_origen->get_tipo() == T_CAJANEGRA)
				agregadoVista = matrizActual->agregar_caja_negra(&x_destino,&y_destino,datos_origen->get_id(),datos_origen->get_cant_entradas(),datos_origen->get_cant_salidas());
			else
				agregadoVista = matrizActual->agregar_componente(&x_destino,&y_destino,datos_origen->get_tipo(),datos_origen->get_id(),datos_origen->get_sentido());

		} catch (ConexionException e) {

			agregadoModelo= false;
			Posicion posicion(datos_origen->get_col_ppal(),datos_origen->get_fila_ppal());
			modeloCliente->mover(datos_origen->get_id(),posicion);
		}

		if(agregadoVista && agregadoModelo){

			//obtengo la celda destino para intentar agregar la compuerta
			Celda* celda_destino=matrizActual->get_celda(fila_destino,col_destino);
			Datos_celda* datos_destino = (celda_destino->hay_secundario())?celda_destino->get_datos_secundarios():celda_destino->get_datos();

			//variables de posicion x e y para borrar el orige
			int x_origen = Modelo_vista_circuito::de_col_a_pixel(datos_origen->get_col_ppal());
			int y_origen = Modelo_vista_circuito::de_fila_a_pixel(datos_origen->get_fila_ppal());

			if(datos_origen->get_tipo() == T_CAJANEGRA){
				fachada_vista->borrar_caja_negra(x_origen,y_origen,datos_origen->get_cant_entradas(),datos_origen->get_cant_salidas());
				fachada_vista->dibujar_caja_negra(x_destino,y_destino,datos_destino->get_cant_entradas(),datos_destino->get_cant_salidas());
			}
			else{
				fachada_vista->borrar_componente(x_origen,y_origen,datos_origen->get_tipo(),datos_origen->get_sentido());
				fachada_vista->dibujar_componente(x_destino,y_destino,datos_origen->get_tipo(),datos_destino->get_sentido());
			}

			std::list<Posicion> vertices;
			std::list<SENTIDO>  sentidos;
			incluir_componentes_rdraw(vertices,sentidos,datos_origen->get_fila_ppal(),datos_origen->get_col_ppal(),datos_origen->get_id());

			matrizActual->eliminar_componente(x_origen,y_origen);
			//redibujo los componentes debido a la superposicion
			std::list<Posicion>::const_iterator it_vertices = vertices.begin();
			std::list<SENTIDO>::const_iterator it_sentido = sentidos.begin();
			while( it_vertices != vertices.end() && it_sentido != sentidos.end()){

				int x_rd= Modelo_vista_circuito::de_col_a_pixel(it_vertices->getX());
				int y_rd= Modelo_vista_circuito::de_fila_a_pixel(it_vertices->getY());
				SENTIDO sent_r= *it_sentido;
				fachada_vista->dibujar_componente(x_rd,y_rd,T_PISTA,sent_r);
				//incremento los iteradores
				++it_vertices;
				++it_sentido;
			}

		}else if (!agregadoVista) {

			Posicion posicion(datos_origen->get_col_ppal(),datos_origen->get_fila_ppal());
			modeloCliente->mover(datos_origen->get_id(),posicion);

		}

	}

}
/*----------------------------------------------------------------------------*/
void Controlador::eliminar_componente(int x,int y){


	Celda* aux=matrizActual->get_celda_px(x,y);

	if(aux->hay_secundario() || aux->esta_ocupada()){

		Datos_celda* aux_datos = (aux->hay_secundario())?aux->get_datos_secundarios():aux->get_datos();

		//variables con datos para eliminar
		SENTIDO sent= aux_datos->get_sentido();
		TIPO_COMPUERTA tipo = aux_datos->get_tipo();
		int id_eliminar= aux_datos->get_id();
		int entradas=aux_datos->get_cant_entradas();
		int salidas= aux_datos->get_cant_salidas();

		//variables x e y de posicion de la celda ppal
		int x_ppal = Modelo_vista_circuito::de_col_a_pixel(aux_datos->get_col_ppal());
		int y_ppal = Modelo_vista_circuito::de_fila_a_pixel(aux_datos->get_fila_ppal());

		//la elimino del modelo
		modeloCliente-> eliminarCompuerta(id_eliminar);

		std::list<Posicion> vertices;
		std::list<SENTIDO>  sentidos;
		incluir_componentes_rdraw(vertices,sentidos,aux_datos->get_fila_ppal(),aux_datos->get_col_ppal(),aux_datos->get_id());

		//elimino el componente de la vista
		matrizActual->eliminar_componente(x_ppal,y_ppal);
		//la borro
		if(tipo == T_CAJANEGRA)
			fachada_vista->borrar_caja_negra(x_ppal,y_ppal,entradas,salidas);
		else{
			fachada_vista->borrar_componente(x_ppal,y_ppal,tipo,sent);
			//redibujo los componentes debido a la superposicion
			std::list<Posicion>::const_iterator it_vertices = vertices.begin();
			std::list<SENTIDO>::const_iterator it_sentido = sentidos.begin();
			while( it_vertices != vertices.end() && it_sentido != sentidos.end()){

				int x_rd= Modelo_vista_circuito::de_col_a_pixel(it_vertices->getX());
				int y_rd= Modelo_vista_circuito::de_fila_a_pixel(it_vertices->getY());
				SENTIDO sent_r= *it_sentido;
				fachada_vista->dibujar_componente(x_rd,y_rd,T_PISTA,sent_r);
				//incremento los iteradores
				++it_vertices;
				++it_sentido;
			}

		}

	}

}

void Controlador::incluir_componentes_rdraw(std::list<Posicion> &vertices,std::list<SENTIDO>  &sentidos,unsigned fila,unsigned int colum,unsigned int id){

	Celda* aux= matrizActual->get_celda(fila,colum);
	Datos_celda* aux_datos = NULL;

	if(aux->hay_secundario()){
		if(aux->get_datos_secundarios()->get_id()==(int)id)
			aux_datos = aux->get_datos_secundarios();
	}
	else if(aux->get_datos()->get_id()== (int)id){
			aux_datos = aux->get_datos();
		}

	if(aux_datos){

		std::list<Celda*>::const_iterator it = aux_datos->get_entorno().begin();

		while( it!= aux_datos->get_entorno().end()){
			//obtengo la celda del entorno
			Celda* auxiliar= *it;
			//busco datos pos de comp a redibujar y la incluyo en la lista
			int fila_rdraw;
			int col_rdraw;
			if(auxiliar->hay_secundario()){
				if(auxiliar->get_datos_secundarios()->get_id() == (int)id){
					fila_rdraw = auxiliar->get_datos()->get_fila_ppal();
					col_rdraw = auxiliar->get_datos()->get_col_ppal();
					Posicion pos_rdraw(col_rdraw,fila_rdraw);
					vertices.push_front(pos_rdraw);
					sentidos.push_front(auxiliar->get_datos()->get_sentido());
				}
				else{
					fila_rdraw = auxiliar->get_datos_secundarios()->get_fila_ppal();
					col_rdraw = auxiliar->get_datos_secundarios()->get_col_ppal();
					Posicion pos_rdraw(col_rdraw,fila_rdraw);
					vertices.push_front(pos_rdraw);
					sentidos.push_front(auxiliar->get_datos_secundarios()->get_sentido());
				}
			}
			++it; //incremento el iterador
		}
		if(aux->hay_secundario()){
			Posicion pos_rdraw(aux->get_datos()->get_col_ppal(),aux->get_datos()->get_fila_ppal());
			vertices.push_front(pos_rdraw);
			sentidos.push_front(aux->get_datos()->get_sentido());
		}
	}

}
void Controlador::conectar_drag_drop(){

	if(!arrastre_activo){
		fachada_vista->activar_dnd();
		arrastre_activo=true;
	}
}

void Controlador::desconectar_drag_drop(){

	if(arrastre_activo){
		fachada_vista->desactivar_dnd();
		arrastre_activo=false;
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
		fachada_vista->agregar_grilla(modeloCliente->getId(),"");

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

	return arrastre_activo;

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

		fachada_vista-> set_nombre_grilla(circuito->getNombre().c_str());

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
	fachada_vista->agregar_grilla(id,nombre.c_str());

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

	std::vector<ConexionVertice> conexiones;

	for (unsigned int var = 0; var < compuertas.size(); ++var) {

		Compuerta* compuerta= compuertas[var];
		Posicion posicion= compuerta->getPosicion();

		modeloCliente->getConexionVertice(compuerta->getId(),&conexiones);

		int x= Modelo_vista_circuito::de_col_a_pixel(posicion.getX());
		int y= Modelo_vista_circuito::de_fila_a_pixel(posicion.getY());

		matrizActual->agregar_componente(&x,&y,compuerta->getTipo(),compuerta->getId(),compuerta->getSentido());


		fachada_vista->dibujar_componente(x,y,compuerta->getTipo(),compuerta->getSentido());

	}
}
