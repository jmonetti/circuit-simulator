

#ifndef COMMON_AREA_DISENIO_H_
#define COMMON_AREA_DISENIO_H_

#include "common_Componente_Visual.h"
#include "../common/constantes.h"

class Area_disenio: public Componente_Visual {

private:

	//GdkPixmap (pixmap intermedio)
	GdkPixmap *pixmap;
	GtkWidget* drawing_area;
	GtkWidget* box_pestania_uno;
	GtkWidget* box_size_pestania_uno;
	int id_manejador_dnd;

	//Colores
	GdkGC* negro_gc;
	GdkGC* gris_gc;
	GdkGC* azul_gc;

public:

	Area_disenio();

	virtual ~Area_disenio();

	void show();

	GtkWidget* getWidget();

	GdkPixmap* get_pixmap();

	void set_pixmap(GdkPixmap *n_pixmap);

	/*
	 * Retorna el un color
	 */
	GdkGC* get_color_negro();

	GdkGC* get_color_gris();

	GdkGC* get_color_azul();

	/**
	 * Borra el area de diseño dejando una grilla en blanco
	 */

	void borrar();

	/**
	 * Dibuja un vertice
	 */

	void draw_vertice(gdouble x,gdouble y,SENTIDO sentido);

	/**
	 * Dibuja una caja negra
	 */
	void draw_CAJANEGRA(gdouble x,gdouble y,int cant_entradas,int cant_salidas);

	/**
	 * Dibuja una pista en la pantalla
	 */
	void draw_pista_sur(gdouble x, gdouble y);

	void draw_pista_norte(gdouble x, gdouble y);

	void draw_pista_este(gdouble x, gdouble y);

	void draw_pista_oeste(gdouble x, gdouble y);

	/**
	 * Dibuja la entrada en la pantalla
	 */
	void draw_entrada_sur(gdouble x, gdouble y);

	void draw_entrada_norte(gdouble x, gdouble y);

	void draw_entrada_este(gdouble x, gdouble y);

	void draw_entrada_oeste(gdouble x, gdouble y);

	/**
	 * Dibuja la salida en la pantalla
	 */
	void draw_salida_sur(gdouble x, gdouble y);

	void draw_salida_norte(gdouble x, gdouble y);

	void draw_salida_este(gdouble x, gdouble y);

	void draw_salida_oeste(gdouble x, gdouble y);

	/**
	 * Dibuja la compuerta NOT en la pantalla
	 */
	void draw_NOT_sur(gdouble x, gdouble y);

	void draw_NOT_norte(gdouble x, gdouble y);

	void draw_NOT_este(gdouble x, gdouble y);

	void draw_NOT_oeste(gdouble x, gdouble y);
	/**
	 * Dibuja la compuerta AND en la pantalla
	 */
	void draw_AND_este(gdouble x, gdouble y);

	void draw_AND_oeste(gdouble x, gdouble y);

	void draw_AND_norte(gdouble x, gdouble y);

	void draw_AND_sur(gdouble x, gdouble y);
	/**
	 * Dibuja la compuerta OR en la pantalla
	 */
	void draw_OR_este(gdouble x, gdouble y);

	void draw_OR_oeste(gdouble x, gdouble y);

	void draw_OR_norte(gdouble x, gdouble y);

	void draw_OR_sur(gdouble x, gdouble y);
	/**
	 * Dibuja la compuerta XOR en la pantalla
	 */
	void draw_XOR_este(gdouble x, gdouble y);

	void draw_XOR_oeste(gdouble x, gdouble y);

	void draw_XOR_norte(gdouble x, gdouble y);

	void draw_XOR_sur(gdouble x, gdouble y);


	void draw_multiple(int _x,int _y);

	/**
	 * Crea el pixmap
	 */
	static void crear_pixmap (GtkWidget *widget, GdkEventConfigure *event,gpointer data);

	/**
	 * Redibuja un sector del pixmap area del pixmap
	 */
	static void exponer_pixmap (GtkWidget *widget, GdkEventExpose *event,gpointer data);

};

#endif /* COMMON_AREA_DISENIO_H_ */
