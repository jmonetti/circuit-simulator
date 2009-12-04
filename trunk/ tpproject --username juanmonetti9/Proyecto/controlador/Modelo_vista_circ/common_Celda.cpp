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

	estado_sec = T_VACIA;
	sentido_sec = ESTE;
	fila_padre_sec = 0;
	colum_padre_sec = 0;
}
/*----------------------------------------------------------------------------*/

bool Celda::agregar_entorno_entrada_salida(TIPO_COMPUERTA _tipo,SENTIDO _sentido,int _id){

	bool retorno=true;

	int fila_entorno;
	int col_entorno;
	this->get_pos_entorno_ES(&fila_entorno,&col_entorno,_sentido,_tipo);

	if( _tipo== T_SALIDA || _tipo== T_ENTRADA){

		Celda* aux=grilla->get_celda(fila_entorno,col_entorno);

		if(!aux->esta_ocupada() ){
 			 aux->ocupar_celda(_tipo,fila,colum,_id);
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

bool Celda::agregar_entorno_pista(SENTIDO _sentido,int _id){

	bool retorno=true;
	Celda* aux_1;
	Celda* aux_2;

	if( _sentido == ESTE || _sentido == OESTE ){

		aux_1 = grilla->get_celda(fila,colum-1);
		aux_2 = grilla->get_celda(fila,colum+1);

	}else{

		aux_1 = grilla->get_celda(fila+1,colum);
		aux_2 = grilla->get_celda(fila-1,colum);

	}

	//Si es que la celda que sera parte del entorno estan vacias o aceptan
	//una pista secundaria
	if (!aux_1->esta_ocupada() && !aux_2->esta_ocupada() ){

		 aux_1->ocupar_celda_pista(_sentido,T_PISTA,fila,colum,_id);
		 aux_2->ocupar_celda_pista(_sentido,T_PISTA,fila,colum,_id);

		 entorno.push_front(aux_1);
		 entorno.push_front(aux_2);
	 }
	 else if(!aux_1->esta_ocupada() && aux_2->acepta_pista_secundaria(_sentido) && aux_2->es_padre()){

		 aux_1->ocupar_celda_pista(_sentido,T_PISTA,fila,colum,_id);
		 aux_2->ocupar_celda_secundaria(T_PISTA,_sentido,fila,colum,_id);
	 }
	 else if(!aux_2->esta_ocupada() && aux_1->acepta_pista_secundaria(_sentido) && aux_1->es_padre()){

		 aux_1->ocupar_celda_secundaria(T_PISTA,_sentido,fila,colum,_id);
		 aux_2->ocupar_celda_pista(_sentido,T_PISTA,fila,colum,_id);
	 }
	 else if(!aux_2->acepta_pista_secundaria(_sentido) && aux_1->acepta_pista_secundaria(_sentido)
			 && aux_1->es_padre()  && aux_2->es_padre()){

		 aux_1->ocupar_celda_secundaria(T_PISTA,_sentido,fila,colum,_id);
		 aux_2->ocupar_celda_secundaria(T_PISTA,_sentido,fila,colum,_id);
	 }
	 else
		 retorno=false;

	return retorno;


}
/*----------------------------------------------------------------------------*/

bool Celda::agregar_entorno_caja_negra(SENTIDO _sentido,int _id){

	return true;//todo
}
/*----------------------------------------------------------------------------*/

bool Celda::agregar_pista(int id,SENTIDO _sentido){

	bool agregada;
	if(_sentido==ESTE)
				g_print("ES ESTE, PQ COÑO NO ACEPTA\n");//TODO
	if(sentido==NORTE)
				g_print("--->NORTE\n");//TODO
	if(sentido==SUR)
					g_print("--->SUR\n");//TODO
	if(sentido==ESTE)
					g_print("--->ESTE\n");//TODO
	if(sentido==OESTE)
					g_print("--->OESTE\n");//TODO
	if(!esta_ocupada()){
		g_print("NO ESTA AGREGADA-> ;-) intento agregar entorno\n");//TODO
		agregada=agregar_entorno_pista(_sentido,id);
		if(agregada){
			ocupar_celda_padre(T_PISTA,_sentido,id,fila,colum);
			g_print("casi AGREGADA\n");//TODO
		}

	}
	else if(acepta_pista_secundaria(_sentido) ){
		g_print("ACEPTA PISTA SECUNDARIA\n");//TODO
		if(_sentido==ESTE)
			g_print("ES ESTE, PQ COÑO NO ACEPTA\n");//TODO
		if(sentido==NORTE)
			g_print("--->NORTE\n");//TODO
		agregada=agregar_entorno_pista(_sentido,id);
		if(agregada)
			ocupar_celda_secundaria(T_PISTA,_sentido,fila,colum,id);
	}
	else
		agregada = false;

	return agregada;
}
/*----------------------------------------------------------------------------*/

bool Celda::agregar_caja_negra(int id,SENTIDO _sentido){

	bool agregada;

	if(!esta_ocupada()){

		agregada=agregar_entorno_caja_negra(_sentido,id);
		if(agregada)
			ocupar_celda_padre(T_CAJANEGRA,_sentido,id,fila,colum);
	}
	else
		agregada=false;

	return agregada;

}
/*----------------------------------------------------------------------------*/

bool Celda::agregar_entorno_compuerta(TIPO_COMPUERTA _tipo,int _id){

	bool retorno= true;
	int f=fila;
	int c=colum;

	for (int i = f-1; i < f+2; ++i) {
		for (int j = c-1; j < c +2; ++j) {

			if(!(i==f && j==c)){
				Celda* aux=grilla->get_celda(i,j);

				if(retorno && aux){
					if(!aux->esta_ocupada() ){
						aux->ocupar_celda(_tipo,fila,colum,_id);
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
void Celda::get_pos_entorno_ES(int* fila_entorno,int* col_entorno,SENTIDO _sentido,TIPO_COMPUERTA tipo){

	if( tipo == T_SALIDA){

		switch(_sentido){

			case ESTE:{	*fila_entorno=fila;
						*col_entorno=colum-1;
						break;}
			case OESTE:{*fila_entorno=fila;
						*col_entorno=colum+1;
						break;}
			case NORTE:{*fila_entorno=fila+1;
						*col_entorno=colum;
						break;}
			case SUR:  {*fila_entorno=fila-1;
						*col_entorno=colum;
						break;}
		}

	}else if( tipo == T_ENTRADA ){

		g_print("ENTRO4\n");
		switch(_sentido){

			case ESTE:{	*fila_entorno=fila;
						*col_entorno=colum+1;
						break;}
			case OESTE:{*fila_entorno=fila;
						*col_entorno=colum-1;
						break;}
			case NORTE:{*fila_entorno=fila-1;
						*col_entorno=colum;
						break;}
			case SUR:  {*fila_entorno=fila+1;
						*col_entorno=colum;
					    break;}
		}
	}
}
/*----------------------------------------------------------------------------*/

void Celda::eliminar_componente(){

	if(esta_ocupada()){

		Celda* padre= grilla->get_celda(fila_padre,colum_padre);
		padre->desocupar_celda();

	}

}

/*----------------------------------------------------------------------------*/

bool Celda::agregar_entrada(int id,SENTIDO _sentido){

	bool agregada=true;

		if(!esta_ocupada()){

			agregada=agregar_entorno_entrada_salida(T_ENTRADA,ESTE,id);

			if(agregada)
				ocupar_celda_padre(T_ENTRADA,_sentido,id,fila,colum);

		}else
			agregada=false;

		return agregada;
}
/*----------------------------------------------------------------------------*/

bool Celda::agregar_salida(int id,SENTIDO _sentido){
	bool agregada=true;

	if(!esta_ocupada()){

		agregada=agregar_entorno_entrada_salida(T_SALIDA,ESTE,id);

		if(agregada)
			ocupar_celda_padre(T_SALIDA,_sentido,id,fila,colum);

	}else
		agregada=false;

	return agregada;
}
/*----------------------------------------------------------------------------*/

bool Celda::agregar_compuerta(TIPO_COMPUERTA tipo,int id,SENTIDO _sentido){

	bool agregada=true;

	if(!esta_ocupada()){

		agregada=agregar_entorno_compuerta(tipo,id);

		if(agregada)
			ocupar_celda_padre(tipo,_sentido,id,fila,colum);
	}
	else
		agregada=false;

	return agregada;
}

/*----------------------------------------------------------------------------*/

void Celda::set_sentido(SENTIDO _sentido){

	sentido= _sentido;
}

/*----------------------------------------------------------------------------*/

void Celda::rotar_izq(){

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

void Celda::rotar_derecha(){

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

void Celda::ocupar_celda_padre(TIPO_COMPUERTA _tipo,SENTIDO _sentido,int id,int filaPadre, int colPadre){

	estado= _tipo;
	set_info_padre(fila,colum);
	set_sentido(_sentido);
	ID= id;
}

void Celda::ocupar_celda(TIPO_COMPUERTA _tipo,int filaPadre, int colPadre,int _id){

	ID= _id;
	estado = _tipo;
	set_info_padre(filaPadre,colPadre);

}
void Celda::ocupar_celda_pista(SENTIDO _sentido,TIPO_COMPUERTA _tipo,int filaPadre, int colPadre,int _id){

	ID= _id;
	estado = _tipo;
	set_info_padre(filaPadre,colPadre);
	sentido= _sentido;
}
void Celda::ocupar_celda_secundaria(TIPO_COMPUERTA _tipo,SENTIDO _sentido,int filaPadre, int colPadre,int _id){

	if(_tipo == T_PISTA){

		ID_sec = _id;
		estado_sec = _tipo;
		colum_padre_sec = colPadre;
		fila_padre_sec = filaPadre;
		sentido_sec = _sentido;
	}

}

bool Celda::get_celda_sec(int* fila_padr_sec,int* col_padr_sec,int* _id){

	*fila_padr_sec = fila_padre_sec;
	*col_padr_sec = colum_padre_sec;
	*_id = ID_sec ;
	if(hay_pista_secundaria()){

		return true;
	}
	else
		return false;
}
/*----------------------------------------------------------------------------*/

SENTIDO Celda::get_sentido_multiple(unsigned int _id){

	if( ID == _id)
		return sentido;
	else
		return sentido_sec;


}

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
	set_sentido(ESTE);
	set_info_padre(0,0);
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


bool Celda::hay_pista_secundaria()const{

	if(estado_sec == T_VACIA){

		return false;
	}
	else
		return true;
}

bool Celda::acepta_pista_secundaria(SENTIDO _sentido)const{

	bool acepta=false ;


	if(sentido==NORTE)
		g_print("SUR\n");//TODO
	if((sentido==NORTE || sentido==SUR) && (_sentido==OESTE || _sentido== ESTE)){
		g_print("TRUE\n");//TODO
		acepta=true;
	}
	else if((sentido==ESTE || sentido==OESTE) && (_sentido==NORTE || _sentido== SUR)){
		g_print("TRUE\n");//TODO
		acepta=true;
	}


	return acepta;
}

bool Celda::es_padre(){

	if(fila == fila_padre && colum == colum_padre){
		return true;
	}
	else{
		return false;
	}
}
/*----------------------------------------------------------------------------*/

Celda::~Celda() {

}
/*----------------------------------------------------------------------------*/
