
#ifndef COMMON_IMPRIMIR_H_
#define COMMON_IMPRIMIR_H_

#include <gtk-2.0/gtk/gtk.h>
#include <vector>
#include "common_Dibujador.h"
#include "../common/constantes.h"
#include "../modelo/circuito/common_ConexionVertice.h"


class Imprimir {
public:

	Imprimir();

	void mostrar();

	void imprimir(GtkPrintContext* context,std::vector<Compuerta*>& compuertas,std::vector<ConexionVertice>& conexiones);

	static void begin_print(GtkPrintOperation* print,GtkPrintContext* context);

private:

	GtkPrintSettings *settings;
	GtkPrintOperation *print;
	Dibujador dibujador;

};

#endif /* COMMON_IMPRIMIR_H_ */
