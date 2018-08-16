/*******************************************************************************
* Contact - functions definitions
*
* Declaration and definition of functions needed by the Contact model
*
* Author: Erik Velasquez
* Date:   2018-08-14
*
* Revision History:
*   2018-Aug-14: Erik Velasquez
*                  - Functions creation
*******************************************************************************/


/* >>>>>>>>>>>>>>>>>>>>>>>> Standard C/C++ Libraries >>>>>>>>>>>>>>>>>>>>>>>> */
/* EMPTY */

/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> POSIX Headers >>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/* EMPTY */

/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Local Headers >>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

#include "contact.h"

/***** Functions Definitions **************************************************/

/******************************************************************************
*   Contact
*
*   Description: Constructor
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
Contact::Contact()
{
	this->uri_ = new std::string("");
	this->name_ = new std::string("");
}

/******************************************************************************
*   ~Contact
*
*   Description: Destructor
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
Contact::~Contact()
{
	//delete uri_;
	//delete name_;
}

/******************************************************************************
*   isNull
*
*   Description: return Null Contact
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
bool Contact::isNull()
{
	if (*this->uri_ == "")
	{
		return true;
	}

	return false;
}

/******************************************************************************
*   uri
*
*   Description: return name
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
std::string Contact::uri()
{
	return *this->uri_;
}

/******************************************************************************
*   name
*
*   Description: return name
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
std::string Contact::name()
{
	return *this->name_;
}

/******************************************************************************
*   Contact
*
*   Description: Constructor
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
Contact::Contact(std::string uri)
{
	if (uri != "")
	{
		this->uri_ = new std::string(uri);
		this->name_ = new std::string("");
	}
	else
	{
		this->uri_ = new std::string("");
		this->name_ = new std::string("");
	}
	
}

/******************************************************************************
*   Contact
*
*   Description: Constructor
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
Contact::Contact(std::string uri, std::string name)
{
	if (uri != "")
	{
		this->uri_ = new std::string(uri);
		this->name_ = new std::string(name);
	}
	else
	{
		this->uri_ = new std::string("");
		this->name_ = new std::string(name);
	}
}

/******************************************************************************
*   Contact
*
*   Description: Constructor
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
Contact::Contact(Contact & contact)
{
	this->uri_ = contact.uri_;
	this->name_ = contact.name_;
}

/******************************************************************************
*   setName
*
*   Description: Set name
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
void Contact::setName(std::string name)
{
	if (this->isNull())
	{
		*this->name_ = "";
	}
	else
	{
		*this->name_ = name;
	}

}

/******************************************************************************
*   setUri
*
*   Description: Set uri
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
void Contact::setUri(std::string uri)
{
	*this->uri_ = uri;
}

/******************************************************************************
*   operator ==
*
*   Description: Operator
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
bool Contact::operator == (Contact & contact)
{
	if(*this->uri_ != contact.uri())
	{
		return false;
	}
	return true;
}

/******************************************************************************
*   operator =
*
*   Description: Operator
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
Contact & Contact::operator = ( Contact & contact)
{
	this->uri_ = contact.uri_;
	this->name_ = contact.name_;
	return *this;
}

/******************************************************************************
*   operator !=
*
*   Description: Operator
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
bool Contact::operator != ( Contact & contact)
{
	return !(*this == contact);
}
/***** End Functions Definitions **********************************************/
