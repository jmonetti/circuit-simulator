/**************************   Clase GRILLA   *************************/
/**************************   	Grupo 8      *************************/

#ifndef COMMON_GRILLA_H_
#define COMMON_GRILLA_H_

#include "common_Componente_Visual.h"
#include "Modelo_Vista_Circuito/common_Modelo_vista_circuito.h"
#include "common_TablaLogica.h"
#include <gtkmm.h>

//constantes de tamanio del drawing area
const int DRW_AREA_WIDTH= 1170;
const int DRW_AREA_HEIGHT= 780;

//constante de tamanio del area de dibujo de una compuerta
const int COMPUERTA_WIDTH= 39;
const int COMPUERTA_HEIGHT= 39;

// defino tamanios de envio
#define _BYTE   8
#define _WORD   16
#define _DWORD  32







class Grilla: public Componente_Visual {

public:

	Grilla();

	void show();

	void escalar(int fa);

	GtkWidget* getWidget();


private:

	//GdkPixmap (pixmap intermedio)
	static GdkPixmap *pixmap;
	GtkWidget* Box_notebook;
	GtkWidget* notebook;
	GtkWidget* tab_noteb1;
	GtkWidget* tab_noteb2;
	GtkWidget* box_noteb1;
	TablaLogica tablaLogica;

	static Modelo_vista_circuito matriz;
	static int pos_x; //pos de comienzo de arrastre
	static int pos_y; //pos de comienzo de arrastre



	/**
	 * Controlador de evento para la creacion de un pixmap, este se invoca
	 * cada vez que se cambia el tamanio de la ventana, como cuando se crea
	 * @return (true) evento ya gestionado
	 */
	static gint configure_event (GtkWidget *widget, GdkEventConfigure *event);

	/**
	 * Controlador de evento de expocicion, copia la porcion relevante del pixmap
	 * en la pantalla
	 * Se determina el area a redibujar del campo event->area
	 */
	static gint expose_event (GtkWidget *widget, GdkEventExpose *event);

	/**
	 * Dibuja la compuerta NOT en la pantalla
	 */
	static void draw_NOT(GtkWidget *widget, gdouble x, gdouble y);
	/**
	 * Dibuja la compuerta AND en la pantalla
	 */
	static void draw_AND(GtkWidget *widget, gdouble x, gdouble y);
	/**
	 * Dibuja la compuerta OR en la pantalla
	 */
	static void draw_OR(GtkWidget *widget, gdouble x, gdouble y);
	/**
	 * Dibuja la compuerta XOR en la pantalla
	 */
	static void draw_XOR(GtkWidget *widget, gdouble x, gdouble y);

	static void draw_sin_commpuerta(GtkWidget *widget, gdouble x, gdouble y);
	/**
	 * Controlador del evento de presionar el primer boton del raton
	 */
	static gint button_press_event (GtkWidget *widget, GdkEventButton *event);
	/**
	 * Controlador del evento de mover el raton
	 */
	static gint motion_notify_event (GtkWidget *widget, GdkEventMotion *event);

	static gboolean drag_drop_handl(GtkWidget *widget, GdkDragContext *context, gint x, gint y, guint time,gpointer user_data);
	static void drag_data_get_handl(GtkWidget *widget, GdkDragContext *context, GtkSelectionData *selection_data,guint target_type, guint time, gpointer user_data);
	static void drag_data_received_handl(GtkWidget *widget, GdkDragContext *context, gint x, gint y,GtkSelectionData *selection_data, guint target_type, guint time,gpointer data);


};

#endif /* COMMON_GRILLA_H_ */
