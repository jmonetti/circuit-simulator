
#ifndef COMMON_MODELOCLIENTE_H_
#define COMMON_MODELOCLIENTE_H_

#include <vector>
#include <string>

#include "circuito/common_Circuito.h"
#include "circuito/compuertas/common_CajaNegra.h"
#include "simulacion/common_ResultadoSimulacion.h"
#include "simulacion/common_ResultadoTiempo.h"
#include "publicacion/common_Servidor.h"
#include "persistencia/common_Persistencia.h"
#include "publicacion/common_Publicacion.h"
#include "simulacion/common_Simulador.h"
#include "../common/constantes.h"


class ModeloCliente {

public:

	ModeloCliente();

	virtual ~ModeloCliente();

	void crearNuevo();

	void eliminar(int idCircuito);

	void agregarCompuerta(int idCircuito,TIPO_COMPUERTA tipo, int tiempoTransicion= 0);

	void eliminarCompuerta(int idCircuito,int idCompuerta);

	std::vector<ResultadoSimulacion*>* simular(int idCircuito);

	ResultadoTiempo* calcularTiempoTransicion(int idCircuito);

	void conectar(int idCircuito, int idSalida,int idEntrada);

	void desconectar(int idCircuito, int idSalida, int idEntrada);

	void guardar(int idCircuito, std::string &ruta);

	void recuperar(const std::string &nombreCircuito);

	void enviar(const std::string &nombreCircuito,const Servidor &servidor);

	void recibir(int idCircuito, const std::string &nombreCircuito,const Servidor &servidor);


private:

	std::vector<Circuito*> circuitos;
	Persistencia persistencia;
	Publicacion publicacion;
	Simulador simulador;
	int contadorId;

	Circuito* obtenerCircuito(int idCircuito);



};

#endif /* COMMON_MODELOCLIENTE_H_ */
