/**************************   Clase Box_Ventana_Interna    ********************/
/**************************   Grupo 8                      ********************/

#ifndef CLASS_COMMON_BOX_VENTANA_INTERNA_H
#define CLASS_COMMON_BOX_VENTANA_INTERNA_H

#include "common_Vista_Panel.h"
#include "common_Componente_Visual.h"

#include "gtkmm.h"
#include "common_Grilla.h"

class Box_Ventana_Interna: public Componente_Visual{

private:
	//atributo
	GtkWidget* _box_ventana;
	Grilla grilla;


public:

	Box_Ventana_Interna();

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
