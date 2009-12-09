
#include "common_Utils.h"

#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include <iostream>
#include <stdexcept>


void Utils::obtenerArchivos(const char* directorio,std::vector<char*>* archivos) {

	DIR *dirh;

	struct dirent *dirp;

	if ((dirh = opendir(directorio)) == NULL) {

		std::string error= "No se pudo abrir el directorio: ";
		error.append(directorio);
		throw std::runtime_error(error);

	}

	char* nombre;

	//Recorro el directorio

	for (dirp = readdir(dirh); dirp != NULL; dirp = readdir(dirh)) {

		//Si el archivo es un archivo comun, lo guardo en el vector archivos
		if (dirp->d_type == DT_REG) {

			nombre= new char[strlen(dirp->d_name) + 1];

			strcpy(nombre,dirp->d_name);

			archivos->push_back(nombre);

		}

	}

	closedir(dirh);

}
