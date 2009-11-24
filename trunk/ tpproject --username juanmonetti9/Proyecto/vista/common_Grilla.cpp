/**************************   Clase GRILLA   *************************/
/**************************   	Grupo 8      *************************/

#include "common_Grilla.h"
GdkPixmap *Grilla::pixmap = NULL;
Modelo_vista_circuito Grilla::matriz;


Grilla::Grilla() {

	Box_notebook= gtk_hbox_new(false,0);
	//Creo el notebook
	notebook= gtk_notebook_new();
	gtk_box_pack_start (GTK_BOX (Box_notebook),notebook, true,true,false);

	tab_noteb1= gtk_label_new ("Area de diseño");
	tab_noteb2= gtk_label_new ("Tabla logica");
	box_noteb1= gtk_hbox_new(false,0);
	//TODO
	GtkWidget *drawing_area;
	GtkWidget *box_noteb1_size=gtk_vbox_new(false,0);
	//Creo el widget drawing area
	drawing_area = gtk_drawing_area_new ();

	//Seteo el tamanio por defecto del drawing area
	gtk_drawing_area_size (GTK_DRAWING_AREA (drawing_area),DRW_AREA_WIDTH,
							  DRW_AREA_HEIGHT);

	//incluyo el drawing area en la caja
	gtk_box_pack_start (GTK_BOX (box_noteb1_size), drawing_area, false,false,false);
	gtk_box_pack_start (GTK_BOX (box_noteb1),box_noteb1_size, false,false,false);
	//muestro el drawing area
	gtk_widget_show (drawing_area);
	gtk_widget_show (box_noteb1_size);

	//conecto con la señal ("expose_event") actualizacion de zona
	gtk_signal_connect (GTK_OBJECT (drawing_area), "expose_event",
						  (GtkSignalFunc) expose_event, NULL);
	//conecto con la señal ("configure_event") producido al modificar el tamanio del drawing area
	gtk_signal_connect (GTK_OBJECT(drawing_area),"configure_event",
						  (GtkSignalFunc) configure_event, NULL);
	//conecto con la señal ("motion_notify_event") de mover el raton
	gtk_signal_connect (GTK_OBJECT (drawing_area), "motion_notify_event",
						  (GtkSignalFunc) motion_notify_event, NULL);
	//conecto con la señal ("button_press_event") de precionar el boton del mouse
	gtk_signal_connect (GTK_OBJECT (drawing_area), "button_press_event",
						  (GtkSignalFunc) button_press_event, NULL);

	//Seteo los eventos que se notificaran al drawing area
	gtk_widget_set_events (drawing_area, GDK_EXPOSURE_MASK | GDK_LEAVE_NOTIFY_MASK |
							GDK_BUTTON_PRESS_MASK | GDK_POINTER_MOTION_MASK |
							GDK_POINTER_MOTION_HINT_MASK);

	//fin TODO
	tablaLogica.completar();
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook),box_noteb1,tab_noteb1);
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook), tablaLogica.getWidget(),tab_noteb2);


}

void Grilla::show() {

	gtk_widget_show(Box_notebook);
	gtk_widget_show(tab_noteb1);
	gtk_widget_show(tab_noteb2);
	gtk_widget_show(box_noteb1);
	tablaLogica.show();
	gtk_widget_show(notebook);


}

void Grilla::escalar(int fa) {


}

GtkWidget* Grilla::getWidget() {

	return Box_notebook;

}


/*----------------------------------------------------------------------------*/

gint Grilla::configure_event (GtkWidget *widget, GdkEventConfigure *event){

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

  return true;
}

/*----------------------------------------------------------------------------*/



gint Grilla::expose_event (GtkWidget *widget, GdkEventExpose *event){

	gdk_draw_pixmap(widget->window,widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
                  pixmap,event->area.x, event->area.y,event->area.x, event->area.y,
                  event->area.width, event->area.height);

  return false;
}
/*----------------------------------------------------------------------------*/


void Grilla::draw_NOT(GtkWidget *widget, gdouble x, gdouble y){

  GdkRectangle update_rect;

  update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
  update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
  update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
  update_rect.height = COMPUERTA_HEIGHT;//alto del rectangulo a redibujar

  //Dibujo compuerta not
  gdk_draw_line(pixmap, widget->style->black_gc,update_rect.x,update_rect.y+10,update_rect.x+5,update_rect.y+10);
  gdk_draw_line(pixmap, widget->style->black_gc,update_rect.x,update_rect.y+20,update_rect.x+5,update_rect.y+20);
  gdk_draw_line(pixmap, widget->style->black_gc,update_rect.x+5,update_rect.y,update_rect.x+5,update_rect.y+30);
  gdk_draw_line(pixmap, widget->style->black_gc,update_rect.x+5,update_rect.y,update_rect.x+35,update_rect.y+15);
  gdk_draw_line(pixmap, widget->style->black_gc,update_rect.x+5,update_rect.y+30,update_rect.x+35,update_rect.y+15);
  gdk_draw_line(pixmap, widget->style->black_gc,update_rect.x+35,update_rect.y+15,update_rect.x+40,update_rect.y+15);
  //informa que la zona dada por update_rect debe actualizarse, el widget
  //generara un evento de exposicion
  gtk_widget_draw (widget, &update_rect);
}



void Grilla::draw_AND(GtkWidget *widget, gdouble x, gdouble y){

  GdkRectangle update_rect;

  update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
  update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
  update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
  update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO

  //Dibujo compuerta and
  gdk_draw_line(pixmap, widget->style->black_gc,update_rect.x,update_rect.y+5,update_rect.x+5,update_rect.y+10);
  gdk_draw_line(pixmap, widget->style->black_gc,update_rect.x,update_rect.y+25,update_rect.x+5,update_rect.y+20);
  gdk_draw_line(pixmap, widget->style->black_gc,update_rect.x+5,update_rect.y,update_rect.x+5,update_rect.y+30);
  gdk_draw_arc(pixmap, widget->style->black_gc,false,update_rect.x-25,update_rect.y,60,30,-5850,11700);
  gdk_draw_line(pixmap, widget->style->black_gc,update_rect.x+35,update_rect.y+15,update_rect.x+40,update_rect.y+15);

  //informa que la zona dada por update_rect debe actualizarse, el widget
  //generara un evento de exposicion
  gtk_widget_draw (widget, &update_rect);
}


void Grilla::draw_OR(GtkWidget *widget, gdouble x, gdouble y){

  GdkRectangle update_rect;

  update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
  update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
  update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
  update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO

  //Dibujo compuerta or
  gdk_draw_line(pixmap, widget->style->black_gc,update_rect.x,update_rect.y+10,update_rect.x+8,update_rect.y+10);
  gdk_draw_line(pixmap, widget->style->black_gc,update_rect.x,update_rect.y+20,update_rect.x+8,update_rect.y+20);
  gdk_draw_arc(pixmap, widget->style->black_gc,false,update_rect.x-25,update_rect.y,60,30,-5850,11700);
  gdk_draw_arc(pixmap, widget->style->black_gc,false,update_rect.x,update_rect.y,10,30,-5850,11700);

  gdk_draw_line(pixmap, widget->style->black_gc,update_rect.x+35,update_rect.y+15,update_rect.x+40,update_rect.y+15);
  //informa que la zona dada por update_rect debe actualizarse, el widget
  //generara un evento de exposicion
  gtk_widget_draw (widget, &update_rect);
}




void Grilla::draw_XOR(GtkWidget *widget, gdouble x, gdouble y){

  GdkRectangle update_rect;

  update_rect.x = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
  update_rect.y = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
  update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
  update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar TODO PARCHE MAS UNO

  //Dibujo compuerta xor
  gdk_draw_line(pixmap, widget->style->black_gc,update_rect.x,update_rect.y+6,update_rect.x+5,update_rect.y+6);
  gdk_draw_line(pixmap, widget->style->black_gc,update_rect.x,update_rect.y+32,update_rect.x+5,update_rect.y+32);
  gdk_draw_arc(pixmap, widget->style->black_gc,false,update_rect.x-25,update_rect.y,60,39,-5850,11700);
  gdk_draw_arc(pixmap, widget->style->black_gc,false,update_rect.x,update_rect.y,10,39,-5850,11700);
  gdk_draw_arc(pixmap, widget->style->black_gc,false,update_rect.x-3,update_rect.y,10,39,-5850,11700);

  gdk_draw_line(pixmap, widget->style->black_gc,update_rect.x+35,update_rect.y+19,update_rect.x+39,update_rect.y+19);
  //informa que la zona dada por update_rect debe actualizarse, el widget
  //generara un evento de exposicion
  gtk_widget_draw (widget, &update_rect);
}
/*----------------------------------------------------------------------------*/



gint Grilla::button_press_event (GtkWidget *widget, GdkEventButton *event){

  if (event->button == 1 && pixmap != NULL){
	  // si es el boton izq del raton
	  //intento agregar una compuerta

	  int x=event->x;
	  int y=event->y;
	  bool agregada= Grilla::matriz.agregar_compuerta(&x,&y,XOR);
	  if(agregada){
		  //TODO
		  g_print("Agregada true tendria que dibujar XOR \n");
		  //fin TODO
		  draw_XOR(widget, x, y);
	  }
	  else{
		  //TODO
		  g_print("Agregada FALSE \n");
		  //fin TODO
	  }

  }


  return true;
}
/*----------------------------------------------------------------------------*/

gint Grilla::motion_notify_event (GtkWidget *widget, GdkEventMotion *event){

  int x, y;
  GdkModifierType state;

  if (event->is_hint){
	  gdk_window_get_pointer (event->window, &x, &y, &state);

  }
  else
    {
      x = event->x;
      y = event->y;
      state = (GdkModifierType)event->state;

    }

  //TODO cambiar GDK_BUTTON3_MASK por boton 1
  if (state & GDK_BUTTON3_MASK && pixmap != NULL){
	  //Si muevo y tengo presionado el boton izq del raton
	  draw_XOR(widget, x, y);
  }


  return true;
}
/*----------------------------------------------------------------------------*/
