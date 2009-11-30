
#ifndef COMMON_POSICION_H_
#define COMMON_POSICION_H_

class Posicion {

public:

	Posicion(unsigned int x= 1,unsigned int y= 1);

	unsigned int getX() const;

	unsigned int getY() const;

	bool operator==(const Posicion &posicion) const;

	Posicion& operator=(const Posicion &posicion);

private:

	unsigned int x;
	unsigned int y;

};

#endif /* COMMON_POSICION_H_ */
