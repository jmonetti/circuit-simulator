/**************************   Clase panel_Principal   *************************/
/**************************   Grupo 8                 *************************/

#include "common_Vista_Panel.h"
#include "../controlador/common_Controlador_Boton.h"

Vista_Panel::Vista_Panel(){

	//Creo la caja del panel principal
	box_panel = gtk_vbox_new(false,0);

	//incluyo los paneles en la caja principal
	gtk_box_pack_start (GTK_BOX (box_panel),box_options.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (box_panel),box_circuit.getWidget(),false,false,0);



}

/*----------------------------------------------------------------------------*/

void Vista_Panel::show(){

   box_circuit.show();
   box_options.show();
   gtk_widget_show (box_panel);
}
/*----------------------------------------------------------------------------*/
void Vista_Panel::escalar(int _fa){

}

/*----------------------------------------------------------------------------*/
GtkWidget* Vista_Panel::getWidget(){
	return box_panel;
}


