/**************************   Clase Controlador Boton  **************/
/**************************   	Grupo 8                **************/

#ifndef COMMON_CONTROLADOR_CIRCUITO_H_
#define COMMON_CONTROLADOR_CIRCUITO_H_
#include "gtkmm.h"

class Controlador_Circuito {
public:
	Controlador_Circuito();

	static void callback_AND( GtkWidget *widget,gpointer callback_data );

	static void callback_OR( GtkWidget *widget,gpointer callback_data );

	static void callback_XOR( GtkWidget *widget,gpointer callback_data );

	static void callback_NOT( GtkWidget *widget,gpointer callback_data );

	static void callback_Pista( GtkWidget *widget,gpointer callback_data );

	static void callback_Selector( GtkWidget *widget,gpointer callback_data );

	static void callback_Delete( GtkWidget *widget,gpointer callback_data );

	static void callback_InvertirR( GtkWidget *widget,gpointer callback_data );

	static void callback_InvertirL( GtkWidget *widget,gpointer callback_data );

	static void callback_Simulacion( GtkWidget *widget,gpointer callback_data );


	virtual ~Controlador_Circuito();

private:

	static void crearVentanaDialogoPuertas(const char* titulo);
};

#endif /* COMMON_CONTROLADOR_BOTON_H_ */
