/*******************************************************************************
* User - functions definitions
*
* Declaration and definition of functions needed by the User model
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

#include "user.h"

/***** Functions Definitions **************************************************/

/******************************************************************************
*   User
*
*   Description: Constructor
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
User::User()
{
	this->uri_ = new std::string("");
	this->name_ = new std::string("");
	this->status_ = new Status(Status::UNKNOWN);
}

/******************************************************************************
*   ~User
*
*   Description: Destructor
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
User::~User()
{
	//delete uri_;
	//delete name_;
	//delete status_;
}

/******************************************************************************
*   isNull
*
*   Description: Return Null User
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
bool User::isNull()
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
*   Description: return uri
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
std::string User::uri()
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
std::string User::name()
{
	return *this->name_;
}

/******************************************************************************
*   User
*
*   Description: Constructor
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
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

/******************************************************************************
*   User
*
*   Description: Constructor
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
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

/******************************************************************************
*   User
*
*   Description: Constructor
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
User::User(User & user)
{
	this->uri_ = user.uri_;
	this->name_ = user.name_;
	this->status_ = user.status_;
}

/******************************************************************************
*   status
*
*   Description: return status
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
User::Status User::status()
{
	if (this->isNull())
	{
		return Status::UNKNOWN;
	}

	return *this->status_;
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
bool User::operator == (User & user)
{
	if(*this->uri_ != user.uri())
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
User & User::operator = ( User & user)
{
	this->uri_ = user.uri_;
	this->name_ = user.name_;
	this->status_ = user.status_;
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
bool User::operator != ( User & user)
{
	return !(*this == user);
};

/******************************************************************************
*   setName
*
*   Description: Set name for user
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
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

/******************************************************************************
*   setUri
*
*   Description: Set uri for user
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
void User::setUri(std::string uri)
{
	*this->uri_ = uri;
}

/******************************************************************************
*   setStatus
*
*   Description: Set status for User
*
* Revision History:
*   2018-Aug-15: Erik Velásquez
*                  - Method creation
******************************************************************************/
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


/***** End Functions Definitions **********************************************/
