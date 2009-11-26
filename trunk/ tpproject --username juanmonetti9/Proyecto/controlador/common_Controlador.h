/**************************   Clase Controlador         *************/
/**************************   	Grupo 8                 *************/

#ifndef COMMON_CONTROLADOR_H_
#define COMMON_CONTROLADOR_H_

#include "Modelo_vista_circ/common_Modelo_vista_circuito.h"
#include "../vista/common_Fachada_vista.h"
#include "../common/constantes.h"

class Controlador {

private:

	//Atributos
	Modelo_vista_circuito matriz; //matriz que representa el modelo
	Fachada_vista* fachada_vista;
	int pos_x; //pos de clickeo
	int pos_y; //pos de clickeo

	//instancia estatica por ser un singleton
	static Controlador* instancia;


	//Constructor privado
	Controlador(Fachada_vista* fachada);

public:

	void set_pos_x_click(int x);

	void set_pos_y_click(int y);

	void agregar_componente(int x,int y,Tipo_Celda _tipo);

	void eliminar_componente(int x,int y);

	static Controlador* crear_instancia(Fachada_vista* fachada);

	static Controlador* get_instancia();

	virtual ~Controlador();
};

#endif /* COMMON_CONTROLADOR_H_ */
