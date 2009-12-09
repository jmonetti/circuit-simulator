
#ifndef COMMON_UTILS_H_
#define COMMON_UTILS_H_

#include <vector>

/*
 * Clase de utilidades.
 */

class Utils {

public:

	/*
	 * Guarda, en archivos, la lista de archivos que hay en directorio.
	 * Los nombres de archivos se guardan en memoria dinamica.
	 */
	static void obtenerArchivos(const char* directorio,std::vector<char*>* archivos);

};

#endif /* COMMON_UTILS_H_ */
