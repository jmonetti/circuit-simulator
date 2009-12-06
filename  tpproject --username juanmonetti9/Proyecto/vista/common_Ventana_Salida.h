#ifndef COMMON_VENTANA_SALIDA_H_
#define COMMON_VENTANA_SALIDA_H_

#include "common_Componente_Visual.h"

class Ventana_Salida: public Componente_Visual {

public:

	Ventana_Salida();

	virtual ~Ventana_Salida();

	void show();

	GtkWidget* getWidget();

	void hide();

	const char* getNombre();

private:

	GtkWidget* cuadro;
	GtkWidget* entry;

	static void callback_ocultar(GtkWidget *widget, gpointer data);



};

#endif /* COMMON_VENTANA_SALIDA_H_ */
