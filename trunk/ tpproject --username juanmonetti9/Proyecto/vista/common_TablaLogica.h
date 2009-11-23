/**************************   Clase TablaLogica    ********************/
/**************************   Grupo 8              ********************/

#ifndef COMMON_TABLALOGICA_H_
#define COMMON_TABLALOGICA_H_

#include <gtkmm.h>
#include "common_Componente_Visual.h"
#include <vector>
#include "../modelo/common_ResultadoSimulacion.h"

class TablaLogica : public Componente_Visual{

public:

	TablaLogica();

	virtual ~TablaLogica();

	virtual void show();

	virtual void escalar(int fd);

	virtual GtkWidget* getWidget();

	void completar();


private:

	GtkWidget* box_Tabla;
	GtkWidget* tabla;

	void crear();


};

#endif /* COMMON_TABLALOGICA_H_ */
