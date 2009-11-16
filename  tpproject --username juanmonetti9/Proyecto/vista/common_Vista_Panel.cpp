/**************************   Clase panel_Principal   *************************/
/**************************   Grupo 8                 *************************/

#include "common_Vista_Panel.h"
#include "../controlador/common_Controlador_Boton.h"

Vista_Panel::Vista_Panel(){

	//Creo la caja del panel principal
	box_panel = gtk_hbox_new(false,0);

	//Creo las cajas de los paneles interiores
	GtkWidget* panel_1=gtk_vbox_new(false,0);

	//Incluyo los botones en las cajas
	gtk_box_pack_start (GTK_BOX (panel_1), imprimir.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (panel_1), Select.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (panel_1), delet.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (panel_1), simular.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (panel_1), AND.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (panel_1), OR.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (panel_1), NOT.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (panel_1), XOR.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (panel_1), PISTA.getWidget(),false,false,0);
	gtk_box_pack_start (GTK_BOX (panel_1), invert.getWidget(),false,false,0);

	//Muestro los botones
	simular.show();
	Select.show();
	invert.show();
	AND.show();
	OR.show();
	NOT.show();
	XOR.show();
	PISTA.show();
	delet.show();
	imprimir.show();


	//Seteo la posicion del panel
	gtk_widget_set_uposition(panel_1,10,20);

	//Muestro el panele
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

/*----------------------------------------------------------------------------*/
GtkWidget* Vista_Panel::getWidget(){
	return box_panel;
}


