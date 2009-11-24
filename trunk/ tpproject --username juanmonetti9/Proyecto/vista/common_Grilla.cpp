/**************************   Clase GRILLA   *************************/
/**************************   	Grupo 8      *************************/

#include "common_Grilla.h"
GdkPixmap *Grilla::pixmap = NULL;
Modelo_vista_circuito Grilla::matriz;
int Grilla::pos_x; //pos de comienzo de arrastre
int Grilla::pos_y; //pos de comienzo de arrastre


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

	//TODO
	gtk_drag_dest_set(drawing_area,GTK_DEST_DEFAULT_MOTION,target_list,n_targets,GDK_ACTION_COPY);
	gtk_drag_source_set(drawing_area,GDK_BUTTON3_MASK,target_list,n_targets,GDK_ACTION_COPY);

	//conecto la señal de recbo del arrastre con el widget destino y el
	//controlador drag_data_received_handl
	g_signal_connect (drawing_area, "drag-data-received",G_CALLBACK(drag_data_received_handl), NULL);

	//conecto con el controlador para cuando se suelte la seleccion en el destino.
	g_signal_connect (drawing_area, "drag-drop",G_CALLBACK (drag_drop_handl), NULL);

	g_signal_connect (drawing_area, "drag-data-get",G_CALLBACK (drag_data_get_handl), NULL);





	//fin TODO

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
	//gtk_signal_connect (GTK_OBJECT (drawing_area), "motion_notify_event",
		//				  (GtkSignalFunc) motion_notify_event, NULL);
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

void Grilla::draw_sin_commpuerta(GtkWidget *widget, gdouble x, gdouble y){

	GdkRectangle update_rect;

	update_rect.x = x -(COMPUERTA_WIDTH/2)-13; //pos x del rectangulo a redibujar
	update_rect.y = y - (COMPUERTA_HEIGHT/2)-13; //pos y del rectangulo a redibujar
	update_rect.width = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	update_rect.height = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	gdk_draw_rectangle (pixmap,widget->style->white_gc,true,update_rect.x,update_rect.y,update_rect.width,update_rect.height);

	gtk_widget_draw (widget, &update_rect);

}

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
  if (event->button == 3 ){
	  pos_x=event->x;
	  pos_y=event->y;

	  g_print ("Presiono el boton en (%d,%d)\n",pos_x,pos_y);


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



/**
 * Controlador para cuando se suelte la seleccion. checkea si se solto sobre una
 * parte valida del widget .
 * Llama a la funcion gtk_drag_get_data que emite una señal de "drag-data-get"
 * @param widget: destino
 */
gboolean Grilla::drag_drop_handl(GtkWidget *widget, GdkDragContext *context, gint x, gint y, guint time,gpointer user_data){


	GdkAtom    target_type;
	//TODO Chequeo si el lugar donde dropie es valido

	g_print ("Ubicacion de drop de -drag_drop_handl-> (%d,%d)\n",x,y);
	bool lugar_valido=true;
	int _x=x;
	int _y=y;
	int _pos_x=pos_x;
	int _pos_y=pos_y;
	if(matriz.hay_componente(&_pos_x,&_pos_y)){

		g_print ("Hay componente en -> (%d,%d)\n",pos_x,pos_y);
		bool agregado= matriz.agregar_compuerta(&_x,&_y,XOR);
		if(agregado){
			draw_XOR(widget, _x, _y);
			g_print ("Agregue xor enn -> (%d,%d)\n",_x,_y);
			matriz.eliminar_componente(_pos_x,_pos_y);
			g_print ("Elimine\n");
			draw_sin_commpuerta(widget,_pos_x,_pos_y);

		}
	}


	//Si el widget "comienzo" entrega informacion
	if (context-> targets && lugar_valido){

		//Selecciono el target a usar
		target_type = GDK_POINTER_TO_ATOM(g_list_nth_data (context-> targets, TARGET_STRING));
		//Pido los datos del widget "comienzo"
		gtk_drag_get_data(widget,context,target_type,time);
    }

    return  true;
}

/*----------------------------------------------------------------------------*/

/**
 * Controla la señal "drag-data-get" que es emitida desde el controlador
 * drag_drop_handl, con el fin de pedir informacion del arrastre.
 * Emite la señal de "drag-data-received"
 *
 * @param widget: comienzo
 *
 */

void Grilla::drag_data_get_handl(GtkWidget *widget, GdkDragContext *context, GtkSelectionData *selection_data,guint target_type, guint time, gpointer user_data){

	const gchar *string_data = "* Cualquier cosa que quiera enviar *\n";

	g_assert (selection_data != NULL);

	g_print ("-Envio-");

	switch (target_type){

		case TARGET_STRING:
			g_print ("string: %s", string_data);
			gtk_selection_data_set(selection_data,selection_data-> target,_BYTE,(guchar*) string_data,strlen (string_data));
			break;

        default:
        	//No relaciona ningun target
        	g_assert_not_reached ();
        }
}

/*----------------------------------------------------------------------------*/

/**
 * Controlador de recibo de la informacion.
 * Maneja la informacion recibida y llama a gtk_drag_finish para finalizar la operacion,
 * emitiendo una señal de "data-delete"
 *
 * * @param widget: destino
 */

void Grilla::drag_data_received_handl(GtkWidget *widget, GdkDragContext *context, gint x, gint y,GtkSelectionData *selection_data, guint target_type, guint time,gpointer data){

	gchar   *_sdata;

	gboolean dnd_success = false;
	gboolean delete_selection_data = false;
	//todo
	g_print ("- Ubicacion de drop de -drag_data_recv_handl-> (X,Y)=(%d,%d)\n",x,y);
	//fin todo

	/* Deal with what we are given from source */
	if((selection_data != NULL) && (selection_data-> length >= 0)){

		if (context-> action == GDK_ACTION_ASK)
		{
			//Pregunto si quiere mover o copiar
		}

		if (context-> action == GDK_ACTION_MOVE)
			delete_selection_data = true;

		//Chequeo de que el formato cumpla con uno que quiero usar
		g_print ("-Recibo-");
		switch (target_type){

			case TARGET_STRING:
				_sdata = (gchar*)selection_data-> data;
				g_print ("string: %s", _sdata);
				dnd_success = TRUE;
				break;
		default:
				g_print ("No recibo nada de nada");
		}


	}

	if (dnd_success == FALSE)
	{
		g_print ("DnD data transfer failed!\n");
	}

	gtk_drag_finish (context, dnd_success, delete_selection_data, time);
}
