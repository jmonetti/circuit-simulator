/**************************   Clase Controlador Boton  **************/
/**************************   	Grupo 8                **************/

#include "common_Controladores_Circuito.h"
#include "stdlib.h"
#include "Acciones/common_Accion_Draw_XOR.h"
#include "Acciones/common_Accion_Draw_AND.h"
#include "Acciones/common_Accion_NULA.h"
#include "Acciones/common_Accion_Draw_NOT.h"
#include "Acciones/common_Accion_Draw_OR.h"
#include "Acciones/common_Accion_Borrar.h"
#include "Acciones/common_Accion_Drag_Drop.h"
#include "Acciones/common_Accion_invertir_left.h"
#include "Acciones/common_Accion_invertir_right.h"
#include "Acciones/common_Accion_Draw_pista.h"
#include "Acciones/common_Accion_new_entrada.h"
#include "Acciones/common_Accion_new_salida.h"




void Controlador_Circuito::crearVentanaDialogoServidor() {

	GtkWidget* cuadro= gtk_dialog_new();
	gtk_window_set_title (&GTK_DIALOG(cuadro)->window, "Servidor");

	GtkWidget* boton= gtk_button_new_with_label("Aceptar");
	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->action_area), boton,TRUE, TRUE, 0);
	gtk_widget_show(boton);

	boton= gtk_button_new_with_label("Cancelar");
	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->action_area), boton,TRUE, TRUE, 0);
	gtk_widget_show(boton);

    GtkWidget* label = gtk_label_new ("Host:");
    gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->vbox), label, TRUE, TRUE, 0);
    gtk_widget_show (label);


    GtkWidget* entry= gtk_entry_new();
    gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->vbox), entry, TRUE, TRUE, 0);
    gtk_widget_show(entry);

    label = gtk_label_new ("Puerto:");
    gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->vbox), label, TRUE, TRUE, 0);
    gtk_widget_show (label);



    entry= gtk_entry_new();
	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->vbox), entry, TRUE, TRUE, 0);
	gtk_widget_show(entry);


	gtk_widget_show(cuadro);
}

void Controlador_Circuito::crearVentanaDialogoPuertas(const char* titulo) {

	GtkWidget* cuadro= gtk_dialog_new();
	gtk_window_set_title (&GTK_DIALOG(cuadro)->window, titulo);

	GtkWidget* boton= gtk_button_new_with_label("Aceptar");
	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->action_area), boton,TRUE, TRUE, 0);
	gtk_widget_show(boton);

	boton= gtk_button_new_with_label("Cancelar");
	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->action_area), boton,TRUE, TRUE, 0);
	gtk_widget_show(boton);

	GtkWidget* combo= gtk_combo_new();

    GList *glist = NULL;

    char* texto[100];

    for (int var = 0; var < 100; ++var) {

    	texto[var]= new char[4];
    	sprintf(texto[var],"%d",var);
    	glist = g_list_append (glist, texto[var]);

	}

    gtk_combo_set_popdown_strings (GTK_COMBO (combo), glist);

    for (int var = 0; var < 100; ++var) {

        delete[] texto[var];

   	}


    g_list_free( glist );

    gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->vbox), combo, TRUE, TRUE, 0);
    gtk_widget_show(combo);

	gtk_widget_show(cuadro);


}

void Controlador_Circuito::callback_crear_Upload( GtkWidget *widget,gpointer callback_data ) {

	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->desconectar_drag_drop();
		controlador->mostrar_upload();
	}


}

void Controlador_Circuito::callback_Upload( GtkWidget *widget,gpointer callback_data ){

	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->desconectar_drag_drop();
		controlador->ejecutar_upload();
	}



}

void Controlador_Circuito::callback_crear_Download( GtkWidget *widget,gpointer callback_data ){

	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->desconectar_drag_drop();
		controlador->mostrar_download();
	}



}

void Controlador_Circuito::callback_conectar( GtkWidget *widget,gpointer callback_data ){

	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->desconectar_drag_drop();
		controlador->conectar();
	}



}


void Controlador_Circuito::callback_Download( GtkWidget *widget,gpointer callback_data ){

	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->desconectar_drag_drop();
		controlador->ejecutar_download();
	}

}


void Controlador_Circuito::callback_AND( GtkWidget *widget,gpointer callback_data ){

	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->desconectar_drag_drop();
		controlador->agregar_accion(new Accion_Draw_AND(controlador));
	}

}

void Controlador_Circuito::callback_OR( GtkWidget *widget,gpointer callback_data ){

	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->desconectar_drag_drop();
		controlador->agregar_accion(new Accion_OR(controlador));
	}


}

void Controlador_Circuito::callback_XOR( GtkWidget *widget,gpointer callback_data ){

	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->desconectar_drag_drop();
		controlador->agregar_accion(new Accion_Draw_XOR(controlador));
	}

}

void Controlador_Circuito::callback_NOT( GtkWidget *widget,gpointer callback_data ){

	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->desconectar_drag_drop();
		controlador->agregar_accion(new Accion_NOT(controlador));
	}

}

void Controlador_Circuito::callback_Selector( GtkWidget *widget,gpointer callback_data ){

	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->conectar_drag_drop();
		controlador->agregar_accion(new Accion_Drag_Drop(controlador));
	}

}

void Controlador_Circuito::callback_Pista( GtkWidget *widget,gpointer callback_data ){


	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->desconectar_drag_drop();
		g_print("Call_back pista\n");//TODO
		controlador->agregar_accion(new Accion_Draw_pista(controlador));
	}

}

void Controlador_Circuito::callback_Simulacion( GtkWidget *widget,gpointer callback_data ){

	//TODO
	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->desconectar_drag_drop();
		controlador->simular();
	}

}

void Controlador_Circuito::callback_Delete( GtkWidget *widget,gpointer callback_data ){

	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->desconectar_drag_drop();
		controlador->agregar_accion(new Accion_Borrar(controlador));
	}

}

void Controlador_Circuito::callback_crear_entrada(GtkWidget *widget,gpointer callback_data ) {

	Controlador* controlador=Controlador::get_instancia();

	if(controlador){

		controlador->desconectar_drag_drop();
		controlador->crear_entrada();

	}


}

void Controlador_Circuito::callback_Entrada(GtkWidget *widget,gpointer callback_data ){

	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->desconectar_drag_drop();
		controlador->agregar_accion(new Accion_new_entrada(controlador));
	}

}

void Controlador_Circuito::callback_crear_salida(GtkWidget *widget,gpointer callback_data ) {

	Controlador* controlador=Controlador::get_instancia();

	if(controlador){

		controlador->desconectar_drag_drop();
		controlador->crear_salida();

	}


}


void Controlador_Circuito::callback_Salida(GtkWidget *widget,gpointer callback_data ){

	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->desconectar_drag_drop();
		controlador->agregar_accion(new Accion_new_salida(controlador));
	}

}


void Controlador_Circuito::callback_InvertirL( GtkWidget *widget,gpointer callback_data ){

	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->desconectar_drag_drop();
		controlador->agregar_accion(new Accion_invertir_left(controlador));
	}
}

void Controlador_Circuito::callback_InvertirR( GtkWidget *widget,gpointer callback_data ){


	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->desconectar_drag_drop();
		controlador->agregar_accion(new Accion_invertir_right(controlador));
	}
}

/*----------------------------------------------------------------------------*/

gint Controlador_Circuito::button_press_event (GtkWidget *widget, GdkEventButton *event){

  if (event->button == 1 ){
	  // si es el boton izq del raton
	  Controlador* controlador=Controlador::get_instancia();
	  int x1=event->x;
	  int y1=event->y;
	  if(controlador)
		  controlador->ejecutar_accion(x1,y1);

  }

  return true;
}

/*----------------------------------------------------------------------------*/

gboolean Controlador_Circuito::drag_drop_handl(GtkWidget *widget, GdkDragContext *context, gint x, gint y, guint time,gpointer user_data){


	 // si es el boton izq del raton
	 Controlador* controlador=Controlador::get_instancia();

	 if(controlador)
		 if(controlador->get_arrastre_activo())
			 controlador->arrastrar(x,y);
    return  true;
}


