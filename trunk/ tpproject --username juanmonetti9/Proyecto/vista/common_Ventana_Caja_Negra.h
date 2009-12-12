
#ifndef COMMON_VENTANA_CAJA_NEGRA_H_
#define COMMON_VENTANA_CAJA_NEGRA_H_

#include "common_Componente_Visual.h"
#include "../controlador/common_Controladores_Window.h"

#include "../common/constantes.h"
#include "common_Area_disenio.h"

class Ventana_Caja_Negra: public Componente_Visual {

private:

	GtkWidget* ventana;
	GtkWidget* box_ventana;
	Area_disenio area_disenio;
	GtkWidget* scroll;



	void dibujar_pista(gdouble x,gdouble y,SENTIDO sentido);

	void dibujar_entrada(gdouble x,gdouble y,SENTIDO sentido);

	void dibujar_salida(gdouble x,gdouble y,SENTIDO sentido);

	void dibujar_and(gdouble x,gdouble y,SENTIDO sentido);

	void dibujar_or(gdouble x,gdouble y,SENTIDO sentido);

	void dibujar_not(gdouble x,gdouble y,SENTIDO sentido);

	void dibujar_xor(gdouble x,gdouble y,SENTIDO sentido);

	void dibujar_compuerta(gdouble x,gdouble y,TIPO_COMPUERTA tipo,SENTIDO sentido);


public:

	Ventana_Caja_Negra();

	void show();

	void hide();

	GtkWidget* getWidget();

	void setear_nombre(const std::string &nombre);

	void agregar_componente(gdouble x,gdouble y,TIPO_COMPUERTA tipo,SENTIDO sentido);

	void agregar_caja_negra(gdouble x,gdouble y,int cant_entradas,int cant_salidas);

	void agregar_vertice(gdouble x,gdouble y,SENTIDO sentido);


	virtual ~Ventana_Caja_Negra();
};

#endif /* COMMON_VENTANA_CAJA_NEGRA_H_ */
