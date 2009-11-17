/*****************   Clase Box herramientas circuito ****************/
/*****************   	   Grupo 8                   ****************/

#include "common_Box_herramientas_Circuito.h"

Box_herramientas_Circuito::Box_herramientas_Circuito() {

	_panel=gtk_vbox_new(false,0);
	gtk_container_border_width (GTK_CONTAINER (_panel), 10);

	//Incluyoa los botones en _panel
	gtk_box_pack_start (GTK_BOX (_panel), AND.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), OR.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), NOT.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), XOR.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), PISTA.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), Delete.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), invert.getWidget(),false,false,0);


}
void Box_herramientas_Circuito::show(){

	invert.show();
	AND.show();
	OR.show();
	NOT.show();
	XOR.show();
	PISTA.show();
	Delete.show();
	gtk_widget_show (_panel);
}

void Box_herramientas_Circuito::escalar(int _fa){

}


GtkWidget* Box_herramientas_Circuito::getWidget(){

	return _panel;
}

Box_herramientas_Circuito::~Box_herramientas_Circuito() {

}
