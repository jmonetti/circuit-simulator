/*****************   Clase Box herramientas options  ****************/
/*****************   	   Grupo 8                   ****************/

#include "common_Box_herramientas_options.h"

Box_herramientas_Options::Box_herramientas_Options() {

	_panel=gtk_vbox_new(false,0);
	gtk_container_border_width (GTK_CONTAINER (_panel), 10);

	//Incluyoa los botones en _panel
	gtk_box_pack_start (GTK_BOX (_panel), imprimir.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), Select.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), upload.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), download.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), simular.getWidget(),false,false,0);


}
void Box_herramientas_Options::show(){

	Select.show();
	simular.show();
	imprimir.show();
	download.show();
	upload.show();
	gtk_widget_show (_panel);
}

void Box_herramientas_Options::escalar(int _fa){

}


GtkWidget* Box_herramientas_Options::getWidget(){

	return _panel;
}

Box_herramientas_Options::~Box_herramientas_Options(){

}
