/**************************   Clase Controlador         *************/
/**************************   	Grupo 8                 *************/

#ifndef COMMON_CONTROLADOR_H_
#define COMMON_CONTROLADOR_H_

#include "Modelo_vista_circ/common_Modelo_vista_circuito.h"
#include "../common/common_Posicion.h"
#include "../vista/common_Fachada_vista.h"
#include "../common/constantes.h"
#include "Acciones/common_Accion_NULA.h"
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
	bool arrstre_activo;
	int pos_x; //pos de clickeo
	int pos_y; //pos de clickeo

	//instancia estatica por ser un singleton
	static Controlador* instancia;


	//Constructor privado
	Controlador(Fachada_vista* fachada,ModeloCliente *modeloCliente);

	void generarCircuito(Circuito* circuito);

public:

	void guardar();

	void simular();

	void abrir_circuito();

	void crear_circuito();

	void eliminar_circuito();

	void cambiar_circuito(int index);

	void agregar_componente(int x,int y,TIPO_COMPUERTA _tipo,SENTIDO sentido = ESTE);

	void eliminar_componente(int x,int y);

	void agregar_accion(Accion* nueva_accion);

	void ejecutar_accion(gdouble x,gdouble y);

	void rotar_right(int x,int y);

	void rotar_left(int x,int y);

	void set_pos_x_click(int x);

	void set_pos_y_click(int y);

	void conectar_drag_drop();

	void desconectar_drag_drop();

	bool get_arrastre_activo()const;

	void arrastrar(gdouble x, gdouble y);

	void aceptar_error();

	void aceptar_abrir();

	void cancelar_abrir();

	static Controlador* crear_instancia(Fachada_vista* fachada,ModeloCliente* modeloCliente);

	static Controlador* get_instancia();

	virtual ~Controlador();
};

#endif /* COMMON_CONTROLADOR_H_ */
