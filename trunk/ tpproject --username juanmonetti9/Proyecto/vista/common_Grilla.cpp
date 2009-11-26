/**************************   Clase GRILLA   *************************/
/**************************   	Grupo 8      *************************/

#include "common_Grilla.h"
#include "../controlador/common_Controlador_Circuito.h"
GdkPixmap *Grilla::pixmap = NULL;



//Defino un listado de la informacion que el widget destino aceptara.
enum {TARGET_STRING};


static GtkTargetEntry target_list[] = {{ (gchar*)"STRING",0, TARGET_STRING },};

//cantidad de elementos de target_list
static guint n_targets = G_N_ELEMENTS (target_list);

Grilla::Grilla() {

	//Creo la caja que contendra la notebook
	box_notebook= gtk_hbox_new(false,0);
	//Creo el notebook y la incluyo en la caja
	notebook= gtk_notebook_new();
	gtk_box_pack_start (GTK_BOX (box_notebook),notebook, true,true,false);
	//Creo las pestanias
	tab_pestania_uno= gtk_label_new ("Area de diseño");
	tab_pestania_dos= gtk_label_new ("Tabla logica");
	//creo las cajas de la pestania uno
	box_pestania_uno= gtk_hbox_new(false,0);
	box_size_pestania_uno=gtk_vbox_new(false,0);
	//Creo el widget drawing area
	drawing_area = gtk_drawing_area_new ();
	//Seteo el tamanio por defecto del drawing area
	gtk_drawing_area_size (GTK_DRAWING_AREA (drawing_area),DRW_AREA_WIDTH,
							  DRW_AREA_HEIGHT);


	//Seteo el drawing area para que sea dropeable
	gtk_drag_dest_set(drawing_area,GTK_DEST_DEFAULT_MOTION,target_list,n_targets,GDK_ACTION_COPY);
	gtk_drag_source_set(drawing_area,GDK_BUTTON3_MASK,target_list,n_targets,GDK_ACTION_COPY);

	//incluyo el drawing area en la caja
	gtk_box_pack_start (GTK_BOX (box_size_pestania_uno), drawing_area, false,false,false);
	gtk_box_pack_start (GTK_BOX (box_pestania_uno),box_size_pestania_uno, false,false,false);

	//Completo la tabla logica
	tablaLogica.completar();
	//incluyo las las pestanias a la notebook
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook),box_pestania_uno,tab_pestania_uno);
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook), tablaLogica.getWidget(),tab_pestania_dos);



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
	g_signal_connect (drawing_area, "drag-drop",G_CALLBACK (Controlador_Circuito::drag_drop_handl), NULL);
	//Seteo los eventos que se notificaran al drawing area
	gtk_widget_set_events (drawing_area, GDK_EXPOSURE_MASK | GDK_LEAVE_NOTIFY_MASK |
							GDK_BUTTON_PRESS_MASK | GDK_POINTER_MOTION_MASK |
							GDK_POINTER_MOTION_HINT_MASK);


}

void Grilla::show() {

	gtk_widget_show(box_notebook);
	gtk_widget_show(notebook);
	gtk_widget_show (drawing_area);
	gtk_widget_show (box_size_pestania_uno);
	gtk_widget_show(box_pestania_uno);
	gtk_widget_show(tab_pestania_uno);
	gtk_widget_show(tab_pestania_dos);
	tablaLogica.show();

}


GtkWidget* Grilla::getWidget() {

	return box_notebook;
}


/*----------------------------------------------------------------------------*/

void Grilla::crear_pixmap (GtkWidget *widget, GdkEventConfigure *event){

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

void Grilla::exponer_pixmap (GtkWidget *widget, GdkEventExpose *event){


	gdk_draw_pixmap(widget->window,widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
                  pixmap,event->area.x, event->area.y,event->area.x, event->area.y,
                  event->area.width, event->area.height);
}

/*----------------------------------------------------------------------------*/

void Grilla::draw_sin_commpuerta(gdouble x, gdouble y){

	GdkRectangle update_rect;

	update_rect.x = x -(COMPUERTA_WIDTH/2)- CELDA_WIDTH; //pos x del rectangulo a redibujar
	update_rect.y = y - (COMPUERTA_HEIGHT/2)- CELDA_HEIGHT; //pos y del rectangulo a redibujar
	update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	gdk_draw_rectangle (pixmap,drawing_area->style->white_gc,true,update_rect.x,update_rect.y,update_rect.width,update_rect.height);

	gtk_widget_draw (drawing_area, &update_rect);

}
/*----------------------------------------------------------------------------*/

void Grilla::draw_NOT(gdouble x, gdouble y){

	 GdkRectangle update_rect;

	 update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	 update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO

	 //Dibujo compuerta NOT
	 gdk_draw_line(pixmap,drawing_area->style->black_gc,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),
						  update_rect.x+(CELDA_WIDTH/2),update_rect.y+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
						 update_rect.x+(CELDA_WIDTH/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_WIDTH/2));
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+(CELDA_WIDTH/2),update_rect.y,update_rect.x+(2*CELDA_WIDTH)+(CELDA_WIDTH/2),update_rect.y+(COMPUERTA_WIDTH/2));
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+(CELDA_WIDTH/2),update_rect.y,update_rect.x+(CELDA_WIDTH/2),update_rect.y+COMPUERTA_HEIGHT);
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+(CELDA_WIDTH/2),update_rect.y+COMPUERTA_HEIGHT,update_rect.x+(2*CELDA_WIDTH)+(CELDA_WIDTH/2),update_rect.y+(COMPUERTA_WIDTH/2));
	 gdk_draw_line(pixmap, drawing_area->style->black_gc,update_rect.x+COMPUERTA_WIDTH-(CELDA_WIDTH/2),update_rect.y+CELDA_HEIGHT+CELDA_HEIGHT/2,
						  update_rect.x+COMPUERTA_WIDTH,update_rect.y+CELDA_HEIGHT+CELDA_HEIGHT/2);
	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);

}
/*----------------------------------------------------------------------------*/

void Grilla::draw_AND(gdouble x, gdouble y){

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
/*----------------------------------------------------------------------------*/

void Grilla::draw_OR(gdouble x, gdouble y){


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
/*----------------------------------------------------------------------------*/

void Grilla::draw_XOR(gdouble x, gdouble y){

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
/*----------------------------------------------------------------------------*/
