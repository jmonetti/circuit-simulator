#include "vista/common_Decorador_Ventana.h"
#include "vista/common_Decorador_Scroll.h"
#include "vista/common_Decorador_Box_ventana.h"
#include "vista/common_Box_Ventana_Interna.h"
#include "vista/common_Decorador_Menu.h"
#include "vista/common_Fachada_vista.h"
#include "controlador/common_Controlador.h"
#include "gtkmm.h"
#include <iostream>
#include "modelo/common_ModeloCliente.h"



int main(int argc,char* argv[]){

	//inicializo y arranco la libreria
	gtk_init (&argc,&argv);
	Box_Ventana_Interna ventana_interna;
	Decorador_Box_ventana box_Ventana(&ventana_interna);
	Decorador_Scroll scroll(&box_Ventana);
	Decorador_Menu menu(&scroll);
	Decorador_Ventana ventana(&menu);

	gtk_widget_set_usize(ventana.getWidget(),890,650);


	Fachada_vista fachada(&ventana_interna);
	ModeloCliente modeloCliente;
	Controlador* controlador=Controlador::crear_instancia(&fachada,&modeloCliente);
	ventana.show();


	gtk_main ();

	//libero la memoria reservada para el controlador
	delete controlador;

	return 0;
}
