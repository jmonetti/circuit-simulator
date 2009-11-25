/*
 * common_Box_ventana.h
 *
 *  Created on: 25/11/2009
 *      Author: juanm
 */
#include "common_Box_Ventana_Interna.h"
#include "botones/common_Boton_Close_pestania.h"

#ifndef COMMON_BOX_VENTANA_H_
#define COMMON_BOX_VENTANA_H_

class Box_ventana: public Componente_Visual{

private:
	//atributo
	GtkWidget* _box_ventana;
	Vista_Panel _panel;
	Box_Ventana_Interna _box_ventana_int;
	Boton_Close_pestania boton_close_pestania;



public:

	Box_ventana();

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

	virtual ~Box_ventana();


};
#endif
