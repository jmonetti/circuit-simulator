
#include "common_Ventana_Abrir.h"

#include "../controlador/common_Controladores_Window.h"
#include "../controlador/common_Controladores_Archivo.h"
#include <vector>


const char* Ventana_Abrir::titulo[] = {

		"Circuitos"

};

char* Ventana_Abrir::circuitoAbrir;

Ventana_Abrir::Ventana_Abrir() {

	cuadro= gtk_dialog_new();
	gtk_window_set_title (&GTK_DIALOG(cuadro)->window, "Abrir");

	gtk_signal_connect (GTK_OBJECT (&GTK_DIALOG(cuadro)->window), "delete_event",
	                        GTK_SIGNAL_FUNC (Controlador_Ventana::delete_event_esconder), this);

	GtkWidget* boton= gtk_button_new_with_label("Aceptar");
	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->action_area), boton,TRUE, TRUE, 0);
	gtk_widget_show(boton);

	gtk_signal_connect (GTK_OBJECT (boton), "clicked",
				GTK_SIGNAL_FUNC (Controlador_Archivo::callback_aceptar_abrir), NULL);


	boton= gtk_button_new_with_label("Cancelar");
	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->action_area), boton,TRUE, TRUE, 0);
	gtk_widget_show(boton);

	gtk_signal_connect (GTK_OBJECT (boton), "clicked",
				GTK_SIGNAL_FUNC (Controlador_Archivo::callback_cancelar_abrir), NULL);

	lista= NULL;

	activa= false;

}

Ventana_Abrir::~Ventana_Abrir() {

	gtk_widget_destroy(cuadro);

}

void Ventana_Abrir::show() {

	gtk_widget_show(cuadro);

}

void Ventana_Abrir::hide() {

	gtk_widget_hide(cuadro);

	activa= false;

}

GtkWidget* Ventana_Abrir::getWidget() {

	return cuadro;

}

bool Ventana_Abrir::estaActiva() {

	return activa;

}

char* Ventana_Abrir::getCircuitoAbrir() {

	return circuitoAbrir;

}

void Ventana_Abrir::mostrarCircuitos(std::vector<char*>* circuitos) {

	circuitoAbrir= NULL;

	if (lista) {

		gtk_widget_destroy(lista);

	}

	lista= gtk_clist_new_with_titles(1,(gchar**) titulo);

	gtk_clist_column_titles_passive( GTK_CLIST(lista) );

	gtk_clist_set_column_justification( GTK_CLIST(lista) , 0, GTK_JUSTIFY_CENTER);

	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->vbox), lista, TRUE, TRUE, 0);

	gtk_widget_show(lista);

	for (unsigned int var = 0; var < circuitos->size(); ++var) {

		gtk_clist_append( GTK_CLIST(lista), &(*circuitos)[var]);
		delete[] (*circuitos)[var];

	}

	delete circuitos;

	gtk_signal_connect(GTK_OBJECT( lista), "select_row",
						GTK_SIGNAL_FUNC(select_row_callback), lista);

	gtk_signal_connect(GTK_OBJECT( lista), "unselect_row",
						GTK_SIGNAL_FUNC(unselect_row_callback), lista);

	activa= true;


}

void Ventana_Abrir::select_row_callback(GtkWidget *widget, gint row, gint colum,
			GdkEventButton *event, gpointer data) {

	gtk_clist_get_text(GTK_CLIST(data), row, colum, &circuitoAbrir);

}

void Ventana_Abrir::unselect_row_callback(GtkWidget *widget, gint row, gint colum,
			GdkEventButton *event, gpointer data) {

	circuitoAbrir= NULL;

}

