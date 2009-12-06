#ifndef COMMON_VENTANA_DOWNLOAD_H_
#define COMMON_VENTANA_DOWNLOAD_H_

#include "common_Componente_Visual.h"

class Ventana_Download: public Componente_Visual {

public:

	Ventana_Download();

	virtual ~Ventana_Download();

	void show();

	void hide();

	GtkWidget* getWidget();

	char* getCircuitoDownload();

	const char* getHost();

	const char* getPuerto();

	void mostrarCircuitos(std::vector<char*>* circuitos);

	bool estaActiva();

private:

	GtkWidget* cuadro;
	GtkWidget* entryHost;
	GtkWidget* entryPuerto;
	GtkWidget* lista;

	const static char* titulo[];

	static char* circuitoDownload;

	static bool activa;

	static void select_row_callback(GtkWidget *widget, gint row, gint colum,
			GdkEventButton *event, gpointer data);

	static void unselect_row_callback(GtkWidget *widget, gint row, gint colum,
				GdkEventButton *event, gpointer data);

	static void callback_ocultar(GtkWidget *widget, gpointer data);

};

#endif /* COMMON_VENTANA_DOWNLOAD_H_ */
