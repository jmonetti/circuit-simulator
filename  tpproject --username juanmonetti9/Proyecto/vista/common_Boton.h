/**************************   Clase BOTON   *************************/
/**************************   	Grupo 8     *************************/

#ifndef COMMON_BOTON_H_
#define COMMON_BOTON_H_

#include <gtkmm.h>
#include "common_Componente_Visual.h"

class Boton : public Componente_Visual{

public:

	Boton();

	void agregarImagen(gchar* image);

	void show();

	GtkWidget* getWidget();

	void escalar(int fa);

private:

	GtkWidget* boton;
	GtkWidget* box;


};

#endif /* COMMON_BOTON_H_ */
