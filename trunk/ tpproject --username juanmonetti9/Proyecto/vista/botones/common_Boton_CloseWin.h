/*
 * common_Boton_CloseWin.h
 *
 *  Created on: 19/11/2009
 *      Author: juanm
 */

#ifndef COMMON_BOTON_CLOSEWIN_H_
#define COMMON_BOTON_CLOSEWIN_H_

#include "common_Boton.h"

class Boton_CloseWin: public Boton {

public:
	Boton_CloseWin();

	void conectar(void* param);

	virtual ~Boton_CloseWin();
};

#endif /* COMMON_BOTON_CLOSEWIN_H_ */
