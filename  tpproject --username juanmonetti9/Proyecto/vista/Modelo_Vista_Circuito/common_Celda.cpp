/**************************   Clase Celda      ***********************/
/**************************   	Grupo 8        ***********************/

#include "common_Celda.h"
#include "common_Modelo_vista_circuito.h"
#include <stdlib.h>

typedef std::list<Celda*>::const_iterator LI;//iterador de la lista

Celda::Celda(Modelo_vista_circuito* _grilla,unsigned int _fila,unsigned int _col){

	grilla=_grilla;
	fila= _fila;
	colum=_col;
	estado=VACIA;
}

void Celda::eliminar_componente(){

	if(esta_ocupada()){

		Celda* padre= grilla->get_celda(fila_padre,colum_padre);
		padre->desocupar_celda();

	}

}


bool Celda::agregar_compuerta_XOR(){

	bool agregada=true;

	if(!esta_ocupada()){

		agregada=agregar_entorno_compuerta(XOR);

		if(agregada){
			set_info_padre(fila,colum);
			ocupar_celda(XOR);
		}

	}
	else
		agregada=false;

	return agregada;
}

bool Celda::agregar_entorno_compuerta(EstadoCelda _estado){

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
						aux->ocupar_celda(_estado);
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

void Celda::ocupar_celda(EstadoCelda _estado){

	estado= _estado;
}

int Celda::get_fila()const{

	return fila;
}

int Celda::get_fila_padre()const{

	return fila_padre;

}

int Celda::get_colum_padre()const{

	return colum_padre;

}

int Celda::get_colum()const{

	return colum;
}

void Celda::vaciar_entorno(){

	bool vacia = entorno.empty();

	if(!vacia){
		Celda* aux;
		do{
			aux = entorno.back();
			entorno.pop_back();
			vacia=entorno.empty();
		}while(!vacia);
	}
}

void Celda::desocupar_celda(){

	if(!this->entorno.empty()){

		LI it = entorno.begin();
		while( it!= entorno.end()){
			((Celda*)*it)->desocupar_celda();
			++it; //incremento el iterador
		}
		vaciar_entorno();

	}
	g_print("Desocupo celda (%d,%d)\n",this->fila,this->colum);
	estado=VACIA;
	fila_padre=0;
	colum_padre=0;
}

void Celda::set_info_padre(int fila, int columna){

	if(fila>=1 && columna>=1){
		colum_padre=columna;
		fila_padre=fila;
	}
}

bool Celda::esta_ocupada(){

	if(estado==VACIA){
		return false;
	}
	else
		return true;
}

Celda::~Celda() {

}
