#include "common_Imprimir.h"
#include "../controlador/common_Controladores_Archivo.h"

#include <cairo/cairo.h>

Imprimir::Imprimir() {

	print= NULL;
	settings= NULL;
}

void Imprimir::mostrar() {

	GtkPrintOperationResult res;

	print = gtk_print_operation_new ();

	if (settings != NULL)
		gtk_print_operation_set_print_settings (print, settings);

	g_signal_connect (print, "begin_print", G_CALLBACK (begin_print), NULL);
	g_signal_connect (print, "draw_page", G_CALLBACK (Controlador_Archivo::callback_draw_page), NULL);

	res = gtk_print_operation_run (print, GTK_PRINT_OPERATION_ACTION_PRINT_DIALOG,
			GTK_WINDOW (NULL), NULL);

	if (res == GTK_PRINT_OPERATION_RESULT_APPLY) {

		if (settings != NULL)
			g_object_unref (settings);
		settings = (GtkPrintSettings*)g_object_ref (gtk_print_operation_get_print_settings (print));

	}

	g_object_unref (print);


}

void Imprimir::begin_print(GtkPrintOperation* print,GtkPrintContext* context) {

	gtk_print_operation_set_n_pages(print,1);

}

void Imprimir::imprimir(GtkPrintContext* context,std::vector<Compuerta*>& compuertas,std::vector<ConexionVertice>& conexiones) {

	cairo_t *cr;

	cr = gtk_print_context_get_cairo_context (context);

	cairo_scale(cr,0.4,0.4);

	dibujador.dibujarGrilla(cr);

	for (unsigned int var = 0; var < compuertas.size(); ++var) {

		dibujador.dibujar(compuertas[var],cr);

	}

	for (unsigned int var = 0; var < conexiones.size(); ++var) {

		dibujador.dibujarConexion(conexiones[var],cr);
	}
}
