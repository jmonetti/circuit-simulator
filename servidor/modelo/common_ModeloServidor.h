
#ifndef COMMON_MODELOSERVIDOR_H_
#define COMMON_MODELOSERVIDOR_H_

#include <string>
#include <vector>
#include "persistencia/common_Persistencia.h"
#include "peticion/common_Peticion.h"
#include "../thread/common_Lock.h"
#include "../thread/common_Mutex.h"
#include "common_ManagerArchivos.h"

using namespace std;

class ModeloServidor {

public:

	ModeloServidor();

	virtual ~ModeloServidor();

	std::string generarRespuesta(std::string &ruta_pedido);

	bool* simular(Circuito* circuito, bool* entradas);

	int* calcularTiempoTransicion(Circuito* circuito,int* entradas);

	void obtenerDatosCircuito(std::string &nombre,int &cantEntradas,int &cantSalidas);

	void recuperarDatosSimular(DOMNodeList* atributos, std::string &nombre, bool* entradas);

	void recuperarDatosTiempos(DOMNodeList* atributos, std::string &nombre, int* entradas);

private:

	Mutex mutex;

	Persistencia persistencia;

	std::string generarRespuesta (int cantSalidas, bool* salidas);

	std::string generarRespuesta (int cantSalidas, int* salidas);

	std::string generarRespuesta(int cantEntradas, int cantSalidas);

	std::string generarListaCircuitos(std::vector<char*> circuitos);

	void enviarRespuesta(const std::string &ruta);

};

#endif /* COMMON_MODELOSERVIDOR_H_ */
