/**************************   Clase panel_Principal   *************************/
/**************************   Grupo 8                 *************************/

#include "common_Vista_Panel.h"

Vista_Panel::Vista_Panel(){

	//Creo la caja del panel principal
	box_panel = gtk_hbox_new(false,0);

	//Creo las cajas de los paneles interiores
	GtkWidget* panel_1=gtk_vbox_new(false,0);


	const char* imagenes[]= { "imagenes/AND.png",
				"imagenes/OR.png",
				"imagenes/XOR.png",
				"imagenes/NOT.png",
				"imagenes/PISTA.png"
	};

	for (int i= 0; i < CANT_BOTONES; i++) {

		botones[i].agregarImagen((gchar*)imagenes[i]);
		botones[i].show();
		gtk_box_pack_start (GTK_BOX (panel_1), botones[i].getWidget(),false,false,0);

	}


	gtk_widget_set_uposition(panel_1,10,20);

	//Muestro paneles
	gtk_widget_show (panel_1);


	//incluyo los paneles en la caja principal

	gtk_box_pack_start (GTK_BOX (box_panel),panel_1,false,false,0);


}

/*----------------------------------------------------------------------------*/

void Vista_Panel::show(){

    gtk_widget_show (box_panel);
}
/*----------------------------------------------------------------------------*/
void Vista_Panel::escalar(int _fa){

}
GtkWidget* Vista_Panel::getWidget(){
	return box_panel;
}
