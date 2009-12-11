
#ifndef COMMON_MODELOSERVIDOR_H_
#define COMMON_MODELOSERVIDOR_H_

#include <string>
#include <vector>
#include "persistencia/common_Persistencia.h"
#include "peticion/common_Peticion.h"

using namespace std;

class ModeloServidor {

public:

	ModeloServidor();

	virtual ~ModeloServidor();

	void cargarCircuitos();

	void guardar(Circuito* circuito);

	void recuperar();

	std::string generarRespuesta(std::string &ruta_pedido);

	bool* simular(int idCircuito, bool* entradas);

	int* calcularTiempoTransicion(int idCircuito,const std::string &nombreCircuito,int* entradas);

	int getId();

	int getIdCircuito(std::string &nombreCircuito);

	void obtenerDatosCircuito(std::string &nombre,int &cantEntradas,int &cantSalidas);

	std::string generarListaCircuitos();

	void recuperarDatosSimular(DOMNodeList* atributos, std::string &nombre, bool* entradas);

	void recuperarDatosTiempos(DOMNodeList* atributos, std::string &nombre, int* entradas);

private:

	std::vector<Circuito*> circuitos;

	Persistencia persistencia;
	int contadorId;

	static std::string generarRespuesta (int cantSalidas, bool* salidas);

	static std::string generarRespuesta (int cantSalidas, int* salidas);

	std::string generarRespuesta(int cantEntradas, int cantSalidas);

	std::string generarListaCircuitos(std::vector<Circuito*> circuitos);

	void enviarRespuesta(const std::string &ruta);

};

#endif /* COMMON_MODELOSERVIDOR_H_ */
