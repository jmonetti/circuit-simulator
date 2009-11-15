/**************************   Clase GRILLA   *************************/
/**************************   	Grupo 8      *************************/

#include "common_Grilla.h"

Grilla::Grilla() {

	tabla= gtk_table_new(CANT_FILAS,CANT_COLUMNAS,false);

	for (int i = 0; i < CANT_FILAS; ++i) {

		for (int j = 0; j < CANT_COLUMNAS; ++j) {

			imagenes[i][j]= gtk_image_new_from_file("imagenes/puntos1.jpg");

		}
	}

	for (int i = 0;  i < CANT_FILAS; ++ i) {

		for (int j = 0; j < CANT_COLUMNAS; ++j) {

			gtk_table_attach_defaults(GTK_TABLE(tabla),imagenes[i][j], i,i+1,j,j+1);
			gtk_widget_show(imagenes[i][j]);

		}

	}
	gtk_widget_hide(imagenes[0][0]);
	gtk_widget_hide(imagenes[0][1]);
	gtk_widget_hide(imagenes[1][0]);
	gtk_widget_hide(imagenes[1][1]);
	gtk_widget_hide(imagenes[2][0]);
	gtk_widget_hide(imagenes[2][1]);


	GtkWidget* imagen= gtk_image_new_from_file("imagenes/AND.png");
	gtk_table_attach_defaults(GTK_TABLE(tabla),imagen, 0,3,0,2);
	gtk_widget_show(imagen);

}

void Grilla::show() {

	gtk_widget_show(tabla);

}

void Grilla::escalar(int fa) {


}

GtkWidget* Grilla::getWidget() {

	return tabla;

}

