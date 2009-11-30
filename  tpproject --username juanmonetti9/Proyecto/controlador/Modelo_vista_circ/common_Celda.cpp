/**************************   Clase Celda      ***********************/
/**************************   	Grupo 8        ***********************/

#include "common_Celda.h"
#include "common_Modelo_vista_circuito.h"
#include <stdlib.h>
/*----------------------------------------------------------------------------*/
typedef std::list<Celda*>::const_iterator LI;//iterador de la lista
/*----------------------------------------------------------------------------*/

Celda::Celda(Modelo_vista_circuito* _grilla,unsigned int _fila,unsigned int _col){

	estado= T_VACIA;
	sentido= ESTE;
	grilla= _grilla;
	fila=  _fila;
	colum= _col;
}
/*----------------------------------------------------------------------------*/

void Celda::eliminar_componente(){

	if(esta_ocupada()){

		Celda* padre= grilla->get_celda(fila_padre,colum_padre);
		padre->desocupar_celda();

	}

}
/*----------------------------------------------------------------------------*/

bool Celda::agregar_pista(){
	return true;//todo

}
/*----------------------------------------------------------------------------*/

bool Celda::agregar_entrada(){

	bool agregada=true;

		if(!esta_ocupada()){

			agregada=agregar_entorno_entrada_salida(T_ENTRADA,ESTE);

			if(agregada){
				set_info_padre(fila,colum);
				set_sentido(ESTE);
				ocupar_celda(T_ENTRADA);
			}

		}
		else
			agregada=false;

		return agregada;
}
/*----------------------------------------------------------------------------*/

bool Celda::agregar_salida(){
	bool agregada=true;

			if(!esta_ocupada()){

				agregada=agregar_entorno_entrada_salida(T_SALIDA,OESTE);

				if(agregada){
					set_info_padre(fila,colum);
					set_sentido(OESTE);
					ocupar_celda(T_SALIDA);
				}

			}
			else
				agregada=false;

			return agregada;
}
/*----------------------------------------------------------------------------*/

bool Celda::agregar_compuerta(TIPO_COMPUERTA tipo){

	bool agregada=true;

	if(!esta_ocupada()){

		agregada=agregar_entorno_compuerta(tipo);

		if(agregada){
			set_info_padre(fila,colum);
			set_sentido(ESTE);
			ocupar_celda(tipo);
		}

	}
	else
		agregada=false;

	return agregada;
}

/*----------------------------------------------------------------------------*/

bool Celda::agregar_entorno_entrada_salida(TIPO_COMPUERTA _tipo,SENTIDO sentido){

	bool retorno=true;

	if(_tipo == T_ENTRADA || _tipo == T_SALIDA){

		int fila_entorno;
		int col_entorno;

		switch(sentido){

			case ESTE:{	fila_entorno=fila;
						col_entorno=colum+1;
						break;}
			case OESTE:{fila_entorno=fila;
						col_entorno=colum-11;
						break;}
			case NORTE:{fila_entorno=fila-1;
						col_entorno=colum;
						break;}
			case SUR:  {fila_entorno=fila+11;
						col_entorno=colum;
					    break;}
		}

		 Celda* aux=grilla->get_celda(fila_entorno,col_entorno);
		 if(!aux->esta_ocupada() ){
			 aux->set_info_padre(fila,colum);
			 aux->ocupar_celda(_tipo);
			 entorno.push_front(aux);
		 }
		 else
			 retorno=false;
	}
	else
		retorno=false;

	return retorno;
}
/*----------------------------------------------------------------------------*/

bool Celda::agregar_entorno_pista(SENTIDO sentido){
	return true;//todo
}
/*----------------------------------------------------------------------------*/

bool Celda::agregar_entorno_compuerta(TIPO_COMPUERTA _tipo){

	bool retorno= true;
	int f=fila;
	int c=colum;

	for (int i = f-1; i < f+2; ++i) {
		for (int j = c-1; j < c +2; ++j) {

			if(!(i==f && j==c)){
				Celda* aux=grilla->get_celda(i,j);

				if(retorno && aux){
					if(!aux->esta_ocupada() ){
						aux->set_info_padre(f,c);
						aux->ocupar_celda(_tipo);
						entorno.push_front(aux);
					}
					else
						retorno=false;
				}
				else
					retorno =false;
			}
		}
	}

	if(!retorno)
		vaciar_entorno();


	return retorno;

}
/*----------------------------------------------------------------------------*/

void Celda::set_sentido(SENTIDO _sentido){

	sentido= _sentido;
}

/*----------------------------------------------------------------------------*/

void Celda::rotar_lef(){

	Celda* celda=grilla->get_celda(fila_padre,colum_padre);

	if(esta_ocupada() && celda){

		switch(celda->get_sentido()){

		case NORTE: celda->set_sentido(OESTE);
					break;
		case OESTE: celda->set_sentido(SUR);
					break;
		case SUR: celda->set_sentido(ESTE);
					break;
		case ESTE: celda->set_sentido(NORTE);
					break;

		}
	}
}
/*----------------------------------------------------------------------------*/

void Celda::rotar_right(){

	Celda* celda=grilla->get_celda(fila_padre,colum_padre);

	if(esta_ocupada() && celda){

		switch(celda->get_sentido()){

		case NORTE: celda->set_sentido(ESTE);
					break;
		case ESTE: celda->set_sentido(SUR);
					break;
		case SUR: celda->set_sentido(OESTE);
					break;
		case OESTE: celda->set_sentido(NORTE);
					break;

		}
	}

}

/*----------------------------------------------------------------------------*/

void Celda::ocupar_celda(TIPO_COMPUERTA _tipo){

	estado= _tipo;
}
/*----------------------------------------------------------------------------*/

int Celda::get_fila()const{

	return fila;
}
/*----------------------------------------------------------------------------*/

int Celda::get_fila_padre()const{

	return fila_padre;

}
/*----------------------------------------------------------------------------*/

int Celda::get_colum_padre()const{

	return colum_padre;

}
/*----------------------------------------------------------------------------*/

int Celda::get_colum()const{

	return colum;
}
/*----------------------------------------------------------------------------*/

int Celda::get_id()const{

	return ID;
}
/*----------------------------------------------------------------------------*/

SENTIDO Celda::get_sentido()const{

	return sentido;
}
/*----------------------------------------------------------------------------*/

void Celda::vaciar_entorno(){

	bool vacia = entorno.empty();

	if(!vacia){
		Celda* aux;
		do{
			aux = entorno.back();
			aux->set_info_padre(0,0);
			aux->desocupar_celda();
			entorno.pop_back();
			vacia=entorno.empty();
		}while(!vacia);
	}
}
/*----------------------------------------------------------------------------*/

void Celda::desocupar_celda(){

	if(!this->entorno.empty()){

		LI it = entorno.begin();
		while( it!= entorno.end()){
			((Celda*)*it)->desocupar_celda();
			++it; //incremento el iterador
		}
		vaciar_entorno();

	}
	estado= T_VACIA;
	ID=0;
	sentido= ESTE;
	fila_padre= 0;
	colum_padre= 0;
}
/*----------------------------------------------------------------------------*/

void Celda::set_info_padre(int fila, int columna){

	if(fila>=0 && columna>=0){
		colum_padre=columna;
		fila_padre=fila;
	}
}
/*----------------------------------------------------------------------------*/

TIPO_COMPUERTA Celda::get_tipo_celda()const{

	return estado;
}
/*----------------------------------------------------------------------------*/

bool Celda::esta_ocupada()const{

	if(estado == T_VACIA){
		return false;
	}
	else
		return true;
}
/*----------------------------------------------------------------------------*/

Celda::~Celda() {

}
/*----------------------------------------------------------------------------*/
