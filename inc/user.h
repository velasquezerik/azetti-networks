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

/*****************************************************************************
*   User Class
*
*   Class that models the User needed for the network
*
* Revision History:
*   2018-June-15: Erik Velasquez
*                  - Class creation
*****************************************************************************/
class User : public Contact
{
		
	public:

		/*Members*/

			/* Enum Class for status*/
			enum class Status { UNKNOWN, ONLINE, OFFLINE };
			/* User Status*/
			Status * status_;

		/* Constructor */
			User();
			User(std::string uri );
			User(std::string uri, std::string name);
			User(User & user);
		/* Destructor*/
			~User();
		

		/* Access methods */
			bool isNull();
			std::string uri();
			std::string name();
			User::Status status();
			
		/* Modifications methods */
			void setName(std::string name);
			void setUri(std::string uri);
			void setStatus(Status status);

		/* Operators */
			bool operator == (User & user);
			User & operator = ( User & user);
			bool operator != ( User & user);

		
}; /* End Class Definition */


/*********************    End of Class Definitions    ************************/

#endif
