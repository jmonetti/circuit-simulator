
#include "common_Utils.h"

#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include <iostream>


void Utils::obtenerArchivos(const char* directorio,std::vector<char*>* archivos) {

	DIR *dirh;

	struct dirent *dirp;

	if ((dirh = opendir(directorio)) == NULL) {

		//TODO

	}

	char* nombre;

	for (dirp = readdir(dirh); dirp != NULL; dirp = readdir(dirh)) {

		if (dirp->d_type == DT_REG) {

			nombre= new char[strlen(dirp->d_name) + 1];

			strcpy(nombre,dirp->d_name);

			archivos->push_back(nombre);

		}

	}

	closedir(dirh);

}
