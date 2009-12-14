/**************************   Clase Box_Ventana_Interna   *********************/
/**************************   Grupo 8                     *********************/

#include "common_Box_Ventana_Interna.h"
#include "../controlador/common_Controladores_Archivo.h"

Box_Ventana_Interna::Box_Ventana_Interna(){

	//Creo el box de la ventana
	_box_ventana= gtk_hbox_new(false,0);
	gtk_container_border_width (GTK_CONTAINER (_box_ventana), 10);
	//Creo la notebook y la incluyo en la caja
	noteb= gtk_notebook_new();
	gtk_notebook_set_tab_pos((GtkNotebook*)noteb,GTK_POS_RIGHT);

	//conecto la senial de cambio de pestania
	gtk_signal_connect (GTK_OBJECT (noteb), "switch-page",
							  (GtkSignalFunc)Controlador_Archivo::callback_cambiar_pestania, NULL);
	gtk_container_add (GTK_CONTAINER (_box_ventana),noteb);
	actual= NULL;

}
/*----------------------------------------------------------------------------*/

int Box_Ventana_Interna::getGrillaActual() const {

	return actual->getId();

}

void Box_Ventana_Interna::agregar_grilla(int id,const char* nombre){


	Grilla* nueva_grilla=new Grilla(id);
	_grillas.push_back(nueva_grilla);
	nueva_grilla->show();
	GtkWidget* label_grilla= gtk_label_new (nombre);
	gtk_notebook_append_page(GTK_NOTEBOOK (noteb),nueva_grilla->getWidget(),label_grilla);
	gtk_notebook_set_current_page(GTK_NOTEBOOK (noteb),_grillas.size()-1);
	actual=nueva_grilla;

}

void Box_Ventana_Interna::limpiar_area(){

	actual->limpiar_area();

}



void Box_Ventana_Interna::set_nombre_grilla(const char* nombre) {

	int page_num= gtk_notebook_get_current_page(GTK_NOTEBOOK(noteb));

	GtkWidget* page= gtk_notebook_get_nth_page(GTK_NOTEBOOK(noteb),page_num);

	gtk_notebook_set_tab_label_text (GTK_NOTEBOOK(noteb),page,nombre);

}

void Box_Ventana_Interna::eliminar_grilla_actual(){

	gint page_num =gtk_notebook_get_current_page(GTK_NOTEBOOK(noteb));
	eliminarGrilla(page_num);
	gtk_notebook_remove_page(GTK_NOTEBOOK(noteb), page_num);

	page_num =gtk_notebook_get_current_page(GTK_NOTEBOOK(noteb));

	if (page_num >= 0) {

		actual= _grillas[page_num];

	}else {

		actual= NULL;
	}


}

int Box_Ventana_Interna::cambiar_grilla_actual(int index){

	actual = _grillas[index];

	return actual->getId();

}


void Box_Ventana_Interna::completar_tabla_actual(Resultado* resultado){

	if (actual) {

		actual->completar_tabla(resultado);

	}

}

/*----------------------------------------------------------------------------*/

void Box_Ventana_Interna::show(){

    gtk_widget_show (_box_ventana);
    gtk_widget_show (noteb);

}
/*----------------------------------------------------------------------------*/

void Box_Ventana_Interna::escalar(int _fa){

}

void Box_Ventana_Interna::dibujar_caja_negra(gdouble x,gdouble y,int cant_entradas,int cant_salidas){

	actual->draw_CAJANEGRA(x,y,cant_entradas,cant_salidas);
}

void Box_Ventana_Interna::dibujar_componente(gdouble x,gdouble y,TIPO_COMPUERTA tipo,SENTIDO sentido,int tam_pista){

	switch(tipo){

		case T_XOR:	{
					actual->draw_XOR(x,y,sentido);
					break;
		}
		case T_AND:	{
					actual->draw_AND(x,y,sentido);
					break;
		}
		case T_NOT:	{
					actual->draw_NOT(x,y,sentido);
					break;
		}
		case T_OR: {
					actual->draw_OR(x,y,sentido);
					break;
		}
		case T_VACIA:{

					break;
		}
		case T_ENTRADA:{
					actual->draw_entrada(x,y,sentido);
					break;
		}
		case T_PISTA:{
					actual->draw_pista(x,y,sentido,tam_pista);
					break;
		}
		case T_SALIDA:{
					actual->draw_salida(x,y,sentido);
					break;
		}
		case T_CAJANEGRA:{
					break;
		}


	}

}

void Box_Ventana_Interna::dibujar_vertice(gdouble x,gdouble y,SENTIDO sentido){

	actual->draw_vertice(x,y,sentido);
}

/*----------------------------------------------------------------------------*/

GtkWidget* Box_Ventana_Interna::getWidget(){
	return _box_ventana;
}
/*----------------------------------------------------------------------------*/

Box_Ventana_Interna::~Box_Ventana_Interna(){

	std::vector<Grilla*>::iterator iterador= _grillas.begin();

	while( iterador != _grillas.end()) {

		delete *iterador;

		++iterador;

	}

}

void Box_Ventana_Interna::eliminarGrilla(int index) {

	std::vector<Grilla*>::iterator iterador= _grillas.begin();
	int i= 0;

	while ( iterador != _grillas.end() ) {

		if (i == index) {

			delete *iterador;
			_grillas.erase(iterador);
			break;

		}else {
			++i;
			++iterador;

		}
	}

}


