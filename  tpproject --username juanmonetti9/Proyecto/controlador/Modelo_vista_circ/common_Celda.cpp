/**************************   Clase Celda      ***********************/
/**************************   	Grupo 8        ***********************/

#include "common_Celda.h"
#include "common_Modelo_vista_circuito.h"
#include <stdlib.h>
/*----------------------------------------------------------------------------*/
typedef std::list<Celda*>::const_iterator LI;//iterador de la lista
/*----------------------------------------------------------------------------*/

Celda::Celda(Modelo_vista_circuito* nueva_grilla,unsigned int nueva_fila,unsigned int nueva_col){


	grilla= nueva_grilla;
	fila=  nueva_fila;
	colum= nueva_col;

}
/*----------------------------------------------------------------------------*/

Datos_celda* Celda::get_datos(){

	return &this->componente;
}
/*----------------------------------------------------------------------------*/

Datos_celda* Celda::get_datos_secundarios(){

	return &this->componente_secundario;
}
/*----------------------------------------------------------------------------*/

int Celda::get_fila()const{

	return this->fila;
}
/*----------------------------------------------------------------------------*/

int Celda::get_columna()const{

	return this->colum;
}
/*----------------------------------------------------------------------------*/

void Celda::set_componente(TIPO_COMPUERTA n_tipo,SENTIDO n_sentido,int n_id,int n_fila_ppal, int n_col_ppal){

	this->componente.set_col_ppal(n_col_ppal);
	this->componente.set_fila_ppal(n_fila_ppal);
	this->componente.set_id(n_id);
	this->componente.set_sentido(n_sentido);
	this->componente.set_tipo(n_tipo);
	this->componente.ocupar();
}
/*----------------------------------------------------------------------------*/

void Celda::set_secundario(TIPO_COMPUERTA n_tipo,SENTIDO n_sentido,int n_id,int n_fila_ppal, int n_col_ppal){

	this->componente_secundario.set_col_ppal(n_col_ppal);
	this->componente_secundario.set_fila_ppal(n_fila_ppal);
	this->componente_secundario.set_id(n_id);
	this->componente_secundario.set_sentido(n_sentido);
	this->componente_secundario.set_tipo(n_tipo);
	this->componente_secundario.ocupar();
}
/*----------------------------------------------------------------------------*/

bool Celda::hay_secundario()const{

	return this->componente_secundario.esta_ocupada();
}
/*----------------------------------------------------------------------------*/

bool Celda::esta_ocupada()const{

	 return this->componente.esta_ocupada();
}
/*----------------------------------------------------------------------------*/

void Celda::rotar(DIRECCION direcc){

	if(!hay_secundario() && componente.esta_ocupada()){

		//obtengo la celda principal y los datos del componente
		Celda* celda=grilla->get_celda(componente.get_fila_ppal(),componente.get_col_ppal());
		Datos_celda* datos = celda->get_datos();
		TIPO_COMPUERTA tipo = datos->get_tipo();

		//obtengo el nuevo sentido que tendra el componente
		SENTIDO nuevo_sentido;
		if(direcc == IZQUIERDA){
			nuevo_sentido = turn_left(datos->get_sentido());
		}
		else{
			nuevo_sentido = turn_right(datos->get_sentido());
		}

		if(tipo == T_PISTA){ //si es una pista

			if(celda->puede_rotar()){

				int _x= Modelo_vista_circuito::de_col_a_pixel(celda->get_columna());
				int _y= Modelo_vista_circuito::de_fila_a_pixel(celda->get_fila());
				int n_id= datos->get_id();

				celda->eliminar_componente();
				grilla->agregar_componente(&_x,&_y,T_PISTA,n_id,nuevo_sentido);
			}
		//si es una compuerta
		}else if( tipo != T_ENTRADA && tipo != T_SALIDA && tipo != T_CAJANEGRA){

			datos->set_sentido(nuevo_sentido);
			//recorro el entorno y seteo el sentido
			if(!datos->get_entorno().empty()){

				LI it = datos->get_entorno().begin();
				while( it!= datos->get_entorno().end()){
					((Celda*)*it)->get_datos()->set_sentido(nuevo_sentido);
					++it; //incremento el iterador
				}
			}
		}
	}
}

/*------------------------- Metodos para agregar componentes --------------*/

bool Celda::agregar_compuerta(TIPO_COMPUERTA nuevo_tipo,int nuevo_id,SENTIDO nuevo_sentido){

	bool agregada=true;

	if(!componente.esta_ocupada()){

		agregada=agregar_entorno_compuerta(nuevo_tipo,nuevo_id,nuevo_sentido);

		if(agregada){
			set_componente(nuevo_tipo,nuevo_sentido,nuevo_id,fila,colum);
			componente.set_ppal(true);
		}
	}
	else
		agregada=false;

	return agregada;
}

bool Celda::agregar_salida(int nuevo_id,SENTIDO nuevo_sentido){

	bool agregada=true;

	if(!esta_ocupada()){

		agregada=agregar_entorno_ES(T_SALIDA,nuevo_sentido,nuevo_id);

		if(agregada){
			set_componente(T_SALIDA,nuevo_sentido,nuevo_id,fila,colum);
			componente.set_ppal(true);
		}

	}else
		agregada=false;

	return agregada;
}

bool Celda::agregar_entrada(int id,SENTIDO _sentido){

	bool agregada=true;

		if(!esta_ocupada()){

			agregada=agregar_entorno_ES(T_ENTRADA,_sentido,id);

			if(agregada){
				set_componente(T_ENTRADA,_sentido,id,fila,colum);
				componente.set_ppal(true);
			}

		}else
			agregada=false;

		return agregada;
}

bool Celda::agregar_pista(int nuevo_id,SENTIDO nuevo_sentido){

	bool agregada;

	if(!componente.esta_ocupada()){

		agregada=agregar_entorno_pista(nuevo_sentido,nuevo_id);
		if(agregada){
			set_componente(T_PISTA,nuevo_sentido,nuevo_id,fila,colum);
			componente.set_ppal(true);
		}

	}
	else if(acepta_secundario(nuevo_sentido) ){

		agregada=agregar_entorno_pista(nuevo_sentido,nuevo_id);
		if(agregada){
			set_secundario(T_PISTA,nuevo_sentido,nuevo_id,fila,colum);
			componente_secundario.set_ppal(true);
		}
	}
	else
		agregada = false;

	return agregada;
}

bool Celda::agregar_caja_negra(int nuevo_id,int cant_entradas,int cant_salidas){

	bool agregada;

	if(!esta_ocupada()){

		agregada=agregar_entorno_caja_negra(cant_entradas,cant_salidas,nuevo_id);
		if(agregada){
			set_componente(T_CAJANEGRA,ESTE,nuevo_id,fila,colum);
			componente.set_ppal(true);
			componente.set_cant_entradas(cant_entradas);
			componente.set_cant_salidas(cant_salidas);
		}
		else
			componente.desocupar();

	}
	else
		agregada=false;

	return agregada;
}
/*----------------------------------------------------------------------------*/

void Celda::eliminar_componente(){

	Celda* celda_ppal=NULL;
	int aux_id;

	if(hay_secundario()){

		aux_id = componente_secundario.get_id();
		celda_ppal = grilla->get_celda(componente_secundario.get_fila_ppal(),componente_secundario.get_col_ppal());

	}else if(componente.esta_ocupada()){

		aux_id = componente.get_id();
		celda_ppal = grilla->get_celda(componente.get_fila_ppal(),componente.get_col_ppal());

	}
	if(celda_ppal)
		celda_ppal->desocupar_componente(aux_id);
}
/*----------------------------------------------------------------------------*/

bool Celda::acepta_secundario(SENTIDO _sentido)const{

	bool acepta=false ;

	if(componente.get_tipo() == T_PISTA && !hay_secundario()){

		if((componente.get_sentido()==NORTE || componente.get_sentido()==SUR) && (_sentido==OESTE || _sentido== ESTE)){

			acepta=true;
		}
		else if((componente.get_sentido()==ESTE || componente.get_sentido()==OESTE) && (_sentido==NORTE || _sentido== SUR)){

			acepta=true;
		}
	}

	return acepta;
}
/*----------------------------------------------------------------------------*/

bool Celda::puede_rotar()const{

	bool retorno= false;

	if(!hay_secundario() && componente.esta_ocupada()){

		//obtengo la id del componente a rotar
		int aux_id = componente.get_id();
		//obtengo la celda ppal del componente
		Celda* celda=grilla->get_celda(componente.get_fila_ppal(),componente.get_col_ppal());
		Datos_celda* datos = celda->get_datos();
		Datos_celda* datos_secundarios = celda->get_datos_secundarios();

		if(datos->get_tipo() == T_PISTA){ //faltaria != caja negra todo

			//obtengo el sentido del componente a rotar
			SENTIDO aux_sentido;

			if(datos->get_id() == aux_id){
				aux_sentido = datos->get_sentido();
			}else
				aux_sentido = datos_secundarios->get_sentido();

			//obtengo las celdas del entorno
			Celda* aux_1;
			Celda* aux_2;

			if(aux_sentido == ESTE || aux_sentido == OESTE){

				aux_1 = grilla->get_celda(celda->get_fila()+1,celda->get_columna());
				aux_2 = grilla->get_celda(celda->get_fila()-1,celda->get_columna());

			}else{

				aux_1 = grilla->get_celda(celda->get_fila(),celda->get_columna()+1);
				aux_2 = grilla->get_celda(celda->get_fila(),celda->get_columna()-1);
			}
			Datos_celda* aux_datos_1 = aux_1->get_datos();
			Datos_celda* aux_datos_2 = aux_2->get_datos();

			if(( (!aux_1->hay_secundario() && aux_datos_1->es_principal() ) || !aux_1->esta_ocupada()) &&
			   ( (!aux_2->hay_secundario() && aux_datos_2->es_principal() ) || !aux_2->esta_ocupada()))
			{
				retorno = true;
			}
		}
		else if (datos->get_tipo() != T_CAJANEGRA){
			retorno = true;
		}
	}

	return retorno;
}

/*---------------------- Metodos para agregar entorno --------------------*/

bool Celda::agregar_entorno_ES(TIPO_COMPUERTA _tipo,SENTIDO _sentido,int _id){

	bool retorno=true;

	int fila_entorno;
	int col_entorno;
	this->get_entorno_ES(&fila_entorno,&col_entorno,_sentido,_tipo);

	if( _tipo== T_SALIDA || _tipo== T_ENTRADA){

		Celda* aux=grilla->get_celda(fila_entorno,col_entorno);

		if(aux){

			if(! aux->get_datos()->esta_ocupada() ){
			 aux->set_componente(_tipo,_sentido,_id,fila,colum);
			 componente.get_entorno().push_front(aux);
			}
			else
			 retorno=false;
		}else
			retorno=false;
	}
	else
		retorno=false;

	if(!retorno){
		vaciar_entorno(_id);
	}

	return retorno;
}

void Celda::get_entorno_ES(int* fila_entorno,int* col_entorno,SENTIDO _sentido,TIPO_COMPUERTA tipo){

	if( tipo == T_SALIDA){

		switch(_sentido){

			case ESTE:{
						*fila_entorno=fila;
						*col_entorno=colum-1;
						break;
					   }

			case OESTE:{
						*fila_entorno=fila;
						*col_entorno=colum+1;
						break;
						}

			case NORTE:{
						*fila_entorno=fila+1;
						*col_entorno=colum;
						break;
						}

			case SUR:  {
						*fila_entorno=fila-1;
						*col_entorno=colum;
						break;
						}
		}

	}else if( tipo == T_ENTRADA ){


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

bool Celda::agregar_entorno_caja_negra(int cant_entradas,int cant_salidas,int _id){

	//variable de retorno de la funcion
	bool retorno= true;

	//variable para la cantidad maxima de filas del entorno
	int cant_max = (cant_entradas > cant_salidas)? cant_entradas:cant_salidas;
	cant_max = (cant_max > 3)?(cant_max):3;

	//variables para recorrer el entorno
	unsigned int i = fila-1;
	unsigned int j = colum -1;

	//Recorro el entorno
	while( retorno && (i < fila+(2*cant_max)-2)){

		while( retorno && (j <= colum+1)){

			if( i!=fila && j!=colum){

				Celda* aux=grilla->get_celda(i,j);

				if(aux){

					Datos_celda* datos_aux = aux->get_datos();

					if(!datos_aux->esta_ocupada()){
						aux->set_componente(T_CAJANEGRA,ESTE,_id,fila,colum);
						datos_aux->set_cant_entradas(cant_entradas);
						datos_aux->set_cant_salidas(cant_salidas);
						componente.get_entorno().push_front(aux);
					}
					else
						retorno=false;
				}
				else retorno=false;
			}
			j++;
		}

		i++;
		j= colum - 1;
	}

	if(!retorno){
		vaciar_entorno(_id);
	}

	return retorno;
}


bool Celda::agregar_entorno_compuerta(TIPO_COMPUERTA _tipo,int _id,SENTIDO nuevo_sentido){

	bool retorno= true;

	int f=fila;
	int c=colum;

	for (int i = f-1; i < f+2; ++i) {
		for (int j = c-1; j < c +2; ++j) {

			if(!(i==f && j==c)){
				Celda* aux=grilla->get_celda(i,j);

				if(aux!=NULL){
					Datos_celda* datos_aux = aux->get_datos();

					if(retorno && !datos_aux->esta_ocupada()){

						aux->set_componente(_tipo,nuevo_sentido,_id,fila,colum);
						componente.get_entorno().push_front(aux);
					}
					else
						retorno =false;
				}else
					retorno=false;
			}
		}
	}

	if(!retorno){
		vaciar_entorno(_id);
	}

	return retorno;

}

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
	if(aux_1!=NULL && aux_2 != NULL){
		//Obtengo los datos de las celdas
		Datos_celda* datos_1 = aux_1->get_datos();
		Datos_celda* datos_2 = aux_2->get_datos();

		//Si es que la celda que sera parte del entorno estan vacias o aceptan
		//una pista secundaria
		if (!datos_1->esta_ocupada() && !datos_2->esta_ocupada() ){

			 aux_1->set_componente(T_PISTA,_sentido,_id,fila,colum);
			 aux_2->set_componente(T_PISTA,_sentido,_id,fila,colum);

		 }
		 else if(!datos_1->esta_ocupada() && aux_2->acepta_secundario(_sentido) && datos_2->es_principal()){

			 aux_1->set_componente(T_PISTA,_sentido,_id,fila,colum);
			 aux_2->set_secundario(T_PISTA,_sentido,_id,fila,colum);
		 }
		 else if(!datos_2->esta_ocupada() && aux_1->acepta_secundario(_sentido) && datos_1->es_principal()){

			 aux_1->set_secundario(T_PISTA,_sentido,_id,fila,colum);
			 aux_2->set_componente(T_PISTA,_sentido,_id,fila,colum);
		 }
		 else if(!aux_2->acepta_secundario(_sentido) && aux_1->acepta_secundario(_sentido)
				 && datos_1->es_principal() && datos_2->es_principal()){

			 aux_1->set_secundario(T_PISTA,_sentido,_id,fila,colum);
			 aux_2->set_secundario(T_PISTA,_sentido,_id,fila,colum);
		 }
		 else
			 retorno=false;
	}
	else
		retorno=false;

	if(retorno){

		if(esta_ocupada()){
			componente_secundario.get_entorno().push_front(aux_1);
			componente_secundario.get_entorno().push_front(aux_2);
		}
		else
			componente.get_entorno().push_front(aux_1);
			componente.get_entorno().push_front(aux_2);
	}
	return retorno;
}
/*----------------------------------------------------------------------------*/

void Celda::vaciar_entorno(int identificador){

	if(componente.get_id() == identificador){

		bool vacia = componente.get_entorno().empty();

		if(!vacia){
			Celda* aux;
			do{
				aux = componente.get_entorno().back();
				aux->desocupar_componente(identificador);
				componente.get_entorno().pop_back();
				vacia=componente.get_entorno().empty();
			}while(!vacia);
		}

	}else if(componente_secundario.get_id() == identificador){

		bool vacia = componente_secundario.get_entorno().empty();

		if(!vacia){
			Celda* aux;
			do{
				aux = componente_secundario.get_entorno().back();
				aux->desocupar_componente(identificador);
				componente_secundario.get_entorno().pop_back();
				vacia=componente_secundario.get_entorno().empty();

			}while(!vacia);
		}
	}
}
/*----------------------------------------------------------------------------*/

void Celda::desocupar_componente(int identificador){


	if(componente.get_id() == identificador){

		if(!this->componente.get_entorno().empty()){

			LI it = componente.get_entorno().begin();
			while( it!= componente.get_entorno().end()){
				((Celda*)*it)->desocupar_componente(identificador);
				++it; //incremento el iterador
			}
			vaciar_entorno(identificador);

		}
		componente.desocupar();
		if(hay_secundario()){
			componente=componente_secundario;
			componente_secundario.desocupar();
		}

	}else if(componente_secundario.get_id() == identificador){

		if(!this->componente_secundario.get_entorno().empty()){

			LI it = componente_secundario.get_entorno().begin();
			while( it!= componente_secundario.get_entorno().end()){
				((Celda*)*it)->desocupar_componente(identificador);
				++it; //incremento el iterador
			}
			vaciar_entorno(identificador);

		}
		componente_secundario.desocupar();
	}
}
/*----------------------------------------------------------------------------*/

SENTIDO Celda::turn_left(SENTIDO _sent){


	switch(_sent){

		case NORTE: return OESTE;

		case ESTE: return NORTE;

		case SUR: return ESTE;

		case OESTE: return SUR;
	}
	return _sent;
}
/*----------------------------------------------------------------------------*/

SENTIDO Celda::turn_right(SENTIDO _sent){

	switch(_sent){

		case NORTE: return ESTE;

		case ESTE: return SUR;

		case SUR: return OESTE;

		case OESTE: return NORTE;
	}
	return _sent;
}
/*----------------------------------------------------------------------------*/

Celda::~Celda() {

}
/*----------------------------------------------------------------------------*/
