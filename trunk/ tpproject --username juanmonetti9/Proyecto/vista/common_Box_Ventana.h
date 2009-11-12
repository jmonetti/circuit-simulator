/**************************   Clase Box_Ventana            ********************/
/**************************   Grupo 8                      ********************/

#ifndef CLASS_COMMON_BOX_VENTANA_H
#define CLASS_COMMON_BOX_VENTANA_H

#include "common_Decorador.h"
#include "common_Decorador_Scroll.h"
#include "common_Vista_Panel.h"
#include "common_Componente_Visual.h"
#include "common_Box_Ventana_Interna.h"
#include "common_Decorador_Ventana.h"


#include "gtkmm.h"

class Box_Ventana: public Componente_Visual{

private:
	//atributo
	GtkWidget* _box_ventana;
	Vista_Panel _panel;
	Box_Ventana_Interna _box_ventana_int;
	Decorador_Scroll _decorador_scroll;



public:

	Box_Ventana();

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
	 * Retorna el widget
	 */
	virtual GtkWidget* getWidget();


};
#endif
