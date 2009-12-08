/**************************   Clase Fachada_Vista      ************************/
/**************************   Grupo 8                  ************************/

#include "common_Fachada_vista.h"

Fachada_vista::Fachada_vista(Box_Ventana_Interna* ventana_int) {

	ventana_interna=ventana_int;
}


void Fachada_vista::dibujar_componente(gdouble x,gdouble y,TIPO_COMPUERTA tipo,SENTIDO sentido,int tam_pista){

	ventana_interna->dibujar_componente(x,y,tipo,sentido,tam_pista);
};

void Fachada_vista::dibujar_caja_negra(gdouble x,gdouble y,int cant_entradas,int cant_salidas){

	ventana_interna->dibujar_caja_negra(x,y,cant_entradas,cant_salidas);
}

void Fachada_vista::borrar_caja_negra(gdouble x,gdouble y,int cant_entradas,int cant_salidas){

	ventana_interna->borrar_caja_negra(x,y,cant_entradas,cant_salidas);
}

void Fachada_vista::borrar_pista(int _x,int _y,SENTIDO _sentido){

	ventana_interna->borrar_pista(_x,_y,_sentido);
}


void Fachada_vista::borrar_componente(gdouble x,gdouble y,TIPO_COMPUERTA tipo,SENTIDO sentido,int tam_pista){

	ventana_interna->borrar_componente(x,y,tipo,sentido,tam_pista);
}

void Fachada_vista::activar_dnd(){

	ventana_interna->connect_dnd();
}

void Fachada_vista::completar_grilla(Resultado* resultado){

	ventana_interna->completar_tabla_actual(resultado);


}

void Fachada_vista::agregar_grilla(int id,const char* nombre){

	ventana_interna->agregar_grilla(id,nombre);

}

void Fachada_vista::set_nombre_grilla(const char* nombre) {

	ventana_interna->set_nombre_grilla(nombre);

}

int Fachada_vista::cambiar_grilla(int index){

	return ventana_interna->cambiar_grilla_actual(index);

}

void Fachada_vista::eliminar_grilla(){

	ventana_interna->eliminar_grilla_actual();

}

void Fachada_vista::desactivar_dnd(){

	ventana_interna->disconnect_dnd();

}

int Fachada_vista::getIdActual() const{

	return ventana_interna->getGrillaActual();

}

void Fachada_vista::mostrar_ventana_upload(std::vector<char*>* circuitos) {

	ventana_upload.mostrarCircuitos(circuitos);

	ventana_upload.show();

}

bool Fachada_vista::upload_activo() {

	return ventana_upload.estaActiva();

}

char* Fachada_vista::get_circuito_upload() {

	return ventana_upload.getCircuitoUpload();

}

void Fachada_vista::ocultar_upload() {

	ventana_upload.hide();

}

const char* Fachada_vista::get_host_upload() {

	return ventana_upload.getHost();

}

const char* Fachada_vista::get_puerto_upload() {

	return ventana_upload.getPuerto();

}


void Fachada_vista::mostrar_ventana_download() {

	ventana_download.show();

}

bool Fachada_vista::download_activo() {

	return ventana_download.estaActiva();

}

char* Fachada_vista::get_circuito_download() {

	return ventana_download.getCircuitoDownload();

}

void Fachada_vista::ocultar_download() {

	ventana_download.hide();

}

const char* Fachada_vista::get_host_download() {

	return ventana_download.getHost();

}

const char* Fachada_vista::get_puerto_download() {

	return ventana_download.getPuerto();

}

void Fachada_vista::mostrar_circuitos_servidor(std::vector<char*>* circuitos) {

	ventana_download.mostrarCircuitos(circuitos);

}



void Fachada_vista::mostrar_ventana_entrada() {

	ventana_entrada.show();

}

void Fachada_vista::mostrar_ventana_salida() {

	ventana_salida.show();

}

const char* Fachada_vista::get_nombre_entrada() {

	return ventana_entrada.getNombre();

}

const char* Fachada_vista::get_nombre_salida() {

	return ventana_salida.getNombre();

}

void Fachada_vista::mostrar_error(const std::string &texto) {

	ventana_error.mostrarError(texto);

	ventana_error.show();

}

void Fachada_vista::mostrar_ventana_abrir(std::vector<char*>* circuitos) {

	ventana_abrir.mostrarCircuitos(circuitos);

	ventana_abrir.show();

}

void Fachada_vista::ocultar_abrir() {

	ventana_abrir.hide();

}

bool Fachada_vista::abriendo() {

	return ventana_abrir.estaActiva();

}

void Fachada_vista::mostrar_ventana_nuevo() {

	ventana_nuevo.show();

}

void Fachada_vista::aceptar_nuevo() {

	ventana_nuevo.hide();

}

char* Fachada_vista::getCircuitoAbrir() {

	return ventana_abrir.getCircuitoAbrir();

}

const char* Fachada_vista::getNombreNuevo() {

	return ventana_nuevo.getNombre();

}

void Fachada_vista::mostrar_confirmacion_guardar() {

	ventana_guardar.show();

}
