#include "common_Imprimir.h"

#include <cairo/cairo.h>

/*------------------- Metodos para el dibujo de entradas -------------------*/

void Imprimir::draw_entrada_sur(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	int widthRectangulo =  CELDA_WIDTH;     //ancho del rectangulo a redibujar
	int heightRectangulo = 2 * CELDA_HEIGHT;//alto del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 0.5);

	//dibnujo el rectangulo
	cairo_rectangle(cr, xRectangulo+1,yRectangulo,widthRectangulo-2,heightRectangulo-(CELDA_HEIGHT/2));
	cairo_stroke_preserve(cr);
	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_fill(cr);

	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 0.5);

	cairo_move_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2)+(CELDA_WIDTH));
	cairo_line_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+2*(CELDA_WIDTH));

	//linea vertical de la E
	cairo_move_to(cr, xRectangulo+3,yRectangulo+4);
	cairo_line_to(cr, xRectangulo+3,yRectangulo+11);

	//lineas horizontales
	cairo_move_to(cr, xRectangulo+3,yRectangulo+3);
	cairo_line_to(cr, xRectangulo+9,yRectangulo+3);

	cairo_move_to(cr, xRectangulo+3,yRectangulo+7);
	cairo_line_to(cr, xRectangulo+9,yRectangulo+7);

	cairo_move_to(cr, xRectangulo+3,yRectangulo+11);
	cairo_line_to(cr, xRectangulo+9,yRectangulo+11);

	cairo_stroke(cr);

}

void Imprimir::draw_entrada_norte(gdouble x, gdouble y,cairo_t *cr){

	GdkRectangle update_rect;
	GdkGC *color=this->get_color_azul();

	xRectangulo = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	yRectangulo = y - (CELDA_HEIGHT) - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	widthRectangulo =  CELDA_WIDTH;     //ancho del rectangulo a redibujar
	heightRectangulo = 2 * CELDA_HEIGHT +1;//alto del rectangulo a redibujar


	//dibnujo el rectangulo
	gdk_draw_rectangle (pixmap,color,false,xRectangulo,yRectangulo+(CELDA_WIDTH/2),widthRectangulo-1,heightRectangulo-(CELDA_HEIGHT/2)-1);
	//dibujo la linea de salida
	gdk_draw_line(pixmap,color,xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2),
							  xRectangulo+(CELDA_WIDTH/2),yRectangulo);

	//linea vertical de la E
	gdk_draw_line(pixmap, color,xRectangulo+3,yRectangulo+1+(CELDA_HEIGHT),xRectangulo+3,yRectangulo+9+(CELDA_HEIGHT));
	//lineas horizontales
	gdk_draw_line(pixmap,color,xRectangulo+3,yRectangulo+1+(CELDA_HEIGHT),xRectangulo+9,yRectangulo+1+(CELDA_HEIGHT));
	gdk_draw_line(pixmap, color,xRectangulo+3,yRectangulo+5+(CELDA_HEIGHT),xRectangulo+9,yRectangulo+5+(CELDA_HEIGHT));
	gdk_draw_line(pixmap, color,xRectangulo+3,yRectangulo+9+(CELDA_HEIGHT),xRectangulo+9,yRectangulo+9+(CELDA_HEIGHT));

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);

}

void Imprimir::draw_entrada_este(gdouble x, gdouble y,cairo_t *cr){

	GdkRectangle update_rect;
	GdkGC *color=this->get_color_azul();

	xRectangulo = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	yRectangulo = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	widthRectangulo = 2 * CELDA_WIDTH; //ancho del rectangulo a redibujar
	heightRectangulo = CELDA_HEIGHT+1;//alto del rectangulo a redibujar


    //dibnujo el rectangulo
	gdk_draw_rectangle (pixmap,color,false,xRectangulo,yRectangulo,widthRectangulo-(CELDA_WIDTH/2),heightRectangulo-1);
	//dibujo la linea de salida
	gdk_draw_line(pixmap,color,xRectangulo+(2*CELDA_WIDTH)-(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2),
							  xRectangulo+(2*CELDA_WIDTH),yRectangulo+(CELDA_HEIGHT/2));

	//linea vertical de la E
	gdk_draw_line(pixmap, color,xRectangulo+6,yRectangulo+2,xRectangulo+6,yRectangulo+10);
	//lineas horizontales
	gdk_draw_line(pixmap,color,xRectangulo+6,yRectangulo+2,xRectangulo+12,yRectangulo+2);
	gdk_draw_line(pixmap, color,xRectangulo+6,yRectangulo+6,xRectangulo+12,yRectangulo+6);
	gdk_draw_line(pixmap, color,xRectangulo+6,yRectangulo+10,xRectangulo+12,yRectangulo+10);

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);
}

void Imprimir::draw_entrada_oeste(gdouble x, gdouble y,cairo_t *cr){

	GdkRectangle update_rect;
	GdkGC *color=this->get_color_azul();

	xRectangulo = x -(CELDA_WIDTH/2)-(CELDA_WIDTH); //pos x del rectangulo a redibujar
	yRectangulo = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	widthRectangulo = 2*CELDA_WIDTH; //ancho del rectangulo a redibujar
	heightRectangulo = CELDA_HEIGHT+1;//alto del rectangulo a redibujar


	//dibnujo el rectangulo
	gdk_draw_rectangle (pixmap,color,false,xRectangulo+6,yRectangulo,widthRectangulo -(CELDA_WIDTH/2)-1,heightRectangulo-1);
	//dibujo la linea de salida
	gdk_draw_line(pixmap,color,xRectangulo,yRectangulo+(CELDA_HEIGHT/2),
							  xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2));

	//linea vertical de la E
	gdk_draw_line(pixmap, color,xRectangulo+12,yRectangulo+2,xRectangulo+12,yRectangulo+10);
	//lineas horizontales
	gdk_draw_line(pixmap,color,xRectangulo+12,yRectangulo+2,xRectangulo+18,yRectangulo+2);
	gdk_draw_line(pixmap, color,xRectangulo+12,yRectangulo+6,xRectangulo+18,yRectangulo+6);
	gdk_draw_line(pixmap, color,xRectangulo+12,yRectangulo+10,xRectangulo+18,yRectangulo+10);

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);
}

/*------------------- Metodos para el dibujo de salidas -------------------*/

void Imprimir::draw_salida_sur(gdouble x, gdouble y,cairo_t *cr){

	GdkRectangle update_rect;
	GdkGC *color=this->get_color_azul();

	xRectangulo = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	yRectangulo = y - (CELDA_HEIGHT) - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	widthRectangulo =  CELDA_WIDTH;     //ancho del rectangulo a redibujar
	heightRectangulo = 2 * CELDA_HEIGHT +1;//alto del rectangulo a redibujar

	//dibnujo el rectangulo
	gdk_draw_rectangle (pixmap,color,false,xRectangulo,yRectangulo+(CELDA_WIDTH/2),widthRectangulo-1,heightRectangulo-(CELDA_HEIGHT/2)-1);
	//dibujo la linea de salida
	gdk_draw_line(pixmap,color,xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2),
							  xRectangulo+(CELDA_WIDTH/2),yRectangulo);
	//linea vertical de la S
	gdk_draw_line(pixmap, color,xRectangulo+3,yRectangulo+1+(CELDA_HEIGHT),xRectangulo+3,yRectangulo+5+(CELDA_HEIGHT));
	gdk_draw_line(pixmap, color,xRectangulo+9,yRectangulo+5+(CELDA_HEIGHT),xRectangulo+9,yRectangulo+9+(CELDA_HEIGHT));
	//lineas horizontales
	gdk_draw_line(pixmap,color,xRectangulo+3,yRectangulo+1+(CELDA_HEIGHT),xRectangulo+9,yRectangulo+1+(CELDA_HEIGHT));
	gdk_draw_line(pixmap, color,xRectangulo+3,yRectangulo+5+(CELDA_HEIGHT),xRectangulo+9,yRectangulo+5+(CELDA_HEIGHT));
	gdk_draw_line(pixmap, color,xRectangulo+3,yRectangulo+9+(CELDA_HEIGHT),xRectangulo+9,yRectangulo+9+(CELDA_HEIGHT));

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);

}

void Imprimir::draw_salida_norte(gdouble x, gdouble y,cairo_t *cr){

	GdkRectangle update_rect;
	GdkGC *color=this->get_color_azul();

	xRectangulo = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	yRectangulo = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	widthRectangulo =  CELDA_WIDTH;     //ancho del rectangulo a redibujar
	heightRectangulo = 2 * CELDA_HEIGHT;//alto del rectangulo a redibujar


	//dibnujo el rectangulo
	gdk_draw_rectangle (pixmap,color,false,xRectangulo+1,yRectangulo,widthRectangulo-2,heightRectangulo-(CELDA_HEIGHT/2));
	//dibujo la linea de salida
	gdk_draw_line(pixmap,color,xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2)+(CELDA_WIDTH),
							  xRectangulo+(CELDA_WIDTH/2),yRectangulo+2*(CELDA_WIDTH));

	//linea vertical de la S
	gdk_draw_line(pixmap, color,xRectangulo+3,yRectangulo+3,xRectangulo+3,yRectangulo+7);
	gdk_draw_line(pixmap, color,xRectangulo+9,yRectangulo+7,xRectangulo+9,yRectangulo+11);
	//lineas horizontales
	gdk_draw_line(pixmap,color,xRectangulo+3,yRectangulo+3,xRectangulo+9,yRectangulo+3);
	gdk_draw_line(pixmap, color,xRectangulo+3,yRectangulo+7,xRectangulo+9,yRectangulo+7);
	gdk_draw_line(pixmap, color,xRectangulo+3,yRectangulo+11,xRectangulo+9,yRectangulo+11);

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);
}

void Imprimir::draw_salida_este(gdouble x, gdouble y,cairo_t *cr){

	GdkRectangle update_rect;
	GdkGC *color=this->get_color_azul();

	xRectangulo = x -CELDA_WIDTH-(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	yRectangulo = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	widthRectangulo = 2*CELDA_WIDTH+1; //ancho del rectangulo a redibujar
	heightRectangulo = CELDA_HEIGHT;//alto del rectangulo a redibujar

	//dibnujo el rectangulo
	gdk_draw_rectangle (pixmap,color,false,xRectangulo+6,yRectangulo,18,11);
	//dibujo la linea de salida
	gdk_draw_line(pixmap,color,xRectangulo,yRectangulo+6,
							  xRectangulo+6,yRectangulo+6);
	//linea vertical de la S
	gdk_draw_line(pixmap, color,xRectangulo+12,yRectangulo+2,xRectangulo+12,yRectangulo+6);
	gdk_draw_line(pixmap, color,xRectangulo+18,yRectangulo+6,xRectangulo+18,yRectangulo+9);
	//lineas horizontales
	gdk_draw_line(pixmap,color,xRectangulo+12,yRectangulo+2,xRectangulo+18,yRectangulo+2);
	gdk_draw_line(pixmap, color,xRectangulo+12,yRectangulo+6,xRectangulo+18,yRectangulo+6);
	gdk_draw_line(pixmap, color,xRectangulo+12,yRectangulo+9,xRectangulo+18,yRectangulo+9);

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);
}

void Imprimir::draw_salida_oeste(gdouble x, gdouble y,cairo_t *cr){

	GdkRectangle update_rect;
	GdkGC *color=this->get_color_azul();

	xRectangulo = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	yRectangulo = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	widthRectangulo = 2 * CELDA_WIDTH; //ancho del rectangulo a redibujar
	heightRectangulo = CELDA_HEIGHT+1;//alto del rectangulo a redibujar


	//dibnujo el rectangulo
	gdk_draw_rectangle (pixmap,color,false,xRectangulo,yRectangulo,widthRectangulo-(CELDA_WIDTH/2),heightRectangulo-1);
	//dibujo la linea de salida
	gdk_draw_line(pixmap,color,xRectangulo+(2*CELDA_WIDTH)-(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2),
							  xRectangulo+(2*CELDA_WIDTH),yRectangulo+(CELDA_HEIGHT/2));

	//linea vertical de la s
	gdk_draw_line(pixmap, color,xRectangulo+6,yRectangulo+2,xRectangulo+6,yRectangulo+6);
	gdk_draw_line(pixmap, color,xRectangulo+12,yRectangulo+6,xRectangulo+12,yRectangulo+10);
	//lineas horizontales
	gdk_draw_line(pixmap,color,xRectangulo+6,yRectangulo+2,xRectangulo+12,yRectangulo+2);
	gdk_draw_line(pixmap, color,xRectangulo+6,yRectangulo+6,xRectangulo+12,yRectangulo+6);
	gdk_draw_line(pixmap, color,xRectangulo+6,yRectangulo+10,xRectangulo+12,yRectangulo+10);

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);
}
/*------------------- Metodos para el dibujo de pistas -------------------*/

void Imprimir::draw_pista_sur(gdouble x, gdouble y,cairo_t *cr){

	GdkRectangle update_rect;
	GdkGC *color=this->get_color_negro();

	xRectangulo = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	yRectangulo = y -CELDA_HEIGHT- (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar

	widthRectangulo = CELDA_WIDTH; //ancho del rectangulo a redibujar
	heightRectangulo = 3 * CELDA_HEIGHT;//alto del rectangulo a redibujar

	gdk_draw_line(pixmap,color,xRectangulo+(CELDA_WIDTH/2),yRectangulo,
								  xRectangulo+(CELDA_WIDTH/2),yRectangulo+(3 * CELDA_HEIGHT));
	gdk_draw_line(pixmap,color,xRectangulo+6,yRectangulo+36,
									  xRectangulo+4,yRectangulo+33);
	gdk_draw_line(pixmap,color,xRectangulo+6,yRectangulo+36,
										  xRectangulo+8,yRectangulo+33);

	gtk_widget_draw (drawing_area, &update_rect);
}

void Imprimir::draw_pista_norte(gdouble x, gdouble y,cairo_t *cr){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	xRectangulo = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	yRectangulo = y -CELDA_HEIGHT- (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar

	widthRectangulo = CELDA_WIDTH; //ancho del rectangulo a redibujar
	heightRectangulo = 3 * CELDA_HEIGHT;//alto del rectangulo a redibujar

	gdk_draw_line(pixmap,color,xRectangulo+(CELDA_WIDTH/2),yRectangulo,
								  xRectangulo+(CELDA_WIDTH/2),yRectangulo+(3 * CELDA_HEIGHT));
	gdk_draw_line(pixmap,color,xRectangulo+6,yRectangulo,
								  xRectangulo+4,yRectangulo+3);
	gdk_draw_line(pixmap,color,xRectangulo+6,yRectangulo,
									  xRectangulo+8,yRectangulo+3);

	gtk_widget_draw (drawing_area, &update_rect);
}

void Imprimir::draw_pista_este(gdouble x, gdouble y,cairo_t *cr){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	xRectangulo = x -CELDA_HEIGHT- (CELDA_HEIGHT/2); //pos x del rectangulo a redibujar
	yRectangulo = y -(CELDA_WIDTH/2); //pos y del rectangulo a redibujar

	widthRectangulo = 3 * CELDA_HEIGHT; //ancho del rectangulo a redibujar
	heightRectangulo = CELDA_WIDTH;//alto del rectangulo a redibujar

	gdk_draw_line(pixmap,color,xRectangulo,yRectangulo+(CELDA_WIDTH/2),
								  xRectangulo+(3 * CELDA_HEIGHT),yRectangulo+(CELDA_WIDTH/2));
	gdk_draw_line(pixmap,color,xRectangulo+33,yRectangulo+4,
								  xRectangulo+(3 * CELDA_HEIGHT),yRectangulo+6);
	gdk_draw_line(pixmap,color,xRectangulo+33,yRectangulo+8,
									  xRectangulo+(3 * CELDA_HEIGHT),yRectangulo+6);

	gtk_widget_draw (drawing_area, &update_rect);
}

void Imprimir::draw_pista_oeste(gdouble x, gdouble y,cairo_t *cr){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	xRectangulo = x -CELDA_HEIGHT- (CELDA_HEIGHT/2); //pos x del rectangulo a redibujar
	yRectangulo = y -(CELDA_WIDTH/2); //pos y del rectangulo a redibujar

	widthRectangulo = 3 * CELDA_HEIGHT; //ancho del rectangulo a redibujar
	heightRectangulo = CELDA_WIDTH;//alto del rectangulo a redibujar

	gdk_draw_line(pixmap,color,xRectangulo,yRectangulo+(CELDA_WIDTH/2),
								  xRectangulo+(3 * CELDA_HEIGHT),yRectangulo+(CELDA_WIDTH/2));

	gdk_draw_line(pixmap,color,xRectangulo,yRectangulo+6,
									  xRectangulo+3,yRectangulo+8);
	gdk_draw_line(pixmap,color,xRectangulo,yRectangulo+6,
										  xRectangulo+3,yRectangulo+4);

	gtk_widget_draw (drawing_area, &update_rect);

}


/*------------------- Metodos para el dibujo de cajaNegra  -----------------*/

void Imprimir::draw_CAJANEGRA(gdouble x,gdouble y,cairo_t *cr,int cant_entradas,int cant_salidas){

	 GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	 xRectangulo = x -(CELDA_WIDTH)-(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	 yRectangulo = y - (CELDA_HEIGHT)-(CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	 widthRectangulo = 3*CELDA_WIDTH; //ancho del rectangulo a redibujar

	 //cantidad maxima entre entradas o salidas
	 int cant_max = (cant_entradas > cant_salidas)? cant_entradas:cant_salidas;
	 heightRectangulo= (cant_max > 2)?(((2*cant_max)-1) * CELDA_HEIGHT):(3 * CELDA_HEIGHT);


	 for (int i = 0; i < cant_entradas; ++i) {

		 gdk_draw_line(pixmap, color,xRectangulo,yRectangulo+ i*(2*CELDA_HEIGHT)+(CELDA_HEIGHT/2),xRectangulo+ (CELDA_HEIGHT/2),yRectangulo+i*(2*CELDA_HEIGHT)+(CELDA_HEIGHT/2));
	 }

	 for (int i = 0; i < cant_salidas; ++i) {

		 gdk_draw_line(pixmap, color,xRectangulo+ (2*CELDA_WIDTH)+(CELDA_WIDTH/2) ,yRectangulo+ i*(2*CELDA_HEIGHT)+(CELDA_HEIGHT/2),xRectangulo+ (3*CELDA_HEIGHT),yRectangulo+i*(2*CELDA_HEIGHT)+(CELDA_HEIGHT/2));
	 }
	 gdk_draw_rectangle (pixmap,color,false,xRectangulo+6,yRectangulo+2,widthRectangulo-CELDA_WIDTH ,heightRectangulo-4);

	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);

}

/*------------------- Metodos para el dibujo de NOT -------------------*/

void Imprimir::draw_NOT_sur(gdouble x, gdouble y,cairo_t *cr){

	 GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	 xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 widthRectangulo = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	 heightRectangulo = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	 gdk_draw_line(pixmap, color,xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo,xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,xRectangulo,yRectangulo+(CELDA_HEIGHT/2),xRectangulo+COMPUERTA_HEIGHT,yRectangulo+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,xRectangulo+COMPUERTA_HEIGHT,yRectangulo+(CELDA_HEIGHT/2),xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),xRectangulo,yRectangulo+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap,color,xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT,
	 	 						  xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);
}

void Imprimir::draw_NOT_oeste(gdouble x, gdouble y,cairo_t *cr){

	 GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	 xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 widthRectangulo = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	 heightRectangulo = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar


	 //Dibujo compuerta NOT
	 gdk_draw_line(pixmap,color,xRectangulo+COMPUERTA_HEIGHT,yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),
						  xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);
	 gdk_draw_line(pixmap, color,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo,xRectangulo+(CELDA_HEIGHT/2),yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT,xRectangulo+(CELDA_HEIGHT/2),yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,xRectangulo+(CELDA_HEIGHT/2),yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),xRectangulo,yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));

	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);
}

void Imprimir::draw_NOT_este(gdouble x, gdouble y,cairo_t *cr){

	 GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();


	 xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 widthRectangulo = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	 heightRectangulo = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	 //Dibujo compuerta NOT
	 gdk_draw_line(pixmap,color,xRectangulo,yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),
						  xRectangulo+(CELDA_WIDTH/2),yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,xRectangulo+(CELDA_WIDTH/2),yRectangulo,xRectangulo+(2*CELDA_WIDTH)+(CELDA_WIDTH/2),yRectangulo+(COMPUERTA_WIDTH/2));
	 gdk_draw_line(pixmap, color,xRectangulo+(CELDA_WIDTH/2),yRectangulo,xRectangulo+(CELDA_WIDTH/2),yRectangulo+COMPUERTA_HEIGHT);
	 gdk_draw_line(pixmap, color,xRectangulo+(CELDA_WIDTH/2),yRectangulo+COMPUERTA_HEIGHT,xRectangulo+(2*CELDA_WIDTH)+(CELDA_WIDTH/2),yRectangulo+(COMPUERTA_WIDTH/2));
	 gdk_draw_line(pixmap, color,xRectangulo+COMPUERTA_WIDTH-(CELDA_WIDTH/2),yRectangulo+CELDA_HEIGHT+CELDA_HEIGHT/2,
						  xRectangulo+COMPUERTA_WIDTH,yRectangulo+CELDA_HEIGHT+CELDA_HEIGHT/2);
	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);
}

void Imprimir::draw_NOT_norte(gdouble x, gdouble y,cairo_t *cr){

	 GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	 xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 widthRectangulo = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	 heightRectangulo = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	 //Dibujo compuerta NOT
	 gdk_draw_line(pixmap,color,xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT,
						  xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,xRectangulo,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),xRectangulo+COMPUERTA_HEIGHT,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,xRectangulo,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,xRectangulo+COMPUERTA_HEIGHT,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
	 gdk_draw_line(pixmap, color,xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2),xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo);

	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);
}

/*------------------- Metodos para el dibujo de ANDs -------------------*/

void Imprimir::draw_AND_este(gdouble x, gdouble y,cairo_t *cr){

	  GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	  xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	  yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	  widthRectangulo = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	  heightRectangulo = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	  //Dibujo compuerta or
	  gdk_draw_line(pixmap,color,xRectangulo,yRectangulo+(CELDA_HEIGHT/2),
						  xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2));
	  gdk_draw_line(pixmap, color,xRectangulo,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
						  xRectangulo+(CELDA_WIDTH/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_WIDTH/2));
	  gdk_draw_arc(pixmap, color,false,xRectangulo-(3*(CELDA_WIDTH/2)),yRectangulo,4*CELDA_WIDTH,COMPUERTA_HEIGHT,-5850,11700);
	  gdk_draw_line(pixmap, color,xRectangulo+(CELDA_WIDTH/2),yRectangulo,xRectangulo+(CELDA_WIDTH/2),yRectangulo+COMPUERTA_HEIGHT);

	  gdk_draw_line(pixmap, color,xRectangulo+COMPUERTA_WIDTH-(CELDA_WIDTH/2),yRectangulo+CELDA_HEIGHT+CELDA_HEIGHT/2,
						  xRectangulo+COMPUERTA_WIDTH,yRectangulo+CELDA_HEIGHT+CELDA_HEIGHT/2);

	  //informa que la zona dada por update_rect debe actualizarse, el widget
	  //generara un evento de exposicion
	  gtk_widget_draw (drawing_area, &update_rect);

}

void Imprimir::draw_AND_oeste(gdouble x, gdouble y,cairo_t *cr){

	 GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	  xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	  yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	  widthRectangulo = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	  heightRectangulo = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	 //dibujo recta
	 gdk_draw_line(pixmap, color,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);
	 //arco para salida
	 gdk_draw_arc(pixmap, color,false,xRectangulo+(CELDA_WIDTH/2),yRectangulo,4*CELDA_WIDTH,COMPUERTA_HEIGHT,-17400,11700);
	//dibujo entradas
	gdk_draw_line(pixmap, color,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2),xRectangulo+COMPUERTA_HEIGHT,yRectangulo+(CELDA_HEIGHT/2));
	gdk_draw_line(pixmap,color,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
		 	  						  xRectangulo+COMPUERTA_HEIGHT,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	//dibuja salida
	gdk_draw_line(pixmap, color,xRectangulo+(CELDA_HEIGHT/2),yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),xRectangulo,yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));

	 //informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);
}

void Imprimir::draw_AND_norte(gdouble x, gdouble y,cairo_t *cr){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	 xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 widthRectangulo = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
	 heightRectangulo = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar


	 //arco para salida
	 gdk_draw_arc(pixmap, color,false,xRectangulo,yRectangulo+(CELDA_HEIGHT/2),COMPUERTA_HEIGHT,4*CELDA_WIDTH,-23100,11450);
	//dibujo entradas
	 gdk_draw_line(pixmap,color,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
	 	  						  xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);
	 gdk_draw_line(pixmap,color,xRectangulo+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT,
	 	 						   xRectangulo+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	//dibuja salida
	 gdk_draw_line(pixmap, color,xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo,xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
	 //linea
	 gdk_draw_line(pixmap, color,xRectangulo,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),xRectangulo+COMPUERTA_HEIGHT,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));


	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);
}

void Imprimir::draw_AND_sur(gdouble x, gdouble y,cairo_t *cr){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	widthRectangulo = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
	heightRectangulo = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	//recta
	gdk_draw_line(pixmap, color,xRectangulo,yRectangulo+(CELDA_HEIGHT/2),xRectangulo+COMPUERTA_HEIGHT,yRectangulo+(CELDA_HEIGHT/2));
	//arco para salida
	gdk_draw_arc(pixmap, color,false,xRectangulo,yRectangulo-CELDA_WIDTH-(CELDA_WIDTH/2),COMPUERTA_HEIGHT,4*CELDA_WIDTH,-11400,11500);
	//dibujo entradas
	gdk_draw_line(pixmap, color,xRectangulo+(CELDA_HEIGHT/2),yRectangulo,xRectangulo+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
	gdk_draw_line(pixmap, color,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
	//dibuja salida
	gdk_draw_line(pixmap,color,xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT,
		  	 						  xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));

	 //informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);

}

/*------------------- Metodos para el dibujo de ORs -------------------*/

void Imprimir::draw_OR_norte(gdouble x, gdouble y,cairo_t *cr){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	 xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 widthRectangulo = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
	 heightRectangulo = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	 //arco para salida
	 gdk_draw_arc(pixmap, color,false,xRectangulo,yRectangulo+(CELDA_HEIGHT/2),COMPUERTA_HEIGHT,4*CELDA_WIDTH,-23100,11450);
	 //arco para entrada
	 gdk_draw_arc(pixmap, color,false,xRectangulo,yRectangulo+26,COMPUERTA_HEIGHT,CELDA_WIDTH,-23100,11450);

	 //dibujo entradas
	 gdk_draw_line(pixmap,color,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
	 	  						  xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);
	 gdk_draw_line(pixmap,color,xRectangulo+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT,
	 	 						   xRectangulo+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	//dibuja salida
	 gdk_draw_line(pixmap, color,xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo,xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));

	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);
}

void Imprimir::draw_OR_este(gdouble x, gdouble y,cairo_t *cr){

	  GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	  xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	  yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	  widthRectangulo = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	  heightRectangulo = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	  //Dibujo compuerta or
	  gdk_draw_line(pixmap,color,xRectangulo,yRectangulo+(CELDA_HEIGHT/2),
					  xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2));
	  gdk_draw_line(pixmap,color,xRectangulo,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
					  xRectangulo+(CELDA_WIDTH/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_WIDTH/2));
	  gdk_draw_arc(pixmap, color,false,xRectangulo-(3*(CELDA_WIDTH/2)),yRectangulo,4*CELDA_WIDTH,COMPUERTA_HEIGHT,-5850,11700);

	  gdk_draw_arc(pixmap, color,false,xRectangulo-3,yRectangulo,10,COMPUERTA_HEIGHT,-5850,11700);

	  gdk_draw_line(pixmap, color,xRectangulo+COMPUERTA_WIDTH-(CELDA_WIDTH/2),yRectangulo+CELDA_HEIGHT+CELDA_HEIGHT/2,
					  xRectangulo+COMPUERTA_WIDTH,yRectangulo+CELDA_HEIGHT+CELDA_HEIGHT/2);
	  //informa que la zona dada por update_rect debe actualizarse, el widget
	  //generara un evento de exposicion
	  gtk_widget_draw (drawing_area, &update_rect);
}

void Imprimir::draw_OR_oeste(gdouble x, gdouble y,cairo_t *cr){

	 GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	  xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	  yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	  widthRectangulo = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	  heightRectangulo = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar


	  //arco para salida
	  gdk_draw_arc(pixmap, color,false,xRectangulo+(CELDA_WIDTH/2),yRectangulo,4*CELDA_WIDTH,COMPUERTA_HEIGHT,-17550,11700);
	  //arco para salida
	  gdk_draw_arc(pixmap, color,false,xRectangulo+27,yRectangulo,CELDA_WIDTH,COMPUERTA_HEIGHT,-17550,11700);


	  //dibujo entradas
	  gdk_draw_line(pixmap, color,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2),xRectangulo+COMPUERTA_HEIGHT,yRectangulo+(CELDA_HEIGHT/2));
	  gdk_draw_line(pixmap,color,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
		 	  						  xRectangulo+COMPUERTA_HEIGHT,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	  //dibuja salida
	  gdk_draw_line(pixmap, color,xRectangulo+(CELDA_HEIGHT/2),yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),xRectangulo,yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));

	  //informa que la zona dada por update_rect debe actualizarse, el widget
	  //generara un evento de exposicion
	  gtk_widget_draw (drawing_area, &update_rect);

}

void Imprimir::draw_OR_sur(gdouble x, gdouble y,cairo_t *cr){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	widthRectangulo = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
	heightRectangulo = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	//arco para salida
	gdk_draw_arc(pixmap, color,false,xRectangulo,yRectangulo-CELDA_WIDTH-(CELDA_WIDTH/2),COMPUERTA_HEIGHT,4*CELDA_WIDTH,-11400,11500);
	 //arco para entrada
	gdk_draw_arc(pixmap, color,false,xRectangulo,yRectangulo-3,COMPUERTA_HEIGHT,CELDA_WIDTH,-11400,11500);

	//dibujo entradas
	gdk_draw_line(pixmap, color,xRectangulo+(CELDA_HEIGHT/2),yRectangulo,xRectangulo+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
	gdk_draw_line(pixmap, color,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
	//dibuja salida
	 gdk_draw_line(pixmap,color,xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT,
								  xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));


	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);
}

/*------------------- Metodos para el dibujo de XORs -------------------*/

void Imprimir::draw_XOR_este(gdouble x, gdouble y,cairo_t *cr){

  GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

  xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
  yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
  widthRectangulo = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
  heightRectangulo = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

  //Dibujo compuerta xor
  gdk_draw_line(pixmap,color,xRectangulo,yRectangulo+(CELDA_HEIGHT/2),
				  xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2));
  gdk_draw_line(pixmap, color,xRectangulo,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
				  xRectangulo+(CELDA_WIDTH/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_WIDTH/2));
  gdk_draw_arc(pixmap, color,false,xRectangulo-(3*(CELDA_WIDTH/2)),yRectangulo,4*CELDA_WIDTH,COMPUERTA_HEIGHT,-5850,11700);
  gdk_draw_arc(pixmap, color,false,xRectangulo,yRectangulo,10,COMPUERTA_HEIGHT,-5850,11700);
  gdk_draw_arc(pixmap, color,false,xRectangulo-3,yRectangulo,10,COMPUERTA_HEIGHT,-5850,11700);

  gdk_draw_line(pixmap,color,xRectangulo+COMPUERTA_WIDTH-(CELDA_WIDTH/2),yRectangulo+CELDA_HEIGHT+CELDA_HEIGHT/2,
				  xRectangulo+COMPUERTA_WIDTH,yRectangulo+CELDA_HEIGHT+CELDA_HEIGHT/2);
  //informa que la zona dada por update_rect debe actualizarse, el widget
  //generara un evento de exposicion
  gtk_widget_draw (drawing_area, &update_rect);

}

void Imprimir::draw_XOR_oeste(gdouble x, gdouble y,cairo_t *cr){

	 GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	 xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 widthRectangulo = COMPUERTA_WIDTH; //ancho del rectangulo a redibujar
	 heightRectangulo = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	 //arco para salida
	 gdk_draw_arc(pixmap, color,false,xRectangulo+(CELDA_WIDTH/2),yRectangulo,4*CELDA_WIDTH,COMPUERTA_HEIGHT,-17550,11700);
	 //arco para salida
	 gdk_draw_arc(pixmap, color,false,xRectangulo+27,yRectangulo,CELDA_WIDTH,COMPUERTA_HEIGHT,-17550,11700);
	 gdk_draw_arc(pixmap, color,false,xRectangulo+29,yRectangulo,CELDA_WIDTH,COMPUERTA_HEIGHT,-17550,11700);

	//dibujo entradas
	gdk_draw_line(pixmap, color,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2),xRectangulo+COMPUERTA_HEIGHT,yRectangulo+(CELDA_HEIGHT/2));
	gdk_draw_line(pixmap,color,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
		 	  						  xRectangulo+COMPUERTA_HEIGHT,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	//dibuja salida
	gdk_draw_line(pixmap, color,xRectangulo+(CELDA_HEIGHT/2),yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),xRectangulo,yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));

	 //informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);
}

void Imprimir::draw_XOR_norte(gdouble x, gdouble y,cairo_t *cr){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	 xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	 yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	 widthRectangulo = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
	 heightRectangulo = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	 //arco para salida
	 gdk_draw_arc(pixmap, color,false,xRectangulo,yRectangulo+(CELDA_HEIGHT/2),COMPUERTA_HEIGHT,4*CELDA_WIDTH,-23100,11450);

	 gdk_draw_arc(pixmap, color,false,xRectangulo,yRectangulo+26,COMPUERTA_HEIGHT,CELDA_WIDTH,-23100,11450);
	 gdk_draw_arc(pixmap, color,false,xRectangulo,yRectangulo+28,COMPUERTA_HEIGHT,CELDA_WIDTH,-23100,11450);
	//dibujo entradas
	 gdk_draw_line(pixmap,color,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),
	 	  						  xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);
	 gdk_draw_line(pixmap,color,xRectangulo+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT,
	 	 						   xRectangulo+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	//dibuja salida
	 gdk_draw_line(pixmap, color,xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo,xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));

	 //informa que la zona dada por update_rect debe actualizarse, el widget
	 //generara un evento de exposicion
	 gtk_widget_draw (drawing_area, &update_rect);
}

void Imprimir::draw_XOR_sur(gdouble x, gdouble y,cairo_t *cr){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar
	widthRectangulo = COMPUERTA_WIDTH+1; //ancho del rectangulo a redibujar
	heightRectangulo = COMPUERTA_HEIGHT+1;//alto del rectangulo a redibujar

	//arco para salida
	gdk_draw_arc(pixmap, color,false,xRectangulo,yRectangulo-CELDA_WIDTH-(CELDA_WIDTH/2),COMPUERTA_HEIGHT,4*CELDA_WIDTH,-11400,11500);
	//arco para entrada
	gdk_draw_arc(pixmap, color,false,xRectangulo,yRectangulo-4,COMPUERTA_HEIGHT,CELDA_WIDTH,-11400,11500);
	 //arco para entrada
	gdk_draw_arc(pixmap, color,false,xRectangulo,yRectangulo-2,COMPUERTA_HEIGHT,CELDA_WIDTH,-11400,11500);
	//dibujo entradas
	gdk_draw_line(pixmap, color,xRectangulo+(CELDA_HEIGHT/2),yRectangulo,xRectangulo+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
	gdk_draw_line(pixmap, color,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
	//dibuja salida
	gdk_draw_line(pixmap,color,xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT,
		  	 						  xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);
}

void Imprimir::draw_vertice(gdouble x,gdouble y,cairo_t *cr,SENTIDO sentido){

	GdkRectangle update_rect;	GdkGC *color=this->get_color_negro();

	xRectangulo = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	yRectangulo = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	widthRectangulo = CELDA_WIDTH; //ancho del rectangulo a redibujar
	heightRectangulo = CELDA_HEIGHT;//alto del rectangulo a redibujar

	switch(sentido){

		case ESTE:{
			gdk_draw_line(pixmap,color,xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_WIDTH/2),xRectangulo+(CELDA_HEIGHT),yRectangulo+(CELDA_HEIGHT/2));
			break;
		}
		case OESTE:{
			gdk_draw_line(pixmap,color,xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_WIDTH/2),xRectangulo,yRectangulo+(CELDA_HEIGHT/2));
			break;
			}
		case NORTE:{
			gdk_draw_line(pixmap,color,xRectangulo+(CELDA_WIDTH/2),yRectangulo,xRectangulo+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
			break;
			}
		case SUR:{
			gdk_draw_line(pixmap,color,xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_WIDTH),xRectangulo+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
			break;
			}
	}

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	gtk_widget_draw (drawing_area, &update_rect);


}

/*----------------------------------------------------------------------------*/
