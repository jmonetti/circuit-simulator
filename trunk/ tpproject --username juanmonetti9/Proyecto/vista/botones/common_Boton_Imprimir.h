/**************************   Clase BOTON Imprimir *******************/
/**************************   	Grupo 8            *******************/

#ifndef COMMON_BOTON_IMPRIMIR_H_
#define COMMON_BOTON_IMPRIMIR_H_

#include "common_Boton.h"

class Boton_Imprimir: public Boton {

public:

	Boton_Imprimir();

	virtual ~Boton_Imprimir();

	static void callback_imprimir(GtkWidget* widget, gpointer data);
};

#endif /* COMMON_BOTON_IMPRIMIR_H_ */
