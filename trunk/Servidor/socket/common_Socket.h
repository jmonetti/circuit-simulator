/**************************   Clase Socket  ***********************************/
/**************************   Grupo 8       ***********************************/


#ifndef CLASS_SOCKET_H
#define CLASS_SOCKET_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <netdb.h>


class Socket{


private:
		//atributos
		int fd; 	 // file descriptor
		bool valido; // estado del Socket

public:
		/**
		 * Constructor publico.
		 * Creo un descriptor,y pone su atributo "valido" en true.
		 */
		Socket();

		/**
		 * Avisa al sistema que comience a atender la conexión de red, y queda
		 * dispuesto a recibir ordenes de aceptacion de clientes.
		 */
		void listen(unsigned short port, int backlog=5);

		/**
		 * Avisa al sistema operativo de que hemos abierto un socket,
		 *  y queremos que asocie el programa a dicho socket.
		 */
		void bind(unsigned short puerto);

		/**
		 * Solicita la conexion al servidor indicado por el host y el pueto.
		 */
		void connect(const std::string& host, unsigned int port);

		/**
		 * Cierra el socket.
		 */
		void close();

		/**
		 * Envia una cadena de caracteres.
		 * @param
		 * stream: cadena de caracteres a enviar.
		 * size: cant de caracteres de stream (contando el '\0'). este valor
		 * debe ser mayor a cero
		 * @return:
		 * cantidad de caracteres enviados
		 */
		int send(const char* stream,unsigned int size);

		/**
		 * Recibe caracteres hasta que llegue el caracter '\0', o en caso de
		 * haber recibido la cantidad maxima indicada en el parametro dos ,
		 * incluye el caracter '\0' en la ultima posicion de stream y deja de
		 * recibir.
		 * @param
		 * stream: buffer donde se guardara la cadena de caract.
		 * size: cant de caracteres maximos a recibir, debe ser mayor a cero.
		 * @return (int) cantidad de caracteres recibidos.
		 *
		 */
		int receive(char* stream,unsigned int size);

		/**
		 * Cancela el socket
		 */
		void shutdown();

		/**
		 * Este metodo recibe del sist operativo un cliente de la cola de clientes y
		 * retorna el socket correspondiente a la conexion.
		 */
		Socket* accept();

		/**
		 * Retorna true si el Socket es valido, false en caso contrario.
		 */
		bool es_valido();

		/**
		 * Retorna un puntero al socket del servidor
		 */
		Socket* get_socket();

		/**
		 *Retorna el file descriptor
		 */
		int get_fd()const;

		//Destructor virtual
		virtual ~Socket();

	private:

		/**
		 * Constructor privado.
		 * Pone el atributo "valido" en true e inicializa el atributo fd con el
		 * valor pasado por parametro.
		 */
		Socket(int fileD);

		/**
		 * Constructor de copia privado
		 */
		Socket(const Socket& s);


};
#endif
