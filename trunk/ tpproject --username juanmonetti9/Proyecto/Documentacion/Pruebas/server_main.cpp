
#include <iostream>
#include "server_Servidor.h"

int main(int argc, char **argv)
{
	Servidor servidor(atoi(argv[1]));

	try{
		servidor.bind();

		servidor.listen(1);

		servidor.iniciarConversacion();

		servidor.terminar();
	}
	catch(std::runtime_error &e){

		return 1;
	}

	return 0;

}

