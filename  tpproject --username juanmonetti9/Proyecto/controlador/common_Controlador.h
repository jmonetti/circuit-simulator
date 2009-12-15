/**************************   Clase Controlador         *************/
/**************************   	Grupo 8                 *************/

#ifndef COMMON_CONTROLADOR_H_
#define COMMON_CONTROLADOR_H_

#include "Modelo_vista_circ/common_Modelo_vista_circuito.h"
#include "../common/common_Posicion.h"
#include "../vista/common_Fachada_vista.h"
#include "../common/constantes.h"
#include "Acciones/common_Accion.h"
#include "../modelo/common_ModeloCliente.h"
#include <map>
#include "../modelo/circuito/common_Circuito.h"

class Controlador {

private:

	//Atributos
	std::map<int,Modelo_vista_circuito*> matrices; //matrices que representa el modelo
	Modelo_vista_circuito* matrizActual;		   //matriz actual
	ModeloCliente* modeloCliente; //modelo que representa el cliente
	Fachada_vista* fachada_vista; //fachada para la comunicacion con la vista
	Accion* accion;
	bool arrastre_activo;
	int pos_x; //pos de clickeo
	int pos_y; //pos de clickeo

	//instancia estatica por ser un singleton
	static Controlador* instancia;


	//Constructor privado
	Controlador(Fachada_vista* fachada,ModeloCliente *modeloCliente);

	void generarCircuito(Circuito* circuito);

	void incluir_componentes_rdraw(std::list<Posicion> &vertices,std::list<SENTIDO>  &sentidos,unsigned fila,unsigned int colum,unsigned int id);

	void incluir_vertices(std::vector<ConexionVertice> conexiones);

	void redibujar_circuito(std::vector<Compuerta*> compuertas);

public:

	/**
	 * Guarda el circuito actual y muestra un msj por pantalla
	 * si fue guardado exitosamente
	 */
	void guardar();

	/**
	 * Simula el circuito actual y completa la tabla de la vista
	 */
	void simular();

	/**
	 * Abre un circuito guardado, muestra por pantalla la ventana
	 * para la eleccion del circuito a abrir
	 */
	void abrir_circuito();

	/**
	 * crea un nuevo circuito, muestra por panatalla la ventana
	 * de nuevo circuito
	 */
	void crear_circuito();

	void mostrar_imprimir();

	void imprimir(GtkPrintContext* context);

	/**
	 * Elimina un circuito del modelo y de la vista
	 */
	void eliminar_circuito();

	/**
	 * cambia el circuito actual, al identificado con el
	 * parametro index
	 */
	void cambiar_circuito(int index);

	/**
	 * muestra la ventana de upload
	 */
	void mostrar_upload();

	/**
	 * Ennvia el circuito al servidor
	 */
	void ejecutar_upload();

	/**
	 * muestra la ventana de download
	 */
	void mostrar_download();

	/**
	 * Recibe el circuito del servidor
	 */
	void ejecutar_download();

	/**
	 * Conecta con el servidor
	 */
	void conectar();

	/**
	 *  Metodos para agregar compoonentes
	 */
	void agregar_entrada(int x,int y,SENTIDO sentido= ESTE);

	void agregar_salida(int x,int y,SENTIDO sentido= ESTE);

	void agregar_componente(int x,int y,TIPO_COMPUERTA _tipo,SENTIDO sentido = ESTE);

	void agregar_caja_negra(int x,int y);

	/**
	 * Elimina el componente de la posicion x , y
	 */
	void eliminar_componente(int x,int y);

	/**
	 * Setea la accion del controlador con el parametro nueva_accion
	 */
	void agregar_accion(Accion* nueva_accion);

	/**
	 * Ejecuta la accion del controlador
	 */
	void ejecutar_accion(gdouble x,gdouble y);

	/**
	 * Reota el componente ubicado en la pos x,y en la direccion
	 * n_direccion
	 */
	void rotar(int x,int y,DIRECCION n_direccion);

	/**
	 * Seteala variable pos_x con el valor pasado por parametro
	 */
	void set_pos_x_click(int x);

	/**
	 * Seteala variable pos_y con el valor pasado por parametro
	 */
	void set_pos_y_click(int y);

	/**
	 * setea en true el atributo arrastre_activo
	 */
	void conectar_drag_drop();

	/**
	 * setea en false el atributo arrastre_activo
	 */
	void desconectar_drag_drop();

	/**
	 * Retorna el valor del atributo arrastre_activo
	 */
	bool get_arrastre_activo()const;

	/**
	 * arrastra a la posicion x,y si es posible
	 */
	void arrastrar(gdouble x, gdouble y);

	/**
	 * Muestra la ventana de pre_view de la caja negra ubicada
	 * en la pos x,y
	 */
	void mostrar_caja_negra(int x,int y);

	/**
	 * Muestra la ventana de nueva entrada
	 */
	void crear_entrada();

	/**
	 * Muestra la ventana de nueva salida
	 */
	void crear_salida();

	/**
	 * Agerga el circuito abierto al modelo y a la vista,
	 * oculta la ventana de abrir
	 */
	void aceptar_abrir();

	/**
	 * Oculta la ventana de abrir y elimina la grilla de la vista
	 */
	void cancelar_abrir();

	/**
	 * Agrega el circuito nuevo al modelo y a la vista
	 */
	void aceptar_nuevo();


	/**
	 * Crea una nueva instancia del controlador y la retorna,
	 * si es que no estaba creada sino retorna la instancia
	 */
	static Controlador* crear_instancia(Fachada_vista* fachada,ModeloCliente* modeloCliente);

	/**
	 * Retorna la instancia del controlador si fue creada, sino
	 * retorna NULL
	 */
	static Controlador* get_instancia();

	/**
	 * Libera los recursos del controlador
	 */
	virtual ~Controlador();
};

#endif /* COMMON_CONTROLADOR_H_ */
