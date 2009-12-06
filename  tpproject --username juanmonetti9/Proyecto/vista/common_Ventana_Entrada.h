#ifndef COMMON_VENTANA_ENTRADA_H_
#define COMMON_VENTANA_ENTRADA_H_

#include "common_Componente_Visual.h"

class Ventana_Entrada: public Componente_Visual {

public:

	Ventana_Entrada();

	virtual ~Ventana_Entrada();

	void show();

	GtkWidget* getWidget();

	void hide();

	const char* getNombre();

private:

	GtkWidget* cuadro;
	GtkWidget* entry;

	static void callback_ocultar(GtkWidget *widget, gpointer data);


};

#endif /* COMMON_VENTANA_ENTRADA_H_ */
