#include "common_Ventana_Upload.h"
#include "../controlador/common_Controladores_Window.h"
#include "../controlador/common_Controladores_Circuito.h"

const char* Ventana_Upload::titulo[] = {

		"Circuitos"

};

char* Ventana_Upload::circuitoUpload;

bool Ventana_Upload::activa= false;

Ventana_Upload::Ventana_Upload() {

	cuadro= gtk_dialog_new();
	gtk_window_set_title (&GTK_DIALOG(cuadro)->window, "Upload");

	gtk_signal_connect (GTK_OBJECT (&GTK_DIALOG(cuadro)->window), "destroy",
									GTK_SIGNAL_FUNC (Controlador_Ventana::destroy), NULL);

	gtk_signal_connect (GTK_OBJECT (&GTK_DIALOG(cuadro)->window), "delete_event",
							GTK_SIGNAL_FUNC (Controlador_Ventana::delete_event_true), NULL);


	GtkWidget* boton= gtk_button_new_with_label("Aceptar");
	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->action_area), boton,TRUE, TRUE, 0);
	gtk_widget_show(boton);


	gtk_signal_connect (GTK_OBJECT (boton), "clicked",
				GTK_SIGNAL_FUNC (Controlador_Circuito::callback_Upload), NULL);


	boton= gtk_button_new_with_label("Cancelar");
	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->action_area), boton,TRUE, TRUE, 0);
	gtk_widget_show(boton);


	gtk_signal_connect (GTK_OBJECT (boton), "clicked",
				GTK_SIGNAL_FUNC (callback_ocultar), cuadro);

    GtkWidget* label = gtk_label_new ("Host:");
    gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->vbox), label, TRUE, TRUE, 0);
    gtk_widget_show (label);


	entryHost= gtk_entry_new();
    gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->vbox), entryHost, TRUE, TRUE, 0);
    gtk_widget_show(entryHost);

    label = gtk_label_new ("Puerto:");
    gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->vbox), label, TRUE, TRUE, 0);
    gtk_widget_show (label);


	entryPuerto= gtk_entry_new();
    gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->vbox), entryPuerto, TRUE, TRUE, 0);
    gtk_widget_show(entryPuerto);


	lista= NULL;

	activa= false;

}

Ventana_Upload::~Ventana_Upload() {
	// TODO Auto-generated destructor stub
}


void Ventana_Upload::show() {

	gtk_widget_show(cuadro);

}

void Ventana_Upload::hide() {

	gtk_widget_hide(cuadro);

	activa= false;

}

GtkWidget* Ventana_Upload::getWidget() {

	return cuadro;

}

bool Ventana_Upload::estaActiva() {

	return activa;

}

char* Ventana_Upload::getCircuitoUpload() {

	return circuitoUpload;

}

const char* Ventana_Upload::getHost() {

	return gtk_entry_get_text(GTK_ENTRY(entryHost));

}

const char* Ventana_Upload::getPuerto() {

	return gtk_entry_get_text(GTK_ENTRY(entryPuerto));

}


void Ventana_Upload::mostrarCircuitos(std::vector<char*>* circuitos) {

	circuitoUpload= NULL;

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

void Ventana_Upload::select_row_callback(GtkWidget *widget, gint row, gint colum,
			GdkEventButton *event, gpointer data) {

	gtk_clist_get_text(GTK_CLIST(data), row, colum, &circuitoUpload);

}

void Ventana_Upload::unselect_row_callback(GtkWidget *widget, gint row, gint colum,
			GdkEventButton *event, gpointer data) {

	circuitoUpload= NULL;

}

void Ventana_Upload::callback_ocultar(GtkWidget *widget,gpointer data) {

	gtk_widget_hide(GTK_WIDGET(data));

	activa= false;

}


