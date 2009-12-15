/**************************   Clase BOTON   *************************/
/**************************   	Grupo 8     *************************/

#ifndef COMMON_BOTON_H_
#define COMMON_BOTON_H_

#include <gtkmm.h>
#include "../common_Componente_Visual.h"

const int HEIGHT_boton = 29;
const int WIDTH_boton = 70;

class Boton : public Componente_Visual{

public:

	Boton();

	void agregarImagen(gchar* image);

	void agregarToolTip(gchar* etiqueta);

	void show();

	void hide();

	virtual GtkWidget* getWidget();

	void escalar(int fa);

private:

	GtkWidget* boton;
	GtkWidget* box;
	GtkTooltips* tooltip;



};

#endif /* COMMON_BOTON_H_ */
