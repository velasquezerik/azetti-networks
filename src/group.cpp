/*******************************************************************************
* Group - functions definitions
*
* Declaration and definition of functions needed by the Group model
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

#include "group.h"

/***** Functions Definitions **************************************************/

Group::Group()
{
	this->uri_ = new std::string("");
	this->name_ = new std::string("");
	numUsers = new int;
	*numUsers = 0;
	listUsers = new User[MAX];
}
Group::~Group()
{
	//EMPTY
}

Group::Group(std::string uri)
{
	if (uri != "")
	{
		this->uri_ = new std::string(uri);
		this->name_ = new std::string("");
		numUsers = new int;
		*numUsers = 0;
		listUsers = new User[MAX];
	}
	else
	{
		this->uri_ = new std::string("");
		this->name_ = new std::string("");
		numUsers = new int;
		*numUsers = 0;
		listUsers = new User[MAX];
	}
	
}

Group::Group(std::string uri, std::string name)
{
	if (uri != "")
	{
		this->uri_ = new std::string(uri);
		this->name_ = new std::string(name);
		numUsers = new int;
		*numUsers = 0;
		listUsers = new User[MAX];
	}
	else
	{
		this->uri_ = new std::string("");
		this->name_ = new std::string(name);
		numUsers = new int;
		*numUsers = 0;
		listUsers = new User[MAX];
	}
}

Group::Group(Group & group)
{
	this->uri_ = group.uri_;
	this->name_ = group.name_;
	numUsers = group.numUsers;
	listUsers = group.listUsers;
}

bool Group::isNull()
{
	if (*this->uri_ == "")
	{
		return true;
	}

	return false;
}

std::string Group::uri()
{
	return *this->uri_;
}

std::string Group::name()
{
	return *this->name_;
}

int Group::count()
{
	return *numUsers;
}


bool Group::operator == (Group & group)
{
	if(*this->uri_ != group.uri())
	{
		return false;
	}
	return true;
}

Group & Group::operator = ( Group & group)
{
	this->uri_ = group.uri_;
	this->name_ = group.name_;
	this->numUsers = group.numUsers;
	this->listUsers = group.listUsers;
	return *this;
};

bool Group::operator != ( Group & group)
{
	return !(*this == group);
};

void Group::add(User & user)
{
	if (this->isNull())
	{	
		return;
	}
	if (!user.isNull())
	{
		bool isHere = false;
		for (int i = 0; i < *this->numUsers; ++i)
		{
			if(user == this->listUsers[i])
			{
				isHere = true;
			}
		}
		if (!isHere)
		{
			if (*numUsers == 0)
			{
				listUsers[0] = user;
				listUsers[0].setUri(user.uri());
				(*numUsers)++;
			}
			else
			{
				User aux[*numUsers];
				for (int i = 0; i < *numUsers; ++i)
				{
					aux[i] = listUsers[i];
					aux[i].setUri(listUsers[i].uri());
				}
				
				for (int i = 0; i < *numUsers; ++i)
				{
					listUsers[i] = aux[i];
					listUsers[i].setUri(aux[i].uri());
				}
				listUsers[(*numUsers)+1] = user;
				listUsers[(*numUsers)+1].setUri(user.uri());
				(*numUsers)++;
			}
			
		}
		
	}

}
void Group::remove(User & user)
{
	int pos = -1;
	for (int i = 0; i < *this->numUsers; ++i)
	{
		if(user == this->listUsers[i])
		{
			pos = i;
			break;
		}
	}
	if (pos != -1)
	{
		User aux[*numUsers];
		for (int i = 0; i < *numUsers; ++i)
		{
			aux[i] = listUsers[i];
		}
		*numUsers--;
		int cont = 0;
		for (int i = 0; i < *numUsers+1; ++i)
		{
			if (i!=pos)
			{
				listUsers[cont] = aux[i];
				cont++;
			}
		}
	}
}
bool Group::contains(User & user)
{
	for (int i = 0; i < *numUsers; ++i)
	{
		if(user == this->listUsers[i])
		{
			return true;
		}
	}

	return false;

}

void Group::setName(std::string name)
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

/***** End Functions Definitions **********************************************/
