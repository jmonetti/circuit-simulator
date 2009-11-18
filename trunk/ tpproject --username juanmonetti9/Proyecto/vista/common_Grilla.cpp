/**************************   Clase GRILLA   *************************/
/**************************   	Grupo 8      *************************/

#include "common_Grilla.h"

Grilla::Grilla() {

	frame= gtk_frame_new(" Area de diseño ");

}

void Grilla::show() {

	gtk_widget_show(frame);

}

void Grilla::escalar(int fa) {


}

GtkWidget* Grilla::getWidget() {

	return frame;

}

