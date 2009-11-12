/**************************   Clase Decorador_Ventana  ************************/
/**************************   Grupo 8                  ************************/

#ifndef CLASS_COMMON_DECORADOR_VENTANA_H
#define CLASS_COMMON_DECORADOR_VENTANA_H

#include "common_Decorador.h"


class Decorador_Ventana: public Decorador{

private:
	//atributo
	GtkWidget* _ventana;
	GtkWidget* _menu;


public:

	Decorador_Ventana(Componente_Visual* componente);

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
