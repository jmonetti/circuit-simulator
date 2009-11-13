
#include "client_Cliente.h"

int main (int argc, char** argv)
{
	Cliente cliente;

	try{

		cliente.conectar(argv[1],atoi(argv[2]));

		cliente.iniciarConversacion();

		cliente.terminar();

	}
	catch(std::runtime_error &e){

		//TODO
		std::cout<<e.what()<<"\n";
		//TODO fin

		return 1;
	}

	return 0;

}
