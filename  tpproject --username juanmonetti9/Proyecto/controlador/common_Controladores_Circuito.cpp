/**************************   Clase Controlador Boton  **************/
/**************************   	Grupo 8                **************/

#include "common_Controladores_Circuito.h"
#include "stdlib.h"
#include "Acciones/common_Accion_Draw_XOR.h"
#include "Acciones/common_Accion_Draw_AND.h"



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
    gtk_widget_show(label);


    GtkWidget* entry= gtk_entry_new();
    gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->vbox), entry, TRUE, TRUE, 0);
    gtk_widget_show(entry);

    label = gtk_label_new ("Puerto:");
    gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->vbox), label, TRUE, TRUE, 0);
    gtk_widget_show (label);
    gtk_widget_show(label);


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

void Controlador_Circuito::callback_Upload( GtkWidget *widget,gpointer callback_data ){
	//TODO
	g_print("Apretado el Upload\n");
	//fin TODO

	crearVentanaDialogoServidor();

}

void Controlador_Circuito::callback_Download( GtkWidget *widget,gpointer callback_data ){
	//TODO
	g_print("Apretado el download\n");
	//fin TODO

	crearVentanaDialogoServidor();

}


void Controlador_Circuito::callback_AND( GtkWidget *widget,gpointer callback_data ){

	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->agregar_accion(new Accion_Draw_AND(controlador));
	}
	//crearVentanaDialogoPuertas("AND");

}

void Controlador_Circuito::callback_OR( GtkWidget *widget,gpointer callback_data ){
	//TODO
	g_print("Apretado el OR\n");
	//fin TODO

	crearVentanaDialogoPuertas("OR");

}

void Controlador_Circuito::callback_XOR( GtkWidget *widget,gpointer callback_data ){

	Controlador* controlador=Controlador::get_instancia();

	if(controlador){
		controlador->agregar_accion(new Accion_Draw_XOR(controlador));
	}

	//crearVentanaDialogoPuertas("XOR");

}

void Controlador_Circuito::callback_NOT( GtkWidget *widget,gpointer callback_data ){
	//TODO
	g_print("Apretado el NOT\n");
	//fin TODO

	crearVentanaDialogoPuertas("NOT");
}

void Controlador_Circuito::callback_Selector( GtkWidget *widget,gpointer callback_data ){
	//TODO
	g_print("Apretado el Selector\n");
	//fin TODO
}

void Controlador_Circuito::callback_Pista( GtkWidget *widget,gpointer callback_data ){
	//TODO
	g_print("Apretado el Pista\n");
	//fin TODO
}

void Controlador_Circuito::callback_Simulacion( GtkWidget *widget,gpointer callback_data ){
	//TODO
	g_print("Apretado el Simulacion\n");
	//fin TODO
}

void Controlador_Circuito::callback_Delete( GtkWidget *widget,gpointer callback_data ){
	//TODO
	g_print("Apretado el Delete\n");
	//fin TODO
}

void Controlador_Circuito::callback_InvertirL( GtkWidget *widget,gpointer callback_data ){
	//TODO
	g_print("Apretado el Invertir Left\n");
	//fin TODO
}

void Controlador_Circuito::callback_InvertirR( GtkWidget *widget,gpointer callback_data ){
	//TODO
	g_print("Apretado el Invertir Right\n");
	//fin TODO
}


/*----------------------------------------------------------------------------*/

gint Controlador_Circuito::button_press_event (GtkWidget *widget, GdkEventButton *event){

  if (event->button == 1 ){
	  // si es el boton izq del raton
	  Controlador* controlador=Controlador::get_instancia();

	  if(controlador)
		  controlador->ejecutar_accion(event->x,event->y);

  }
 /* if (event->button == 3 ){
	  pos_x=event->x;
	  pos_y=event->y;

	  g_print ("Presiono el boton en (%d,%d)\n",pos_x,pos_y);
  }*/
  return true;
}

/*----------------------------------------------------------------------------*/

gboolean Controlador_Circuito::drag_drop_handl(GtkWidget *widget, GdkDragContext *context, gint x, gint y, guint time,gpointer user_data){

	//TODO Chequeo si el lugar donde dropie es valido
	g_print ("Ubicacion de drop de -drag_drop_handl-> (%d,%d)\n",x,y);
/*
	int _x=x;
	int _y=y;
	int _pos_x=pos_x;
	int _pos_y=pos_y;
	if(matriz.hay_componente(&_pos_x,&_pos_y)){

		bool agregado= matriz.agregar_compuerta(&_x,&_y,XOR);
		if(agregado){
			draw_XOR(widget, _x, _y);
			g_print ("Agregue xor enn -> (%d,%d)\n",_x,_y);
			matriz.eliminar_componente(_pos_x,_pos_y);
			g_print ("Elimine\n");
			draw_sin_commpuerta(widget,_pos_x,_pos_y);
		}
	}
*/
    return  true;
}


