/**************************   Clase Fachada_Vista      ************************/
/**************************   Grupo 8                  ************************/


#ifndef COMMON_FACHADA_VISTA_H_
#define COMMON_FACHADA_VISTA_H_

#include "common_Box_Ventana_Interna.h"
#include <gtkmm.h>
#include "../common/constantes.h"
#include "../modelo/simulacion/common_Resultado.h"
#include "common_Ventana_Error.h"
#include "common_Ventana_Abrir.h"

class Fachada_vista {

private:

	Box_Ventana_Interna* ventana_interna;
	Ventana_Error ventana_error;
	Ventana_Abrir ventana_abrir;

public:

	Fachada_vista(Box_Ventana_Interna* ventata_int);

	void dibujar_componente(gdouble x,gdouble y,TIPO_COMPUERTA tipo,SENTIDO sentido,int tam_pista=0);

	void borrar_pista(int _x,int _y,SENTIDO _sentido);

	void borrar_componente(gdouble x,gdouble y,TIPO_COMPUERTA tipo,SENTIDO sentido,int tam_pista=0);

	void completar_grilla(Resultado* resultado);

	void agregar_grilla(int id);

	int cambiar_grilla(int index);

	void eliminar_grilla();

	void activar_dnd();

	void desactivar_dnd();

	int getIdActual() const;

	void mostrar_error(const std::string &texto);

	void aceptar_error();

	void mostrar_ventana_abrir();

	void aceptar_abrir();

	void cancelar_abrir();

	bool abriendo();

	char* getCircuitoAbrir();


};

#endif /* COMMON_FACHADA_VISTA_H_ */
