
#include "common_Ventana_Abrir.h"

#include "../controlador/common_Controladores_Window.h"
#include "../controlador/common_Controladores_Archivo.h"

#include <vector>
#include "../common/constantes.h"
#include "../common/common_Utils.h"

const char* Ventana_Abrir::titulo[] = {

		"Circuitos"

};

char* Ventana_Abrir::circuitoAbrir;

Ventana_Abrir::Ventana_Abrir() {

	cuadro= gtk_dialog_new();
	gtk_window_set_title (&GTK_DIALOG(cuadro)->window, "Abrir");

	gtk_signal_connect (GTK_OBJECT (&GTK_DIALOG(cuadro)->window), "destroy",
			                        GTK_SIGNAL_FUNC (Controlador_Ventana::do_nothing), NULL);

	gtk_signal_connect (GTK_OBJECT (&GTK_DIALOG(cuadro)->window), "delete_event",
	                        GTK_SIGNAL_FUNC (Controlador_Ventana::delete_event_true), NULL);

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
	// TODO Auto-generated destructor stub
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

void Ventana_Abrir::mostrarCircuitos() {

	circuitoAbrir= NULL;

	if (lista) {

		gtk_widget_destroy(lista);

	}

	lista= gtk_clist_new_with_titles(1,(gchar**) titulo);

	gtk_clist_column_titles_passive( GTK_CLIST(lista) );

	gtk_clist_set_column_justification( GTK_CLIST(lista) , 0, GTK_JUSTIFY_CENTER);

	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->vbox), lista, TRUE, TRUE, 0);

	gtk_widget_show(lista);


	std::vector<char*> archivos;
	Utils::obtenerArchivos(PATH_SAVES,&archivos);

	for (unsigned int var = 0; var < archivos.size(); ++var) {

		gtk_clist_append( GTK_CLIST(lista), &archivos[var]);

	}

	gtk_signal_connect(GTK_OBJECT( lista), "select_row",
						GTK_SIGNAL_FUNC(select_row_callback), lista);

	activa= true;

}

void Ventana_Abrir::select_row_callback(GtkWidget *widget, gint row, gint colum,
			GdkEventButton *event, gpointer data) {

	gtk_clist_get_text(GTK_CLIST(data), row, colum, &circuitoAbrir);

}
