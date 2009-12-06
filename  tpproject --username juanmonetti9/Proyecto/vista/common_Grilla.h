/**************************   Clase GRILLA   *************************/
/**************************   	Grupo 8      *************************/

#ifndef COMMON_GRILLA_H_
#define COMMON_GRILLA_H_

#include "common_Componente_Visual.h"
#include "common_TablaLogica.h"
#include "common_Area_disenio.h"
#include <gtkmm.h>
#include "../common/constantes.h"
#include "common_Decorador_Scroll.h"




class Grilla: public Componente_Visual {


private:

	GtkWidget* box_notebook;
	GtkWidget* notebook;
	GtkWidget* tab_pestania_uno;
	GtkWidget* tab_pestania_dos;
	Area_disenio areaDisenio;
	TablaLogica tablaLogica;
	Decorador_Scroll scrollDisenio;
	Decorador_Scroll scrollTabla;
	int id;




public:

	Grilla(int id);

	void show();

	void escalar(int fa);

	GtkWidget* getWidget();

	int getId() const;

	void completar_tabla(Resultado* resultado);

	void draw_borrar(gdouble x, gdouble y,TIPO_COMPUERTA tipo,SENTIDO sentido,int cant_celdas=0);

	void draw_salida(gdouble x,gdouble y, SENTIDO sentido);

	void draw_entrada(gdouble x,gdouble y, SENTIDO sentido);

	void draw_pista(gdouble x,gdouble y, SENTIDO sentido,int cant_celdas);

	void draw_NOT(gdouble x,gdouble y, SENTIDO sentido);

	void draw_AND(gdouble x,gdouble y, SENTIDO sentido);

	void draw_OR(gdouble x,gdouble y, SENTIDO sentido);

	void draw_XOR(gdouble x,gdouble y, SENTIDO sentido);

	void draw_CAJANEGRA(gdouble x,gdouble y,int cant_entradas,int cant_salidas);

	void draw_borrar_CAJANEGRA(gdouble x,gdouble y,int cant_entradas,int cant_salidas);

	void draw_borrar_pista(int _x,int _y,SENTIDO _sentido);



	void disconnect_DnD();

	void connect_DnD();

};

#endif /* COMMON_GRILLA_H_ */
