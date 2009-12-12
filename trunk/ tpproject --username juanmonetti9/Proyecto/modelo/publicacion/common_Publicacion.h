
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

	/*
	 * Envia un circuito a un servidor
	 * nombreCircuito= nombre del circuito
	 * servidor= servidor a donde se va a enviar el circuito
	 */
	void enviar(const std::string &nombreCircuito,Servidor servidor);

	/*
	 * Simula un circuito de un servidor
	 * nombreCircuito= nombre del circuito
	 * servidor= servidor que tiene el circuito
	 * entradas= los valores de entrada
	 * cantidad= cantidad de entradas
	 * Retorna los valores de salida
	 */
	void simular(const std::string &nombreCircuito,Servidor servidor,bool* entradas,int cantidad,bool* salidas);

	/*
	 * Calcula el tiempo de transicion de un circuito de un servidor
	 * nombreCircuito= nombre del circuito
	 * servidor= servidor que tiene el circuito
	 * tiempos= tiempos de entradas
	 * cantidad= cantidad de tiempos
	 * Retorna los tiempos de las salidas
	 */
	void calcularTiempoTransicion(const std::string &nombreCircuito,Servidor servidor, int* tiempos,int cantidad,int* salidas);

	/*
	 * Recibe un circuito de un servidor
	 * nombreCircuito= nombre del circuito
	 * servidor= servidor que tiene al circuito
	 * Retorna el tamanio del circuito
	 */
	TamanioCajaNegra recibir(const std::string &nombreCircuito,Servidor servidor);

	/*
	 * Obtiene la lista de circuitos que tiene un servidor
	 * servidor= servidor que tiene los circuitos
	 * circuitos= vector donde se cargan los nombres de los circuitos
	 */
	void obtenerCircuitos(Servidor servidor, std::vector<char*>* circuitos);

	/*
	 * Obtiene el diseño de la caja negra.
	 * nombreCajaNegra = nombre del circuito caja negra.
	 * servidor = servidor que tiene al circuito.
	 */
	Circuito* verCajaNegra(const std::string &nombreCajaNegra,Servidor servidor);


private:

	Protocolo protocolo;

	void conectar(Servidor servidor);
	void enviarPedido(const std::string &ruta);
	std::string recibirRespuesta();

	/* Genera pedido de simulacion */
	std::string generarPedidoSimulacion (const std::string &nombreCircuito,int cantEntradas, bool* entradas);

	/* Genera pedido de simulacion de tiempos*/
	std::string generarPedidoTiempoSimulacion (const std::string &nombreCircuito,int cantEntradas,int* entradas);

	std::string publicarCircuito(Circuito* circuito);

	/* Genera Pedido para la Lista de Circuitos*/
	std::string generarPedidoListaCircuitos();

	/* Genera Pedido para obtener una Caja Negra*/
	std::string generarPedidoCircuito(const std::string &nombreCircuito);

	/* Genera Pedido para obtener el diseño de una Caja Negra*/
	std::string generarPedidoDisenio(const std::string &nombreCircuito);

	void recuperarDatosSimular(const std::string &ruta,bool* salidas);

	void recuperarDatosTiempos(const std::string &ruta,int* salidas);

	TamanioCajaNegra recuperarDatosCajaNegra(const std::string &ruta);

	void recuperarDatosCircuitos(const std::string &ruta,std::vector<char*>* circuitos);

	Circuito* recuperarDisenioCajaNegra(const std::string &ruta);


};

#endif /* COMMON_PUBLICACION_H_ */
