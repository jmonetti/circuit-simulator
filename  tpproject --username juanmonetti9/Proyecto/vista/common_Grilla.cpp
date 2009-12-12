/**************************   Clase GRILLA   *************************/
/**************************   	Grupo 8      *************************/

#include "common_Grilla.h"



Grilla::Grilla(int id) : scrollDisenio(&areaDisenio),scrollTabla(&tablaLogica){

	//Creo la caja que contendra la notebook
	box_notebook= gtk_hbox_new(false,0);
	//Creo el notebook y la incluyo en la caja
	notebook= gtk_notebook_new();
	gtk_box_pack_start (GTK_BOX (box_notebook),notebook, true,true,false);
	gtk_notebook_set_scrollable (GTK_NOTEBOOK(notebook),true);
	//Creo las pestanias
	tab_pestania_uno= gtk_label_new ("Area de diseño");
	tab_pestania_dos= gtk_label_new ("Tabla logica");

	//incluyo las las pestanias a la notebook
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook),scrollDisenio.getWidget(),tab_pestania_uno);
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook), scrollTabla.getWidget(),tab_pestania_dos);
	scrollDisenio.show();
	scrollTabla.show();

	areaDisenio.conectarClick();

	this->id= id;
}

void Grilla::show() {

	gtk_widget_show(box_notebook);
	gtk_widget_show(notebook);
	gtk_widget_show(tab_pestania_uno);
	gtk_widget_show(tab_pestania_dos);




}


GtkWidget* Grilla::getWidget() {

	return box_notebook;
}

int Grilla::getId() const{

	return id;

}

/*----------------------------------------------------------------------------*/

void Grilla::completar_tabla(Resultado* resultado){

	tablaLogica.completar(resultado);
}
/*----------------------------------------------------------------------------*/

void Grilla::limpiar_area(){

	areaDisenio.borrar();

}

void Grilla::draw_NOT(gdouble x,gdouble y, SENTIDO sentido){

	switch(sentido){

	case ESTE: {
				areaDisenio.draw_NOT_este(x,y);
				break;
	}

	case OESTE: {
				areaDisenio.draw_NOT_oeste(x,y);
				break;
	}
	case NORTE:{
				areaDisenio.draw_NOT_norte(x,y);
				break;
	}
	case SUR: {
			  areaDisenio.draw_NOT_sur(x,y);
			  break;
	}

	}

}

/*----------------------------------------------------------------------------*/
void Grilla::draw_AND(gdouble x,gdouble y, SENTIDO sentido){

	switch(sentido){

		case ESTE: areaDisenio.draw_AND_este(x,y);
				   break;
		case OESTE:areaDisenio.draw_AND_oeste(x,y);
				   break;
		case NORTE:areaDisenio.draw_AND_norte(x,y);
				   break;
		case SUR:areaDisenio.draw_AND_sur(x,y);
				   break;

		}

}

/*----------------------------------------------------------------------------*/
void Grilla::draw_OR(gdouble x,gdouble y, SENTIDO sentido){

	switch(sentido){

		case ESTE: areaDisenio.draw_OR_este(x,y);
				   break;
		case OESTE:areaDisenio.draw_OR_oeste(x,y);
				   break;
		case NORTE:areaDisenio.draw_OR_norte(x,y);
				   break;
		case SUR:areaDisenio.draw_OR_sur(x,y);
				   break;

		}
}

/*----------------------------------------------------------------------------*/
void Grilla::draw_XOR(gdouble x,gdouble y, SENTIDO sentido){

	switch(sentido){

		case ESTE: areaDisenio.draw_XOR_este(x,y);
				   break;
		case OESTE:areaDisenio.draw_XOR_oeste(x,y);
				   break;
		case NORTE:areaDisenio.draw_XOR_norte(x,y);
				   break;
		case SUR:areaDisenio.draw_XOR_sur(x,y);
				   break;

		}
}



void Grilla::draw_entrada(gdouble x,gdouble y, SENTIDO sentido){

	switch(sentido){

		case ESTE: areaDisenio.draw_entrada_este(x,y);
				   break;
		case OESTE:areaDisenio.draw_entrada_oeste(x,y);
				   break;
		case NORTE:areaDisenio.draw_entrada_norte(x,y);
				   break;
		case SUR:areaDisenio.draw_entrada_sur(x,y);
				   break;

		}
}

void Grilla::draw_salida(gdouble x,gdouble y, SENTIDO sentido){

	switch(sentido){

		case ESTE: areaDisenio.draw_salida_este(x,y);
				   break;
		case OESTE:areaDisenio.draw_salida_oeste(x,y);
				   break;
		case NORTE:areaDisenio.draw_salida_norte(x,y);
				   break;
		case SUR:  areaDisenio.draw_salida_sur(x,y);
				   break;

		}
}
void Grilla::draw_pista(gdouble x,gdouble y, SENTIDO sentido,int cant_celdas){

	switch(sentido){

		case ESTE: areaDisenio.draw_pista_este(x,y);
				   break;
		case OESTE:areaDisenio.draw_pista_oeste(x,y);
				   break;
		case NORTE:areaDisenio.draw_pista_norte(x,y);
				   break;
		case SUR:  areaDisenio.draw_pista_sur(x,y);
				   break;

		}
}

void Grilla::draw_CAJANEGRA(gdouble x,gdouble y,int cant_entradas,int cant_salidas){

	areaDisenio.draw_CAJANEGRA(x,y,cant_entradas,cant_salidas);
}

void Grilla::draw_vertice(gdouble x,gdouble y,SENTIDO sentido){

	areaDisenio.draw_vertice(x,y,sentido);
}



void escalar(int fa){

}
