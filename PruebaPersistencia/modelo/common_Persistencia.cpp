
#include <sstream>
#include <stdexcept>
#include <list>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <xercesc/dom/DOMLSSerializer.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>

#include "../circuito/common_Circuito.h"

#include "../circuito/common_FactoryParser.h"

#include "common_Persistencia.h"

Persistencia::Persistencia() {

	try
	{
		XMLPlatformUtils::Initialize();  // Initialize Xerces infrastructure
	}
	catch( XMLException& e )
	{
		std::string mensaje = XMLString::transcode( e.getMessage() );
		throw runtime_error("XML toolkit initialization error: " + mensaje);
	}

	TAG_INITIALIZER = XMLString::transcode("XML");
	TAG_CIRCUITO = XMLString::transcode("Circuito");

	TAG_SALIDA= XMLString::transcode("Salida");
	TAG_ENTRADA= XMLString::transcode("Entrada");
	TAG_NOT= XMLString::transcode("NOT");
	TAG_AND= XMLString::transcode("AND");
	TAG_OR= XMLString::transcode("OR");
	TAG_XOR= XMLString::transcode("XOR");
	TAG_PISTA= XMLString::transcode("Pista");

}

Persistencia::~Persistencia() {

	try
	{
	  XMLString::release( &TAG_INITIALIZER);
	  XMLString::release( &TAG_CIRCUITO);
	  XMLString::release( &TAG_SALIDA );
	  XMLString::release( &TAG_ENTRADA );
	  XMLString::release( &TAG_NOT );
	  XMLString::release( &TAG_AND );
	  XMLString::release( &TAG_OR );
	  XMLString::release( &TAG_XOR );
	  XMLString::release( &TAG_PISTA );
	}
	catch( ... )
	{
	  throw runtime_error("Unknown exception encountered in TagNamesdtor");
	}

	try
	{
		XMLPlatformUtils::Terminate();  // Terminate Xerces
	}
	catch( xercesc::XMLException& e )
	{
		std::string message = xercesc::XMLString::transcode( e.getMessage() );
		throw runtime_error("XML ttolkit teardown error: " + message);
	}
}

void Persistencia::guardar(const Circuito &circuito, std::string &ruta) {


	XMLCh tempStr[100];
	XMLString::transcode("XML", tempStr, 99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);

	//TODO CREAR ARBOL DE DATOS

	DOMDocument*   doc = impl->createDocument(0, TAG_INITIALIZER, 0);

	circuito.guardar(doc, doc->getFirstChild());

    DOMLSSerializer* theSerializer = ((DOMImplementationLS*)impl)->createLSSerializer();

    // optionally you can set some features on this serializer
    if (theSerializer->getDomConfig()->canSetParameter(XMLUni::fgDOMWRTDiscardDefaultContent, true))
        theSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTDiscardDefaultContent, true);

    if (theSerializer->getDomConfig()->canSetParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true))
         theSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true);

    // StdOutFormatTarget prints the resultant XML stream
    // to stdout once it receives any thing from the serializer.

    XMLFormatTarget *myFormatTarget = new LocalFileFormatTarget(ruta.c_str());

   // XMLFormatTarget *myFormTarget = new StdOutFormatTarget();
    DOMLSOutput* theOutput = ((DOMImplementationLS*)impl)->createLSOutput();
    theOutput->setByteStream(myFormatTarget);

    DOMNode* nodo = doc->getFirstChild();

    try {
        // do the serialization through DOMLSSerializer::write();
        theSerializer->write(nodo, theOutput);
    }
    catch (const XMLException& toCatch) {
        std::string message = XMLString::transcode(toCatch.getMessage());
        throw runtime_error("Exception message is: \n" + message);
    }
    catch (const DOMException& toCatch) {
        std::string message = XMLString::transcode(toCatch.msg);
        throw runtime_error("Exception message is: \n" + message);
    }
    catch (...) {
        throw runtime_error("Unexpected Exception");
    }

    theOutput->release();
    theSerializer->release();

}


Circuito* Persistencia::recuperar(const std::string &nombreCircuito) {

	// Test to see if the file is ok.

	   struct stat estadoArchivo;

	   int iretStat = stat(nombreCircuito.c_str(), &estadoArchivo);

	   if( iretStat == ENOENT )
	      throw ( std::runtime_error("Path file_name does not exist, or path is an empty string.") );
	   else if( iretStat == ENOTDIR )
	      throw ( std::runtime_error("A component of the path is not a directory."));
	   else if( iretStat == ELOOP )
	      throw ( std::runtime_error("Too many symbolic links encountered while traversing the path."));
	   else if( iretStat == EACCES )
	      throw ( std::runtime_error("Permission denied."));
	   else if( iretStat == ENAMETOOLONG )
	      throw ( std::runtime_error("File can not be read\n"));

	   // Configure DOM parser.
	   xercesc::XercesDOMParser *m_ConfigFileParser = new XercesDOMParser;

	   m_ConfigFileParser->setValidationScheme( XercesDOMParser::Val_Never );
	   m_ConfigFileParser->setDoNamespaces( false );
	   m_ConfigFileParser->setDoSchema( false );
	   m_ConfigFileParser->setLoadExternalDTD( false );

	   try
	   {
		   m_ConfigFileParser->parse( nombreCircuito.c_str() );

		   // no need to free this pointer - owned by the parent parser object
		   DOMDocument* xmlDoc = m_ConfigFileParser->getDocument();

		   // Get the top-level element: NAme is "root". No attributes for "root"

		   DOMElement* elementRoot = xmlDoc->getDocumentElement();
		   if( !elementRoot ) throw(std::runtime_error( "empty XML document" ));

		   DOMNode* circuito = elementRoot->getFirstChild();

		   if( circuito->getNodeType() &&  // true is not NULL
				   circuito->getNodeType() == DOMNode::ELEMENT_NODE ) // is element
		   {
			   // Found node which is an Element. Re-cast node as element
			   DOMElement* ElementoCte = dynamic_cast< xercesc::DOMElement* >( circuito );
			   if( XMLString::equals(ElementoCte->getTagName(), TAG_CIRCUITO))
			   {
				   return parserCircuito(ElementoCte);
			   }
			}
	   }
	   catch( xercesc::XMLException& e )
	   {
	      std::string message = xercesc::XMLString::transcode( e.getMessage() );
	      throw runtime_error("Error parsing file: "+ message);
	   }

	return NULL;

}

Circuito* Persistencia::parserCircuito(DOMElement* ElementoCte) {

	std::string aux;

	XMLCh* ATTR_ID = XMLString::transcode("id");
	DOMAttr* attr_id = ElementoCte->getAttributeNode(ATTR_ID);
	aux = XMLString::transcode(attr_id->getValue());

	int id = atoi(aux.c_str());

	Circuito* circuito = new Circuito(id);

	DOMNodeList*      salidas = ElementoCte->getChildNodes();
	const  XMLSize_t cantSalidas = salidas->getLength();

	// Para todos los nodos, hijos de "root" en el arbol XML.

	for( XMLSize_t i = 0; i < cantSalidas; ++i )
	{
	   DOMNode* SalidaActual = salidas->item(i);
	   if( SalidaActual->getNodeType() &&  // true is not NULL
			   SalidaActual->getNodeType() == DOMNode::ELEMENT_NODE ) // is element
	   {
		   // Found node which is an Element. Re-cast node as element
		   DOMElement* ElementoCte = dynamic_cast< xercesc::DOMElement* >( SalidaActual );
		   if( XMLString::equals(ElementoCte->getTagName(), TAG_SALIDA))
		   {
			  parserSalida(ElementoCte, circuito);

		   }
	   }
	}

	return circuito;

}

void Persistencia::parserSalida(DOMElement* ElementoCte, Circuito* circuito) {

	std::string aux;

	XMLCh* ATTR_ID = XMLString::transcode("id");
	DOMAttr* attr_id = ElementoCte->getAttributeNode(ATTR_ID);
	aux = XMLString::transcode(attr_id->getValue());

	int id = atoi(aux.c_str());

	XMLCh* ATTR_ENTRADA = XMLString::transcode("idEntrada");
	DOMAttr* attr_id_entrada = ElementoCte->getAttributeNode(ATTR_ENTRADA);
	aux = XMLString::transcode(attr_id_entrada->getValue());

	int idEntrada = atoi(aux.c_str());

	XMLCh* ATTR_VALOR = XMLString::transcode("Valor");
	DOMAttr* attr_valor = ElementoCte->getAttributeNode(ATTR_VALOR);
	aux = XMLString::transcode(attr_valor->getValue());

	bool valor = atoi(aux.c_str());

	//FactoryParser::crearCompuerta(T_SALIDA,circuito, id )

	//if(XMLString::equals(ElementoCte->getTagName(), TAG_ENTRADA)){

	  // parserEntrada(ElementoCte);

//	}
	if(XMLString::equals(ElementoCte->getTagName(), TAG_NOT)){

	   parserNOT(ElementoCte);

	}
	if(XMLString::equals(ElementoCte->getTagName(), TAG_AND)){

	   parserAND(ElementoCte);

	}
	if(XMLString::equals(ElementoCte->getTagName(), TAG_OR)){

	   parserOR(ElementoCte);

	}
	if(XMLString::equals(ElementoCte->getTagName(), TAG_XOR)){

	   parserXOR(ElementoCte);

	}
	if(XMLString::equals(ElementoCte->getTagName(), TAG_PISTA)){

	   parserPista(ElementoCte);

	}



}

void Persistencia::parserEntrada(DOMElement* ElementoCte) {

}

void Persistencia::parserNOT(DOMElement* ElementoCte){

}

void Persistencia::parserAND(DOMElement* ElementoCte) {

}

void Persistencia::parserOR(DOMElement* ElementoCte) {

}

void Persistencia::parserXOR(DOMElement* ElementoCte) {

}

void Persistencia::parserPista(DOMElement* ElementoCte) {

}
