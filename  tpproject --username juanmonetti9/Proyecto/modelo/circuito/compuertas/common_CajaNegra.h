
#ifndef COMMON_CAJANEGRA_H_
#define COMMON_CAJANEGRA_H_

#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"
#include <vector>
#include <string>
#include "../../publicacion/common_Publicacion.h"
#include "../../publicacion/common_Servidor.h"
#include "../../../common/common_TamanioCajaNegra.h"
#include "common_Compuerta.h"

using namespace std;

class CajaNegra: public Compuerta {

public:

	CajaNegra(int id,EntradaCompuerta** entradas, SalidaCompuerta** salidas,TamanioCajaNegra tamanio,
			Posicion posicion,SENTIDO sentido, const std::string &nombreCircuito,Servidor servidor);

	virtual ~CajaNegra();

	TIPO_COMPUERTA getTipo() const;

	EntradaCompuerta** getEntradas();

	SalidaCompuerta** getSalidas();

	int getCantidadEntradas();

	int getCantidadSalidas();

	void guardar(DOMDocument* doc, DOMNode* padre);

	Servidor getServidor() const;

	std::string getNombre() const;

protected:

	void actualizarEntradas();
	void actualizarSalidas();

	void actuarSimular(bool* valores);
	void actuarTiempo(int* tiempos);

private:

	EntradaCompuerta** entradas;
	SalidaCompuerta** salidas;
	TamanioCajaNegra tamanio;
	Publicacion publicacion;
	std::string nombreCircuito;
	Servidor servidor;

};

#endif /* COMMON_CAJANEGRA_H_ */
