/**************************   Clase TablaLogica    ********************/
/**************************   Grupo 8              ********************/

#ifndef COMMON_TABLALOGICA_H_
#define COMMON_TABLALOGICA_H_

#include <gtkmm.h>
#include "common_Componente_Visual.h"
#include "../modelo/simulacion/common_Resultado.h"
#include <vector>

class TablaLogica : public Componente_Visual{

public:

	TablaLogica();

	virtual ~TablaLogica();

	virtual void show();

	virtual void escalar(int fd);

	virtual GtkWidget* getWidget();

	void completar(Resultado* resultados);


private:

	GtkWidget* box_Tabla;
	GtkWidget* tablaEntradas;
	GtkWidget* tablaSalidas;
	GtkWidget* tablaTiempos;

	void crear(Resultado* resultados);

	void crearTablaEntradas(std::vector<std::string>* entradas);
	void crearTablaSalidas(std::vector<std::string>* salidas);
	void crearTablaTiempos();

	void completarSimulacion(std::vector<ResultadoSimulacion*>* resultado);
	void completarTiempo(ResultadoTiempo* resultado,std::vector<std::string>* salidas);

	char** generarSalida(bool* valores,int cantidad);

	static const char* titlesTiempos[];

	static const int CANTIDADTITLESTIEMPOS= 3;

	static char* UNO;

	static char* CERO;

};

#endif /* COMMON_TABLALOGICA_H_ */
