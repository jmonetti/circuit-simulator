/**************************   Clase GRILLA   *************************/
/**************************   	Grupo 8      *************************/

#ifndef COMMON_GRILLA_H_
#define COMMON_GRILLA_H_

#include "common_Componente_Visual.h"
#include <gtkmm.h>

class Grilla: public Componente_Visual {

public:

	Grilla();

	void show();

	void escalar(int fa);

	GtkWidget* getWidget();

private:

	GtkWidget* tabla;
	const static gint CANT_FILAS= 20;
	const static gint CANT_COLUMNAS= 20;
	GtkWidget* imagenes[CANT_FILAS][CANT_COLUMNAS];

};

#endif /* COMMON_GRILLA_H_ */
