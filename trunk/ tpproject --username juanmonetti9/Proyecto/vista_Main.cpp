#include "common_Decorador_Ventana.h"
#include "common_Decorador_Scroll.h"
#include "common_Box_Ventana.h"
#include "common_Decorador_Menu.h"
#include "gtkmm.h"
int main(int argc,char* argv[]){

	//inicializo y arranco la libreria
	gtk_init (&argc,&argv);
	Box_Ventana box;
	Decorador_Scroll scroll(&box);
	scroll.set_dimensiones(800,700);
	Decorador_Menu menu(&scroll);
	Decorador_Ventana ventana(&menu);
	ventana.show();
	gtk_main ();

	return 0;
}
