/*
 * common_Boton_CloseWin.h
 *
 *  Created on: 19/11/2009
 *      Author: juanm
 */

#ifndef COMMON_BOTON_CLOSE_PESTANIA_H_
#define COMMON_BOTON_CLOSE_PESTANIA_H_

#include "common_Boton.h"

class Boton_Close_pestania: public Boton {

private:
	GtkWidget* box_boton;

public:
	Boton_Close_pestania();

	void conectar();

	virtual GtkWidget* get_Box_Widget();

	virtual ~Boton_Close_pestania();
};

#endif /* COMMON_BOTON_CLOSE_PESTANIA_H_ */
