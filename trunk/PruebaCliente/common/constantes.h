
#ifndef CONSTANTES_H_
#define CONSTANTES_H_

enum TIPO_COMPUERTA { T_AND , T_OR , T_NOT , T_XOR , T_PISTA , T_ENTRADA , T_SALIDA, T_CAJANEGRA};

enum SENTIDO { NORTE , SUR , ESTE , OESTE };

const static int TIEMPO_TRANSICION_AND= 10;
const static int TIEMPO_TRANSICION_OR= 20;
const static int TIEMPO_TRANSICION_XOR= 30;
const static int TIEMPO_TRANSICION_NOT= 5;

#endif /* CONSTANTES_H_ */