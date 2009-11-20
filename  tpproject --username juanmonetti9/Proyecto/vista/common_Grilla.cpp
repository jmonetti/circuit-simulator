/**************************   Clase GRILLA   *************************/
/**************************   	Grupo 8      *************************/

#include "common_Grilla.h"

Grilla::Grilla() {

	//Creo el notebook
	notebook= gtk_notebook_new();
	tab_noteb1= gtk_label_new ("Area de diseño");
	tab_noteb2= gtk_label_new ("Tabla logica");
	box_noteb1= gtk_hbox_new(false,0);
	box_noteb2= gtk_hbox_new(false,0);
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook),box_noteb1,tab_noteb1);
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook), box_noteb2,tab_noteb2);


}

void Grilla::show() {

	gtk_widget_show(tab_noteb1);
	gtk_widget_show(tab_noteb2);
	gtk_widget_show(box_noteb1);
	gtk_widget_show(box_noteb2);
	gtk_widget_show(notebook);


}

void Grilla::escalar(int fa) {


}

GtkWidget* Grilla::getWidget() {

	return notebook;

}
