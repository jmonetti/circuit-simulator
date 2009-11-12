/**************************   Clase Decorador_Scroll   ************************/
/**************************   Grupo 8                  ************************/

#include "common_Decorador_Scroll.h"

/*----------------------------------------------------------------------------*/

Decorador_Scroll::Decorador_Scroll(Componente_Visual* componente): Decorador(componente){

		//Creo la ventana scrollable
		_scroll= gtk_scrolled_window_new(NULL,NULL);
		gtk_scrolled_window_set_policy((GtkScrolledWindow*)_scroll,GTK_POLICY_AUTOMATIC,GTK_POLICY_AUTOMATIC);
		gtk_container_border_width (GTK_CONTAINER (_scroll), 20);

		//Incluyo el componente
		gtk_scrolled_window_add_with_viewport((GtkScrolledWindow*)_scroll,componente->getWidget());

}
/*----------------------------------------------------------------------------*/

void Decorador_Scroll::show(){

	//muestro el componente
	show_componente();
	//muestro la ventana
	gtk_widget_show (_scroll);

}
/*----------------------------------------------------------------------------*/

void Decorador_Scroll::escalar(int _fa){


}
/*----------------------------------------------------------------------------*/

GtkWidget* Decorador_Scroll::getWidget(){

	return _scroll;
}
/*----------------------------------------------------------------------------*/

void Decorador_Scroll::set_dimensiones(int weight, int height){
	gtk_widget_set_usize(_scroll,weight,height);
}
/*----------------------------------------------------------------------------*/
