/**************************   Clase Decorador_Scroll   ************************/
/**************************   Grupo 8                  ************************/

#ifndef CLASS_COMMON_DECORADOR_SCROLL_H
#define CLASS_COMMON_DECORADOR_SCROLL_H

#include "common_Decorador.h"
#include "gtkmm.h"

class Decorador_Scroll: public Decorador{

private:
	//atributo
	GtkWidget* _scroll;


public:

	Decorador_Scroll(Componente_Visual* componente);

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


	/**
	 * Redimensiona el Decorador_scroll con los parametros pasados
	 * @param:
	 * (int) widht nuevo ancho
	 * (int) height nuevo largo
	 */
	void set_dimensiones(int weight, int height);


};
#endif
