/**************************   Clase GRILLA   *************************/
/**************************   	Grupo 8      *************************/

#ifndef COMMON_GRILLA_H_
#define COMMON_GRILLA_H_

#include "common_Componente_Visual.h"
#include "common_TablaLogica.h"
#include <gtkmm.h>
#include "../common/constantes.h"




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
	gint id_manejador_dnd;

public:

	Grilla();

	void show();

	void escalar(int fa);

	GtkWidget* getWidget();

	void completar_tabla(Resultado* resultado);

	void draw_Borrar_compuerta(gdouble x,gdouble y, SENTIDO sentido);

	void draw_salida(gdouble x,gdouble y, SENTIDO sentido);

	void draw_entrada(gdouble x,gdouble y, SENTIDO sentido);

	void draw_pista(gdouble x,gdouble y, SENTIDO sentido);

	void draw_NOT(gdouble x,gdouble y, SENTIDO sentido);

	void draw_AND(gdouble x,gdouble y, SENTIDO sentido);

	void draw_OR(gdouble x,gdouble y, SENTIDO sentido);

	void draw_XOR(gdouble x,gdouble y, SENTIDO sentido);

	void desconectar_DnD();

	void conectar_DnD();

private:

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
