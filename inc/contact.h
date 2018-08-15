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
#include <QtTest/QtTest>

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
		QString * uri_;
		QString * name_;
		Contact();
		~Contact();
		Contact(QString uri );
		Contact(QString uri, QString name);
		Contact(Contact & contact);

		bool isNull();
		QString uri();
		QString name();
		void setName(QString name);
		void setUri(QString uri);

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
	this->uri_ = new QString("");
	this->name_ = new QString("");
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

QString Contact::uri()
{
	return *this->uri_;
}

QString Contact::name()
{
	return *this->name_;
}

Contact::Contact(QString uri)
{
	if (uri != "")
	{
		this->uri_ = new QString(uri);
		this->name_ = new QString("");
	}
	else
	{
		this->uri_ = new QString("");
		this->name_ = new QString("");
	}
	
}

Contact::Contact(QString uri, QString name)
{
	if (uri != "")
	{
		this->uri_ = new QString(uri);
		this->name_ = new QString(name);
	}
	else
	{
		this->uri_ = new QString("");
		this->name_ = new QString(name);
	}
}

Contact::Contact(Contact & contact)
{
	this->uri_ = contact.uri_;
	this->name_ = contact.name_;
}


void Contact::setName(QString name)
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
void Contact::setUri(QString uri)
{
	*this->uri_ = uri;
}



/*********************    End of Class Definitions    ************************/

#endif
