/**************************   Clase GRILLA   *************************/
/**************************   	Grupo 8      *************************/

#ifndef COMMON_GRILLA_H_
#define COMMON_GRILLA_H_

#include "common_Componente_Visual.h"
#include "common_TablaLogica.h"
#include <gtkmm.h>

//constantes de tamanio del drawing area
const int DRW_AREA_WIDTH= 1170;
const int DRW_AREA_HEIGHT= 780;

//constante de tamanio del area de dibujo de una compuerta
const int COMPUERTA_WIDTH= 36;
const int COMPUERTA_HEIGHT= 36;

//constantes de tamanio de una celda
const int CELDA_WIDTH= 12;
const int CELDA_HEIGHT= 12;

// defino tamanios de envio
#define _BYTE   8
#define _WORD   16
#define _DWORD  32


class Grilla: public Componente_Visual {


private:

	//GdkPixmap (pixmap intermedio)
	static GdkPixmap *pixmap;
	GtkWidget* box_notebook;
	GtkWidget* notebook;
	GtkWidget* tab_pestania_uno;
	GtkWidget* drawing_area;
	GtkWidget* box_pestania_uno;
	GtkWidget* box_size_pestania_uno;
	GtkWidget* tab_pestania_dos;
	TablaLogica tablaLogica;


public:

	Grilla();

	void show();

	void escalar(int fa);

	GtkWidget* getWidget();



	/**
	 * Dibuja la compuerta NOT en la pantalla
	 */
	void draw_NOT(gdouble x, gdouble y);
	/**
	 * Dibuja la compuerta AND en la pantalla
	 */
	void draw_AND(gdouble x, gdouble y);
	/**
	 * Dibuja la compuerta OR en la pantalla
	 */
	void draw_OR(gdouble x, gdouble y);
	/**
	 * Dibuja la compuerta XOR en la pantalla
	 */
	void draw_XOR(gdouble x, gdouble y);

	/**
	 * Borra una compuerta del drawing area
	 */
	void draw_sin_commpuerta(gdouble x, gdouble y);


	/**
	 * Crea el pixmap
	 */
	static void crear_pixmap (GtkWidget *widget, GdkEventConfigure *event);

	/**
	 * Redibuja un sector del pixmap area del pixmap
	 */
	static void exponer_pixmap (GtkWidget *widget, GdkEventExpose *event);




};

#endif /* COMMON_GRILLA_H_ */
