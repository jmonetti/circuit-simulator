
#ifndef COMMON_CAJANEGRA_H_
#define COMMON_CAJANEGRA_H_

#include "common_Compuerta.h"
#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"
#include "../../modelo/common_Publicacion.h"
#include "../../modelo/common_Servidor.h"
#include <vector>

class CajaNegra: public Compuerta {

public:

	CajaNegra(int id,std::vector<EntradaCompuerta*> &entradas, std::vector<SalidaCompuerta*> &salidas,Servidor &servidor);

	virtual ~CajaNegra();

	void calcularTiempoTransicion();

protected:

	virtual void actuarSimular(bool* entradas);

	virtual EntradaCompuerta** getEntradasCompuerta();

	virtual int getCantidadEntradas();

private:

	std::vector<EntradaCompuerta*> entradas;
	std::vector<SalidaCompuerta*> salidas;
	Publicacion publicacion;
	Servidor servidor;
	std::string nombre;

};

#endif /* COMMON_CAJANEGRA_H_ */
