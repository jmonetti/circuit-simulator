
#include "common_Ventana_Nuevo.h"
#include "../controlador/common_Controladores_Archivo.h"
#include "../controlador/common_Controladores_Window.h"

Ventana_Nuevo::Ventana_Nuevo() {

	cuadro= gtk_dialog_new();
	gtk_window_set_title (&GTK_DIALOG(cuadro)->window, "Nuevo");

	gtk_signal_connect (GTK_OBJECT (&GTK_DIALOG(cuadro)->window), "delete_event",
	                        GTK_SIGNAL_FUNC (Controlador_Ventana::delete_event_true), NULL);


	GtkWidget* boton= gtk_button_new_with_label("Aceptar");

	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->action_area), boton,TRUE, TRUE, 0);
	gtk_widget_show(boton);

	gtk_signal_connect (GTK_OBJECT (boton), "clicked",
			GTK_SIGNAL_FUNC (Controlador_Archivo::callback_aceptar_nuevo), NULL);

	boton= gtk_button_new_with_label("Cancelar");

	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->action_area), boton,TRUE, TRUE, 0);
	gtk_widget_show(boton);

	gtk_signal_connect (GTK_OBJECT (boton), "clicked",
			GTK_SIGNAL_FUNC (callback_cancelar), cuadro);

	entry= gtk_entry_new();
    gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->vbox), entry, TRUE, TRUE, 0);
    gtk_widget_show(entry);

}

Ventana_Nuevo::~Ventana_Nuevo() {


}

void Ventana_Nuevo::show() {

	gtk_widget_show(cuadro);

}

GtkWidget* Ventana_Nuevo::getWidget() {

	return cuadro;

}

void Ventana_Nuevo::hide() {

	gtk_widget_hide(cuadro);

}

const char* Ventana_Nuevo::getNombre() {

	return gtk_entry_get_text(GTK_ENTRY(entry));

}

void Ventana_Nuevo::callback_cancelar(GtkWidget *widget, gpointer data) {

	gtk_widget_hide(GTK_WIDGET(data));

}
