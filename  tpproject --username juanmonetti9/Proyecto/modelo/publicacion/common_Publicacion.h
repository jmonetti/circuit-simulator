
#ifndef COMMON_PUBLICACION_H_
#define COMMON_PUBLICACION_H_

#include "common_Servidor.h"
#include <vector>
#include "../circuito/common_Circuito.h"
#include "../simulacion/common_ResultadoSimulacion.h"
#include "../../common/common_TamanioCajaNegra.h"
#include "common_Mensajes.h"
#include "../../socket/common_Protocolo.h"

class Publicacion {

public:

	void enviar(const std::string &nombreCircuito,Servidor servidor);

	bool* simular(const std::string &nombreCircuito,Servidor servidor,bool* entradas,int cantidad);

	int* calcularTiempoTransicion(const std::string &nombreCircuito,Servidor servidor, int* tiempos,int cantidad);

	TamanioCajaNegra recibir(const std::string &nombreCircuito,Servidor servidor);

	void obtenerCircuitos(Servidor servidor, std::vector<char*>* circuitos);


private:

	Protocolo protocolo;

	void conectar(Servidor servidor);
	void enviarPedido(const std::string &ruta);
	std::string recibirRespuesta();

	/* Genera pedido de simulacion */
	std::string generarPedido (const std::string &nombreCircuito,int cantEntradas, bool* entradas);

	/* Genera pedido de simulacion de tiempos*/
	std::string generarPedido (const std::string &nombreCircuito,int cantEntradas,int* entradas);

	std::string publicarCircuito(Circuito* circuito);

	/* Genera Pedido para la Lista de Circuitos*/
	std::string generarPedido();

	/* Genera Pedido para obtener una Caja Negra*/
	std::string generarPedido(const std::string &nombreCircuito);

	bool* recuperarDatosSimular(const std::string &ruta);

	int* recuperarDatosTiempos(const std::string &ruta);

	TamanioCajaNegra recuperarDatosCajaNegra(const std::string &ruta);

	void recuperarDatosCircuitos(const std::string &ruta,std::vector<char*>* circuitos);


};

#endif /* COMMON_PUBLICACION_H_ */
