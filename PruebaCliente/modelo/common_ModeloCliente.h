
#ifndef COMMON_MODELOCLIENTE_H_
#define COMMON_MODELOCLIENTE_H_

#include <vector>
#include <string>

#include "circuito/common_Circuito.h"
#include "circuito/compuertas/common_CajaNegra.h"
#include "publicacion/common_Servidor.h"
#include "persistencia/common_Persistencia.h"
#include "publicacion/common_Publicacion.h"
#include "simulacion/common_Simulador.h"
#include "../common/constantes.h"
#include "../common/common_Posicion.h"
#include "simulacion/common_Resultado.h"

class ModeloCliente {

public:

	ModeloCliente();

	virtual ~ModeloCliente();

	void crearNuevo(const std::string &nombre);

	void cambiarCircuitoActual(int idCircuito);

	void eliminar();

	void agregarCompuerta(TIPO_COMPUERTA tipo,Posicion posicion,SENTIDO sentido);

	void agregarEntrada(Posicion posicion,const std::string &nombre, SENTIDO sentido);

	void agregarSalida(Posicion posicion,const std::string &nombre, SENTIDO sentido);

	void eliminarCompuerta(int idCompuerta);

	Resultado* simular();

	void rotar(int idCompuerta,DIRECCION direccion);

	void mover(int idCompuerta,Posicion posicion);

	void guardar();

	void recuperar(const std::string &nombreCircuito);

	void enviar(const std::string &nombreCircuito,Servidor servidor);

	void recibir(const std::string &nombreCircuito,Servidor servidor);

	int getUltimo() const; //TODO


private:

	std::vector<Circuito*> circuitos;

	Circuito* circuitoActual;

	Persistencia persistencia;
	Publicacion publicacion;
	Simulador simulador;
	int contadorId;

	Circuito* obtenerCircuito(int idCircuito);



};

#endif /* COMMON_MODELOCLIENTE_H_ */
