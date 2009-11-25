#include "vista/common_Decorador_Ventana.h"
#include "vista/common_Decorador_Scroll.h"
#include "vista/common_Decorador_Box_ventana.h"
#include "vista/common_Box_Ventana_Interna.h"
#include "vista/common_Decorador_Menu.h"
#include "gtkmm.h"
int main(int argc,char* argv[]){

	//inicializo y arranco la libreria
	gtk_init (&argc,&argv);
	Box_Ventana_Interna ventana_interna;
	Decorador_Box_ventana box_Ventana(&ventana_interna);
	Decorador_Scroll scroll(&box_Ventana);
	Decorador_Menu menu(&scroll);
	Decorador_Ventana ventana(&menu);
	//TODO gronchada para darle el tamanio a la ventana
	gtk_widget_set_usize(ventana.getWidget(),890,600);
	//fin TODO

	ventana.show();
	gtk_main ();

	return 0;
}