#ifndef COMMON_VENTANA_GUARDAR_H_
#define COMMON_VENTANA_GUARDAR_H_

#include "common_Componente_Visual.h"

class Ventana_Guardar: public Componente_Visual {

public:

	Ventana_Guardar();

	virtual ~Ventana_Guardar();

	void show();

	void hide();

	GtkWidget* getWidget();


private:

	GtkWidget* cuadro;
	GtkWidget* label;

	static void callback_aceptar( GtkWidget *widget,gpointer callback_data );

};

#endif /* COMMON_VENTANA_GUARDAR_H_ */
