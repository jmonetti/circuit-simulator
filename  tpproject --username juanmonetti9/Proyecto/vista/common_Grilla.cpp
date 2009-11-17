/**************************   Clase GRILLA   *************************/
/**************************   	Grupo 8      *************************/

#include "common_Grilla.h"

Grilla::Grilla() {

	tabla= gtk_table_new(CANT_FILAS,CANT_COLUMNAS,true);

	for (int i = 0; i < CANT_FILAS; ++i) {

		for (int j = 0; j < CANT_COLUMNAS; ++j) {

			imagenes[i][j]= gtk_image_new_from_file("imagenes/punto.png");

		}
	}

	for (int i = 0;  i < CANT_FILAS; ++ i) {

		for (int j = 0; j < CANT_COLUMNAS; ++j) {

			gtk_table_attach_defaults(GTK_TABLE(tabla),imagenes[i][j], i,i+1,j,j+1);
			gtk_widget_show(imagenes[i][j]);

		}

	}

}

void Grilla::show() {

	gtk_widget_show(tabla);

}

void Grilla::escalar(int fa) {


}

GtkWidget* Grilla::getWidget() {

	return tabla;

}

