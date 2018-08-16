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
		User(std::string uri );
		User(std::string uri, std::string name);
		User(User & user);

		bool isNull();
		std::string uri();
		std::string name();
		User::Status status();
		void setName(std::string name);
		void setUri(std::string uri);
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
	this->uri_ = new std::string("");
	this->name_ = new std::string("");
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

std::string User::uri()
{
	return *this->uri_;
}

std::string User::name()
{
	return *this->name_;
}

User::User(std::string uri)
{
	if (uri != "")
	{
		this->uri_ = new std::string(uri);
		this->name_ = new std::string("");
		this->status_ = new Status(Status::UNKNOWN);
	}
	else
	{
		this->uri_ = new std::string("");
		this->name_ = new std::string("");
		this->status_ = new Status(Status::UNKNOWN);
	}
	
}

User::User(std::string uri, std::string name)
{
	if (uri != "")
	{
		this->uri_ = new std::string(uri);
		this->name_ = new std::string(name);
		this->status_ = new Status(Status::UNKNOWN);
	}
	else
	{
		this->uri_ = new std::string("");
		this->name_ = new std::string(name);
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

void User::setName(std::string name)
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
void User::setUri(std::string uri)
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
