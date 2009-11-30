/**************************   Clase Box_Ventana_Interna   *********************/
/**************************   Grupo 8                     *********************/

#include "common_Box_Ventana_Interna.h"

Box_Ventana_Interna::Box_Ventana_Interna():scroll_grilla(&grilla){

	//Creo el box de la ventana
	_box_ventana= gtk_hbox_new(false,0);
	gtk_container_border_width (GTK_CONTAINER (_box_ventana), 10);
	//Creo la notebook y la incluyo en la caja
	noteb= gtk_notebook_new();
	gtk_notebook_set_tab_pos((GtkNotebook*)noteb,GTK_POS_RIGHT);
	gtk_container_add (GTK_CONTAINER (_box_ventana),noteb);
	//agrego un area de disenio
	agregar_AreaDisenio();
}
/*----------------------------------------------------------------------------*/

void Box_Ventana_Interna::agregar_AreaDisenio(){


	GtkWidget* label_grilla= gtk_label_new ("Circuito");
	gtk_notebook_append_page (GTK_NOTEBOOK (noteb),scroll_grilla.getWidget(),label_grilla);
	scroll_grilla.show();

}
/*----------------------------------------------------------------------------*/

void Box_Ventana_Interna::show(){

    gtk_widget_show (_box_ventana);
    gtk_widget_show (noteb);

}
/*----------------------------------------------------------------------------*/

void Box_Ventana_Interna::escalar(int _fa){

}

void Box_Ventana_Interna::eliminar_pestania_actual(){

	gint page_num =gtk_notebook_get_current_page(GTK_NOTEBOOK(noteb));
	gtk_notebook_remove_page(GTK_NOTEBOOK(noteb), page_num);

}

void Box_Ventana_Interna::agregar_pestania(){
	//TODO agregar a una lista de paginas o something
	void gtk_notebook_prepend_page( GtkNotebook *notebook,
	                                GtkWidget   *child,
	                                GtkWidget   *tab_label );

}

void Box_Ventana_Interna::connect_dnd(){

	grilla.conectar_DnD();
}

void Box_Ventana_Interna::disconnect_dnd(){

	grilla.desconectar_DnD();
}

void Box_Ventana_Interna::dibujar_compuerta(gdouble x,gdouble y,TIPO_COMPUERTA tipo,SENTIDO sentido){

	switch(tipo){

	case T_XOR:	{
				grilla.draw_XOR(x,y,sentido);

				break;
	}
	case T_AND:	{
				grilla.draw_AND(x,y,sentido);
				g_print("Dibujo una AND\n");
				break;
	}
	case T_NOT:	{
				grilla.draw_NOT(x,y,sentido);
				g_print("Dibujo una not\n");
				break;
	}
	case T_OR: {
				grilla.draw_OR(x,y,sentido);
				g_print("Dibujo una OR\n");
				break;
	}
	case T_VACIA:{
				grilla.draw_Borrar_compuerta(x,y,sentido);
				g_print("Dibujo una vacia\n");
				break;
	}

	case T_ENTRADA:break;//todo
	case T_PISTA:break;//todo
	case T_SALIDA:break;//todo
	}

}
/*----------------------------------------------------------------------------*/

GtkWidget* Box_Ventana_Interna::getWidget(){
	return _box_ventana;
}
/*----------------------------------------------------------------------------*/
