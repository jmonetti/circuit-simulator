

#include "common_Area_disenio.h"
#include "../controlador/common_Controladores_Circuito.h"

GdkPixmap *Area_disenio::pixmap = NULL;


//Defino un listado de la informacion que el widget destino aceptara.
enum {TARGET_STRING};


static GtkTargetEntry target_list[] = {{ (gchar*)"STRING",0, TARGET_STRING },};

//cantidad de elementos de target_list
static guint n_targets = G_N_ELEMENTS (target_list);


Area_disenio::Area_disenio() {

	//creo las cajas de la pestania uno
	box_pestania_uno= gtk_hbox_new(false,0);
	box_size_pestania_uno=gtk_vbox_new(false,0);
	//Creo el widget drawing area
	drawing_area = gtk_drawing_area_new ();
	//Seteo los eventos que se notificaran al drawing area
	gtk_widget_set_events (drawing_area, GDK_BUTTON_PRESS_MASK | GDK_POINTER_MOTION_MASK );
	//Seteo el tamanio por defecto del drawing area
	gtk_drawing_area_size (GTK_DRAWING_AREA (drawing_area),DRW_AREA_WIDTH,
							  DRW_AREA_HEIGHT);
	//Seteo el drawing area para que sea dropeable
	gtk_drag_dest_set(drawing_area,GTK_DEST_DEFAULT_MOTION,target_list,n_targets,GDK_ACTION_COPY);
	gtk_drag_source_set(drawing_area,GDK_BUTTON1_MASK,target_list,n_targets,GDK_ACTION_COPY);


	//incluyo el drawing area en la caja
	gtk_box_pack_start (GTK_BOX (box_size_pestania_uno), drawing_area, false,false,false);
	gtk_box_pack_start (GTK_BOX (box_pestania_uno),box_size_pestania_uno, false,false,false);

	//conecto con la señal ("expose_event") actualizacion de zona
	gtk_signal_connect (GTK_OBJECT (drawing_area), "expose_event",
						  (GtkSignalFunc)exponer_pixmap, NULL);
	//conecto con la señal ("configure_event") producido al modificar el tamanio del drawing area
	gtk_signal_connect (GTK_OBJECT(drawing_area),"configure_event",
						  (GtkSignalFunc)crear_pixmap, NULL);


	//conecto con la señal ("button_press_event") de precionar el boton del mouse
	gtk_signal_connect (GTK_OBJECT (drawing_area), "button_press_event",
						  (GtkSignalFunc)Controlador_Circuito::button_press_event, NULL);
	//conecto con el controlador para cuando se suelte la seleccion en el destino.
	id_manejador_dnd=g_signal_connect (drawing_area, "drag-drop",G_CALLBACK (Controlador_Circuito::drag_drop_handl), NULL);


}

Area_disenio::~Area_disenio() {

}




void Area_disenio::show() {

	gtk_widget_show (drawing_area);
	gtk_widget_show (box_size_pestania_uno);
	gtk_widget_show(box_pestania_uno);


}


GtkWidget* Area_disenio::getWidget() {

	return box_pestania_uno;
}


/*----------------------------------------------------------------------------*/

void Area_disenio::crear_pixmap (GtkWidget *widget, GdkEventConfigure *event){


	if (pixmap){

		//desreferencio el pixmap
		gdk_pixmap_unref(pixmap);

	}
	//Creo un nuevo pixmap, tomando las propiedades del widget, con
	//parametro -1 misma profundidad de color que la ventana
	pixmap = gdk_pixmap_new(widget->window,widget->allocation.width,
						widget->allocation.height,-1);
	//Rellena t0do el pixmap de blanco
	gdk_draw_rectangle (pixmap,widget->style->white_gc,true,0,0,widget->allocation.width,widget->allocation.height);

}


/*----------------------------------------------------------------------------*/

void Area_disenio::exponer_pixmap (GtkWidget *widget, GdkEventExpose *event){

	g_print("HOLA\n");
	gdk_draw_pixmap(widget->window,widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
                  pixmap,event->area.x, event->area.y,event->area.x, event->area.y,
                  event->area.width, event->area.height);
}

/*----------------------------------------------------------------------------*/

void Area_disenio::desconectar_DnD(){

	//gtk_drag_dest_unset(drawing_area);
	//gtk_drag_source_unset(drawing_area);


}
/*----------------------------------------------------------------------------*/

void Area_disenio::conectar_DnD(){

	//Seteo el drawing area para que sea dropeable
	//gtk_drag_dest_set(drawing_area,GTK_DEST_DEFAULT_MOTION,target_list,n_targets,GDK_ACTION_COPY);
	//gtk_drag_source_set(drawing_area,GDK_BUTTON1_MASK,target_list,n_targets,GDK_ACTION_COPY);
	//Seteo el drawing area para que sea dropeable
	//gtk_drag_dest_set(drawing_area,GTK_DEST_DEFAULT_MOTION,target_list,n_targets,GDK_ACTION_COPY);


}
/*----------------------------------------------------------------------------*/

void Area_disenio::draw_Borrar_compuerta(gdouble x, gdouble y,SENTIDO sentido){

	GdkRectangle update_rect;

	update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar

	if(sentido==ESTE || sentido ==OESTE){
		update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
		update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar
	}
	else{

		update_rect.width = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
		update_rect.height = COMPUERTA_HEIGHT;//alto del rectangulo a redibujar
	}

	gdk_draw_rectangle (pixmap,drawing_area->style->white_gc,true,update_rect.x,update_rect.y,update_rect.width,update_rect.height);

	gtk_widget_draw (drawing_area, &update_rect);

}
/*----------------------------------------------------------------------------*/

void Area_disenio::draw_pista_sur(gdouble x, gdouble y){

}
/*----------------------------------------------------------------------------*/

void Area_disenio::draw_pista_norte(gdouble x, gdouble y){

}
/*----------------------------------------------------------------------------*/

void Area_disenio::draw_pista_este(gdouble x, gdouble y){

}
/*----------------------------------------------------------------------------*/

void Area_disenio::draw_pista_oeste(gdouble x, gdouble y){

}

/*----------------------------------------------------------------------------*/

void Area_disenio::draw_entrada_sur(gdouble x, gdouble y){

}
/*----------------------------------------------------------------------------*/

void Area_disenio::draw_entrada_norte(gdouble x, gdouble y){

}
/*----------------------------------------------------------------------------*/

void Area_disenio::draw_entrada_este(gdouble x, gdouble y){

	GdkRectangle update_rect;

	update_rect.x = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	update_rect.width = 2*CELDA_WIDTH; //ancho del rectangulo a redibujar
	update_rect.height = CELDA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO


    //dibnujo el rectangulo
	gdk_draw_rectangle (pixmap,drawing_area->style->black_gc,false,update_rect.x,update_rect.y,update_rect.width-(CELDA_WIDTH/2),update_rect.height-1);
	//dibujo la linea de salida
	gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x+(2*CELDA_WIDTH)-(CELDA_WIDTH/2),update_rect.y+(CELDA_HEIGHT/2),
							  update_rect.x+(2*CELDA_WIDTH),update_rect.y+(CELDA_HEIGHT/2));

	//linea vertical de la E
	gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+6,update_rect.y+2,update_rect.x+6,update_rect.y+10);
	//lineas horizontales
	gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+6,update_rect.y+2,update_rect.x+12,update_rect.y+2);
	gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+6,update_rect.y+6,update_rect.x+12,update_rect.y+6);
	gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+6,update_rect.y+10,update_rect.x+12,update_rect.y+10);

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);


}
/*----------------------------------------------------------------------------*/

void Area_disenio::draw_entrada_oeste(gdouble x, gdouble y){

	GdkRectangle update_rect;

		update_rect.x = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
		update_rect.y = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
		update_rect.width = 2*CELDA_WIDTH; //ancho del rectangulo a redibujar
		update_rect.height = CELDA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO


	    //dibnujo el rectangulo
		gdk_draw_rectangle (pixmap,drawing_area->style->black_gc,false,update_rect.x+6,update_rect.y,update_rect.width -(CELDA_WIDTH/2),update_rect.height-1);
		//dibujo la linea de salida
		gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),
								  update_rect.x+(CELDA_WIDTH/2),update_rect.y+(CELDA_HEIGHT/2));

		//informa que la zona dada por update_rect debe actualizarse, el widget
		//generara un evento de exposicion
		gtk_widget_draw (drawing_area, &update_rect);

}
/*----------------------------------------------------------------------------*/

void Area_disenio::draw_salida_sur(gdouble x, gdouble y){

}
/*----------------------------------------------------------------------------*/

void Area_disenio::draw_salida_norte(gdouble x, gdouble y){

}
/*----------------------------------------------------------------------------*/

void Area_disenio::draw_salida_este(gdouble x, gdouble y){

	GdkRectangle update_rect;

	update_rect.x = x -CELDA_WIDTH-(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	update_rect.width = 2*CELDA_WIDTH+1; //ancho del rectangulo a redibujar
	update_rect.height = CELDA_HEIGHT;//alto del rectangulo a redibujar TODO PARCHE MAS UNO


	//dibnujo el rectangulo
	gdk_draw_rectangle (pixmap,drawing_area->style->black_gc,false,update_rect.x+6,update_rect.y,18,11);
	//dibujo la linea de salida
	gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x,update_rect.y+6,
							  update_rect.x+6,update_rect.y+6);

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);

}
/*----------------------------------------------------------------------------*/

void Area_disenio::draw_salida_oeste(gdouble x, gdouble y){
	GdkRectangle update_rect;

	update_rect.x = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	update_rect.width = 2*CELDA_WIDTH+1; //ancho del rectangulo a redibujar
	update_rect.height = CELDA_HEIGHT;//alto del rectangulo a redibujar TODO PARCHE MAS UNO


	//dibnujo el rectangulo
	gdk_draw_rectangle (pixmap,drawing_area->style->black_gc,false,update_rect.x+6,update_rect.y,update_rect.width -(CELDA_WIDTH/2)-1,update_rect.height-1);
	//dibujo la linea de salida
	gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),
							  update_rect.x+(CELDA_WIDTH/2),update_rect.y+(CELDA_HEIGHT/2));

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);

}
/*----------------------------------------------------------------------------*/

void Area_disenio::draw_NOT_sur(gdouble x, gdouble y){

	 GdkRectangle update_rect;

	 update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	 update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO

	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),update_rect.x+COMPUERTA_HEIGHT,update_rect.y+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT,update_rect.y+(CELDA_HEIGHT/2),update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.x,update_rect.y+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT,
	 	 						  update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);


}



void Area_disenio::draw_NOT_oeste(gdouble x, gdouble y){

	 GdkRectangle update_rect;

	 update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	 update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO


	 //Dibujo compuerta NOT
	 gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT,update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2),
						  update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT);
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.x,update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2));

	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);

}

void Area_disenio::draw_NOT_este(gdouble x, gdouble y){

	 GdkRectangle update_rect;

	 update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	 update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO

	 //Dibujo compuerta NOT
	 gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x,update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2),
						  update_rect.x+(CELDA_WIDTH/2),update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+(CELDA_WIDTH/2),update_rect.y,update_rect.x+(2*CELDA_WIDTH)+(CELDA_WIDTH/2),update_rect.y+(COMPUERTA_WIDTH/2));
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+(CELDA_WIDTH/2),update_rect.y,update_rect.x+(CELDA_WIDTH/2),update_rect.y+COMPUERTA_HEIGHT);
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+(CELDA_WIDTH/2),update_rect.y+COMPUERTA_HEIGHT,update_rect.x+(2*CELDA_WIDTH)+(CELDA_WIDTH/2),update_rect.y+(COMPUERTA_WIDTH/2));
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+COMPUERTA_WIDTH-(CELDA_WIDTH/2),update_rect.y+CELDA_HEIGHT+CELDA_HEIGHT/2,
						  update_rect.x+COMPUERTA_WIDTH,update_rect.y+CELDA_HEIGHT+CELDA_HEIGHT/2);
	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);

}


void Area_disenio::draw_NOT_norte(gdouble x, gdouble y){

	 GdkRectangle update_rect;

	 update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	 update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO

	 //Dibujo compuerta NOT
	 gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT,
						  update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.x+COMPUERTA_HEIGHT,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2),update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y);

	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);



}


/*----------------------------------------------------------------------------*/


void Area_disenio::draw_AND_este(gdouble x, gdouble y){

	  GdkRectangle update_rect;

	  update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	  update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	  update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	  update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO

	  //Dibujo compuerta or
	  gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),
						  update_rect.x+(CELDA_WIDTH/2),update_rect.y+(CELDA_HEIGHT/2));
	  gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
						  update_rect.x+(CELDA_WIDTH/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_WIDTH/2));
	  gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x-(3*(CELDA_WIDTH/2)),update_rect.y,4*CELDA_WIDTH,COMPUERTA_HEIGHT,-5850,11700);
	  gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+(CELDA_WIDTH/2),update_rect.y,update_rect.x+(CELDA_WIDTH/2),update_rect.y+COMPUERTA_HEIGHT);

	  gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+COMPUERTA_WIDTH-(CELDA_WIDTH/2),update_rect.y+CELDA_HEIGHT+CELDA_HEIGHT/2,
						  update_rect.x+COMPUERTA_WIDTH,update_rect.y+CELDA_HEIGHT+CELDA_HEIGHT/2);

	  //informa que la zona dada por update_rect debe actualizarse, el widget
	  //generara un evento de exposicion
	  gtk_widget_draw (drawing_area, &update_rect);



}
void Area_disenio::draw_AND_oeste(gdouble x, gdouble y){

	 GdkRectangle update_rect;

	  update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	  update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	  update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	  update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO

	 //dibujo recta
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT);
	 //arco para salida
	 gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x+(CELDA_WIDTH/2),update_rect.y,4*CELDA_WIDTH,COMPUERTA_HEIGHT,-17400,11700);
	//dibujo entradas
	gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2),update_rect.x+COMPUERTA_HEIGHT,update_rect.y+(CELDA_HEIGHT/2));
	gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
		 	  						  update_rect.x+COMPUERTA_HEIGHT,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	//dibuja salida
	gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.x,update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2));


	 //informa que la zona dada por update_rect debe actualizarse, el widget
		 //generara un evento de exposicion
		 gtk_widget_draw (drawing_area, &update_rect);
}

void Area_disenio::draw_AND_norte(gdouble x, gdouble y){


	GdkRectangle update_rect;

	 update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 update_rect.width = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
	 update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO


	 //arco para salida
	 gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),COMPUERTA_HEIGHT,4*CELDA_WIDTH,-23100,11450);
	//dibujo entradas
	 gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
	 	  						  update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT);
	 gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT,
	 	 						   update_rect.x+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	//dibuja salida
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
	 //linea
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.x+COMPUERTA_HEIGHT,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));


	 //informa que la zona dada por update_rect debe actualizarse, el widget
		 //generara un evento de exposicion
		 gtk_widget_draw (drawing_area, &update_rect);

}

void Area_disenio::draw_AND_sur(gdouble x, gdouble y){

	GdkRectangle update_rect;

	update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	update_rect.width = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
	update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO

	//recta
	gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),update_rect.x+COMPUERTA_HEIGHT,update_rect.y+(CELDA_HEIGHT/2));
	//arco para salida
	gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x,update_rect.y-CELDA_WIDTH-(CELDA_WIDTH/2),COMPUERTA_HEIGHT,4*CELDA_WIDTH,-11400,11500);
	//dibujo entradas
	gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+(CELDA_HEIGHT/2),update_rect.y,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
	gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
	//dibuja salida
	gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT,
		  	 						  update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));


	 //informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);

}
/*----------------------------------------------------------------------------*/


void Area_disenio::draw_OR_norte(gdouble x, gdouble y){


	GdkRectangle update_rect;

	 update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 update_rect.width = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
	 update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO



	 //arco para salida
	 gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),COMPUERTA_HEIGHT,4*CELDA_WIDTH,-23100,11450);
	 //arco para entrada
	 gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x,update_rect.y+26,COMPUERTA_HEIGHT,CELDA_WIDTH,-23100,11450);

	 //dibujo entradas
	 gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
	 	  						  update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT);
	 gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT,
	 	 						   update_rect.x+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	//dibuja salida
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));


	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);

}
void Area_disenio::draw_OR_este(gdouble x, gdouble y){


	GdkRectangle update_rect;

		  update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
		  update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
		  update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
		  update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO

		  //Dibujo compuerta or
		  gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),
						  update_rect.x+(CELDA_WIDTH/2),update_rect.y+(CELDA_HEIGHT/2));
		  gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
						  update_rect.x+(CELDA_WIDTH/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_WIDTH/2));
		  gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x-(3*(CELDA_WIDTH/2)),update_rect.y,4*CELDA_WIDTH,COMPUERTA_HEIGHT,-5850,11700);

		  gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x-3,update_rect.y,10,COMPUERTA_HEIGHT,-5850,11700);

		  gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+COMPUERTA_WIDTH-(CELDA_WIDTH/2),update_rect.y+CELDA_HEIGHT+CELDA_HEIGHT/2,
						  update_rect.x+COMPUERTA_WIDTH,update_rect.y+CELDA_HEIGHT+CELDA_HEIGHT/2);
		  //informa que la zona dada por update_rect debe actualizarse, el widget
		  //generara un evento de exposicion
		  gtk_widget_draw (drawing_area, &update_rect);


}

void Area_disenio::draw_OR_oeste(gdouble x, gdouble y){

	 GdkRectangle update_rect;

	  update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	  update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	  update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	  update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO


	  //arco para salida
	  gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x+(CELDA_WIDTH/2),update_rect.y,4*CELDA_WIDTH,COMPUERTA_HEIGHT,-17550,11700);
	  //arco para salida
	  gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x+27,update_rect.y,CELDA_WIDTH,COMPUERTA_HEIGHT,-17550,11700);


	  //dibujo entradas
	  gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2),update_rect.x+COMPUERTA_HEIGHT,update_rect.y+(CELDA_HEIGHT/2));
	  gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
		 	  						  update_rect.x+COMPUERTA_HEIGHT,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	  //dibuja salida
	  gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.x,update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2));

	  //informa que la zona dada por update_rect debe actualizarse, el widget
	  //generara un evento de exposicion
	  gtk_widget_draw (drawing_area, &update_rect);

}

void Area_disenio::draw_OR_sur(gdouble x, gdouble y){


		GdkRectangle update_rect;

		update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
		update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
		update_rect.width = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
		update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO

		//arco para salida
		gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x,update_rect.y-CELDA_WIDTH-(CELDA_WIDTH/2),COMPUERTA_HEIGHT,4*CELDA_WIDTH,-11400,11500);
		 //arco para entrada
		gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x,update_rect.y-3,COMPUERTA_HEIGHT,CELDA_WIDTH,-11400,11500);

		//dibujo entradas
		gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+(CELDA_HEIGHT/2),update_rect.y,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
		gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
		//dibuja salida
		 gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT,
		  	 						  update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));


		//informa que la zona dada por update_rect debe actualizarse, el widget
		//generara un evento de exposicion
		 gtk_widget_draw (drawing_area, &update_rect);


}
/*----------------------------------------------------------------------------*/


void Area_disenio::draw_XOR_este(gdouble x, gdouble y){

	  GdkRectangle update_rect;

	  update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	  update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	  update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	  update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO

	  //Dibujo compuerta xor
	  gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),
					  update_rect.x+(CELDA_WIDTH/2),update_rect.y+(CELDA_HEIGHT/2));
	  gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
					  update_rect.x+(CELDA_WIDTH/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_WIDTH/2));
	  gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x-(3*(CELDA_WIDTH/2)),update_rect.y,4*CELDA_WIDTH,COMPUERTA_HEIGHT,-5850,11700);
	  gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x,update_rect.y,10,COMPUERTA_HEIGHT,-5850,11700);
	  gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x-3,update_rect.y,10,COMPUERTA_HEIGHT,-5850,11700);

	  gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x+COMPUERTA_WIDTH-(CELDA_WIDTH/2),update_rect.y+CELDA_HEIGHT+CELDA_HEIGHT/2,
					  update_rect.x+COMPUERTA_WIDTH,update_rect.y+CELDA_HEIGHT+CELDA_HEIGHT/2);
	  //informa que la zona dada por update_rect debe actualizarse, el widget
	  //generara un evento de exposicion
	  gtk_widget_draw (drawing_area, &update_rect);

}

void Area_disenio::draw_XOR_oeste(gdouble x, gdouble y){

	 GdkRectangle update_rect;

	 update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	 update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO


	 //arco para salida
	 gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x+(CELDA_WIDTH/2),update_rect.y,4*CELDA_WIDTH,COMPUERTA_HEIGHT,-17550,11700);
	 //arco para salida
	 gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x+27,update_rect.y,CELDA_WIDTH,COMPUERTA_HEIGHT,-17550,11700);
	 gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x+29,update_rect.y,CELDA_WIDTH,COMPUERTA_HEIGHT,-17550,11700);

	//dibujo entradas
	gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2),update_rect.x+COMPUERTA_HEIGHT,update_rect.y+(CELDA_HEIGHT/2));
	gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
		 	  						  update_rect.x+COMPUERTA_HEIGHT,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	//dibuja salida
	gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.x,update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2));

	 //informa que la zona dada por update_rect debe actualizarse, el widget
		 //generara un evento de exposicion
		 gtk_widget_draw (drawing_area, &update_rect);

}

void Area_disenio::draw_XOR_norte(gdouble x, gdouble y){

	GdkRectangle update_rect;

	 update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 update_rect.width = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
	 update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO

	 //arco para salida
	 gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),COMPUERTA_HEIGHT,4*CELDA_WIDTH,-23100,11450);

	 gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x,update_rect.y+26,COMPUERTA_HEIGHT,CELDA_WIDTH,-23100,11450);
	 gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x,update_rect.y+28,COMPUERTA_HEIGHT,CELDA_WIDTH,-23100,11450);
	//dibujo entradas
	 gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
	 	  						  update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT);
	 gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT,
	 	 						   update_rect.x+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	//dibuja salida
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));


	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);

}

void Area_disenio::draw_XOR_sur(gdouble x, gdouble y){

	GdkRectangle update_rect;

	update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	update_rect.width = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
	update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO

	//arco para salida
	gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x,update_rect.y-CELDA_WIDTH-(CELDA_WIDTH/2),COMPUERTA_HEIGHT,4*CELDA_WIDTH,-11400,11500);
	//arco para entrada
	gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x,update_rect.y-4,COMPUERTA_HEIGHT,CELDA_WIDTH,-11400,11500);
	 //arco para entrada
	gdk_draw_arc(pixmap, drawing_area->style->black_gc,false,update_rect.x,update_rect.y-2,COMPUERTA_HEIGHT,CELDA_WIDTH,-11400,11500);
	//dibujo entradas
	gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+(CELDA_HEIGHT/2),update_rect.y,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
	gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
	//dibuja salida
	gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT,
		  	 						  update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));


	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);
}

/*----------------------------------------------------------------------------*/
