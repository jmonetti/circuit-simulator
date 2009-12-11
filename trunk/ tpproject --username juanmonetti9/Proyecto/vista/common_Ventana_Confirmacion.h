#ifndef COMMON_VENTANA_CONFIRMACION_H_
#define COMMON_VENTANA_CONFIRMACION_H_

#include "common_Componente_Visual.h"

class Ventana_Confirmacion: public Componente_Visual {

public:

	Ventana_Confirmacion();

	virtual ~Ventana_Confirmacion();

	void show();

	void hide();

	GtkWidget* getWidget();

	void mostrarConfirmacion(const std::string &texto);


private:

	GtkWidget* cuadro;
	GtkWidget* label;

	static void callback_aceptar( GtkWidget *widget,gpointer callback_data );

};

#endif /* COMMON_VENTANA_CONFIRMACION_H_ */
