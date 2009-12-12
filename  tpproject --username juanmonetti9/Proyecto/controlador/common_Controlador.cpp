/**************************   Clase Controlador         *************/
/**************************   	Grupo 8                 *************/
#include "common_Controlador.h"
#include "../excepciones/common_ConexionException.h"
#include "../excepciones/common_CircuitoException.h"
#include "../excepciones/common_PublicacionException.h"
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

		try {

			modeloCliente->enviar(fachada_vista->get_circuito_upload(),servidor);
			fachada_vista->mostrar_confirmacion("Circuito Enviado Exitosamente");
			fachada_vista->ocultar_upload();

		} catch (PublicacionException e) {

			fachada_vista->mostrar_error(e.getMensaje());

		}



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

	try{

		modeloCliente->obtenerCircuitosServidor(servidor, &circuitos);

		fachada_vista->mostrar_circuitos_servidor(&circuitos);

	}catch(PublicacionException e) {

		fachada_vista->mostrar_error(e.getMensaje());

	}

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
							agregadaVista= matrizActual->agregar_componente(&_x,&_y,_tipo,id,sentido);
							celda=matrizActual->get_celda_px(_x,_y);
							if(agregadaVista)
								this->agregar_accion(NULL);

						} catch (ConexionException e) {
							agregadaModelo= false;
						}
						break;
					}

	case T_PISTA:{

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

	 if(agregadaModelo && celda && agregadaVista){
		//Redibujo
		this->redibujar_circuito(modeloCliente->getCompuertas());

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
		agregadaVista=matrizActual->agregar_caja_negra(&_x,&_y,id,cant_entradas,cant_salidas);
		celda=matrizActual->get_celda_px(_x,_y);
		if(agregadaVista)
			this->agregar_accion(NULL);

	} catch (ConexionException e) {
		agregadaModelo= false;
	} catch (PublicacionException e) {

		agregadaModelo= false;
		fachada_vista->mostrar_error(e.getMensaje());

	}


	if(agregadaModelo && celda && agregadaVista){

		this->agregar_accion(NULL);
		//redibujo
		this->redibujar_circuito(modeloCliente->getCompuertas());

	}else if ((!agregadaVista) && (agregadaModelo)) {
		modeloCliente->eliminarCompuerta(id);
	}
}

void Controlador::mostrar_caja_negra(int x,int y) {

	Celda* aux=matrizActual->get_celda_px(x,y);

	if(aux->esta_ocupada()){

		Datos_celda* aux_datos = aux->get_datos();

		if (aux_datos->get_tipo() == T_CAJANEGRA) {

			int id= aux_datos->get_id();

			try {

				Circuito* circuito= modeloCliente->obtenerCircuitoServidor(id);

				fachada_vista->mostrar_Caja_negra();

				std::vector<Compuerta*> compuertas= circuito->getCompuertas();

				Compuerta* compuerta;
				for (unsigned int var = 0; var < compuertas.size(); ++var) {

					compuerta= compuertas[var];

					Posicion posicion= compuerta->getPosicion();

					int x= Modelo_vista_circuito::de_col_a_pixel(posicion.getX());
					int y= Modelo_vista_circuito::de_fila_a_pixel(posicion.getY());
					//Dibujo el componente
					if(compuerta->getTipo()== T_CAJANEGRA){

						fachada_vista->dibujar_caja_negra_CN(x,y,compuerta->getCantidadEntradas(),compuerta->getCantidadSalidas());

					}
					else

						fachada_vista->dibujar_componente_CN(x,y,compuerta->getTipo(),compuerta->getSentido());
				}

				std::vector<ConexionVertice> conexiones;
				circuito->getConexionVertice(&conexiones);

				std::vector<ConexionVertice>::const_iterator it_conexion = conexiones.begin();

				while( it_conexion != conexiones.end() ){

					int x_rd= Modelo_vista_circuito::de_col_a_pixel(it_conexion->getPosicion().getX());
					int y_rd= Modelo_vista_circuito::de_fila_a_pixel(it_conexion->getPosicion().getY());

					fachada_vista->dibujar_vertice_CN(x_rd,y_rd,it_conexion->getSentido());
					//incremento los iteradores
					++it_conexion;

				}

				delete circuito;


			} catch (PublicacionException e) {

				fachada_vista->mostrar_error(e.getMensaje());

			}



		}
	}


}

void Controlador::incluir_vertices(std::vector<ConexionVertice> conexiones){

	std::vector<ConexionVertice>::const_iterator it_conexion = conexiones.begin();

	while( it_conexion != conexiones.end() ){

		int x_rd= Modelo_vista_circuito::de_col_a_pixel(it_conexion->getPosicion().getX());
		int y_rd= Modelo_vista_circuito::de_fila_a_pixel(it_conexion->getPosicion().getY());

		fachada_vista->dibujar_vertice(x_rd,y_rd,it_conexion->getSentido());
		//incremento los iteradores
		++it_conexion;

	}
}

void Controlador::rotar(int x,int y,DIRECCION n_direccion){

	int _x=x;
	int _y=y;
	TIPO_COMPUERTA _tipo;



	if(matrizActual->hay_componente(&_x,&_y,&_tipo)){

		//Obtengo la celda padre la que representa la compuerta
		Celda* celda=matrizActual->get_celda_px(_x,_y);
		Datos_celda* aux_datos= celda->get_datos();
		Datos_celda datos=*aux_datos;

		if(_tipo == T_PISTA){


			if(celda->puede_rotar()){

				try {
					modeloCliente->rotar(datos.get_id(),n_direccion);
					celda->rotar(n_direccion);

				} catch (ConexionException e) {

					if (n_direccion == IZQUIERDA)
						modeloCliente->rotar(datos.get_id(),DERECHA);
					else
						modeloCliente->rotar(datos.get_id(),IZQUIERDA);
				}
			}

		}else if(_tipo == T_ENTRADA || _tipo == T_SALIDA){

			try {
				modeloCliente->rotar(datos.get_id(),n_direccion);
				//Elimino el componente de la vista
				int x_origen=Modelo_vista_circuito::de_col_a_pixel(celda->get_columna());
				int y_origen=Modelo_vista_circuito::de_col_a_pixel(celda->get_fila());
				//elimino el componente
				matrizActual->eliminar_componente(x_origen,y_origen);
				//lo intento agregar con el nuevo sentido
				SENTIDO nuevo_sentido=(n_direccion == IZQUIERDA)?(Celda::turn_left(datos.get_sentido())):(Celda::turn_right(datos.get_sentido()));
				bool rotado_vista = matrizActual->agregar_componente(&x_origen,&y_origen,datos.get_tipo(),datos.get_id(),nuevo_sentido);
				if(!rotado_vista){
					rotado_vista = matrizActual->agregar_componente(&x_origen,&y_origen,datos.get_tipo(),datos.get_id(),datos.get_sentido());
					if (n_direccion == IZQUIERDA)
						modeloCliente->rotar(datos.get_id(),DERECHA);
					else
						modeloCliente->rotar(datos.get_id(),IZQUIERDA);

				}
			} catch (ConexionException e) {

				if (n_direccion == IZQUIERDA)
					modeloCliente->rotar(datos.get_id(),DERECHA);
				else
					modeloCliente->rotar(datos.get_id(),IZQUIERDA);
			}

		}
		else if(_tipo != T_CAJANEGRA){


			try {
				modeloCliente->rotar(datos.get_id(),n_direccion);
				celda->rotar(n_direccion);

			} catch (ConexionException e) {

				if (n_direccion == IZQUIERDA)
					modeloCliente->rotar(datos.get_id(),DERECHA);
				else
					modeloCliente->rotar(datos.get_id(),IZQUIERDA);
			}
		}

		this->redibujar_circuito(modeloCliente->getCompuertas());
	}
}

/*----------------------------------------------------------------------------*/

void Controlador::arrastrar(gdouble x, gdouble y){

	//obtengo la celda origen
	Celda* celda_origen=matrizActual->get_celda_px(pos_x,pos_y);

	if(celda_origen->hay_secundario() || celda_origen->esta_ocupada()){

		Datos_celda* datos_origen_aux = (celda_origen->hay_secundario())?celda_origen->get_datos_secundarios():celda_origen->get_datos();
		//copio los datos del orgien
		Datos_celda datos_origen = *datos_origen_aux;
		//variables de posicion x e y para borrar el orige
		int x_origen = Modelo_vista_circuito::de_col_a_pixel(datos_origen.get_col_ppal());
		int y_origen = Modelo_vista_circuito::de_fila_a_pixel(datos_origen.get_fila_ppal());
		//variables usadas para identificar la posicion del destino
		int fila_destino = Modelo_vista_circuito::de_pixel_a_fila(y);
		int col_destino = Modelo_vista_circuito::de_pixel_a_col(x);
		int x_destino = x;
		int y_destino = y;

		//intento mover
		bool agregadoModelo= true;
		bool agregadoVista= true;

		try {
			Posicion posicion(col_destino,fila_destino);
			//muevo el componente en el modelo
			modeloCliente->mover(datos_origen.get_id(),posicion);
			//Elimino el componente de la vista
			Celda* ppal_origen=matrizActual->get_celda_px(x_origen,y_origen);
			ppal_origen->desocupar_componente(datos_origen.get_id());

			//lo intento agregar en la nueva posicion
			if(datos_origen.get_tipo() == T_CAJANEGRA)
				agregadoVista = matrizActual->agregar_caja_negra(&x_destino,&y_destino,datos_origen.get_id(),datos_origen.get_cant_entradas(),datos_origen.get_cant_salidas());
			else
				agregadoVista = matrizActual->agregar_componente(&x_destino,&y_destino,datos_origen.get_tipo(),datos_origen.get_id(),datos_origen.get_sentido());

		} catch (ConexionException e) {
			g_print("no se puede mover");
			agregadoModelo= false;
			Posicion posicion(datos_origen.get_col_ppal(),datos_origen.get_fila_ppal());
			modeloCliente->mover(datos_origen.get_id(),posicion);

		}

		if (!agregadoVista) {

			//lo intento agregar en la nueva posicion
			if(datos_origen.get_tipo() == T_CAJANEGRA)
				agregadoVista = matrizActual->agregar_caja_negra(&x_origen,&y_origen,datos_origen.get_id(),datos_origen.get_cant_entradas(),datos_origen.get_cant_salidas());
			else
				agregadoVista = matrizActual->agregar_componente(&x_origen,&y_origen,datos_origen.get_tipo(),datos_origen.get_id(),datos_origen.get_sentido());

			Posicion posicion(datos_origen.get_col_ppal(),datos_origen.get_fila_ppal());
			modeloCliente->mover(datos_origen.get_id(),posicion);
		}

		this->redibujar_circuito(modeloCliente->getCompuertas());
	}

}
/*----------------------------------------------------------------------------*/
void Controlador::eliminar_componente(int x,int y){


	Celda* aux=matrizActual->get_celda_px(x,y);

	if(aux->hay_secundario() || aux->esta_ocupada()){

		Datos_celda* aux_datos = (aux->hay_secundario())?aux->get_datos_secundarios():aux->get_datos();

		//variables con datos para eliminar
		/*SENTIDO sent= aux_datos->get_sentido();
		TIPO_COMPUERTA tipo = aux_datos->get_tipo();*/
		int id_eliminar= aux_datos->get_id();
		/*int entradas=aux_datos->get_cant_entradas();
		int salidas= aux_datos->get_cant_salidas();
*/
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
		/*if(tipo == T_CAJANEGRA)
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

		}*/

		this->redibujar_circuito(modeloCliente->getCompuertas());
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

		arrastre_activo=true;
	}
}

void Controlador::desconectar_drag_drop(){

	if(arrastre_activo){

		arrastre_activo=false;
	}
}

void Controlador::guardar(){

	try {

		modeloCliente->guardar();
		fachada_vista->mostrar_confirmacion("Circuito Guardado Exitosamente");

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

	if (nombre != "") {

		int id= modeloCliente->crearNuevo(nombre);
		matrizActual= new Modelo_vista_circuito();
		matrices.insert(make_pair(id,matrizActual));
		fachada_vista->agregar_grilla(id,nombre.c_str());

		fachada_vista->aceptar_nuevo();

	}
	//this->redibujar_circuito(modeloCliente->getCompuertas());

}

void Controlador::destruir_vista(){

	fachada_vista->delete_vista();

}

/*----------------------------------------------------------------------------*/

Controlador::~Controlador() {

	if(accion){
	//libero la memoria reservada por la accion actual
	delete(accion);
	}
	std::map<int,Modelo_vista_circuito*>::const_iterator  it;
	it= matrices.begin();
	while( it!= matrices.end()){
		delete((Modelo_vista_circuito*)it->second);
		++it; //incremento el iterador
	}


}

void Controlador::generarCircuito(Circuito* circuito) {

	std::vector<Compuerta*> compuertas= circuito->getCompuertas();

	std::vector<ConexionVertice> conexiones;

	for (unsigned int var = 0; var < compuertas.size(); ++var) {

		Compuerta* compuerta= compuertas[var];
		Posicion posicion= compuerta->getPosicion();


		int x= Modelo_vista_circuito::de_col_a_pixel(posicion.getX());
		int y= Modelo_vista_circuito::de_fila_a_pixel(posicion.getY());

		if(compuerta->getTipo()== T_CAJANEGRA){

			matrizActual->agregar_caja_negra(&x,&y,compuerta->getId(),compuerta->getCantidadEntradas(),compuerta->getCantidadSalidas());

		}else {

			matrizActual->agregar_componente(&x,&y,compuerta->getTipo(),compuerta->getId(),compuerta->getSentido());
		}

	}

	this->redibujar_circuito(compuertas);

}
void Controlador::redibujar_circuito(std::vector<Compuerta*> compuertas) {

	fachada_vista->limpiar_area_disenio();

	for (unsigned int var = 0; var < compuertas.size(); ++var) {

		Compuerta* compuerta= compuertas[var];
		Posicion posicion= compuerta->getPosicion();

		int x= Modelo_vista_circuito::de_col_a_pixel(posicion.getX());
		int y= Modelo_vista_circuito::de_fila_a_pixel(posicion.getY());
		//Dibujo el componente
		if(compuerta->getTipo()== T_CAJANEGRA){
			fachada_vista->dibujar_caja_negra(x,y,compuerta->getCantidadEntradas(),compuerta->getCantidadSalidas());
		}
		else
			fachada_vista->dibujar_componente(x,y,compuerta->getTipo(),compuerta->getSentido());


	}

	std::vector<ConexionVertice> conexiones;
	modeloCliente->getConexionVertice(&conexiones);
	incluir_vertices(conexiones);

}

