#include "vista/common_Decorador_Ventana.h"
#include "vista/common_Decorador_Scroll.h"
#include "vista/common_Box_Ventana.h"
#include "vista/common_Decorador_Menu.h"
#include "gtkmm.h"
int main(int argc,char* argv[]){

	//inicializo y arranco la libreria
	gtk_init (&argc,&argv);
	Box_Ventana box;
	Decorador_Scroll scroll(&box);
	Decorador_Menu menu(&scroll);
	Decorador_Ventana ventana(&menu);
	//TODO gronchada para darle el tamanio a la ventana
	gtk_widget_set_usize(ventana.getWidget(),800,600);
	//fin TODO

	ventana.show();
	gtk_main ();

	return 0;
}
