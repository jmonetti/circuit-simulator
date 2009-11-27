/**************************   Clase Box_Ventana_Interna    ********************/
/**************************   Grupo 8                      ********************/

#ifndef CLASS_COMMON_BOX_VENTANA_INTERNA_H
#define CLASS_COMMON_BOX_VENTANA_INTERNA_H

#include "common_Vista_Panel.h"
#include "common_Decorador_Scroll.h"
#include "common_Componente_Visual.h"
#include <gtkmm.h>
#include "common_Grilla.h"
#include "../common/constantes.h"
#include <list>

class Box_Ventana_Interna: public Componente_Visual{

private:

	//atributo
	std::list<Grilla*> _grillas;
	GtkWidget* _box_ventana;
	GtkWidget* noteb;
	Grilla grilla;
	Decorador_Scroll scroll_grilla;

	//todo
	Grilla grilla1;





public:

	Box_Ventana_Interna();

	void agregar_AreaDisenio();



	/**
	 * Muestra el componente Visual
	 */
	virtual void show();

	/**
	 * Da un nuevo tamanio al componente visual
	 * @param: factor de amplificacion de la escala
	 */
	virtual void escalar(int _fa);

	/**
	 * TODO este va a dibujar cualquier compuerta
	 * y sobre la pestania actual CAMBIAR
	 */
	void dibujar_compuerta(gdouble x,gdouble y,Tipo_Celda tipo);

	void eliminar_pestania_actual();

	void agregar_pestania();

	/**
	 * Retorna el widget
	 */
	virtual GtkWidget* getWidget();


};
#endif
