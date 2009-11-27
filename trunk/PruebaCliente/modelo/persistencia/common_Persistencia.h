
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
class Circuito;
#include <xercesc/util/PlatformUtils.hpp>

using namespace xercesc;
using namespace std;

class Persistencia {

public:

	Persistencia();

	virtual ~Persistencia();

	void guardar(const Circuito &circuito);

	Circuito* recuperar(int idCircuito, const std::string &nombreCircuito);

private:

	Circuito* parserCircuito(DOMElement* ElementoCte, int idCircuito);

	void parserSalida(DOMElement* ElementoCte, Circuito* circuito);

	void parserEntrada(DOMElement* ElementoCte, Circuito* circuito);

	void parserNOT(DOMElement* ElementoCte, Circuito* circuito);

	void parserAND(DOMElement* ElementoCte, Circuito* circuito);

	void parserOR(DOMElement* ElementoCte, Circuito* circuito);

	void parserXOR(DOMElement* ElementoCte, Circuito* circuito);

	void parserPista(DOMElement* ElementoCte, Circuito* circuito);



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


};

#endif /* COMMON_PERSISTENCIA_H_ */
