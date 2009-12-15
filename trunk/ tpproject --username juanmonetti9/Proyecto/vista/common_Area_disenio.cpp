

#include "common_Area_disenio.h"
#include "../controlador/common_Controladores_Circuito.h"




//Defino un listado de la informacion que el widget destino aceptara.
enum {TARGET_STRING};


static GtkTargetEntry target_list[] = {{ (gchar*)"STRING",0, TARGET_STRING },};

//cantidad de elementos de target_list
static guint n_targets = G_N_ELEMENTS (target_list);


Area_disenio::Area_disenio() {

	//inicializo el pixmap
	pixmap = NULL;
	negro_gc =NULL;
	gris_gc =NULL;
	azul_gc =NULL;

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


	//incluyo el drawing area en la caja
	gtk_box_pack_start (GTK_BOX (box_size_pestania_uno), drawing_area, false,false,false);
	gtk_box_pack_start (GTK_BOX (box_pestania_uno),box_size_pestania_uno, false,false,false);

	//conecto con la señal ("expose_event") actualizacion de zona
	gtk_signal_connect (GTK_OBJECT (drawing_area), "expose_event",
						  (GtkSignalFunc)exponer_pixmap, this);
	//conecto con la señal ("configure_event") producido al modificar el tamanio del drawing area
	gtk_signal_connect (GTK_OBJECT(drawing_area),"configure_event",
						  (GtkSignalFunc)crear_pixmap, this);






}

Area_disenio::~Area_disenio() {

}

void Area_disenio::conectarClick() {

	//Seteo el drawing area para que sea dropeable
	gtk_drag_dest_set(drawing_area,GTK_DEST_DEFAULT_MOTION,target_list,n_targets,GDK_ACTION_COPY);
	gtk_drag_source_set(drawing_area,GDK_BUTTON1_MASK,target_list,n_targets,GDK_ACTION_COPY);

	//conecto con la señal ("button_press_event") de precionar el boton del mouse
	gtk_signal_connect (GTK_OBJECT (drawing_area), "button_press_event",
						  (GtkSignalFunc)Controlador_Circuito::button_press_event, NULL);
	//conecto con el controlador para cuando se suelte la seleccion en el destino.
	id_manejador_dnd=g_signal_connect (drawing_area, "drag-drop",G_CALLBACK (Controlador_Circuito::drag_drop_handl), NULL);


}

GdkGC* Area_disenio::get_color_negro(){

	if(!negro_gc){
		GdkColor black;
		//Creo el color negro
		black.pixel=1;
		gdk_color_parse("black", &black);
		negro_gc = gdk_gc_new(drawing_area->window);
		gdk_gc_set_foreground(negro_gc, &black);
		gdk_gc_set_background(negro_gc, &black);
		gdk_color_parse("black", &black);
		gdk_gc_set_line_attributes(negro_gc,1,GDK_LINE_DOUBLE_DASH,GDK_CAP_PROJECTING,GDK_JOIN_ROUND);

		return negro_gc;
	}
	else
		return negro_gc;

}

GdkGC* Area_disenio::get_color_azul(){

	if(!azul_gc){
		GdkColor blue;
		//Creo el color azul
		blue.pixel=1450;
		gdk_color_parse("blue", &blue);
		azul_gc = gdk_gc_new(drawing_area->window);
		gdk_gc_set_foreground(azul_gc, &blue);
		gdk_gc_set_background(azul_gc, &blue);
		gdk_color_parse("blue", &blue);
		gdk_gc_set_line_attributes(azul_gc,1,GDK_LINE_DOUBLE_DASH,GDK_CAP_PROJECTING,GDK_JOIN_ROUND);

		return azul_gc;
	}
	else
		return azul_gc;
}

GdkGC* Area_disenio::get_color_gris(){

	if(!gris_gc){

		GdkColor gris;
		//Creo el color gris
		gris.pixel=-8500;

		gdk_color_parse("gris", &gris);
		gris_gc = gdk_gc_new(drawing_area->window);
		gdk_gc_set_foreground(gris_gc, &gris);
		gdk_gc_set_background(gris_gc, &gris);
		gdk_color_parse("gris", &gris);


		return gris_gc;
	}
	else
		return gris_gc;
}

void Area_disenio::show() {

	gtk_widget_show (drawing_area);
	gtk_widget_show (box_size_pestania_uno);
	gtk_widget_show(box_pestania_uno);

}

void Area_disenio::hide() {

	gtk_widget_hide (drawing_area);
	gtk_widget_hide (box_size_pestania_uno);
	gtk_widget_hide(box_pestania_uno);

}

GtkWidget* Area_disenio::getWidget() {

	return box_pestania_uno;
}

GdkPixmap* Area_disenio::get_pixmap(){

	return pixmap;
}

void Area_disenio::set_pixmap(GdkPixmap *n_pixmap){

	pixmap = n_pixmap;
}

void Area_disenio::crear_pixmap (GtkWidget *widget, GdkEventConfigure *event,gpointer data){

	Area_disenio* area_disenio = (Area_disenio*)data;
	GdkPixmap* p_pixmap =area_disenio->get_pixmap();

	if (p_pixmap){

		//desreferencio el pixmap
		gdk_pixmap_unref(p_pixmap);

	}
	//Creo un nuevo pixmap, tomando las propiedades del widget, con
	//parametro -1 misma profundidad de color que la ventana
	p_pixmap = gdk_pixmap_new(widget->window,widget->allocation.width,
						widget->allocation.height,-1);

	area_disenio->set_pixmap(p_pixmap);
	//Rellena t0do el pixmap de blanco
	gdk_draw_rectangle (p_pixmap,widget->style->white_gc,true,0,0,widget->allocation.width,widget->allocation.height);
	area_disenio->borrar();

}

void Area_disenio::exponer_pixmap (GtkWidget *widget, GdkEventExpose *event,gpointer data){


	Area_disenio* area_disenio = (Area_disenio*)data;
	GdkPixmap* p_pixmap =area_disenio->get_pixmap();

	gdk_draw_pixmap(widget->window,widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
                  p_pixmap,event->area.x, event->area.y,event->area.x, event->area.y,
                  event->area.width, event->area.height);

}

void Area_disenio::borrar(){

	GdkRectangle update_rect;

	update_rect.x = 0; //pos x del rectangulo a redibujar
	update_rect.y = 0; //pos y del rectangulo a redibujar
	update_rect.width = DRW_AREA_WIDTH; //ancho del rectangulo a redibujar
	update_rect.height = DRW_AREA_HEIGHT;//alto del rectangulo a redibujar

	gdk_draw_rectangle (pixmap,drawing_area->style->white_gc,true,update_rect.x,update_rect.y,update_rect.width,update_rect.height);


	GdkGC *gris=this->get_color_gris();

	for (int var = 0; var < 65; ++var) {

		gdk_draw_line(pixmap,gris,update_rect.x,update_rect.y+var * (CELDA_HEIGHT)+6,
										  update_rect.x+DRW_AREA_WIDTH,update_rect.y+var *(CELDA_HEIGHT)+6);

	}

	for (int var = 0; var < 98; ++var) {

		gdk_draw_line(pixmap,gris,update_rect.x + var*(CELDA_HEIGHT),update_rect.y,
										  update_rect.x+var*(CELDA_HEIGHT),update_rect.y+DRW_AREA_HEIGHT);
	}
	gtk_widget_draw (drawing_area, &update_rect);
}

/*------------------- Metodos para el dibujo de entradas -------------------*/

void Area_disenio::draw_entrada_sur(gdouble x, gdouble y){

	GdkRectangle update_rect;

	GdkGC *color=this->get_color_azul();
	update_rect.x = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	update_rect.width =  CELDA_WIDTH;     //ancho del rectangulo a redibujar
	update_rect.height = 2 * CELDA_HEIGHT;//alto del rectangulo a redibujar

	//dibnujo el rectangulo
	gdk_draw_rectangle (pixmap,color,false,update_rect.x+1,update_rect.y,update_rect.width-2,update_rect.height-(CELDA_HEIGHT/2));
	//dibujo la linea de salida
	gdk_draw_line(pixmap,color,update_rect.x+(CELDA_WIDTH/2),update_rect.y+(CELDA_HEIGHT/2)+(CELDA_WIDTH),
							  update_rect.x+(CELDA_WIDTH/2),update_rect.y+2*(CELDA_WIDTH));

	//linea vertical de la E
	gdk_draw_line(pixmap, color,update_rect.x+3,update_rect.y+4,update_rect.x+3,update_rect.y+11);
	//lineas horizontales
	gdk_draw_line(pixmap,color,update_rect.x+3,update_rect.y+3,update_rect.x+9,update_rect.y+3);
	gdk_draw_line(pixmap, color,update_rect.x+3,update_rect.y+7,update_rect.x+9,update_rect.y+7);
	gdk_draw_line(pixmap, color,update_rect.x+3,update_rect.y+11,update_rect.x+9,update_rect.y+11);

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);
}

void Area_disenio::draw_entrada_norte(gdouble x, gdouble y){

	GdkRectangle update_rect;
	GdkGC *color=this->get_color_azul();

	update_rect.x = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y - (CELDA_HEIGHT) - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	update_rect.width =  CELDA_WIDTH;     //ancho del rectangulo a redibujar
	update_rect.height = 2 * CELDA_HEIGHT +1;//alto del rectangulo a redibujar


	//dibnujo el rectangulo
	gdk_draw_rectangle (pixmap,color,false,update_rect.x,update_rect.y+(CELDA_WIDTH/2),update_rect.width-1,update_rect.height-(CELDA_HEIGHT/2)-1);
	//dibujo la linea de salida
	gdk_draw_line(pixmap,color,update_rect.x+(CELDA_WIDTH/2),update_rect.y+(CELDA_HEIGHT/2),
							  update_rect.x+(CELDA_WIDTH/2),update_rect.y);

	//linea vertical de la E
	gdk_draw_line(pixmap, color,update_rect.x+3,update_rect.y+1+(CELDA_HEIGHT),update_rect.x+3,update_rect.y+9+(CELDA_HEIGHT));
	//lineas horizontales
	gdk_draw_line(pixmap,color,update_rect.x+3,update_rect.y+1+(CELDA_HEIGHT),update_rect.x+9,update_rect.y+1+(CELDA_HEIGHT));
	gdk_draw_line(pixmap, color,update_rect.x+3,update_rect.y+5+(CELDA_HEIGHT),update_rect.x+9,update_rect.y+5+(CELDA_HEIGHT));
	gdk_draw_line(pixmap, color,update_rect.x+3,update_rect.y+9+(CELDA_HEIGHT),update_rect.x+9,update_rect.y+9+(CELDA_HEIGHT));

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);

}

void Area_disenio::draw_entrada_este(gdouble x, gdouble y){

	GdkRectangle update_rect;
	GdkGC *color=this->get_color_azul();

	update_rect.x = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	update_rect.width = 2 * CELDA_WIDTH; //ancho del rectangulo a redibujar
	update_rect.height = CELDA_HEIGHT+1;//alto del rectangulo a redibujar


    //dibnujo el rectangulo
	gdk_draw_rectangle (pixmap,color,false,update_rect.x,update_rect.y,update_rect.width-(CELDA_WIDTH/2),update_rect.height-1);
	//dibujo la linea de salida
	gdk_draw_line(pixmap,color,update_rect.x+(2*CELDA_WIDTH)-(CELDA_WIDTH/2),update_rect.y+(CELDA_HEIGHT/2),
							  update_rect.x+(2*CELDA_WIDTH),update_rect.y+(CELDA_HEIGHT/2));

	//linea vertical de la E
	gdk_draw_line(pixmap, color,update_rect.x+6,update_rect.y+2,update_rect.x+6,update_rect.y+10);
	//lineas horizontales
	gdk_draw_line(pixmap,color,update_rect.x+6,update_rect.y+2,update_rect.x+12,update_rect.y+2);
	gdk_draw_line(pixmap, color,update_rect.x+6,update_rect.y+6,update_rect.x+12,update_rect.y+6);
	gdk_draw_line(pixmap, color,update_rect.x+6,update_rect.y+10,update_rect.x+12,update_rect.y+10);

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);
}

void Area_disenio::draw_entrada_oeste(gdouble x, gdouble y){

	GdkRectangle update_rect;
	GdkGC *color=this->get_color_azul();

	update_rect.x = x -(CELDA_WIDTH/2)-(CELDA_WIDTH); //pos x del rectangulo a redibujar
	update_rect.y = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	update_rect.width = 2*CELDA_WIDTH; //ancho del rectangulo a redibujar
	update_rect.height = CELDA_HEIGHT+1;//alto del rectangulo a redibujar


	//dibnujo el rectangulo
	gdk_draw_rectangle (pixmap,color,false,update_rect.x+6,update_rect.y,update_rect.width -(CELDA_WIDTH/2)-1,update_rect.height-1);
	//dibujo la linea de salida
	gdk_draw_line(pixmap,color,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),
							  update_rect.x+(CELDA_WIDTH/2),update_rect.y+(CELDA_HEIGHT/2));

	//linea vertical de la E
	gdk_draw_line(pixmap, color,update_rect.x+12,update_rect.y+2,update_rect.x+12,update_rect.y+10);
	//lineas horizontales
	gdk_draw_line(pixmap,color,update_rect.x+12,update_rect.y+2,update_rect.x+18,update_rect.y+2);
	gdk_draw_line(pixmap, color,update_rect.x+12,update_rect.y+6,update_rect.x+18,update_rect.y+6);
	gdk_draw_line(pixmap, color,update_rect.x+12,update_rect.y+10,update_rect.x+18,update_rect.y+10);

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);
}

/*------------------- Metodos para el dibujo de salidas -------------------*/

void Area_disenio::draw_salida_sur(gdouble x, gdouble y){

	GdkRectangle update_rect;
	GdkGC *color=this->get_color_azul();

	update_rect.x = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y - (CELDA_HEIGHT) - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	update_rect.width =  CELDA_WIDTH;     //ancho del rectangulo a redibujar
	update_rect.height = 2 * CELDA_HEIGHT +1;//alto del rectangulo a redibujar

	//dibnujo el rectangulo
	gdk_draw_rectangle (pixmap,color,false,update_rect.x,update_rect.y+(CELDA_WIDTH/2),update_rect.width-1,update_rect.height-(CELDA_HEIGHT/2)-1);
	//dibujo la linea de salida
	gdk_draw_line(pixmap,color,update_rect.x+(CELDA_WIDTH/2),update_rect.y+(CELDA_HEIGHT/2),
							  update_rect.x+(CELDA_WIDTH/2),update_rect.y);
	//linea vertical de la S
	gdk_draw_line(pixmap, color,update_rect.x+3,update_rect.y+1+(CELDA_HEIGHT),update_rect.x+3,update_rect.y+5+(CELDA_HEIGHT));
	gdk_draw_line(pixmap, color,update_rect.x+9,update_rect.y+5+(CELDA_HEIGHT),update_rect.x+9,update_rect.y+9+(CELDA_HEIGHT));
	//lineas horizontales
	gdk_draw_line(pixmap,color,update_rect.x+3,update_rect.y+1+(CELDA_HEIGHT),update_rect.x+9,update_rect.y+1+(CELDA_HEIGHT));
	gdk_draw_line(pixmap, color,update_rect.x+3,update_rect.y+5+(CELDA_HEIGHT),update_rect.x+9,update_rect.y+5+(CELDA_HEIGHT));
	gdk_draw_line(pixmap, color,update_rect.x+3,update_rect.y+9+(CELDA_HEIGHT),update_rect.x+9,update_rect.y+9+(CELDA_HEIGHT));

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);

}

void Area_disenio::draw_salida_norte(gdouble x, gdouble y){

	GdkRectangle update_rect;
	GdkGC *color=this->get_color_azul();

	update_rect.x = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	update_rect.width =  CELDA_WIDTH;     //ancho del rectangulo a redibujar
	update_rect.height = 2 * CELDA_HEIGHT;//alto del rectangulo a redibujar


	//dibnujo el rectangulo
	gdk_draw_rectangle (pixmap,color,false,update_rect.x+1,update_rect.y,update_rect.width-2,update_rect.height-(CELDA_HEIGHT/2));
	//dibujo la linea de salida
	gdk_draw_line(pixmap,color,update_rect.x+(CELDA_WIDTH/2),update_rect.y+(CELDA_HEIGHT/2)+(CELDA_WIDTH),
							  update_rect.x+(CELDA_WIDTH/2),update_rect.y+2*(CELDA_WIDTH));

	//linea vertical de la S
	gdk_draw_line(pixmap, color,update_rect.x+3,update_rect.y+3,update_rect.x+3,update_rect.y+7);
	gdk_draw_line(pixmap, color,update_rect.x+9,update_rect.y+7,update_rect.x+9,update_rect.y+11);
	//lineas horizontales
	gdk_draw_line(pixmap,color,update_rect.x+3,update_rect.y+3,update_rect.x+9,update_rect.y+3);
	gdk_draw_line(pixmap, color,update_rect.x+3,update_rect.y+7,update_rect.x+9,update_rect.y+7);
	gdk_draw_line(pixmap, color,update_rect.x+3,update_rect.y+11,update_rect.x+9,update_rect.y+11);

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);
}

void Area_disenio::draw_salida_este(gdouble x, gdouble y){

	GdkRectangle update_rect;
	GdkGC *color=this->get_color_azul();

	update_rect.x = x -CELDA_WIDTH-(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	update_rect.width = 2*CELDA_WIDTH+1; //ancho del rectangulo a redibujar
	update_rect.height = CELDA_HEIGHT;//alto del rectangulo a redibujar

	//dibnujo el rectangulo
	gdk_draw_rectangle (pixmap,color,false,update_rect.x+6,update_rect.y,18,11);
	//dibujo la linea de salida
	gdk_draw_line(pixmap,color,update_rect.x,update_rect.y+6,
							  update_rect.x+6,update_rect.y+6);
	//linea vertical de la S
	gdk_draw_line(pixmap, color,update_rect.x+12,update_rect.y+2,update_rect.x+12,update_rect.y+6);
	gdk_draw_line(pixmap, color,update_rect.x+18,update_rect.y+6,update_rect.x+18,update_rect.y+9);
	//lineas horizontales
	gdk_draw_line(pixmap,color,update_rect.x+12,update_rect.y+2,update_rect.x+18,update_rect.y+2);
	gdk_draw_line(pixmap, color,update_rect.x+12,update_rect.y+6,update_rect.x+18,update_rect.y+6);
	gdk_draw_line(pixmap, color,update_rect.x+12,update_rect.y+9,update_rect.x+18,update_rect.y+9);

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);
}

void Area_disenio::draw_salida_oeste(gdouble x, gdouble y){

	GdkRectangle update_rect;
	GdkGC *color=this->get_color_azul();

	update_rect.x = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	update_rect.width = 2 * CELDA_WIDTH; //ancho del rectangulo a redibujar
	update_rect.height = CELDA_HEIGHT+1;//alto del rectangulo a redibujar


	//dibnujo el rectangulo
	gdk_draw_rectangle (pixmap,color,false,update_rect.x,update_rect.y,update_rect.width-(CELDA_WIDTH/2),update_rect.height-1);
	//dibujo la linea de salida
	gdk_draw_line(pixmap,color,update_rect.x+(2*CELDA_WIDTH)-(CELDA_WIDTH/2),update_rect.y+(CELDA_HEIGHT/2),
							  update_rect.x+(2*CELDA_WIDTH),update_rect.y+(CELDA_HEIGHT/2));

	//linea vertical de la s
	gdk_draw_line(pixmap, color,update_rect.x+6,update_rect.y+2,update_rect.x+6,update_rect.y+6);
	gdk_draw_line(pixmap, color,update_rect.x+12,update_rect.y+6,update_rect.x+12,update_rect.y+10);
	//lineas horizontales
	gdk_draw_line(pixmap,color,update_rect.x+6,update_rect.y+2,update_rect.x+12,update_rect.y+2);
	gdk_draw_line(pixmap, color,update_rect.x+6,update_rect.y+6,update_rect.x+12,update_rect.y+6);
	gdk_draw_line(pixmap, color,update_rect.x+6,update_rect.y+10,update_rect.x+12,update_rect.y+10);

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);
}
/*------------------- Metodos para el dibujo de pistas -------------------*/

void Area_disenio::draw_pista_sur(gdouble x, gdouble y){

	GdkRectangle update_rect;
	GdkGC *color=this->get_color_negro();

	update_rect.x = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y -CELDA_HEIGHT- (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar

	update_rect.width = CELDA_WIDTH; //ancho del rectangulo a redibujar
	update_rect.height = 3 * CELDA_HEIGHT;//alto del rectangulo a redibujar

	gdk_draw_line(pixmap,color,update_rect.x+(CELDA_WIDTH/2),update_rect.y,
								  update_rect.x+(CELDA_WIDTH/2),update_rect.y+(3 * CELDA_HEIGHT));
	gdk_draw_line(pixmap,color,update_rect.x+6,update_rect.y+36,
									  update_rect.x+4,update_rect.y+33);
	gdk_draw_line(pixmap,color,update_rect.x+6,update_rect.y+36,
										  update_rect.x+8,update_rect.y+33);

	gtk_widget_draw (drawing_area, &update_rect);
}

void Area_disenio::draw_pista_norte(gdouble x, gdouble y){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	update_rect.x = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y -CELDA_HEIGHT- (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar

	update_rect.width = CELDA_WIDTH; //ancho del rectangulo a redibujar
	update_rect.height = 3 * CELDA_HEIGHT;//alto del rectangulo a redibujar

	gdk_draw_line(pixmap,color,update_rect.x+(CELDA_WIDTH/2),update_rect.y,
								  update_rect.x+(CELDA_WIDTH/2),update_rect.y+(3 * CELDA_HEIGHT));
	gdk_draw_line(pixmap,color,update_rect.x+6,update_rect.y,
								  update_rect.x+4,update_rect.y+3);
	gdk_draw_line(pixmap,color,update_rect.x+6,update_rect.y,
									  update_rect.x+8,update_rect.y+3);

	gtk_widget_draw (drawing_area, &update_rect);
}

void Area_disenio::draw_pista_este(gdouble x, gdouble y){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	update_rect.x = x -CELDA_HEIGHT- (CELDA_HEIGHT/2); //pos x del rectangulo a redibujar
	update_rect.y = y -(CELDA_WIDTH/2); //pos y del rectangulo a redibujar

	update_rect.width = 3 * CELDA_HEIGHT; //ancho del rectangulo a redibujar
	update_rect.height = CELDA_WIDTH;//alto del rectangulo a redibujar

	gdk_draw_line(pixmap,color,update_rect.x,update_rect.y+(CELDA_WIDTH/2),
								  update_rect.x+(3 * CELDA_HEIGHT),update_rect.y+(CELDA_WIDTH/2));
	gdk_draw_line(pixmap,color,update_rect.x+33,update_rect.y+4,
								  update_rect.x+(3 * CELDA_HEIGHT),update_rect.y+6);
	gdk_draw_line(pixmap,color,update_rect.x+33,update_rect.y+8,
									  update_rect.x+(3 * CELDA_HEIGHT),update_rect.y+6);

	gtk_widget_draw (drawing_area, &update_rect);
}

void Area_disenio::draw_pista_oeste(gdouble x, gdouble y){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	update_rect.x = x -CELDA_HEIGHT- (CELDA_HEIGHT/2); //pos x del rectangulo a redibujar
	update_rect.y = y -(CELDA_WIDTH/2); //pos y del rectangulo a redibujar

	update_rect.width = 3 * CELDA_HEIGHT; //ancho del rectangulo a redibujar
	update_rect.height = CELDA_WIDTH;//alto del rectangulo a redibujar

	gdk_draw_line(pixmap,color,update_rect.x,update_rect.y+(CELDA_WIDTH/2),
								  update_rect.x+(3 * CELDA_HEIGHT),update_rect.y+(CELDA_WIDTH/2));

	gdk_draw_line(pixmap,color,update_rect.x,update_rect.y+6,
									  update_rect.x+3,update_rect.y+8);
	gdk_draw_line(pixmap,color,update_rect.x,update_rect.y+6,
										  update_rect.x+3,update_rect.y+4);

	gtk_widget_draw (drawing_area, &update_rect);

}


/*------------------- Metodos para el dibujo de cajaNegra  -----------------*/

void Area_disenio::draw_CAJANEGRA(gdouble x,gdouble y,int cant_entradas,int cant_salidas){

	 GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	 update_rect.x = x -(CELDA_WIDTH)-(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	 update_rect.y = y - (CELDA_HEIGHT)-(CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	 update_rect.width = 3*CELDA_WIDTH; //ancho del rectangulo a redibujar

	 //cantidad maxima entre entradas o salidas
	 int cant_max = (cant_entradas > cant_salidas)? cant_entradas:cant_salidas;
	 update_rect.height= (cant_max > 2)?(((2*cant_max)-1) * CELDA_HEIGHT):(3 * CELDA_HEIGHT);


	 for (int i = 0; i < cant_entradas; ++i) {

		 gdk_draw_line(pixmap, color,update_rect.x,update_rect.y+ i*(2*CELDA_HEIGHT)+(CELDA_HEIGHT/2),update_rect.x+ (CELDA_HEIGHT/2),update_rect.y+i*(2*CELDA_HEIGHT)+(CELDA_HEIGHT/2));
	 }

	 for (int i = 0; i < cant_salidas; ++i) {

		 gdk_draw_line(pixmap, color,update_rect.x+ (2*CELDA_WIDTH)+(CELDA_WIDTH/2) ,update_rect.y+ i*(2*CELDA_HEIGHT)+(CELDA_HEIGHT/2),update_rect.x+ (3*CELDA_HEIGHT),update_rect.y+i*(2*CELDA_HEIGHT)+(CELDA_HEIGHT/2));
	 }
	 gdk_draw_rectangle (pixmap,color,false,update_rect.x+6,update_rect.y+2,update_rect.width-CELDA_WIDTH ,update_rect.height-4);

	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);

}

/*------------------- Metodos para el dibujo de NOT -------------------*/

void Area_disenio::draw_NOT_sur(gdouble x, gdouble y){

	 GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	 update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	 update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	 gdk_draw_line(pixmap, color,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),update_rect.x+COMPUERTA_HEIGHT,update_rect.y+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,update_rect.x+COMPUERTA_HEIGHT,update_rect.y+(CELDA_HEIGHT/2),update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.x,update_rect.y+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap,color,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT,
	 	 						  update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);
}

void Area_disenio::draw_NOT_oeste(gdouble x, gdouble y){

	 GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	 update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	 update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar


	 //Dibujo compuerta NOT
	 gdk_draw_line(pixmap,color,update_rect.x+COMPUERTA_HEIGHT,update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2),
						  update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT);
	 gdk_draw_line(pixmap, color,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.x,update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2));

	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);
}

void Area_disenio::draw_NOT_este(gdouble x, gdouble y){

	 GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();


	 update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	 update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	 //Dibujo compuerta NOT
	 gdk_draw_line(pixmap,color,update_rect.x,update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2),
						  update_rect.x+(CELDA_WIDTH/2),update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,update_rect.x+(CELDA_WIDTH/2),update_rect.y,update_rect.x+(2*CELDA_WIDTH)+(CELDA_WIDTH/2),update_rect.y+(COMPUERTA_WIDTH/2));
	 gdk_draw_line(pixmap, color,update_rect.x+(CELDA_WIDTH/2),update_rect.y,update_rect.x+(CELDA_WIDTH/2),update_rect.y+COMPUERTA_HEIGHT);
	 gdk_draw_line(pixmap, color,update_rect.x+(CELDA_WIDTH/2),update_rect.y+COMPUERTA_HEIGHT,update_rect.x+(2*CELDA_WIDTH)+(CELDA_WIDTH/2),update_rect.y+(COMPUERTA_WIDTH/2));
	 gdk_draw_line(pixmap, color,update_rect.x+COMPUERTA_WIDTH-(CELDA_WIDTH/2),update_rect.y+CELDA_HEIGHT+CELDA_HEIGHT/2,
						  update_rect.x+COMPUERTA_WIDTH,update_rect.y+CELDA_HEIGHT+CELDA_HEIGHT/2);
	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);
}

void Area_disenio::draw_NOT_norte(gdouble x, gdouble y){

	 GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	 update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	 update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	 //Dibujo compuerta NOT
	 gdk_draw_line(pixmap,color,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT,
						  update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,update_rect.x,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.x+COMPUERTA_HEIGHT,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,update_rect.x,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,update_rect.x+COMPUERTA_HEIGHT,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2),update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y);

	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);
}

/*------------------- Metodos para el dibujo de ANDs -------------------*/

void Area_disenio::draw_AND_este(gdouble x, gdouble y){

	  GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	  update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	  update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	  update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	  update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	  //Dibujo compuerta or
	  gdk_draw_line(pixmap,color,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),
						  update_rect.x+(CELDA_WIDTH/2),update_rect.y+(CELDA_HEIGHT/2));
	  gdk_draw_line(pixmap, color,update_rect.x,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
						  update_rect.x+(CELDA_WIDTH/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_WIDTH/2));
	  gdk_draw_arc(pixmap, color,false,update_rect.x-(3*(CELDA_WIDTH/2)),update_rect.y,4*CELDA_WIDTH,COMPUERTA_HEIGHT,-5850,11700);
	  gdk_draw_line(pixmap, color,update_rect.x+(CELDA_WIDTH/2),update_rect.y,update_rect.x+(CELDA_WIDTH/2),update_rect.y+COMPUERTA_HEIGHT);

	  gdk_draw_line(pixmap, color,update_rect.x+COMPUERTA_WIDTH-(CELDA_WIDTH/2),update_rect.y+CELDA_HEIGHT+CELDA_HEIGHT/2,
						  update_rect.x+COMPUERTA_WIDTH,update_rect.y+CELDA_HEIGHT+CELDA_HEIGHT/2);

	  //informa que la zona dada por update_rect debe actualizarse, el widget
	  //generara un evento de exposicion
	  gtk_widget_draw (drawing_area, &update_rect);

}

void Area_disenio::draw_AND_oeste(gdouble x, gdouble y){

	 GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	  update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	  update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	  update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	  update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	 //dibujo recta
	 gdk_draw_line(pixmap, color,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT);
	 //arco para salida
	 gdk_draw_arc(pixmap, color,false,update_rect.x+(CELDA_WIDTH/2),update_rect.y,4*CELDA_WIDTH,COMPUERTA_HEIGHT,-17400,11700);
	//dibujo entradas
	gdk_draw_line(pixmap, color,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2),update_rect.x+COMPUERTA_HEIGHT,update_rect.y+(CELDA_HEIGHT/2));
	gdk_draw_line(pixmap,color,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
		 	  						  update_rect.x+COMPUERTA_HEIGHT,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	//dibuja salida
	gdk_draw_line(pixmap, color,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.x,update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2));

	 //informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);
}

void Area_disenio::draw_AND_norte(gdouble x, gdouble y){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	 update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 update_rect.width = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
	 update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar


	 //arco para salida
	 gdk_draw_arc(pixmap, color,false,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),COMPUERTA_HEIGHT,4*CELDA_WIDTH,-23100,11450);
	//dibujo entradas
	 gdk_draw_line(pixmap,color,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
	 	  						  update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT);
	 gdk_draw_line(pixmap,color,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT,
	 	 						   update_rect.x+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	//dibuja salida
	 gdk_draw_line(pixmap, color,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
	 //linea
	 gdk_draw_line(pixmap, color,update_rect.x,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.x+COMPUERTA_HEIGHT,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));


	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);
}

void Area_disenio::draw_AND_sur(gdouble x, gdouble y){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	update_rect.width = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
	update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	//recta
	gdk_draw_line(pixmap, color,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),update_rect.x+COMPUERTA_HEIGHT,update_rect.y+(CELDA_HEIGHT/2));
	//arco para salida
	gdk_draw_arc(pixmap, color,false,update_rect.x,update_rect.y-CELDA_WIDTH-(CELDA_WIDTH/2),COMPUERTA_HEIGHT,4*CELDA_WIDTH,-11400,11500);
	//dibujo entradas
	gdk_draw_line(pixmap, color,update_rect.x+(CELDA_HEIGHT/2),update_rect.y,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
	gdk_draw_line(pixmap, color,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
	//dibuja salida
	gdk_draw_line(pixmap,color,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT,
		  	 						  update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));

	 //informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);

}

/*------------------- Metodos para el dibujo de ORs -------------------*/

void Area_disenio::draw_OR_norte(gdouble x, gdouble y){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	 update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 update_rect.width = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
	 update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	 //arco para salida
	 gdk_draw_arc(pixmap, color,false,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),COMPUERTA_HEIGHT,4*CELDA_WIDTH,-23100,11450);
	 //arco para entrada
	 gdk_draw_arc(pixmap, color,false,update_rect.x,update_rect.y+26,COMPUERTA_HEIGHT,CELDA_WIDTH,-23100,11450);

	 //dibujo entradas
	 gdk_draw_line(pixmap,color,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
	 	  						  update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT);
	 gdk_draw_line(pixmap,color,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT,
	 	 						   update_rect.x+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	//dibuja salida
	 gdk_draw_line(pixmap, color,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));

	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);
}

void Area_disenio::draw_OR_este(gdouble x, gdouble y){

	  GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	  update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	  update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	  update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	  update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	  //Dibujo compuerta or
	  gdk_draw_line(pixmap,color,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),
					  update_rect.x+(CELDA_WIDTH/2),update_rect.y+(CELDA_HEIGHT/2));
	  gdk_draw_line(pixmap,color,update_rect.x,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
					  update_rect.x+(CELDA_WIDTH/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_WIDTH/2));
	  gdk_draw_arc(pixmap, color,false,update_rect.x-(3*(CELDA_WIDTH/2)),update_rect.y,4*CELDA_WIDTH,COMPUERTA_HEIGHT,-5850,11700);

	  gdk_draw_arc(pixmap, color,false,update_rect.x-3,update_rect.y,10,COMPUERTA_HEIGHT,-5850,11700);

	  gdk_draw_line(pixmap, color,update_rect.x+COMPUERTA_WIDTH-(CELDA_WIDTH/2),update_rect.y+CELDA_HEIGHT+CELDA_HEIGHT/2,
					  update_rect.x+COMPUERTA_WIDTH,update_rect.y+CELDA_HEIGHT+CELDA_HEIGHT/2);
	  //informa que la zona dada por update_rect debe actualizarse, el widget
	  //generara un evento de exposicion
	  gtk_widget_draw (drawing_area, &update_rect);
}

void Area_disenio::draw_OR_oeste(gdouble x, gdouble y){

	 GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	  update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	  update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	  update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	  update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar


	  //arco para salida
	  gdk_draw_arc(pixmap, color,false,update_rect.x+(CELDA_WIDTH/2),update_rect.y,4*CELDA_WIDTH,COMPUERTA_HEIGHT,-17550,11700);
	  //arco para salida
	  gdk_draw_arc(pixmap, color,false,update_rect.x+27,update_rect.y,CELDA_WIDTH,COMPUERTA_HEIGHT,-17550,11700);


	  //dibujo entradas
	  gdk_draw_line(pixmap, color,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2),update_rect.x+COMPUERTA_HEIGHT,update_rect.y+(CELDA_HEIGHT/2));
	  gdk_draw_line(pixmap,color,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
		 	  						  update_rect.x+COMPUERTA_HEIGHT,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	  //dibuja salida
	  gdk_draw_line(pixmap, color,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.x,update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2));

	  //informa que la zona dada por update_rect debe actualizarse, el widget
	  //generara un evento de exposicion
	  gtk_widget_draw (drawing_area, &update_rect);

}

void Area_disenio::draw_OR_sur(gdouble x, gdouble y){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	update_rect.width = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
	update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	//arco para salida
	gdk_draw_arc(pixmap, color,false,update_rect.x,update_rect.y-CELDA_WIDTH-(CELDA_WIDTH/2),COMPUERTA_HEIGHT,4*CELDA_WIDTH,-11400,11500);
	 //arco para entrada
	gdk_draw_arc(pixmap, color,false,update_rect.x,update_rect.y-3,COMPUERTA_HEIGHT,CELDA_WIDTH,-11400,11500);

	//dibujo entradas
	gdk_draw_line(pixmap, color,update_rect.x+(CELDA_HEIGHT/2),update_rect.y,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
	gdk_draw_line(pixmap, color,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
	//dibuja salida
	 gdk_draw_line(pixmap,color,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT,
								  update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));


	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);
}

/*------------------- Metodos para el dibujo de XORs -------------------*/

void Area_disenio::draw_XOR_este(gdouble x, gdouble y){

  GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

  update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
  update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
  update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
  update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

  //Dibujo compuerta xor
  gdk_draw_line(pixmap,color,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),
				  update_rect.x+(CELDA_WIDTH/2),update_rect.y+(CELDA_HEIGHT/2));
  gdk_draw_line(pixmap, color,update_rect.x,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
				  update_rect.x+(CELDA_WIDTH/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_WIDTH/2));
  gdk_draw_arc(pixmap, color,false,update_rect.x-(3*(CELDA_WIDTH/2)),update_rect.y,4*CELDA_WIDTH,COMPUERTA_HEIGHT,-5850,11700);
  gdk_draw_arc(pixmap, color,false,update_rect.x,update_rect.y,10,COMPUERTA_HEIGHT,-5850,11700);
  gdk_draw_arc(pixmap, color,false,update_rect.x-3,update_rect.y,10,COMPUERTA_HEIGHT,-5850,11700);

  gdk_draw_line(pixmap,color,update_rect.x+COMPUERTA_WIDTH-(CELDA_WIDTH/2),update_rect.y+CELDA_HEIGHT+CELDA_HEIGHT/2,
				  update_rect.x+COMPUERTA_WIDTH,update_rect.y+CELDA_HEIGHT+CELDA_HEIGHT/2);
  //informa que la zona dada por update_rect debe actualizarse, el widget
  //generara un evento de exposicion
  gtk_widget_draw (drawing_area, &update_rect);

}

void Area_disenio::draw_XOR_oeste(gdouble x, gdouble y){

	 GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	 update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	 update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	 //arco para salida
	 gdk_draw_arc(pixmap, color,false,update_rect.x+(CELDA_WIDTH/2),update_rect.y,4*CELDA_WIDTH,COMPUERTA_HEIGHT,-17550,11700);
	 //arco para salida
	 gdk_draw_arc(pixmap, color,false,update_rect.x+27,update_rect.y,CELDA_WIDTH,COMPUERTA_HEIGHT,-17550,11700);
	 gdk_draw_arc(pixmap, color,false,update_rect.x+29,update_rect.y,CELDA_WIDTH,COMPUERTA_HEIGHT,-17550,11700);

	//dibujo entradas
	gdk_draw_line(pixmap, color,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2),update_rect.x+COMPUERTA_HEIGHT,update_rect.y+(CELDA_HEIGHT/2));
	gdk_draw_line(pixmap,color,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
		 	  						  update_rect.x+COMPUERTA_HEIGHT,update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	//dibuja salida
	gdk_draw_line(pixmap, color,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.x,update_rect.y+CELDA_HEIGHT+(CELDA_HEIGHT/2));

	 //informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);
}

void Area_disenio::draw_XOR_norte(gdouble x, gdouble y){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	 update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 update_rect.width = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
	 update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	 //arco para salida
	 gdk_draw_arc(pixmap, color,false,update_rect.x,update_rect.y+(CELDA_HEIGHT/2),COMPUERTA_HEIGHT,4*CELDA_WIDTH,-23100,11450);

	 gdk_draw_arc(pixmap, color,false,update_rect.x,update_rect.y+26,COMPUERTA_HEIGHT,CELDA_WIDTH,-23100,11450);
	 gdk_draw_arc(pixmap, color,false,update_rect.x,update_rect.y+28,COMPUERTA_HEIGHT,CELDA_WIDTH,-23100,11450);
	//dibujo entradas
	 gdk_draw_line(pixmap,color,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
	 	  						  update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT);
	 gdk_draw_line(pixmap,color,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT,
	 	 						   update_rect.x+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	//dibuja salida
	 gdk_draw_line(pixmap, color,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));

	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);
}

void Area_disenio::draw_XOR_sur(gdouble x, gdouble y){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	update_rect.width = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
	update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	//arco para salida
	gdk_draw_arc(pixmap, color,false,update_rect.x,update_rect.y-CELDA_WIDTH-(CELDA_WIDTH/2),COMPUERTA_HEIGHT,4*CELDA_WIDTH,-11400,11500);
	//arco para entrada
	gdk_draw_arc(pixmap, color,false,update_rect.x,update_rect.y-4,COMPUERTA_HEIGHT,CELDA_WIDTH,-11400,11500);
	 //arco para entrada
	gdk_draw_arc(pixmap, color,false,update_rect.x,update_rect.y-2,COMPUERTA_HEIGHT,CELDA_WIDTH,-11400,11500);
	//dibujo entradas
	gdk_draw_line(pixmap, color,update_rect.x+(CELDA_HEIGHT/2),update_rect.y,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
	gdk_draw_line(pixmap, color,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y,update_rect.x+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
	//dibuja salida
	gdk_draw_line(pixmap,color,update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT,
		  	 						  update_rect.x+CELDA_HEIGHT+(CELDA_HEIGHT/2),update_rect.y+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);
}

void Area_disenio::draw_vertice(gdouble x,gdouble y,SENTIDO sentido){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	update_rect.x = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	update_rect.y = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	update_rect.width = CELDA_WIDTH; //ancho del rectangulo a redibujar
	update_rect.height = CELDA_HEIGHT;//alto del rectangulo a redibujar

	switch(sentido){

		case ESTE:{
			gdk_draw_line(pixmap,color,update_rect.x+(CELDA_WIDTH/2),update_rect.y+(CELDA_WIDTH/2),update_rect.x+(CELDA_HEIGHT),update_rect.y+(CELDA_HEIGHT/2));
			break;
		}
		case OESTE:{
			gdk_draw_line(pixmap,color,update_rect.x+(CELDA_WIDTH/2),update_rect.y+(CELDA_WIDTH/2),update_rect.x,update_rect.y+(CELDA_HEIGHT/2));
			break;
			}
		case NORTE:{
			gdk_draw_line(pixmap,color,update_rect.x+(CELDA_WIDTH/2),update_rect.y,update_rect.x+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
			break;
			}
		case SUR:{
			gdk_draw_line(pixmap,color,update_rect.x+(CELDA_WIDTH/2),update_rect.y+(CELDA_WIDTH),update_rect.x+(CELDA_HEIGHT/2),update_rect.y+(CELDA_HEIGHT/2));
			break;
			}
	}

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);


}

/*----------------------------------------------------------------------------*/
