#ifndef COMMON_DIBUJADOR_H_
#define COMMON_DIBUJADOR_H_

#include <cairo/cairo.h>
#include "../modelo/circuito/compuertas/common_Compuerta.h"
#include "../modelo/circuito/common_ConexionVertice.h"
#include <gtk-2.0/gtk/gtk.h>

class Dibujador {

public:

	void dibujar(Compuerta* compuerta,cairo_t* cr);

	void dibujarConexion(ConexionVertice conexion,cairo_t* cr);

	void dibujarGrilla(cairo_t* cr);


private:

	void dibujarAnd(Posicion posicion, SENTIDO sentido,cairo_t* cr);

	void dibujarOr(Posicion posicion, SENTIDO sentido,cairo_t* cr);

	void dibujarXOr(Posicion posicion, SENTIDO sentido,cairo_t* cr);

	void dibujarNot(Posicion posicion, SENTIDO sentido,cairo_t* cr);

	void dibujarPista(Posicion posicion, SENTIDO sentido,cairo_t* cr);

	void dibujarEntrada(Posicion posicion, SENTIDO sentido,cairo_t* cr);

	void dibujarSalida(Posicion posicion, SENTIDO sentido,cairo_t* cr);

	void dibujarCajaNegra(Posicion posicion, SENTIDO sentido,int entradas,int salidas,cairo_t* cr);


	void draw_vertice(gdouble x,gdouble y,cairo_t *cr,SENTIDO sentido);

	/**
	 * Dibuja una caja negra
	 */
	void draw_CAJANEGRA(gdouble x,gdouble y,cairo_t *cr,int cant_entradas,int cant_salidas);

	/**
	 * Dibuja una pista
	 */
	void draw_pista_sur(gdouble x, gdouble y,cairo_t *cr);

	void draw_pista_norte(gdouble x, gdouble y,cairo_t *cr);

	void draw_pista_este(gdouble x, gdouble y,cairo_t *cr);

	void draw_pista_oeste(gdouble x, gdouble y,cairo_t *cr);

	/**
	 * Dibuja la entrada
	 */
	void draw_entrada_sur(gdouble x, gdouble y,cairo_t *cr);

	void draw_entrada_norte(gdouble x, gdouble y,cairo_t *cr);

	void draw_entrada_este(gdouble x, gdouble y,cairo_t *cr);

	void draw_entrada_oeste(gdouble x, gdouble y,cairo_t *cr);

	/**
	 * Dibuja la salida
	 */
	void draw_salida_sur(gdouble x, gdouble y,cairo_t *cr);

	void draw_salida_norte(gdouble x, gdouble y,cairo_t *cr);

	void draw_salida_este(gdouble x, gdouble y,cairo_t *cr);

	void draw_salida_oeste(gdouble x, gdouble y,cairo_t *cr);

	/**
	 * Dibuja la compuerta NOT
	 */
	void draw_NOT_sur(gdouble x, gdouble y,cairo_t *cr);

	void draw_NOT_norte(gdouble x, gdouble y,cairo_t *cr);

	void draw_NOT_este(gdouble x, gdouble y,cairo_t *cr);

	void draw_NOT_oeste(gdouble x, gdouble y,cairo_t *cr);
	/**
	 * Dibuja la compuerta AND
	 */
	void draw_AND_este(gdouble x, gdouble y,cairo_t *cr);

	void draw_AND_oeste(gdouble x, gdouble y,cairo_t *cr);

	void draw_AND_norte(gdouble x, gdouble y,cairo_t *cr);

	void draw_AND_sur(gdouble x, gdouble y,cairo_t *cr);
	/**
	 * Dibuja la compuerta OR
	 */
	void draw_OR_este(gdouble x, gdouble y,cairo_t *cr);

	void draw_OR_oeste(gdouble x, gdouble y,cairo_t *cr);

	void draw_OR_norte(gdouble x, gdouble y,cairo_t *cr);

	void draw_OR_sur(gdouble x, gdouble y,cairo_t *cr);
	/**
	 * Dibuja la compuerta XOR
	 */
	void draw_XOR_este(gdouble x, gdouble y,cairo_t *cr);

	void draw_XOR_oeste(gdouble x, gdouble y,cairo_t *cr);

	void draw_XOR_norte(gdouble x, gdouble y,cairo_t *cr);

	void draw_XOR_sur(gdouble x, gdouble y,cairo_t *cr);


};

#endif /* COMMON_DIBUJADOR_H_ */
