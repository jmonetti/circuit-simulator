#include "common_Ventana_Salida.h"
#include "../controlador/common_Controladores_Window.h"
#include "../controlador/common_Controladores_Circuito.h"

Ventana_Salida::Ventana_Salida() {

	cuadro= gtk_dialog_new();
	gtk_window_set_title (&GTK_DIALOG(cuadro)->window, "Salida");

	gtk_signal_connect (GTK_OBJECT (&GTK_DIALOG(cuadro)->window), "delete_event",
							GTK_SIGNAL_FUNC (Controlador_Ventana::delete_event_true), NULL);


	GtkWidget* boton= gtk_button_new_with_label("Aceptar");

	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->action_area), boton,TRUE, TRUE, 0);
	gtk_widget_show(boton);

	gtk_signal_connect (GTK_OBJECT (boton), "clicked",
			GTK_SIGNAL_FUNC (Controlador_Circuito::callback_Salida), NULL);

	gtk_signal_connect (GTK_OBJECT (boton), "clicked",
			GTK_SIGNAL_FUNC (callback_ocultar), cuadro);


	boton= gtk_button_new_with_label("Cancelar");

	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->action_area), boton,TRUE, TRUE, 0);
	gtk_widget_show(boton);

	gtk_signal_connect (GTK_OBJECT (boton), "clicked",
			GTK_SIGNAL_FUNC (callback_ocultar), cuadro);

	entry= gtk_entry_new();
	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->vbox), entry, TRUE, TRUE, 0);
	gtk_widget_show(entry);


}

Ventana_Salida::~Ventana_Salida() {
	// TODO Auto-generated destructor stub
}

void Ventana_Salida::show() {

	gtk_widget_show(cuadro);

}

GtkWidget* Ventana_Salida::getWidget() {

	return cuadro;

}

void Ventana_Salida::hide() {

	gtk_widget_hide(cuadro);

}

const char* Ventana_Salida::getNombre() {

	return gtk_entry_get_text(GTK_ENTRY(entry));

}

void Ventana_Salida::callback_ocultar(GtkWidget *widget, gpointer data) {

	gtk_widget_hide(GTK_WIDGET(data));

}

