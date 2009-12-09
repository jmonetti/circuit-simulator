/**************************   Clase Box_Ventana_Interna    ********************/
/**************************   Grupo 8                      ********************/

#ifndef CLASS_COMMON_BOX_VENTANA_INTERNA_H
#define CLASS_COMMON_BOX_VENTANA_INTERNA_H

#include "common_Vista_Panel.h"
#include "common_Decorador_Scroll.h"
#include "common_Componente_Visual.h"
#include <gtkmm.h>
#include "common_Grilla.h"
#include "../common/constantes.h"
#include <vector>

class Box_Ventana_Interna: public Componente_Visual{

private:

	//atributo
	std::vector<Grilla*> _grillas;
	GtkWidget* _box_ventana;
	GtkWidget* noteb;
	Grilla* actual;

	void eliminarGrilla(int index);


public:

	Box_Ventana_Interna();

	void limpiar_area();

	void agregar_grilla(int id,const char* nombre);

	void set_nombre_grilla(const char* nombre);

	int getGrillaActual() const;

	int cambiar_grilla_actual(int index);

	void eliminar_grilla_actual();

	void completar_tabla_actual(Resultado* resultado);

	/**
	 * Muestra el componente Visual
	 */
	virtual void show();

	/**
	 * Da un nuevo tamanio al componente visual
	 * @param: factor de amplificacion de la escala
	 */
	virtual void escalar(int _fa);

	/**
	 * TODO este va a dibujar cualquier compuerta
	 * y sobre la pestania actual CAMBIAR
	 */
	void dibujar_componente(gdouble x,gdouble y,TIPO_COMPUERTA tipo,SENTIDO sentido,int tam_pista);

	void dibujar_caja_negra(gdouble x,gdouble y,int cant_entradas,int cant_salidas);

	void dibujar_vertice(gdouble x,gdouble y,SENTIDO sentido);

	void borrar_caja_negra(gdouble x,gdouble y,int cant_entradas,int cant_salidas);

	void borrar_pista(int _x,int _y,SENTIDO _sentido);

	void borrar_componente(gdouble x,gdouble y,TIPO_COMPUERTA tipo,SENTIDO sentido,int tam_pista=0);

	void connect_dnd();

	void disconnect_dnd();

	/**
	 * Retorna el widget
	 */
	virtual GtkWidget* getWidget();

	virtual ~Box_Ventana_Interna();




};
#endif
