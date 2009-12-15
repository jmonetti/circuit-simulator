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
#include "common_Imprimir.h"

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
	Imprimir impresion;

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

	void mostrar_imprimir();

	void imprimir(GtkPrintContext* context,std::vector<Compuerta*>& compuertas,std::vector<ConexionVertice>& conexiones);

	/**
	 * Compĺeta la tabla de la vista con los datos del parametro
	 * resultado
	 */
	void completar_grilla(Resultado* resultado);

	/**
	 * Agrega un nuevo area de diseño a la vista
	 */
	void agregar_grilla(int id,const char* nombre);

	/**
	 * Setea el nombre del area de diseño
	 */
	void set_nombre_grilla(const char* nombre);

	/**
	 * Cambia el area de diseño que esta actualmente visible
	 * en pantalla por la identifiicada con el parametro
	 * index
	 */
	int cambiar_grilla(int index);

	/**
	 * Elimina el area de diseño actual
	 */
	void eliminar_grilla();

	/**
	 * Retorna el identificador del area de diseño
	 * que se esta mostrando por pantalla
	 */
	int getIdActual() const;

	/**
	 * Muestra la ventana de upload
	 */
	void mostrar_ventana_upload(std::vector<char*>* circuitos);

	/**
	 * Retorna true si la ventana esta activa
	 */
	bool upload_activo();

	/**
	 * Retorna el texto con el circuito seleccionado
	 */
	char* get_circuito_upload();

	/**
	 * Oculta la ventana
	 */
	void ocultar_upload();

	/**
	 * Retorna el host recibido por el usuario
	 */
	const char* get_host_upload();

	/**
	 * Retorna el host recibido por el usuario
	 */
	const char* get_puerto_upload();

	/**
	 * Muestra la ventana de download
	 */
	void mostrar_ventana_download();

	/**
	 * Retorna true si la ventana esta activa
	 */
	bool download_activo();

	/**
	 * Retorna el texto con el circuito seleccionado
	 */
	char* get_circuito_download();

	/**
	 * Oculta la ventana
	 */
	void ocultar_download();

	/**
	 * Retorna el host recibido por el usuario
	 */
	const char* get_host_download();

	/**
	 * Retorna el puerto recibido por el usuario
	 */
	const char* get_puerto_download();

	/**
	 * Muestra la ventana conlos circuitos del servidor
	 */
	void mostrar_circuitos_servidor(std::vector<char*>* circuitos);

	/**
	 * Muestra la ventana para la incorporacion de una entrada
	 */
	void mostrar_ventana_entrada();

	/**
	 * Muestra la ventana para la incorporacion de una salida
	 */
	void mostrar_ventana_salida();

	/**
	 * Retorna el nombre de la entrada recibido por el usuario
	 */
	const char* get_nombre_entrada();

	/**
	 * Retorna el nombre de la salida recibido por el usuario
	 */
	const char* get_nombre_salida();

	/**
	 * Muestra la ventana de error, con el msj del parametro texto
	 */
	void mostrar_error(const std::string &texto);

	/**
	 * Muestra la ventana para abrir con los circuitos pasados
	 * por parametro
	 */
	void mostrar_ventana_abrir(std::vector<char*>* circuitos);

	/**
	 * Oculta la ventana
	 */
	void ocultar_abrir();

	/**
	 * Retoirna true si la ventana esta activa
	 */
	bool abriendo();

	/**
	 * Muestra la ventana de nuevo circuit
	 */
	void mostrar_ventana_nuevo();

	/**
	 * Esconde la ventana
	 */
	void aceptar_nuevo();

	/**
	 * Retorna la cadena con el circuito selecc por el usuario
	 */
	char* getCircuitoAbrir();

	/**
	 *  Retorna la cadena ingresada por el usuario en la ventana
	 */
	const char* getNombreNuevo();

	/**
	 * Muestra la ventana de confirmacion con el texto pasado
	 * por el parametro
	 */
	void mostrar_confirmacion(const std::string &texto);


};

#endif /* COMMON_FACHADA_VISTA_H_ */
