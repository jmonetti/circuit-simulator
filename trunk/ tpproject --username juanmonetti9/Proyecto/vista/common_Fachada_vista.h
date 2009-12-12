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
#include "common_Ventana_Nuevo.h"
#include "common_Ventana_Confirmacion.h"
#include "common_Ventana_Entrada.h"
#include "common_Ventana_Salida.h"
#include "common_Ventana_Upload.h"
#include "common_Ventana_Download.h"
#include "common_Ventana_Caja_Negra.h"

class Fachada_vista {

private:

	Box_Ventana_Interna* ventana_interna;
	Ventana_Error ventana_error;
	Ventana_Abrir ventana_abrir;
	Ventana_Nuevo ventana_nuevo;
	Ventana_Confirmacion ventana_confirmacion;
	Ventana_Entrada ventana_entrada;
	Ventana_Salida ventana_salida;
	Ventana_Upload ventana_upload;
	Ventana_Download ventana_download;
	Ventana_Caja_Negra ventana_caja_negra;

public:

	Fachada_vista(Box_Ventana_Interna* ventata_int);

	void limpiar_area_disenio();

	/**
	 * Metodos para el dibujo sobre el area de diseño
	 */

	void dibujar_componente(gdouble x,gdouble y,TIPO_COMPUERTA tipo,SENTIDO sentido,int tam_pista=0);

	void dibujar_caja_negra(gdouble x,gdouble y,int cant_entradas,int cant_salidas);

	void dibujar_vertice(gdouble x,gdouble y,SENTIDO sentido);

	/**
	 * Metodos para el dibujo sobre la ventana auxiliar donde se
	 * mostrara el contenido de una caja negra
	 */

	void dibujar_componente_CN(gdouble x,gdouble y,TIPO_COMPUERTA tipo,SENTIDO sentido);

	void dibujar_caja_negra_CN(gdouble x,gdouble y,int cant_entradas,int cant_salidas);

	void dibujar_vertice_CN(gdouble x,gdouble y,SENTIDO sentido);

	void ocultar_Caja_negra();

	void mostrar_Caja_negra(const std::string &nombre);


	/**
	 * Metodos de la fachada
	 */

	void completar_grilla(Resultado* resultado);

	void agregar_grilla(int id,const char* nombre);

	void set_nombre_grilla(const char* nombre);

	int cambiar_grilla(int index);

	void eliminar_grilla();

	int getIdActual() const;

	void mostrar_ventana_upload(std::vector<char*>* circuitos);

	bool upload_activo();

	char* get_circuito_upload();

	void ocultar_upload();

	const char* get_host_upload();

	const char* get_puerto_upload();

	void mostrar_ventana_download();

	bool download_activo();

	char* get_circuito_download();

	void ocultar_download();

	const char* get_host_download();

	const char* get_puerto_download();

	void mostrar_circuitos_servidor(std::vector<char*>* circuitos);

	void mostrar_ventana_entrada();

	void mostrar_ventana_salida();

	const char* get_nombre_entrada();

	const char* get_nombre_salida();

	void mostrar_error(const std::string &texto);

	void mostrar_ventana_abrir(std::vector<char*>* circuitos);

	void ocultar_abrir();

	bool abriendo();

	void mostrar_ventana_nuevo();

	void aceptar_nuevo();

	char* getCircuitoAbrir();

	const char* getNombreNuevo();

	void mostrar_confirmacion(const std::string &texto);

	void delete_vista();


};

#endif /* COMMON_FACHADA_VISTA_H_ */
