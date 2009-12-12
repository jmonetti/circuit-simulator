

#include "common_Ventana_Caja_Negra.h"

Ventana_Caja_Negra::Ventana_Caja_Negra() {

	//Creo la ventana
	ventana = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	//seteo el titulo que llevara la ventana
	gtk_window_set_title (GTK_WINDOW (ventana), " Caja Negra ");
	//creo la caja y la incluyo en la ventana
	box_ventana=gtk_vbox_new(false,0);
	gtk_container_add (GTK_CONTAINER (ventana),box_ventana);
	//incluyo el area de disenio en la caja
	gtk_container_add (GTK_CONTAINER (box_ventana),area_disenio.getWidget());
	//Muestro la caja y el area de disenio
	area_disenio.show();
	gtk_widget_show(box_ventana);
	//Conecto con sus controladores
	gtk_signal_connect (GTK_OBJECT (ventana), "delete_event",
							GTK_SIGNAL_FUNC (Controlador_Ventana::delete_event_esconder),this);


}
void Ventana_Caja_Negra::dibujar_pista(gdouble x,gdouble y,SENTIDO sentido){

	switch(sentido){

	case ESTE:{
		area_disenio.draw_pista_este(x,y);
		break;
		}

	case OESTE:{
		area_disenio.draw_pista_oeste(x,y);
		break;
		}

	case NORTE:{
		area_disenio.draw_pista_norte(x,y);
		break;
		}

	case SUR:{
		area_disenio.draw_pista_sur(x,y);
		break;
		}

	}
}

void Ventana_Caja_Negra::dibujar_entrada(gdouble x,gdouble y,SENTIDO sentido){

	switch(sentido){

	case ESTE:{
			area_disenio.draw_entrada_este(x,y);
			break;
		}

	case OESTE:{
			area_disenio.draw_entrada_oeste(x,y);
			break;
		}

	case NORTE:{
			area_disenio.draw_entrada_norte(x,y);
			break;
		}

	case SUR:{
			area_disenio.draw_entrada_sur(x,y);
			break;
		}

	}
}

void Ventana_Caja_Negra::dibujar_salida(gdouble x,gdouble y,SENTIDO sentido){

	switch(sentido){

	case ESTE:{
		area_disenio.draw_salida_este(x,y);
		break;
		}

	case OESTE:{
		area_disenio.draw_salida_oeste(x,y);
		break;
		}

	case NORTE:{
		area_disenio.draw_salida_norte(x,y);
		break;
		}

	case SUR:{
		area_disenio.draw_salida_sur(x,y);
		break;
		}

	}
}

void Ventana_Caja_Negra::dibujar_and(gdouble x,gdouble y,SENTIDO sentido){

	switch(sentido){

	case ESTE:{
		area_disenio.draw_AND_este(x,y);
		break;
		}

	case OESTE:{
		area_disenio.draw_AND_oeste(x,y);
		break;
		}

	case NORTE:{
		area_disenio.draw_AND_norte(x,y);
		break;
		}

	case SUR:{
		area_disenio.draw_AND_sur(x,y);
		break;
		}

	}

}

void Ventana_Caja_Negra::dibujar_or(gdouble x,gdouble y,SENTIDO sentido){

	switch(sentido){

	case ESTE:{
		area_disenio.draw_OR_este(x,y);
		break;
		}

	case OESTE:{
		area_disenio.draw_OR_oeste(x,y);
		break;
		}

	case NORTE:{
		area_disenio.draw_OR_norte(x,y);
		break;
		}

	case SUR:{
		area_disenio.draw_OR_sur(x,y);
		break;
		}

	}

}

void Ventana_Caja_Negra::dibujar_not(gdouble x,gdouble y,SENTIDO sentido){

	switch(sentido){

	case ESTE:{
		area_disenio.draw_NOT_este(x,y);
		break;
		}

	case OESTE:{
		area_disenio.draw_NOT_oeste(x,y);
		break;
		}

	case NORTE:{
		area_disenio.draw_NOT_norte(x,y);
		break;
		}

	case SUR:{
		area_disenio.draw_NOT_sur(x,y);
		break;
		}

	}

}

void Ventana_Caja_Negra::dibujar_xor(gdouble x,gdouble y,SENTIDO sentido){

	switch(sentido){

	case ESTE:{
		area_disenio.draw_XOR_este(x,y);
		break;
		}

	case OESTE:{
		area_disenio.draw_XOR_oeste(x,y);
		break;
		}

	case NORTE:{
		area_disenio.draw_XOR_norte(x,y);
		break;
		}

	case SUR:{
		area_disenio.draw_XOR_sur(x,y);
		break;
		}

	}

}


void Ventana_Caja_Negra::dibujar_compuerta(gdouble x,gdouble y,TIPO_COMPUERTA tipo,SENTIDO sentido){

	switch(tipo){

	case T_AND:{
		dibujar_and(x,y,sentido);
		break;
		}

	case T_OR:{
		dibujar_or(x,y,sentido);
		break;
		}

	case T_NOT :{
		dibujar_not(x,y,sentido);
		break;
		}

	case T_XOR:{
		dibujar_xor(x,y,sentido);
		break;
		}
	default: break;

	}
}


void Ventana_Caja_Negra::agregar_componente(gdouble x,gdouble y,TIPO_COMPUERTA tipo,SENTIDO sentido){

	switch(tipo){

		case T_CAJANEGRA: break;

		case T_PISTA:{

			dibujar_pista(x,y,sentido);
			break;
		}

		case T_ENTRADA:{

			dibujar_entrada(x,y,sentido);
			break;
		}

		case T_SALIDA:{

			dibujar_salida(x,y,sentido);
			break;
		}

		default:{

			dibujar_compuerta(x,y,tipo,sentido);
			break;
		}


	}
}

void Ventana_Caja_Negra::agregar_caja_negra(gdouble x,gdouble y,int cant_entradas,int cant_salidas){

	area_disenio.draw_CAJANEGRA(x,y,cant_entradas,cant_salidas);
}

void Ventana_Caja_Negra::agregar_vertice(gdouble x,gdouble y,SENTIDO sentido){

	area_disenio.draw_vertice(x,y,sentido);
}


void Ventana_Caja_Negra::show() {

	gtk_widget_show(ventana);

}

void Ventana_Caja_Negra::hide() {

	gtk_widget_hide(ventana);



}

GtkWidget* Ventana_Caja_Negra::getWidget() {

	return ventana;

}




Ventana_Caja_Negra::~Ventana_Caja_Negra() {
	// TODO Auto-generated destructor stub
}
