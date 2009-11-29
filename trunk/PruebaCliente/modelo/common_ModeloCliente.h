
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

	void eliminar(int idCircuito);

	void agregarCompuerta(int idCircuito,TIPO_COMPUERTA tipo,Posicion posicion,SENTIDO sentido = ESTE);

	void agregarEntrada(int idCircuito,Posicion posicion,const std::string &nombre, SENTIDO sentido = ESTE);

	void agregarSalida(int idCircuito,Posicion posicion,const std::string &nombre, SENTIDO sentido = ESTE);

	void eliminarCompuerta(int idCircuito,int idCompuerta);

	Resultado* simular(int idCircuito);

	void conectar(int idCircuito, int idSalida,int idEntrada);

	void desconectar(int idCircuito, int idSalida, int idEntrada);

	void guardar(int idCircuito);

	void recuperar(const std::string &nombreCircuito);

	void enviar(const std::string &nombreCircuito,Servidor servidor);

	void recibir(int idCircuito, const std::string &nombreCircuito,Servidor servidor);

	int getUltimo() const; //TODO


private:

	std::vector<Circuito*> circuitos;
	Persistencia persistencia;
	Publicacion publicacion;
	Simulador simulador;
	int contadorId;

	Circuito* obtenerCircuito(int idCircuito);



};

#endif /* COMMON_MODELOCLIENTE_H_ */
