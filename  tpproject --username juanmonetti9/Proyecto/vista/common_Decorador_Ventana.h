/**************************   Clase Decorador_Ventana  ************************/
/**************************   Grupo 8                  ************************/

#ifndef CLASS_COMMON_DECORADOR_VENTANA_H
#define CLASS_COMMON_DECORADOR_VENTANA_H

#include "common_Decorador.h"


class Decorador_Ventana: public Decorador{

private:
	//atributo
	GtkWidget* _ventana;


public:

	Decorador_Ventana(Componente_Visual* componente);

	/**
	 * Muestra el componente Visual
	 */
	virtual void show();

	virtual void hide();

	/**
	 * Retorna el widget
	 */
	virtual GtkWidget* getWidget();

	virtual ~Decorador_Ventana();


};
#endif
