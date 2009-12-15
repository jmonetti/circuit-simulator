#include "common_Dibujador.h"
#include "../controlador/Modelo_vista_circ/common_Modelo_vista_circuito.h"

void Dibujador::dibujar(Compuerta* compuerta,cairo_t* cr) {

	TIPO_COMPUERTA tipo= compuerta->getTipo();
	Posicion posicion= compuerta->getPosicion();
	SENTIDO sentido= compuerta->getSentido();

	switch (tipo) {

		case T_AND:

			dibujarAnd(posicion,sentido,cr);
			break;

		case T_NOT:
			dibujarNot(posicion,sentido,cr);
			break;

		case T_PISTA:
			dibujarPista(posicion,sentido,cr);
			break;

		case T_OR:
			dibujarOr(posicion,sentido,cr);
			break;

		case T_XOR:
			dibujarXOr(posicion,sentido,cr);
			break;

		case T_ENTRADA:
			dibujarEntrada(posicion,sentido,cr);
			break;

		case T_SALIDA:
			dibujarSalida(posicion,sentido,cr);
			break;

		case T_CAJANEGRA:
			dibujarCajaNegra(posicion,sentido,compuerta->getCantidadEntradas(),compuerta->getCantidadSalidas(),cr);
			break;

		default:

			break;
	}

}


void Dibujador::dibujarAnd(Posicion posicion, SENTIDO sentido,cairo_t* cr) {

	int x= Modelo_vista_circuito::de_col_a_pixel(posicion.getX());
	int y= Modelo_vista_circuito::de_fila_a_pixel(posicion.getY());

	switch (sentido) {

		case ESTE:

			draw_AND_este(x,y,cr);
			break;

		case OESTE:

			draw_AND_oeste(x,y,cr);

		case NORTE:

			draw_AND_norte(x,y,cr);

		case SUR:

			draw_AND_sur(x,y,cr);

		default:
			break;
	}

}

void Dibujador::dibujarOr(Posicion posicion, SENTIDO sentido,cairo_t* cr) {

	int x= Modelo_vista_circuito::de_col_a_pixel(posicion.getX());
	int y= Modelo_vista_circuito::de_fila_a_pixel(posicion.getY());

	switch (sentido) {

		case ESTE:

			draw_OR_este(x,y,cr);
			break;

		case OESTE:

			draw_OR_oeste(x,y,cr);

		case NORTE:

			draw_OR_norte(x,y,cr);

		case SUR:

			draw_OR_sur(x,y,cr);

		default:
			break;
	}

}

void Dibujador::dibujarXOr(Posicion posicion, SENTIDO sentido,cairo_t* cr) {

	int x= Modelo_vista_circuito::de_col_a_pixel(posicion.getX());
	int y= Modelo_vista_circuito::de_fila_a_pixel(posicion.getY());

	switch (sentido) {

		case ESTE:

			draw_XOR_este(x,y,cr);
			break;

		case OESTE:

			draw_XOR_oeste(x,y,cr);

		case NORTE:

			draw_XOR_norte(x,y,cr);

		case SUR:

			draw_XOR_sur(x,y,cr);

		default:
			break;
	}


}

void Dibujador::dibujarNot(Posicion posicion, SENTIDO sentido,cairo_t* cr) {

	int x= Modelo_vista_circuito::de_col_a_pixel(posicion.getX());
	int y= Modelo_vista_circuito::de_fila_a_pixel(posicion.getY());

	switch (sentido) {

		case ESTE:

			draw_NOT_este(x,y,cr);
			break;

		case OESTE:

			draw_NOT_oeste(x,y,cr);

		case NORTE:

			draw_NOT_norte(x,y,cr);

		case SUR:

			draw_NOT_sur(x,y,cr);

		default:
			break;
	}


}

void Dibujador::dibujarPista(Posicion posicion, SENTIDO sentido,cairo_t* cr) {

	int x= Modelo_vista_circuito::de_col_a_pixel(posicion.getX());
	int y= Modelo_vista_circuito::de_fila_a_pixel(posicion.getY());

	switch (sentido) {

		case ESTE:

			draw_pista_este(x,y,cr);
			break;

		case OESTE:

			draw_pista_oeste(x,y,cr);

		case NORTE:

			draw_pista_norte(x,y,cr);

		case SUR:

			draw_pista_sur(x,y,cr);

		default:
			break;
	}

}

void Dibujador::dibujarEntrada(Posicion posicion, SENTIDO sentido,cairo_t* cr) {

	int x= Modelo_vista_circuito::de_col_a_pixel(posicion.getX());
	int y= Modelo_vista_circuito::de_fila_a_pixel(posicion.getY());

	switch (sentido) {

		case ESTE:

			draw_entrada_este(x,y,cr);
			break;

		case OESTE:

			draw_entrada_oeste(x,y,cr);

		case NORTE:

			draw_entrada_norte(x,y,cr);

		case SUR:

			draw_entrada_sur(x,y,cr);

		default:
			break;
	}


}

void Dibujador::dibujarSalida(Posicion posicion, SENTIDO sentido,cairo_t* cr) {

	int x= Modelo_vista_circuito::de_col_a_pixel(posicion.getX());
	int y= Modelo_vista_circuito::de_fila_a_pixel(posicion.getY());

	switch (sentido) {

		case ESTE:

			draw_salida_este(x,y,cr);
			break;

		case OESTE:

			draw_salida_oeste(x,y,cr);

		case NORTE:

			draw_salida_norte(x,y,cr);

		case SUR:

			draw_salida_sur(x,y,cr);

		default:
			break;
	}

}

void Dibujador::dibujarCajaNegra(Posicion posicion, SENTIDO sentido,int entradas,int salidas,cairo_t* cr) {

	int x= Modelo_vista_circuito::de_col_a_pixel(posicion.getX());
	int y= Modelo_vista_circuito::de_fila_a_pixel(posicion.getY());

	draw_CAJANEGRA(x,y,cr,entradas,salidas);
}



void Dibujador::dibujarConexion(ConexionVertice conexion,cairo_t* cr) {

	Posicion posicion= conexion.getPosicion();
	int x= Modelo_vista_circuito::de_col_a_pixel(posicion.getX());
	int y= Modelo_vista_circuito::de_fila_a_pixel(posicion.getY());
	draw_vertice(x,y,cr,conexion.getSentido());

}


void Dibujador::dibujarGrilla(cairo_t *cr){

	int xRectangulo = 0; //pos x del rectangulo a redibujar
	int yRectangulo = 0; //pos y del rectangulo a redibujar
	int widthRectangulo = DRW_AREA_WIDTH; //ancho del rectangulo a redibujar
	int heightRectangulo = DRW_AREA_HEIGHT;//alto del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 0);

	cairo_rectangle(cr, xRectangulo,yRectangulo,widthRectangulo,heightRectangulo);
	cairo_stroke_preserve(cr);
	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_fill(cr);

	cairo_set_source_rgb(cr, 0.5, 0.5, 0.5);
	cairo_set_line_width (cr, 0.5);

	for (int var = 0; var < 65; ++var) {

		cairo_move_to(cr, xRectangulo,yRectangulo+var * (CELDA_HEIGHT)+6);
		cairo_line_to(cr, xRectangulo+DRW_AREA_WIDTH,yRectangulo+var *(CELDA_HEIGHT)+6);

	}

	for (int var = 0; var < 98; ++var) {

		cairo_move_to(cr, xRectangulo + var*(CELDA_HEIGHT),yRectangulo);
		cairo_line_to(cr, xRectangulo+var*(CELDA_HEIGHT),yRectangulo+DRW_AREA_HEIGHT);

	}

	cairo_stroke(cr);

}


/*------------------- Metodos para el dibujo de entradas -------------------*/

void Dibujador::draw_entrada_sur(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	int widthRectangulo =  CELDA_WIDTH;     //ancho del rectangulo a redibujar
	int heightRectangulo = 2 * CELDA_HEIGHT;//alto del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 1);

	//dibnujo el rectangulo
	cairo_rectangle(cr, xRectangulo+1,yRectangulo,widthRectangulo-2,heightRectangulo-(CELDA_HEIGHT/2));
	cairo_stroke_preserve(cr);
	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_fill(cr);

	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 1);

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

void Dibujador::draw_entrada_norte(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (CELDA_HEIGHT) - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	int widthRectangulo =  CELDA_WIDTH;     //ancho del rectangulo a redibujar
	int heightRectangulo = 2 * CELDA_HEIGHT +1;//alto del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 1);

	//dibnujo el rectangulo
	cairo_rectangle(cr, xRectangulo,yRectangulo+(CELDA_WIDTH/2),widthRectangulo-1,heightRectangulo-(CELDA_HEIGHT/2)-1);
	cairo_stroke_preserve(cr);
	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_fill(cr);

	//dibujo la linea de salida
	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo);

	//linea vertical de la E
	cairo_move_to(cr, xRectangulo+3,yRectangulo+1+(CELDA_HEIGHT));
	cairo_line_to(cr, xRectangulo+3,yRectangulo+9+(CELDA_HEIGHT));

	//lineas horizontales
	cairo_move_to(cr, xRectangulo+3,yRectangulo+1+(CELDA_HEIGHT));
	cairo_line_to(cr, xRectangulo+9,yRectangulo+1+(CELDA_HEIGHT));

	cairo_move_to(cr, xRectangulo+3,yRectangulo+5+(CELDA_HEIGHT));
	cairo_line_to(cr, xRectangulo+9,yRectangulo+5+(CELDA_HEIGHT));

	cairo_move_to(cr, xRectangulo+3,yRectangulo+9+(CELDA_HEIGHT));
	cairo_line_to(cr, xRectangulo+9,yRectangulo+9+(CELDA_HEIGHT));

	cairo_stroke(cr);

}

void Dibujador::draw_entrada_este(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	int widthRectangulo = 2 * CELDA_WIDTH; //ancho del rectangulo a redibujar
	int heightRectangulo = CELDA_HEIGHT+1;//alto del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 1);

	//dibnujo el rectangulo
	cairo_rectangle(cr, xRectangulo,yRectangulo,widthRectangulo-(CELDA_WIDTH/2),heightRectangulo-1);
	cairo_stroke_preserve(cr);
	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_fill(cr);

	//dibujo la linea de salida
	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo+(2*CELDA_WIDTH)-(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+(2*CELDA_WIDTH),yRectangulo+(CELDA_HEIGHT/2));

	//linea vertical de la E
	cairo_move_to(cr, xRectangulo+6,yRectangulo+2);
	cairo_line_to(cr, xRectangulo+6,yRectangulo+10);

	//lineas horizontales
	cairo_move_to(cr, xRectangulo+6,yRectangulo+2);
	cairo_line_to(cr, xRectangulo+12,yRectangulo+2);

	cairo_move_to(cr, xRectangulo+6,yRectangulo+6);
	cairo_line_to(cr, xRectangulo+12,yRectangulo+6);

	cairo_move_to(cr, xRectangulo+6,yRectangulo+10);
	cairo_line_to(cr, xRectangulo+12,yRectangulo+10);

	cairo_stroke(cr);

}

void Dibujador::draw_entrada_oeste(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(CELDA_WIDTH/2)-(CELDA_WIDTH); //pos x del rectangulo a redibujar
	int yRectangulo = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	int widthRectangulo = 2*CELDA_WIDTH; //ancho del rectangulo a redibujar
	int heightRectangulo = CELDA_HEIGHT+1;//alto del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 1);

	//dibnujo el rectangulo
	cairo_rectangle(cr, xRectangulo+6,yRectangulo,widthRectangulo -(CELDA_WIDTH/2)-1,heightRectangulo-1);
	cairo_stroke_preserve(cr);
	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_fill(cr);

	//dibujo la linea de salida
	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo,yRectangulo+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2));

	//linea vertical de la E
	cairo_move_to(cr, xRectangulo+12,yRectangulo+2);
	cairo_line_to(cr, xRectangulo+12,yRectangulo+10);

	//lineas horizontales
	cairo_move_to(cr, xRectangulo+12,yRectangulo+2);
	cairo_line_to(cr, xRectangulo+18,yRectangulo+2);

	cairo_move_to(cr, xRectangulo+12,yRectangulo+6);
	cairo_line_to(cr, xRectangulo+18,yRectangulo+6);

	cairo_move_to(cr, xRectangulo+12,yRectangulo+10);
	cairo_line_to(cr, xRectangulo+18,yRectangulo+10);

	cairo_stroke(cr);

}

/*------------------- Metodos para el dibujo de salidas -------------------*/

void Dibujador::draw_salida_sur(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (CELDA_HEIGHT) - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	int widthRectangulo =  CELDA_WIDTH;     //ancho del rectangulo a redibujar
	int heightRectangulo = 2 * CELDA_HEIGHT +1;//alto del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 1);

	//dibnujo el rectangulo
	cairo_rectangle(cr, xRectangulo,yRectangulo+(CELDA_WIDTH/2),widthRectangulo-1,heightRectangulo-(CELDA_HEIGHT/2)-1);
	cairo_stroke_preserve(cr);
	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_fill(cr);

	//dibujo la linea de salida
	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo);

	//linea vertical de la S
	cairo_move_to(cr, xRectangulo+3,yRectangulo+1+(CELDA_HEIGHT));
	cairo_line_to(cr, xRectangulo+3,yRectangulo+5+(CELDA_HEIGHT));

	cairo_move_to(cr, xRectangulo+9,yRectangulo+5+(CELDA_HEIGHT));
	cairo_line_to(cr, xRectangulo+9,yRectangulo+9+(CELDA_HEIGHT));


	//lineas horizontales
	cairo_move_to(cr, xRectangulo+3,yRectangulo+1+(CELDA_HEIGHT));
	cairo_line_to(cr, xRectangulo+9,yRectangulo+1+(CELDA_HEIGHT));

	cairo_move_to(cr, xRectangulo+3,yRectangulo+5+(CELDA_HEIGHT));
	cairo_line_to(cr, xRectangulo+9,yRectangulo+5+(CELDA_HEIGHT));

	cairo_move_to(cr, xRectangulo+3,yRectangulo+9+(CELDA_HEIGHT));
	cairo_line_to(cr, xRectangulo+9,yRectangulo+9+(CELDA_HEIGHT));

	cairo_stroke(cr);

}

void Dibujador::draw_salida_norte(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	int widthRectangulo =  CELDA_WIDTH;     //ancho del rectangulo a redibujar
	int heightRectangulo = 2 * CELDA_HEIGHT;//alto del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 1);

	//dibnujo el rectangulo
	cairo_rectangle(cr, xRectangulo+1,yRectangulo,widthRectangulo-2,heightRectangulo-(CELDA_HEIGHT/2));
	cairo_stroke_preserve(cr);
	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_fill(cr);

	//dibujo la linea de salida
	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2)+(CELDA_WIDTH));
	cairo_line_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+2*(CELDA_WIDTH));

	//linea vertical de la S
	cairo_move_to(cr, xRectangulo+3,yRectangulo+3);
	cairo_line_to(cr, xRectangulo+3,yRectangulo+7);

	cairo_move_to(cr, xRectangulo+9,yRectangulo+7);
	cairo_line_to(cr, xRectangulo+9,yRectangulo+11);


	//lineas horizontales
	cairo_move_to(cr, xRectangulo+3,yRectangulo+3);
	cairo_line_to(cr, xRectangulo+9,yRectangulo+3);

	cairo_move_to(cr, xRectangulo+3,yRectangulo+7);
	cairo_line_to(cr, xRectangulo+9,yRectangulo+7);

	cairo_move_to(cr, xRectangulo+3,yRectangulo+11);
	cairo_line_to(cr, xRectangulo+9,yRectangulo+11);

	cairo_stroke(cr);

}

void Dibujador::draw_salida_este(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -CELDA_WIDTH-(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
//	int widthRectangulo = 2*CELDA_WIDTH+1; //ancho del rectangulo a redibujar
//	int heightRectangulo = CELDA_HEIGHT;//alto del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 1);

	//dibnujo el rectangulo
	cairo_rectangle(cr, xRectangulo+6,yRectangulo,18,11);
	cairo_stroke_preserve(cr);
	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_fill(cr);

	//dibujo la linea de salida
	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo,yRectangulo+6);
	cairo_line_to(cr, xRectangulo+6,yRectangulo+6);

	//linea vertical de la S
	cairo_move_to(cr, xRectangulo+12,yRectangulo+2);
	cairo_line_to(cr, xRectangulo+12,yRectangulo+6);

	cairo_move_to(cr, xRectangulo+18,yRectangulo+6);
	cairo_line_to(cr, xRectangulo+18,yRectangulo+9);


	//lineas horizontales
	cairo_move_to(cr, xRectangulo+12,yRectangulo+2);
	cairo_line_to(cr, xRectangulo+18,yRectangulo+2);

	cairo_move_to(cr, xRectangulo+12,yRectangulo+6);
	cairo_line_to(cr, xRectangulo+18,yRectangulo+6);

	cairo_move_to(cr, xRectangulo+12,yRectangulo+9);
	cairo_line_to(cr, xRectangulo+18,yRectangulo+9);

	cairo_stroke(cr);

}

void Dibujador::draw_salida_oeste(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	int widthRectangulo = 2 * CELDA_WIDTH; //ancho del rectangulo a redibujar
	int heightRectangulo = CELDA_HEIGHT+1;//alto del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 1);

	//dibnujo el rectangulo
	cairo_rectangle(cr, xRectangulo,yRectangulo,widthRectangulo-(CELDA_WIDTH/2),heightRectangulo-1);
	cairo_stroke_preserve(cr);
	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_fill(cr);

	//dibujo la linea de salida
	cairo_set_source_rgb(cr, 0, 0, 1);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo+(2*CELDA_WIDTH)-(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+(2*CELDA_WIDTH),yRectangulo+(CELDA_HEIGHT/2));

	//linea vertical de la S
	cairo_move_to(cr, xRectangulo+6,yRectangulo+2);
	cairo_line_to(cr, xRectangulo+6,yRectangulo+6);

	cairo_move_to(cr, xRectangulo+12,yRectangulo+6);
	cairo_line_to(cr, xRectangulo+12,yRectangulo+10);


	//lineas horizontales
	cairo_move_to(cr, xRectangulo+6,yRectangulo+2);
	cairo_line_to(cr, xRectangulo+12,yRectangulo+2);

	cairo_move_to(cr, xRectangulo+6,yRectangulo+6);
	cairo_line_to(cr, xRectangulo+12,yRectangulo+6);

	cairo_move_to(cr, xRectangulo+6,yRectangulo+10);
	cairo_line_to(cr, xRectangulo+12,yRectangulo+10);

	cairo_stroke(cr);

}
/*------------------- Metodos para el dibujo de pistas -------------------*/

void Dibujador::draw_pista_sur(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y -CELDA_HEIGHT- (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
//	int widthRectangulo = CELDA_WIDTH; //ancho del rectangulo a redibujar
//	int heightRectangulo = 3 * CELDA_HEIGHT;//alto del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo);
	cairo_line_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+(3 * CELDA_HEIGHT));

	cairo_move_to(cr, xRectangulo+6,yRectangulo+36);
	cairo_line_to(cr, xRectangulo+4,yRectangulo+33);

	cairo_move_to(cr, xRectangulo+6,yRectangulo+36);
	cairo_line_to(cr, xRectangulo+8,yRectangulo+33);

	cairo_stroke(cr);

}

void Dibujador::draw_pista_norte(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y -CELDA_HEIGHT- (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
//	int widthRectangulo = CELDA_WIDTH; //ancho del rectangulo a redibujar
//	int heightRectangulo = 3 * CELDA_HEIGHT;//alto del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo);
	cairo_line_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+(3 * CELDA_HEIGHT));

	cairo_move_to(cr, xRectangulo+6,yRectangulo);
	cairo_line_to(cr, xRectangulo+4,yRectangulo+3);

	cairo_move_to(cr, xRectangulo+6,yRectangulo);
	cairo_line_to(cr, xRectangulo+8,yRectangulo+3);

	cairo_stroke(cr);

}

void Dibujador::draw_pista_este(gdouble x, gdouble y,cairo_t *cr){


	int	xRectangulo = x -CELDA_HEIGHT- (CELDA_HEIGHT/2); //pos x del rectangulo a redibujar
	int yRectangulo = y -(CELDA_WIDTH/2); //pos y del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo,yRectangulo+(CELDA_WIDTH/2));
	cairo_line_to(cr, xRectangulo+(3 * CELDA_HEIGHT),yRectangulo+(CELDA_WIDTH/2));

	cairo_move_to(cr, xRectangulo+33,yRectangulo+4);
	cairo_line_to(cr, xRectangulo+(3 * CELDA_HEIGHT),yRectangulo+6);

	cairo_move_to(cr, xRectangulo+33,yRectangulo+8);
	cairo_line_to(cr, xRectangulo+(3 * CELDA_HEIGHT),yRectangulo+6);

	cairo_stroke(cr);

}

void Dibujador::draw_pista_oeste(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -CELDA_HEIGHT- (CELDA_HEIGHT/2); //pos x del rectangulo a redibujar
	int yRectangulo = y -(CELDA_WIDTH/2); //pos y del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo,yRectangulo+(CELDA_WIDTH/2));
	cairo_line_to(cr, xRectangulo+(3 * CELDA_HEIGHT),yRectangulo+(CELDA_WIDTH/2));

	cairo_move_to(cr, xRectangulo,yRectangulo+6);
	cairo_line_to(cr, xRectangulo+3,yRectangulo+8);

	cairo_move_to(cr, xRectangulo,yRectangulo+6);
	cairo_line_to(cr, xRectangulo+3,yRectangulo+4);

	cairo_stroke(cr);

}


/*------------------- Metodos para el dibujo de cajaNegra  -----------------*/

void Dibujador::draw_CAJANEGRA(gdouble x,gdouble y,cairo_t *cr,int cant_entradas,int cant_salidas){

	//cantidad maxima entre entradas o salidas
	int cant_max = (cant_entradas > cant_salidas)? cant_entradas:cant_salidas;

	int xRectangulo = x -(CELDA_WIDTH)-(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (CELDA_HEIGHT)-(CELDA_HEIGHT/2); //pos y del rectangulo a redibujar
	int widthRectangulo = 3*CELDA_WIDTH; //ancho del rectangulo a redibujar
	int heightRectangulo= (cant_max > 2)?(((2*cant_max)-1) * CELDA_HEIGHT):(3 * CELDA_HEIGHT);

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	//dibnujo el rectangulo
	cairo_rectangle(cr, xRectangulo+6,yRectangulo+2,widthRectangulo-CELDA_WIDTH ,heightRectangulo-4);
	cairo_stroke_preserve(cr);
	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_fill(cr);

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	for (int i = 0; i < cant_entradas; ++i) {

		cairo_move_to(cr, xRectangulo,yRectangulo+ i*(2*CELDA_HEIGHT)+(CELDA_HEIGHT/2));
		cairo_line_to(cr, xRectangulo+ (CELDA_HEIGHT/2),yRectangulo+i*(2*CELDA_HEIGHT)+(CELDA_HEIGHT/2));

	}

	for (int i = 0; i < cant_salidas; ++i) {

		cairo_move_to(cr, xRectangulo+ (2*CELDA_WIDTH)+(CELDA_WIDTH/2) ,yRectangulo+ i*(2*CELDA_HEIGHT)+(CELDA_HEIGHT/2));
		cairo_line_to(cr, xRectangulo+ (3*CELDA_HEIGHT),yRectangulo+i*(2*CELDA_HEIGHT)+(CELDA_HEIGHT/2));

	}

	cairo_stroke(cr);

}

/*------------------- Metodos para el dibujo de NOT -------------------*/

void Dibujador::draw_NOT_sur(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo);
	cairo_line_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo,yRectangulo+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+COMPUERTA_HEIGHT,yRectangulo+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+COMPUERTA_HEIGHT,yRectangulo+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo,yRectangulo+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);
	cairo_line_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));

	cairo_stroke(cr);

}

void Dibujador::draw_NOT_oeste(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo+COMPUERTA_HEIGHT,yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo);
	cairo_line_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);

	cairo_move_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo);
	cairo_line_to(cr, xRectangulo+(CELDA_HEIGHT/2),yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);
	cairo_line_to(cr, xRectangulo+(CELDA_HEIGHT/2),yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+(CELDA_HEIGHT/2),yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo,yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));

	cairo_stroke(cr);

}

void Dibujador::draw_NOT_este(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo,yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo);
	cairo_line_to(cr, xRectangulo+(2*CELDA_WIDTH)+(CELDA_WIDTH/2),yRectangulo+(COMPUERTA_WIDTH/2));

	cairo_move_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo);
	cairo_line_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+COMPUERTA_HEIGHT);


	cairo_move_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+COMPUERTA_HEIGHT);
	cairo_line_to(cr, xRectangulo+(2*CELDA_WIDTH)+(CELDA_WIDTH/2),yRectangulo+(COMPUERTA_WIDTH/2));

	cairo_move_to(cr, xRectangulo+COMPUERTA_WIDTH-(CELDA_WIDTH/2),yRectangulo+CELDA_HEIGHT+CELDA_HEIGHT/2);
	cairo_line_to(cr, xRectangulo+COMPUERTA_WIDTH,yRectangulo+CELDA_HEIGHT+CELDA_HEIGHT/2);

	cairo_stroke(cr);

}

void Dibujador::draw_NOT_norte(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);
	cairo_line_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+COMPUERTA_HEIGHT,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+COMPUERTA_HEIGHT,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo);

	cairo_stroke(cr);

}

/*------------------- Metodos para el dibujo de ANDs -------------------*/

void Dibujador::draw_AND_este(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo,yRectangulo+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_WIDTH/2));

	cairo_move_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo);
	cairo_line_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+COMPUERTA_HEIGHT);

	cairo_move_to(cr, xRectangulo+COMPUERTA_WIDTH-(CELDA_WIDTH/2),yRectangulo+CELDA_HEIGHT+CELDA_HEIGHT/2);
	cairo_line_to(cr, xRectangulo+COMPUERTA_WIDTH,yRectangulo+CELDA_HEIGHT+CELDA_HEIGHT/2);

	cairo_stroke(cr);

	cairo_scale(cr,1,0.5);
	//arco sur Salida
	cairo_arc(cr,xRectangulo-4,(yRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT))*2,34,-M_PI/2+M_PI/10,M_PI/2-M_PI/10);
	cairo_stroke(cr);
	cairo_scale(cr,1,2);

}

void Dibujador::draw_AND_oeste(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo);
	cairo_line_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);

	cairo_move_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+COMPUERTA_HEIGHT,yRectangulo+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+COMPUERTA_HEIGHT,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+(CELDA_HEIGHT/2),yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo,yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	cairo_stroke(cr);

	cairo_scale(cr,1,0.5);
	//arco sur Salida
	cairo_arc(cr,xRectangulo+4+COMPUERTA_WIDTH,(yRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT))*2,34,+M_PI/2+M_PI/12,-M_PI/2-M_PI/12);
	cairo_stroke(cr);
	cairo_scale(cr,1,2);

}

void Dibujador::draw_AND_norte(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);

	cairo_move_to(cr, xRectangulo+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);
	cairo_line_to(cr, xRectangulo+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo);
	cairo_line_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+COMPUERTA_HEIGHT,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));

	cairo_stroke(cr);

	cairo_scale(cr,0.5,1);
	//arco sur Salida
	cairo_arc(cr,(xRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT))*2,yRectangulo+4+COMPUERTA_HEIGHT,34,M_PI+M_PI/12,-M_PI/12);
	cairo_stroke(cr);
	cairo_scale(cr,2,1);


}

void Dibujador::draw_AND_sur(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo,yRectangulo+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+COMPUERTA_HEIGHT,yRectangulo+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+(CELDA_HEIGHT/2),yRectangulo);
	cairo_line_to(cr, xRectangulo+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo);
	cairo_line_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);
	cairo_line_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));

	cairo_stroke(cr);
	cairo_scale(cr,0.5,1);
	//arco sur Salida
	cairo_arc(cr,(xRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT))*2,yRectangulo-4,34,M_PI/11,-M_PI-M_PI/11);
	cairo_stroke(cr);
	cairo_scale(cr,2,1);
}

/*------------------- Metodos para el dibujo de ORs -------------------*/

void Dibujador::draw_OR_norte(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);

	cairo_move_to(cr, xRectangulo+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);
	cairo_line_to(cr, xRectangulo+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo);
	cairo_line_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));

	cairo_stroke(cr);

	cairo_scale(cr, 1, 0.5);
	//Arco sur entradas
	cairo_arc(cr,xRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT),yRectangulo*2+2*COMPUERTA_HEIGHT,16,M_PI,0);
	cairo_stroke(cr);

	cairo_scale(cr,0.5,2);
	//arco sur Salida
	cairo_arc(cr,(xRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT))*2,yRectangulo+4+COMPUERTA_HEIGHT,34,M_PI+M_PI/18,-M_PI/18);
	cairo_stroke(cr);
	cairo_scale(cr,2,1);
}

void Dibujador::draw_OR_este(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo,yRectangulo+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_WIDTH/2));

	cairo_move_to(cr, xRectangulo+COMPUERTA_WIDTH-(CELDA_WIDTH/2),yRectangulo+CELDA_HEIGHT+CELDA_HEIGHT/2);
	cairo_line_to(cr, xRectangulo+COMPUERTA_WIDTH,yRectangulo+CELDA_HEIGHT+CELDA_HEIGHT/2);

	cairo_stroke(cr);

	cairo_scale(cr,0.5,1);
	//Arco sur entradas
	cairo_arc(cr,xRectangulo*2,yRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT),16,-M_PI/2,M_PI/2);
	cairo_stroke(cr);

	cairo_scale(cr,2,0.5);
	//arco sur Salida
	cairo_arc(cr,xRectangulo-4,(yRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT))*2,34,-M_PI/2+M_PI/15,M_PI/2-M_PI/15);
	cairo_stroke(cr);
	cairo_scale(cr,1,2);
}

void Dibujador::draw_OR_oeste(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+COMPUERTA_HEIGHT,yRectangulo+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+COMPUERTA_HEIGHT,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+(CELDA_HEIGHT/2),yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo,yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	cairo_stroke(cr);

	cairo_scale(cr,0.5,1);
	//Arco sur entradas
	cairo_arc(cr,xRectangulo*2+2*COMPUERTA_WIDTH,yRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT),16,+M_PI/2,-M_PI/2);
	cairo_stroke(cr);
	//arco sur entrada_seg XOR
	//cairo_arc(cr,6+xRectangulo*2+2*COMPUERTA_WIDTH-CELDA_WIDTH,yRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT),16,+M_PI/2,-M_PI/2);
	//cairo_stroke(cr);
	cairo_scale(cr,2,0.5);
	//arco sur Salida
	cairo_arc(cr,xRectangulo+4+COMPUERTA_WIDTH,(yRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT))*2,34,+M_PI/2+M_PI/17,-M_PI/2-M_PI/17);
	cairo_stroke(cr);
	cairo_scale(cr,1,2);


}

void Dibujador::draw_OR_sur(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo+(CELDA_HEIGHT/2),yRectangulo);
	cairo_line_to(cr, xRectangulo+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo);
	cairo_line_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);
	cairo_line_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));

	cairo_stroke(cr);
	//dibuja salida
	cairo_move_to(cr,xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);
	cairo_line_to(cr,  xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	cairo_stroke(cr);


	cairo_scale(cr, 1, 0.5);
	//Arco sur entradas
	cairo_arc(cr,xRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT),yRectangulo*2,16,0,-M_PI);
	cairo_stroke(cr);

	cairo_scale(cr,0.5,2);
	//arco sur Salida
	cairo_arc(cr,(xRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT))*2,yRectangulo-4,34,M_PI/15,-M_PI-M_PI/15);
	cairo_stroke(cr);
	cairo_scale(cr,2,1);


}

/*------------------- Metodos para el dibujo de XORs -------------------*/

void Dibujador::draw_XOR_este(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo,yRectangulo+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_WIDTH/2));

	cairo_move_to(cr, xRectangulo+COMPUERTA_WIDTH-(CELDA_WIDTH/2),yRectangulo+CELDA_HEIGHT+CELDA_HEIGHT/2);
	cairo_line_to(cr, xRectangulo+COMPUERTA_WIDTH,yRectangulo+CELDA_HEIGHT+CELDA_HEIGHT/2);

	cairo_stroke(cr);

	cairo_scale(cr,0.5,1);
	//Arco sur entradas
	cairo_arc(cr,xRectangulo*2,yRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT),16,-M_PI/2,M_PI/2);
	cairo_stroke(cr);
	//arco sur entrada_seg XOR
	cairo_arc(cr,6+xRectangulo*2,yRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT),16,-M_PI/2,M_PI/2);
	cairo_stroke(cr);
	cairo_scale(cr,2,0.5);
	//arco sur Salida
	cairo_arc(cr,xRectangulo-4,(yRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT))*2,34,-M_PI/2+M_PI/15,M_PI/2-M_PI/15);
	cairo_stroke(cr);
	cairo_scale(cr,1,2);

}

void Dibujador::draw_XOR_oeste(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+COMPUERTA_HEIGHT,yRectangulo+(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+COMPUERTA_HEIGHT,yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+(CELDA_HEIGHT/2),yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo,yRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2));

	cairo_stroke(cr);
	cairo_scale(cr,0.5,1);
	//Arco sur entradas
	cairo_arc(cr,xRectangulo*2+2*COMPUERTA_WIDTH,yRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT),16,+M_PI/2,-M_PI/2);
	cairo_stroke(cr);
	//arco sur entrada_seg XOR
	cairo_arc(cr,6+xRectangulo*2+2*COMPUERTA_WIDTH-CELDA_WIDTH,yRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT),16,+M_PI/2,-M_PI/2);
	cairo_stroke(cr);
	cairo_scale(cr,2,0.5);
	//arco sur Salida
	cairo_arc(cr,xRectangulo+4+COMPUERTA_WIDTH,(yRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT))*2,34,+M_PI/2+M_PI/10,-M_PI/2-M_PI/10);
	cairo_stroke(cr);
	cairo_scale(cr,1,2);

}

void Dibujador::draw_XOR_norte(gdouble x, gdouble y,cairo_t *cr){

	int xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);

	cairo_move_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	cairo_line_to(cr, xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);

	cairo_move_to(cr, xRectangulo+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);
	cairo_line_to(cr, xRectangulo+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));

	cairo_move_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo);
	cairo_line_to(cr, xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));

	cairo_stroke(cr);
	cairo_scale(cr, 1, 0.5);
	//Arco sur entradas
	cairo_arc(cr,xRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT),yRectangulo*2+2*COMPUERTA_HEIGHT,16,M_PI,0);
	cairo_stroke(cr);
	//arco sur entrada_seg XOR
	cairo_arc(cr,xRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT),-6+yRectangulo*2+2*COMPUERTA_HEIGHT,16,M_PI,0);
	cairo_stroke(cr);
	cairo_scale(cr,0.5,2);
	//arco sur Salida
	cairo_arc(cr,(xRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT))*2,yRectangulo+4+COMPUERTA_HEIGHT,34,M_PI+M_PI/11,-M_PI/11);
	cairo_stroke(cr);
	cairo_scale(cr,2,1);
}

void Dibujador::draw_XOR_sur(gdouble x, gdouble y,cairo_t *cr){



	int xRectangulo = x -(COMPUERTA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (COMPUERTA_HEIGHT/2); //pos y del rectangulo a redibujar

	cairo_set_line_width(cr,1);
	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_scale(cr, 1, 1);

	cairo_move_to(cr,xRectangulo+(CELDA_HEIGHT/2),yRectangulo);
	cairo_line_to(cr,xRectangulo+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
	cairo_move_to(cr,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo);
	cairo_line_to(cr,xRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));

	//dibuja salida
	cairo_move_to(cr,xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT);
	cairo_line_to(cr,  xRectangulo+CELDA_HEIGHT+(CELDA_HEIGHT/2),yRectangulo+COMPUERTA_HEIGHT-(CELDA_HEIGHT/2));
	cairo_stroke(cr);


	cairo_scale(cr, 1, 0.5);
	//Arco sur entradas
	cairo_arc(cr,xRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT),yRectangulo*2,16,0,-M_PI);
	cairo_stroke(cr);
	//arco sur entrada_seg XOR
	cairo_arc(cr,xRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT),6+yRectangulo*2,16,0,-M_PI);
	cairo_stroke(cr);
	cairo_scale(cr,0.5,2);
	//arco sur Salida
	cairo_arc(cr,(xRectangulo+(CELDA_HEIGHT/2)+(CELDA_HEIGHT))*2,yRectangulo-4,34,M_PI/11,-M_PI-M_PI/11);
	cairo_stroke(cr);
	cairo_scale(cr,2,1);


}

void Dibujador::draw_vertice(gdouble x,gdouble y,cairo_t *cr,SENTIDO sentido){


	int xRectangulo = x -(CELDA_WIDTH/2); //pos x del rectangulo a redibujar
	int yRectangulo = y - (CELDA_HEIGHT/2); //pos y del rectangulo a redibujar

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width (cr, 0.5);


	switch(sentido){

		case ESTE:{
			//dibujo la linea este
			cairo_move_to(cr, xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_WIDTH/2));
			cairo_line_to(cr, xRectangulo+(CELDA_HEIGHT),yRectangulo+(CELDA_HEIGHT/2));

			break;
		}
		case OESTE:{
			cairo_move_to(cr,xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_WIDTH/2));
			cairo_line_to(cr,xRectangulo,yRectangulo+(CELDA_HEIGHT/2));
			break;
			}
		case NORTE:{
			cairo_move_to(cr,xRectangulo+(CELDA_WIDTH/2),yRectangulo);
			cairo_line_to(cr,xRectangulo+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
			break;
			}
		case SUR:{
			cairo_move_to(cr,xRectangulo+(CELDA_WIDTH/2),yRectangulo+(CELDA_WIDTH));
			cairo_line_to(cr,xRectangulo+(CELDA_HEIGHT/2),yRectangulo+(CELDA_HEIGHT/2));
			break;
			}
	}

	//informa que la zona dada por update_rect debe actualizarse, el widget
	//generara un evento de exposicion
	cairo_stroke(cr);


}
