
#ifndef CONSTANTES_H_
#define CONSTANTES_H_

#include <string>


//Definicion para el tipo de compuertas
enum TIPO_COMPUERTA { T_AND , T_OR , T_NOT , T_XOR , T_PISTA , T_ENTRADA , T_SALIDA,T_CAJANEGRA, T_VACIA};

enum TIPO_SOAP { LISTA, CIRCUITO, NUEVOCIRCUITO , SIMULAR , SIMULARTIEMPO };

//Sentido de la compuerta
enum SENTIDO { NORTE , SUR , ESTE , OESTE };

//Direccion para rotar
enum DIRECCION { IZQUIERDA , DERECHA };

//constantes de tamanio del drawing area
const int DRW_AREA_WIDTH= 1170;
const int DRW_AREA_HEIGHT= 780;

//Constantes del tamanio del modelo
const int FILAS_MODELO= 65;
const int COLUMNAS_MODELO= 98;


//constante de tamanio del area de dibujo de una compuerta
const int COMPUERTA_WIDTH= 36;
const int COMPUERTA_HEIGHT= 36;

//constantes de tamanio de una celda
const int CELDA_WIDTH= 12;
const int CELDA_HEIGHT= 12;

// defino tamanios de envio
#define _BYTE   8
#define _WORD   16
#define _DWORD  32

//Tiempos de transicion de las compuertas
const static int TIEMPO_TRANSICION_AND= 10;
const static int TIEMPO_TRANSICION_OR= 20;
const static int TIEMPO_TRANSICION_XOR= 30;
const static int TIEMPO_TRANSICION_NOT= 5;

//Path donde se guardan los circuitos
const static std::string PATH_SAVES= "saves/";

const static std::string LENGTH = "Content-Length: ";

#endif /* CONSTANTES_H_ */
