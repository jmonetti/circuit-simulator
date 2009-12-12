/*****************   Clase Box herramientas circuito ****************/
/*****************   	   Grupo 8                   ****************/

#include "common_Box_herramientas_Circuito.h"

Box_herramientas_Circuito::Box_herramientas_Circuito() {

	//box con primera columna de botones
	_panel=gtk_vbox_new(false,0);
	gtk_widget_set_usize(_panel,WIDTH_BOTONERA,HEIGHT_BOTONERA);
	//box botonera principal
	_panel_size=gtk_hbox_new(false,0);
	gtk_box_pack_start (GTK_BOX (_panel_size),_panel,false,false,0);
	gtk_container_border_width (GTK_CONTAINER (_panel_size), 10);
	//Incluyo los botones en _panel_size
	gtk_box_pack_start (GTK_BOX (_panel), simular.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), upload.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), download.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), AND.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), OR.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), NOT.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), XOR.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), PISTA.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), entrada.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), salida.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), Select.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), invert.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), invertL.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), Delete.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (_panel), mostrar.getWidget(),false,false,0);

}

void Box_herramientas_Circuito::show(){

	invert.show();
	invertL.show();
	AND.show();
	OR.show();
	NOT.show();
	XOR.show();
	PISTA.show();
	Delete.show();
	Select.show();
	simular.show();
	download.show();
	upload.show();
	entrada.show();
	salida.show();
	mostrar.show();
	gtk_widget_show (_panel_size);
	gtk_widget_show (_panel);
}

void Box_herramientas_Circuito::escalar(int _fa){

}


GtkWidget* Box_herramientas_Circuito::getWidget(){

	return _panel_size;
}

Box_herramientas_Circuito::~Box_herramientas_Circuito() {

}
