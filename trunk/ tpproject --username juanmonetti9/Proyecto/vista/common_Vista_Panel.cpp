/**************************   Clase panel_Principal   *************************/
/**************************   Grupo 8                 *************************/

#include "common_Vista_Panel.h"

Vista_Panel::Vista_Panel(){

	//Creo la caja del panel principal
	box_panel = gtk_hbox_new(false,0);

	//Creo las cajas de los paneles interiores
	GtkWidget* panel_1=gtk_hbox_new(false,0);
	GtkWidget* panel_2=gtk_vbox_new(false,0);
	GtkWidget* panel_3=gtk_hbox_new(false,0);

	//Creo boton AND y lo incluyo en la caja
	AND = gtk_button_new_with_label ("AND");
	gtk_widget_show (AND);
	gtk_widget_set_usize(AND,SIZE_COMPUERTA,SIZE_COMPUERTA);
	gtk_box_pack_start (GTK_BOX (panel_1),AND,false,false,0);

	//Creo boton OR y lo incluyo en la caja
	OR = gtk_button_new_with_label ("OR");
	gtk_widget_show (OR);
	gtk_widget_set_usize(OR,SIZE_COMPUERTA,SIZE_COMPUERTA);
	gtk_box_pack_start (GTK_BOX (panel_1),OR,false,false,0);

	//Creo boton XOR y lo incluyo en la caja
	XOR = gtk_button_new_with_label ("XOR");
	gtk_widget_show (XOR);
	gtk_widget_set_usize(XOR,SIZE_COMPUERTA,SIZE_COMPUERTA);
	gtk_box_pack_start (GTK_BOX (panel_3),XOR,false,false,0);

	//Creo boton NOT y lo incluyo en la caja
	NOT = gtk_button_new_with_label ("NOT");
	gtk_widget_show (NOT);
	gtk_widget_set_usize(NOT,SIZE_COMPUERTA,SIZE_COMPUERTA);
	gtk_box_pack_start (GTK_BOX (panel_3),NOT,false,false,0);

	//Creo boton ENTRADA y lo incluyo en la caja
	ENTRADA = gtk_button_new_with_label ("ENTRADA");
	gtk_widget_show (ENTRADA);
	gtk_widget_set_usize(ENTRADA,WIDTH_botton,HEIGHT_botton);
	gtk_box_pack_start (GTK_BOX (panel_2),ENTRADA,false,false,0);

	//Creo boton SALIDA y lo incluyo en la caja
	SALIDA = gtk_button_new_with_label ("SALIDA");
	gtk_widget_show (SALIDA);
	gtk_widget_set_usize(SALIDA,WIDTH_botton,HEIGHT_botton);
	gtk_box_pack_start (GTK_BOX (panel_2),SALIDA,false,false,0);

	//Creo boton PISTA y lo incluyo en la caja
	PISTA = gtk_button_new_with_label ("PISTA");
	gtk_widget_show (PISTA);
	gtk_widget_set_usize(PISTA,WIDTH_botton,HEIGHT_botton);
	gtk_box_pack_start (GTK_BOX (panel_2),PISTA,false,false,0);

	//Creo boton DELETE y lo incluyo en la caja
	DELETE = gtk_button_new_with_label ("DELETE");
	gtk_widget_show (DELETE);
	gtk_widget_set_usize(DELETE,WIDTH_botton,HEIGHT_botton);
	gtk_box_pack_start (GTK_BOX (panel_2),DELETE,false,false,0);

	//Creo boton INVERTIR y lo incluyo en la caja
	INVERTIR = gtk_button_new_with_label ("INVERTIR");
	gtk_widget_show (INVERTIR);
	gtk_widget_set_usize(INVERTIR,WIDTH_botton,HEIGHT_botton);
	gtk_box_pack_start (GTK_BOX (panel_2),INVERTIR,false,false,0);


	gtk_widget_set_uposition(panel_2,10,20);

	//Muestro paneles
	gtk_widget_show (panel_2);
	gtk_widget_show (panel_1);
	gtk_widget_show (panel_3);

	//incluyo los paneles en la caja principal
	gtk_box_pack_start (GTK_BOX (panel_2),panel_1,false,false,0);
	gtk_box_pack_start (GTK_BOX (panel_2),panel_3,false,false,0);
	gtk_box_pack_start (GTK_BOX (box_panel),panel_2,false,false,0);





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
