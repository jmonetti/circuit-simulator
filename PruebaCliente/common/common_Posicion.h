
#ifndef COMMON_POSICION_H_
#define COMMON_POSICION_H_

class Posicion {

public:

	Posicion(unsigned int x= 0,unsigned int y= 0);

	unsigned int getX() const;

	unsigned int getY() const;

	void setX(unsigned int x);

	void setY(unsigned int y);

private:

	unsigned int x;
	unsigned int y;

};

#endif /* COMMON_POSICION_H_ */
