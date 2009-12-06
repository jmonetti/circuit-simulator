
#include "common_Publicacion.h"
#include <iostream>
#include "../../common/common_Utils.h"


void Publicacion::enviar(const std::string &nombreCircuito,Servidor servidor) {

	std::cout<<"enviando circuito: "<<nombreCircuito<<" al servidor : host: "<<servidor.getHost()<<
	" puerto: "<<servidor.getPuerto()<<std::endl;

}

bool* Publicacion::simular(const std::string &nombreCircuito,Servidor servidor,bool* entradas,int cantidad) {

	return NULL;

}

int* Publicacion::calcularTiempoTransicion(const std::string &nombreCircuito,Servidor servidor,int* tiempos,int cantidad) {

	return NULL;

}

int Publicacion::recibir(const std::string &nombreCircuito,Servidor servidor,Circuito* circuito) {

	return 0;

}

std::vector<char*>* Publicacion::obtenerCircuitos(Servidor servidor) {

	std::vector<char*>* circuitos= new std::vector<char*>();

	Utils::obtenerArchivos(PATH_SAVES,circuitos);

	return circuitos;

}
