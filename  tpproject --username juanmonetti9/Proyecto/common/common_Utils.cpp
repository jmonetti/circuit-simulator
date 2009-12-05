
#include "common_Utils.h"

#include <stdio.h>
#include <dirent.h>

#include <iostream>


void Utils::obtenerArchivos(const char* directorio,std::vector<char*>* archivos) {

	DIR *dirh;

	struct dirent *dirp;

	if ((dirh = opendir(directorio)) == NULL) {

		//TODO

	}

	for (dirp = readdir(dirh); dirp != NULL; dirp = readdir(dirh)) {

		if (dirp->d_type == DT_REG) {

			archivos->push_back(dirp->d_name);

		}

	}

	closedir(dirh);

}
