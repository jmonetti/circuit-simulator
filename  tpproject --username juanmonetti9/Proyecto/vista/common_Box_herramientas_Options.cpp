/*****************   Clase Box herramientas options  ****************/
/*****************   	   Grupo 8                   ****************/

#include "common_Box_herramientas_options.h"

Box_herramientas_Options::Box_herramientas_Options() {

	_panel=gtk_vbox_new(false,0);
	_panel_box1=gtk_hbox_new(false,0);
	_panel_box2=gtk_hbox_new(false,0);

	gtk_container_border_width (GTK_CONTAINER (_panel), 10);


	//Incluyoa los botones en _panel
	gtk_box_pack_start (GTK_BOX (_panel_box1), imprimir.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel_box1), nuevo.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel_box2), abrir.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel_box2), guardar.getWidget(),false,false,0);

	gtk_box_pack_start (GTK_BOX (_panel), _panel_box1,false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), _panel_box2,false,false,0);






}
void Box_herramientas_Options::show(){


	imprimir.show();
	nuevo.show();
	guardar.show();
	abrir.show();
	gtk_widget_show (_panel_box1);
	gtk_widget_show (_panel_box2);
	gtk_widget_show (_panel);
}

void Box_herramientas_Options::hide() {

	gtk_widget_hide (_panel_box1);
	gtk_widget_hide (_panel_box2);
	gtk_widget_hide (_panel);


}

void Box_herramientas_Options::escalar(int _fa){

}


GtkWidget* Box_herramientas_Options::getWidget(){

	return _panel;
}

Box_herramientas_Options::~Box_herramientas_Options(){

}
