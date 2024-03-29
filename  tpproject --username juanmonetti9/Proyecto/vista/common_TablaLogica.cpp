/**************************   Clase TablaLogica    ********************/
/**************************   Grupo 8              ********************/

#include "common_TablaLogica.h"
#include <string>
#include <iostream>

TablaLogica::TablaLogica() {

	box_Tabla= gtk_hbox_new(false,0);

	tablaEntradas= gtk_clist_new(1);

	gtk_box_pack_start(GTK_BOX(box_Tabla),tablaEntradas,TRUE,TRUE,0);

	gtk_widget_show(tablaEntradas);

	tablaSalidas= gtk_clist_new(1);

	gtk_box_pack_start(GTK_BOX(box_Tabla),tablaSalidas,TRUE,TRUE,0);

	gtk_widget_show(tablaSalidas);

	tablaTiempos= gtk_clist_new(1);

	gtk_box_pack_start(GTK_BOX(box_Tabla),tablaTiempos,TRUE,TRUE,0);

	gtk_widget_show(tablaTiempos);



}

TablaLogica::~TablaLogica() {
	// TODO Auto-generated destructor stub
}


void TablaLogica::show() {

	gtk_widget_show(box_Tabla);

}

void TablaLogica::hide() {

	gtk_widget_hide(box_Tabla);

}

void TablaLogica::escalar(int fd) {

}

GtkWidget* TablaLogica::getWidget() {

	return box_Tabla;

}

void TablaLogica::completar(Resultado* resultados) {

	crear(resultados);

	completarSimulacion(resultados->getResultadoSimulacion());
	completarTiempo(resultados->getResultadoTiempo(),resultados->getNombreSalidas());

	delete resultados;

}

void TablaLogica::crear(Resultado* resultados) {

	gtk_widget_destroy(tablaEntradas);
	gtk_widget_destroy(tablaSalidas);
	gtk_widget_destroy(tablaTiempos);

	crearTablaEntradas(resultados->getNombreEntradas());
	crearTablaSalidas(resultados->getNombreSalidas());
	crearTablaTiempos();


}

void TablaLogica::crearTablaEntradas(std::vector<std::string>* entradas) {

	char** titles= new char*[entradas->size()];

	for (unsigned int var = 0; var < entradas->size(); ++var) {

		titles[var]= new char[(*entradas)[var].size() + 1];

		(*entradas)[var].copy(titles[var],(*entradas)[var].size());

		titles[var][(*entradas)[var].size()]= '\0';

	}

	tablaEntradas= gtk_clist_new_with_titles(entradas->size(),titles);

	for (unsigned int var = 0; var < entradas->size(); ++var) {

		delete[] titles[var];

	}

	delete[] titles;

	gtk_clist_column_titles_passive( GTK_CLIST(tablaEntradas) );

	for (unsigned int var = 0; var < entradas->size(); ++var) {

		gtk_clist_set_column_justification( GTK_CLIST(tablaEntradas) , var, GTK_JUSTIFY_CENTER);

	}

	gtk_box_pack_start(GTK_BOX(box_Tabla),tablaEntradas,TRUE,TRUE,0);

	gtk_widget_show(tablaEntradas);


}

void TablaLogica::crearTablaSalidas(std::vector<std::string>* salidas) {

	char** titles= new char*[salidas->size()];

	for (unsigned int var = 0; var < salidas->size(); ++var) {

		titles[var]= new char[(*salidas)[var].size() + 1];

		(*salidas)[var].copy(titles[var],(*salidas)[var].size());

		titles[var][(*salidas)[var].size()]= '\0';

	}

	tablaSalidas= gtk_clist_new_with_titles(salidas->size(),titles);

	for (unsigned int var = 0; var < salidas->size(); ++var) {

		delete[] titles[var];

	}

	delete[] titles;

	gtk_clist_column_titles_passive( GTK_CLIST(tablaSalidas) );

	for (unsigned int var = 0; var < salidas->size(); ++var) {

		gtk_clist_set_column_justification( GTK_CLIST(tablaSalidas) , var, GTK_JUSTIFY_CENTER);

	}

	gtk_box_pack_start(GTK_BOX(box_Tabla),tablaSalidas,TRUE,TRUE,0);

	gtk_widget_show(tablaSalidas);

}

const char* TablaLogica::titlesTiempos[]= {

	"Salidas","Tiempos",""

};

void TablaLogica::crearTablaTiempos() {

	tablaTiempos= gtk_clist_new_with_titles(CANTIDADTITLESTIEMPOS,(gchar**)titlesTiempos);

	gtk_clist_column_titles_passive( GTK_CLIST(tablaTiempos) );

	for (int var = 0; var < CANTIDADTITLESTIEMPOS; ++var) {

		gtk_clist_set_column_justification( GTK_CLIST(tablaTiempos) , var, GTK_JUSTIFY_CENTER);

	}

	gtk_box_pack_start(GTK_BOX(box_Tabla),tablaTiempos,TRUE,TRUE,0);

	gtk_widget_show(tablaTiempos);


}

void TablaLogica::completarSimulacion(std::vector<ResultadoSimulacion*>* resultado) {

	ResultadoSimulacion* resultadoAux;

	char** entradas;
	char** salidas;

	for (unsigned int var = 0; var < resultado->size(); ++var) {

		resultadoAux= (*resultado)[var];

		entradas= generarSalida(resultadoAux->getEntradas(),resultadoAux->getCantidadEntradas());
		salidas= generarSalida(resultadoAux->getSalidas(),resultadoAux->getCantidadSalidas());

		gtk_clist_append( GTK_CLIST(tablaEntradas), entradas);
		gtk_clist_append( GTK_CLIST(tablaSalidas), salidas);

		delete[] entradas;
		delete[] salidas;

	}

}

void TablaLogica::completarTiempo(ResultadoTiempo* resultado,std::vector<std::string>* salidas) {

	char* fila[3];
	int* tiempos= resultado->getTiempos();

	for (unsigned int var = 0; var < resultado->getCantidad(); ++var) {

		fila[0]= new char[(*salidas)[var].size() + 1];
		(*salidas)[var].copy(fila[0],(*salidas)[var].size());
		fila[0][(*salidas)[var].size()]= '\0';

		fila[1]= new char[4];
		sprintf(fila[1],"%d",tiempos[var]);

		fila[2]= (char*)"";

		gtk_clist_append( GTK_CLIST(tablaTiempos), fila);

		delete[] fila[0];
		delete[] fila[1];

	}

}

char* TablaLogica::UNO= (char*)"1";
char* TablaLogica::CERO= (char*)"0";

char** TablaLogica::generarSalida(bool* valores,int cantidad) {

	char** salida= new char*[cantidad];

	for (int var = 0; var < cantidad; ++var) {

		if (valores[var]) {

			salida[var]= UNO;

		}else {

			salida[var]= CERO;

		}
	}

	return salida;

}
