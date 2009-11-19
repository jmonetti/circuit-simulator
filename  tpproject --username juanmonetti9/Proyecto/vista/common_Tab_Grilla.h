/**************************   Clase TAB GRILLA ***********************/
/**************************   	Grupo 8        ***********************/


#ifndef COMMON_TAB_GRILLA_H_
#define COMMON_TAB_GRILLA_H_

#include "common_Componente_Visual.h"

class Tab_Grilla: public Componente_Visual {

private:

	GtkWidget* tab_grilla;
	GtkWidget* label_grilla;
	GtkWidget* boton_grilla;
	GtkWidget* box_image;
	GtkWidget* imagen;

public:

	Tab_Grilla();

	void show();

	void escalar(int fa);

	GtkWidget* getWidget();


	virtual ~Tab_Grilla();
};

#endif /* COMMON_TAB_GRILLA_H_ */
