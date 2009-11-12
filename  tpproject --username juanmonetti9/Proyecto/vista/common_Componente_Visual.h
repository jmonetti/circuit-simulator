/**************************   Clase Componente_Visual  ************************/
/**************************   Grupo 8                  ************************/

#ifndef CLASS_COMMON_COMPONENTE_VISUAL_H
#define CLASS_COMMON_COMPONENTE_VISUAL_H

#include "gtkmm.h"

/* Constantes de dimension de la ventana */
const int WEIGHT_Ventana=600;
const int HEIGHT_Ventana=500;

class Componente_Visual{

	public:

		/**
		 * Muestra el componente Visual
		 */
		virtual void show()=0;

		/**
		 * Da un nuevo tamanio al componente visual
		 * @param: factor de amplificacion de la escala
		 */
		virtual void escalar(int _fa)=0;

		/**
		 * Retorna el widget
		 */
		virtual GtkWidget* getWidget()=0;

};
#endif
