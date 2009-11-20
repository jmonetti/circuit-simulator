/**************************   Clase Box_Ventana_Interna    ********************/
/**************************   Grupo 8                      ********************/

#ifndef CLASS_COMMON_BOX_VENTANA_INTERNA_H
#define CLASS_COMMON_BOX_VENTANA_INTERNA_H

#include "common_Vista_Panel.h"
#include "common_Componente_Visual.h"

#include "gtkmm.h"
#include "common_Grilla.h"
#include <list>

class Box_Ventana_Interna: public Componente_Visual{

private:

	std::list<Grilla*> _grillas;
	//atributo
	GtkWidget* _box_ventana;
	GtkWidget* noteb;

	Grilla grilla;
	//todo
	Grilla grilla1;
	Grilla grilla2;
	//fin todo




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

	void eliminar_pestania_actual();

	void agregar_pestania();

	/**
	 * Retorna el widget
	 */
	virtual GtkWidget* getWidget();


};
#endif
