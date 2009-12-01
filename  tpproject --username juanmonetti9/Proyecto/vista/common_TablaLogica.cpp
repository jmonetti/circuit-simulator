/**************************   Clase TablaLogica    ********************/
/**************************   Grupo 8              ********************/

#include "common_TablaLogica.h"
#include <string>
#include <iostream>

TablaLogica::TablaLogica() {

	box_Tabla= gtk_hbox_new(false,0);

	tabla= gtk_clist_new(1);

	gtk_box_pack_start(GTK_BOX(box_Tabla),tabla,TRUE,TRUE,0);

	gtk_widget_show(tabla);


}

TablaLogica::~TablaLogica() {
	// TODO Auto-generated destructor stub
}


void TablaLogica::show() {

	gtk_widget_show(box_Tabla);

}

void TablaLogica::escalar(int fd) {

}

GtkWidget* TablaLogica::getWidget() {

	return box_Tabla;

}

void TablaLogica::completar(Resultado* resultados) {

	crear();

	gchar* filas[4] = {
			"1","0","1",""
	};

	gtk_clist_append(GTK_CLIST(tabla),filas);

	/************************************/

	ResultadoSimulacion* resultado;
	for (unsigned int var = 0; var < resultados->getResultadoSimulacion()->size(); ++var) {

		resultado= resultados->getResultadoSimulacion()->at(var);

		std::cout<<"Entrada: ";

		for (unsigned int j = 0; j < resultado->getCantidadEntradas(); ++j) {

			std::cout<<resultado->getEntradas()[j];

		}

		std::cout<<std::endl;

		std::cout<<"Salida: ";

		for (unsigned int j = 0; j < resultado->getCantidadSalidas(); ++j) {

			std::cout<<resultado->getSalidas()[j];

		}

		std::cout<<std::endl;

	}

	std::cout<<std::endl<<std::endl;

	int* tiempos= resultados->getResultadoTiempo()->getTiempos();

	for (unsigned int var = 0; var < resultados->getResultadoTiempo()->getCantidad(); ++var) {

		std::cout << "Tiempo: "  << tiempos[var] << std::endl;

	}

	delete resultados;
	/***********************************************/


}

void TablaLogica::crear() {

	gtk_widget_destroy(tabla);

	std::string nombres[4]= {
			"Entrada 1" , "Entrada 2" , "Salida 1" , ""
	};

	char* titles[4];

	for (int var = 0; var < 4; ++var) {

		titles[var]= (char*) nombres[var].c_str();

	}

	tabla= gtk_clist_new_with_titles(4,titles);

	gtk_clist_column_titles_passive( GTK_CLIST(tabla) );

	for (int var = 0; var < 4; ++var) {

		gtk_clist_set_column_justification( GTK_CLIST(tabla) , var, GTK_JUSTIFY_CENTER);
		gtk_clist_set_column_width( GTK_CLIST(tabla) , var, nombres[var].size() * 10);

	}

	gtk_box_pack_start(GTK_BOX(box_Tabla),tabla,TRUE,TRUE,0);

	gtk_widget_show(tabla);

}
