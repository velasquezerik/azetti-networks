/*******************************************************************************
* Contact - header file
*
* Declaration of datatypes needed by the Contact model
*
* Author: Erik Velasquez
* Date:   2018-08-14
*
* Revision History:
*   2018-Aug-14: Erik Velasquez
*                  - Header file creation
*******************************************************************************/

#ifndef CONTACT_H
#define CONTACT_H

/* >>>>>>>>>>>>>>>>>>>>>>>> Standard C/C++ Libraries >>>>>>>>>>>>>>>>>>>>>>>> */

#include <iostream>

/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> POSIX Headers >>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/* EMPTY */

/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Local Headers >>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/* EMPTY */

/*****************************    Definitions    ******************************/

/*** EMPTY ***/

/************************    End of Definitions    ***************************/

/******************************    Constants    ******************************/

/*** EMPTY ***/

/**************************    End of Constants    ***************************/


/*******************************    Macros    ********************************/

/*** EMPTY ***/

/***************************    End of Macros    *****************************/



/******************************    Variables    ******************************/

/*** EMPTY ***/

/**************************    End of Variables    ***************************/

/***************************    Class Definitions   **************************/

class Contact
{
		
	public:
		std::string * uri_;
		std::string * name_;
		Contact();
		~Contact();
		Contact(std::string uri );
		Contact(std::string uri, std::string name);
		Contact(Contact & contact);

		bool isNull();
		std::string uri();
		std::string name();
		void setName(std::string name);
		void setUri(std::string uri);

		bool operator == (Contact & contact)
		{
			if(*this->uri_ != contact.uri())
			{
				return false;
			}
			return true;
		};
		Contact & operator = ( Contact & contact)
		{
			this->uri_ = contact.uri_;
			this->name_ = contact.name_;
			return *this;
		};

		bool operator != ( Contact & contact)
		{
			return !(*this == contact);
		};

		
};

Contact::Contact()
{
	this->uri_ = new std::string("");
	this->name_ = new std::string("");
}

Contact::~Contact()
{
	//delete uri_;
	//delete name_;
}

bool Contact::isNull()
{
	if (*this->uri_ == "")
	{
		return true;
	}

	return false;
}

std::string Contact::uri()
{
	return *this->uri_;
}

std::string Contact::name()
{
	return *this->name_;
}

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

Contact::Contact(Contact & contact)
{
	this->uri_ = contact.uri_;
	this->name_ = contact.name_;
}


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
void Contact::setUri(std::string uri)
{
	*this->uri_ = uri;
}



/*********************    End of Class Definitions    ************************/

#endif
