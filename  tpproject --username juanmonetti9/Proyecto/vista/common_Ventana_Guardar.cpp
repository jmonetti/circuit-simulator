#include "common_Ventana_Guardar.h"
#include "../controlador/common_Controladores_Window.h"

Ventana_Guardar::Ventana_Guardar() {

	cuadro= gtk_dialog_new();
	gtk_window_set_title (&GTK_DIALOG(cuadro)->window, "Guardar");

	gtk_signal_connect (GTK_OBJECT (&GTK_DIALOG(cuadro)->window), "destroy",
			                        GTK_SIGNAL_FUNC (Controlador_Ventana::destroy), NULL);

	gtk_signal_connect (GTK_OBJECT (&GTK_DIALOG(cuadro)->window), "delete_event",
	                        GTK_SIGNAL_FUNC (Controlador_Ventana::delete_event_true), NULL);


	GtkWidget* boton= gtk_button_new_with_label("Aceptar");

	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->action_area), boton,TRUE, TRUE, 0);
	gtk_widget_show(boton);

	gtk_signal_connect (GTK_OBJECT (boton), "clicked",
			GTK_SIGNAL_FUNC (callback_aceptar), cuadro);

	label = gtk_label_new ("Circuito guardado exitosamente");
    gtk_box_pack_start (GTK_BOX (GTK_DIALOG (cuadro)->vbox), label, TRUE, TRUE, 0);
    gtk_widget_show (label);


}

Ventana_Guardar::~Ventana_Guardar() {
	// TODO Auto-generated destructor stub
}

void Ventana_Guardar::show() {

	gtk_widget_show(cuadro);

}

void Ventana_Guardar::hide() {

	gtk_widget_hide(cuadro);

}

GtkWidget* Ventana_Guardar::getWidget() {

	return cuadro;

}

void Ventana_Guardar::callback_aceptar( GtkWidget *widget,gpointer callback_data ) {

	gtk_widget_hide(GTK_WIDGET(callback_data));

}
