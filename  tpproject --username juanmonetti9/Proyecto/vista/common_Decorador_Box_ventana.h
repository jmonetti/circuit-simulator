/*
 * common_Box_ventana.h
 *
 *  Created on: 25/11/2009
 *      Author: juanm
 */
#include "common_Decorador.h"
#include "common_Componente_Visual.h"
#include "common_Box_Ventana_Interna.h"
#include "botones/common_Boton_Close_pestania.h"

#ifndef COMMON_BOX_VENTANA_H_
#define COMMON_BOX_VENTANA_H_

class Decorador_Box_ventana: public Decorador{

private:
	//atributo
	GtkWidget* _box_ventana;
	Vista_Panel _panel;
	Boton_Close_pestania boton_close_pestania;



public:

	Decorador_Box_ventana(Componente_Visual* componente);

	/**
	 * Muestra el componente Visual
	 */
	virtual void show();

	void hide();
	/**
	 * Retorna el widget
	 */
	virtual GtkWidget* getWidget();


	virtual ~Decorador_Box_ventana();


};
#endif
