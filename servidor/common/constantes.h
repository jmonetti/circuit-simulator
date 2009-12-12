
#ifndef CONSTANTES_H_
#define CONSTANTES_H_

#include <string>


//Definicion para el tipo de compuertas
enum TIPO_COMPUERTA { T_AND , T_OR , T_NOT , T_XOR , T_PISTA , T_ENTRADA , T_SALIDA,T_CAJANEGRA, T_VACIA};

enum TIPO_SOAP { LISTA, CIRCUITO, NUEVOCIRCUITO , SIMULAR , SIMULARTIEMPO, DISENIO };

enum SENTIDO { NORTE , SUR , ESTE , OESTE };

enum DIRECCION { IZQUIERDA , DERECHA };

//constantes de tamanio del drawing area
const int DRW_AREA_WIDTH= 1170;
const int DRW_AREA_HEIGHT= 780;

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

const static int TIEMPO_TRANSICION_AND= 10;
const static int TIEMPO_TRANSICION_OR= 20;
const static int TIEMPO_TRANSICION_XOR= 30;
const static int TIEMPO_TRANSICION_NOT= 5;

const static char* PATH_SAVES= "saves/";

const static std::string PATH_TEMP= "temp/";

const static std::string STRNUEVOCIRCUITO = "NuevoCircuito";

const std::string PEDIDO = "pedido";

const std::string RESPUESTA = "respuesta";

#endif /* CONSTANTES_H_ */
