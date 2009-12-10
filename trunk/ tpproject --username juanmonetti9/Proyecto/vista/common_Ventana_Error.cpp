#include "common_Ventana_Error.h"
#include "../controlador/common_Controladores_Window.h"

Ventana_Error::Ventana_Error() {

	cuadro= gtk_dialog_new();
	gtk_window_set_title (&GTK_DIALOG(cuadro)->window, "Error");

	gtk_signal_connect (GTK_OBJECT (&GTK_DIALOG(cuadro)->window), "destroy",
			                        GTK_SIGNAL_FUNC (Controlador_Ventana::destroy), NULL);

	gtk_signal_connect (GTK_OBJECT (&GTK_DIALOG(cuadro)->window), "delete_event",
	                        GTK_SIGNAL_FUNC (Controlador_Ventana::delete_event_true), NULL);


	GtkWidget* boton= gtk_button_new_with_label("Aceptar");

	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->action_area), boton,TRUE, TRUE, 0);
	gtk_widget_show(boton);

	gtk_signal_connect (GTK_OBJECT (boton), "clicked",
			GTK_SIGNAL_FUNC (callback_aceptar), cuadro);

	label = gtk_label_new ("");
    gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->vbox), label, TRUE, TRUE, 0);
    gtk_widget_show (label);


}

Ventana_Error::~Ventana_Error() {
	// TODO Auto-generated destructor stub
}

void Ventana_Error::show() {

	gtk_widget_show(cuadro);

}

void Ventana_Error::hide() {

	gtk_widget_hide(cuadro);

}

GtkWidget* Ventana_Error::getWidget() {

	return cuadro;

}

void Ventana_Error::mostrarError(const std::string &texto) {

	char* text= new char[texto.size() + 1];
	texto.copy(text,texto.size());
	text[texto.size()] = '\0';

	gtk_label_set (GTK_LABEL(label),text);
	gtk_widget_show (label);

    delete[] text;

}

void Ventana_Error::callback_aceptar( GtkWidget *widget,gpointer callback_data ) {

	gtk_widget_hide(GTK_WIDGET(callback_data));

}
