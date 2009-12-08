
#ifndef COMMON_PERSISTENCIA_H_
#define COMMON_PERSISTENCIA_H_

#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMDocumentType.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/dom/DOMNodeIterator.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMText.hpp>

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/XMLUni.hpp>
#include <xercesc/util/XMLString.hpp>

#include <string>
#include <sstream>

class Circuito;

#include <xercesc/util/PlatformUtils.hpp>

#include "../../common/constantes.h"

using namespace xercesc;
using namespace std;

class Persistencia {

public:

	Persistencia();

	virtual ~Persistencia();

	void guardarCircuito(const Circuito &circuito);

	Circuito* recuperar(int idCircuito, const std::string &nombreCircuito);

	static void guardarElemento(DOMDocument* doc, DOMElement* elem,std::string &nombre,int valor);

	static void guardarElemento(DOMDocument* doc, DOMElement* elem,std::string &nombre,std::string &valor);

	static void guardarElementoTexto(DOMDocument* doc, DOMElement* elem,std::string &nombre,int valor);

	static std::string recuperarDatoTexto(DOMElement* ElementoCte);

	static int recuperarDato(DOMElement* ElementoCte, std::string &nombre);

	static std::string publicarCircuito(Circuito* circuito);

	static void generarSOAP(DOMImplementation *impl,DOMDocument* doc,const std::string &ruta, DOMElement* datos);

	DOMElement* getElemSOAP(std::string &ruta, std::string &tag);

	DOMElement* getTipoSOAP(std::string &ruta, TIPO_SOAP &tipo);

	Circuito* parserCircuito(DOMElement* ElementoCte, int idCircuito, const std::string &nombreCircuito);

	std::string obtenerNombre(DOMElement* ElementoCte);

private:



	void parserSalida(DOMElement* ElementoCte, Circuito* circuito);

	void parserEntrada(DOMElement* ElementoCte, Circuito* circuito);

	void parserNOT(DOMElement* ElementoCte, Circuito* circuito);

	void parserAND(DOMElement* ElementoCte, Circuito* circuito);

	void parserOR(DOMElement* ElementoCte, Circuito* circuito);

	void parserXOR(DOMElement* ElementoCte, Circuito* circuito);

	void parserPista(DOMElement* ElementoCte, Circuito* circuito);

	void parserCajaNegra(DOMElement* ElementoCte, Circuito* circuito);



	xercesc::XercesDOMParser *m_ConfigFileParser;
	XMLCh* TAG_INITIALIZER;
	XMLCh* TAG_CIRCUITO;

	XMLCh* TAG_SALIDA;
	XMLCh* TAG_ENTRADA;
	XMLCh* TAG_NOT;
	XMLCh* TAG_AND;
	XMLCh* TAG_OR;
	XMLCh* TAG_XOR;
	XMLCh* TAG_PISTA;
	//TODO
	XMLCh* TAG_GETSIMULACION;
	XMLCh* TAG_GETTIEMPOSIMULACION;
	XMLCh* TAG_PUBLICARCIRCUITO ;
	XMLCh* TAG_BODY;
	XMLCh* TAG_PEDIDOLISTA ;
	XMLCh* TAG_PEDIDOCIRCUITO;


};

#endif /* COMMON_PERSISTENCIA_H_ */
