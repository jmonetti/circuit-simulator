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
	std::map<int,Modelo_vista_circuito*> matrices; //matriz que representa el modelo
	Modelo_vista_circuito* matrizActual;
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

	void guardar();

	void simular();

	void abrir_circuito();

	void crear_circuito();

	void eliminar_circuito();

	void cambiar_circuito(int index);

	void mostrar_upload();

	void ejecutar_upload();

	void mostrar_download();

	void ejecutar_download();

	void conectar();

	void agregar_entrada(int x,int y,SENTIDO sentido= ESTE);

	void agregar_salida(int x,int y,SENTIDO sentido= ESTE);

	void agregar_componente(int x,int y,TIPO_COMPUERTA _tipo,SENTIDO sentido = ESTE);

	void agregar_caja_negra(int x,int y);

	void eliminar_componente(int x,int y);

	void agregar_accion(Accion* nueva_accion);

	void ejecutar_accion(gdouble x,gdouble y);

	void rotar(int x,int y,DIRECCION n_direccion);

	void set_pos_x_click(int x);

	void set_pos_y_click(int y);

	void conectar_drag_drop();

	void desconectar_drag_drop();

	bool get_arrastre_activo()const;

	void arrastrar(gdouble x, gdouble y);

	void crear_entrada();

	void crear_salida();

	void aceptar_abrir();

	void cancelar_abrir();

	void aceptar_nuevo();

	void destruir_vista();


	static Controlador* crear_instancia(Fachada_vista* fachada,ModeloCliente* modeloCliente);

	static Controlador* get_instancia();

	virtual ~Controlador();
};

#endif /* COMMON_CONTROLADOR_H_ */
