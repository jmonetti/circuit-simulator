
#ifndef COMMON_CAJANEGRA_H_
#define COMMON_CAJANEGRA_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"
#include <vector>
#include <string>
#include "../../publicacion/common_Publicacion.h"
#include "../../publicacion/common_Servidor.h"

using namespace std;

class CajaNegra: public Compuerta {

public:

	CajaNegra(int id,std::vector<EntradaCompuerta*> &entradas, std::vector<SalidaCompuerta*> &salidas,Posicion posicion,SENTIDO sentido,
const std::string &nombreCircuito,Servidor servidor);

	virtual ~CajaNegra();

	void calcularTiempoTransicion();

	void simular();

	TIPO_COMPUERTA getTipo() const;

	EntradaCompuerta** getEntradas();

	SalidaCompuerta** getSalidas();

	int getCantidadEntradas();

	int getCantidadSalidas();

	void guardar(DOMDocument* doc, DOMNode* padre);

protected:

	void actualizarEntradas();
	void actualizarSalidas();

private:

	std::vector<EntradaCompuerta*> entradas;
	std::vector<SalidaCompuerta*> salidas;
	Publicacion publicacion;
	std::string nombreCircuito;
	Servidor servidor;

};

#endif /* COMMON_CAJANEGRA_H_ */
