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

	void hide();

	void escalar(int fa);

	GtkWidget* getWidget();

	int getId() const;

	void completar_tabla(Resultado* resultado);

	void draw_salida(gdouble x,gdouble y, SENTIDO sentido);

	void draw_entrada(gdouble x,gdouble y, SENTIDO sentido);

	void draw_pista(gdouble x,gdouble y, SENTIDO sentido,int cant_celdas);

	void draw_NOT(gdouble x,gdouble y, SENTIDO sentido);

	void draw_AND(gdouble x,gdouble y, SENTIDO sentido);

	void draw_OR(gdouble x,gdouble y, SENTIDO sentido);

	void draw_XOR(gdouble x,gdouble y, SENTIDO sentido);

	void draw_CAJANEGRA(gdouble x,gdouble y,int cant_entradas,int cant_salidas);

	void draw_vertice(gdouble x,gdouble y,SENTIDO sentido);

	void limpiar_area();


};

#endif /* COMMON_GRILLA_H_ */
