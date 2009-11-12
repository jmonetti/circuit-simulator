/**************************   Clase Decorador          ************************/
/**************************   Grupo 8                  ************************/

#ifndef CLASS_COMMON_DECORADOR_H
#define CLASS_COMMON_DECORADOR_H

#include "common_Componente_Visual.h"
#include "gtkmm.h"

class Decorador: public Componente_Visual{

private:
	//atributo
	Componente_Visual* _componente;


public:

	Decorador(Componente_Visual* componente);

	/**
	 * Se muestra el decorador
	 */
	virtual void show()=0;

	/**
	 * Muestra el componente Visual
	 */
	void show_componente();

	/**
	 * Da un nuevo tamanio al componente visual
	 * @param: factor de amplificacion de la escala
	 */
	virtual void escalar(int _fa)=0;

	/**
	 * da un nuevo tamanio al componente
	 */
	void escalar_componente(int _fa);

	/**
	 * Retorna el widget
	 */
	virtual GtkWidget* getWidget()=0;


};
#endif
