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

/* EMPTY */

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

class User
{

	private:
		string uri_;
		string name_;
	public:
		enum class Status { UNKNOWN, Hearts, Clubs, Spades };

		User();
		~User();
		User(string uri );
		User(string uri, string name);

		bool isNull();
		string uri();
		string name();
		User::Status status();

		bool operator == (User & user)
		{
			if(this->uri_ != user.uri())
			{
				return false;
			}
			if(this->name_ != user.name())
			{
				return false;
			}
			return true;
		};
		User & operator = ( User & user)
		{
			this->uri_ = user.uri();
			this->name_ = user.name();
			return *this;
		};

		bool operator != ( User & user)
		{
			return !(*this == user);
		};
};

User::User()
{
	this->uri_ = "";
	this->name_ = "";
}

User::~User()
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

User::User(string uri)
{
	this->uri_ = uri;
	this->name_ = "";
}

User::User(string uri, string name)
{
	this->uri_ = uri;
	this->name_ = name;
}

User::Status User::status()
{
	if (this->isNull())
	{
		return User::Status::UNKNOWN;
	}

	return User::Status::UNKNOWN;
}


/*********************    End of Class Definitions    ************************/

#endif
