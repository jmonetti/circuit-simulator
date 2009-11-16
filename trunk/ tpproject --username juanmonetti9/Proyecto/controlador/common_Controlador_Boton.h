/**************************   Clase Controlador Boton  **************/
/**************************   	Grupo 8                **************/

#ifndef COMMON_CONTROLADOR_BOTON_H_
#define COMMON_CONTROLADOR_BOTON_H_
#include "gtkmm.h"

class Controlador_Boton {
public:
	Controlador_Boton();

	static void callback_AND( GtkWidget *widget,gpointer callback_data );

	static void callback_OR( GtkWidget *widget,gpointer callback_data );

	static void callback_XOR( GtkWidget *widget,gpointer callback_data );

	static void callback_NOT( GtkWidget *widget,gpointer callback_data );

	static void callback_Pista( GtkWidget *widget,gpointer callback_data );

	static void callback_Selector( GtkWidget *widget,gpointer callback_data );

	static void callback_Delete( GtkWidget *widget,gpointer callback_data );

	static void callback_Invertir( GtkWidget *widget,gpointer callback_data );

	static void callback_Simulacion( GtkWidget *widget,gpointer callback_data );

	static void callback_Imprimir( GtkWidget *widget,gpointer callback_data );

	static void callback_Upload( GtkWidget *widget,gpointer callback_data );

	static void callback_Download( GtkWidget *widget,gpointer callback_data );

	virtual ~Controlador_Boton();
};

#endif /* COMMON_CONTROLADOR_BOTON_H_ */
