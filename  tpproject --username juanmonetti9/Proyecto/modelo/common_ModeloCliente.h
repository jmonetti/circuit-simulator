
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
#include "../common/common_TamanioCajaNegra.h"
#include "simulacion/common_Resultado.h"
#include "circuito/common_ConexionVertice.h"

class ModeloCliente {

public:

	ModeloCliente();

	virtual ~ModeloCliente();

	void agregarEntradaCompuerta(int id);

	void agregarSalidaCompuerta(int id);

	int crearNuevo(const std::string &nombre);

	void cambiarCircuitoActual(int idCircuito);

	void eliminar();

	int agregarCompuerta(TIPO_COMPUERTA tipo,Posicion posicion,SENTIDO sentido);

	int agregarEntrada(Posicion posicion,const std::string &nombre, SENTIDO sentido);

	int agregarSalida(Posicion posicion,const std::string &nombre, SENTIDO sentido);

	int agregarCajaNegra(Posicion posicion,const std::string &nombre, SENTIDO sentido,Servidor servidor, TamanioCajaNegra tamanio);

	void eliminarCompuerta(int idCompuerta);

	Resultado* simular();

	void rotar(int idCompuerta,DIRECCION direccion);

	void mover(int idCompuerta,Posicion posicion);

	void guardar();

	std::vector<char*>* obtenerCircuitosGuardados();

	void obtenerCircuitosServidor(Servidor servidor, std::vector<char*>* circuitos);

	Circuito* recuperar(const std::string &nombreCircuito);

	void enviar(const std::string &nombreCircuito,Servidor servidor);

	TamanioCajaNegra recibir(const std::string &nombreCircuito,Servidor servidor);

	int getId();

	bool hayCircuito();

	void getConexionVertice(int idCompuerta,std::vector<ConexionVertice>* conexiones);



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
