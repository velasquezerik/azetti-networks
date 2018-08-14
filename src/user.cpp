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

void User::User()
{
	this->uri_ = "";
	this->name_ = "";
}

void User::~User()
{
	//empty
}

bool User::isNull()
{
	if (this->uri_ == "")
	{
		return true;
	}

	return false;
}

string User::uri()
{
	return this->uri_;
}

string User::name()
{
	return this->name_;
}

void User::User(string uri)
{
	this->uri_ = uri;
	this->name_ = "";
}

void User::User(string uri, string name)
{
	this->uri_ = uri;
	this->name_ = name;
}

int User::status()
{
	if (this->isNull())
	{
		return User::Status::UNKNOWN;
	}

	return 1;
}


/***** End Functions Definitions **********************************************/
