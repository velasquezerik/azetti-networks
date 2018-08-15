/*******************************************************************************
* User - header file
*
* Declaration of datatypes needed by the User model
*
* Author: Erik Velasquez
* Date:   2018-08-14
*
* Revision History:
*   2018-Aug-14: Erik Velasquez
*                  - Header file creation
*******************************************************************************/

#ifndef USER_H
#define USER_H

/* >>>>>>>>>>>>>>>>>>>>>>>> Standard C/C++ Libraries >>>>>>>>>>>>>>>>>>>>>>>> */

#include <iostream>
#include <QtTest/QtTest>

using namespace std;
/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> POSIX Headers >>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/* EMPTY */

/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Local Headers >>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

#include "contact.h"

/*****************************    Definitions    ******************************/

/* EMPTY */

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

class User : public Contact
{
		
	public:

		enum class Status { UNKNOWN, ONLINE, OFFLINE };
		Status * status_;
		User();
		~User();
		User(QString uri );
		User(QString uri, QString name);
		User(User & user);

		bool isNull();
		QString uri();
		QString name();
		User::Status status();
		void setName(QString name);
		void setUri(QString uri);
		void setStatus(Status status);

		bool operator == (User & user)
		{
			if(*this->uri_ != user.uri())
			{
				return false;
			}
			return true;
		};
		User & operator = ( User & user)
		{
			this->uri_ = user.uri_;
			this->name_ = user.name_;
			this->status_ = user.status_;
			return *this;
		};

		bool operator != ( User & user)
		{
			return !(*this == user);
		};

		
};

User::User()
{
	this->uri_ = new QString("");
	this->name_ = new QString("");
	this->status_ = new Status(Status::UNKNOWN);
}

User::~User()
{
	//delete uri_;
	//delete name_;
	//delete status_;
}

bool User::isNull()
{
	if (*this->uri_ == "")
	{
		return true;
	}

	return false;
}

QString User::uri()
{
	return *this->uri_;
}

QString User::name()
{
	return *this->name_;
}

User::User(QString uri)
{
	if (uri != "")
	{
		this->uri_ = new QString(uri);
		this->name_ = new QString("");
		this->status_ = new Status(Status::UNKNOWN);
	}
	else
	{
		this->uri_ = new QString("");
		this->name_ = new QString("");
		this->status_ = new Status(Status::UNKNOWN);
	}
	
}

User::User(QString uri, QString name)
{
	if (uri != "")
	{
		this->uri_ = new QString(uri);
		this->name_ = new QString(name);
		this->status_ = new Status(Status::UNKNOWN);
	}
	else
	{
		this->uri_ = new QString("");
		this->name_ = new QString(name);
		this->status_ = new Status(Status::UNKNOWN);
	}
}

User::User(User & user)
{
	this->uri_ = user.uri_;
	this->name_ = user.name_;
	this->status_ = user.status_;
}

User::Status User::status()
{
	if (this->isNull())
	{
		return Status::UNKNOWN;
	}

	return *this->status_;
}

void User::setName(QString name)
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
void User::setUri(QString uri)
{
	*this->uri_ = uri;
}
void User::setStatus(Status status)
{
	if (this->isNull())
	{
		*this->status_ = Status::UNKNOWN;
	}
	else
	{
		*this->status_ = status;
	}

}


/*********************    End of Class Definitions    ************************/

#endif
