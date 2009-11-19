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

	GtkWidget* get_tabGrilla();

private:

	GtkWidget* notebook;
	GtkWidget* tab_noteb1;
	GtkWidget* tab_noteb2;
	GtkWidget* box_noteb1;
	GtkWidget* box_noteb2;
	GtkWidget* tab_grilla;
	GtkWidget* label_grilla;
	GtkWidget* boton_grilla;
	GtkWidget* box_image;
	GtkWidget* imagen;

};

#endif /* COMMON_GRILLA_H_ */
