

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

public:

	Area_disenio();

	virtual ~Area_disenio();

	void show();

	GtkWidget* getWidget();

	GdkPixmap* get_pixmap();

	void set_pixmap(GdkPixmap *n_pixmap);

	void draw_Borrar_compuerta(gdouble x,gdouble y, SENTIDO sentido);

	void draw_Borrar_entrada(gdouble x,gdouble y, SENTIDO sentido);

	void draw_Borrar_salida(gdouble x,gdouble y, SENTIDO sentido);

	void draw_Borrar_pista(gdouble x,gdouble y, SENTIDO sentido,int cant_celdas=1);

	void desconectar_DnD();

	void conectar_DnD();



	void draw_CAJANEGRA(gdouble x,gdouble y,int cant_entradas,int cant_salidas);

	void draw_borrar_CAJANEGRA(gdouble x,gdouble y,int cant_entradas,int cant_salidas);
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
