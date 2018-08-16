/*******************************************************************************
* Group - header file
*
* Declaration of datatypes needed by the Group model
*
* Author: Erik Velasquez
* Date:   2018-08-14
*
* Revision History:
*   2018-Aug-14: Erik Velasquez
*                  - Header file creation
*******************************************************************************/

#ifndef GROUP_H
#define GROUP_H

/* >>>>>>>>>>>>>>>>>>>>>>>> Standard C/C++ Libraries >>>>>>>>>>>>>>>>>>>>>>>> */

#include <iostream>

/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> POSIX Headers >>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/* EMPTY */

/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Local Headers >>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

#include "user.h"

/*****************************    Definitions    ******************************/

/*** EMPTY ***/

/************************    End of Definitions    ***************************/

/******************************    Constants    ******************************/

#define MAX 10000

/**************************    End of Constants    ***************************/


/*******************************    Macros    ********************************/

/*** EMPTY ***/

/***************************    End of Macros    *****************************/



/******************************    Variables    ******************************/

/*** EMPTY ***/

/**************************    End of Variables    ***************************/

/***************************    Class Definitions   **************************/

/*****************************************************************************
*   Group Class
*
*   Class that models the Group needed for the network
*
* Revision History:
*   2018-June-15: Erik Velasquez
*                  - Class creation
*****************************************************************************/
class Group : public Contact
{
	public:

		/*Members*/

			/* List for all users in the group */
			User * listUsers;
			/* number of users in the group */
			int *numUsers;

		/* Constructor */
			Group();
			Group(std::string uri );
			Group(std::string uri, std::string name);
			Group(Group & group);

		/* Destructor*/
			~Group();
		
		/* Access methods */
			bool isNull();
			std::string uri();
			std::string name();
			int count();

		/* Operators */
			bool operator == (Group & group);
			Group & operator = ( Group & group);
			bool operator != ( Group & group);

		/* Modifications methods */
			void add(User & user);
			void remove(User & user);
			bool contains(User & user);
			void setName(std::string name);


}; /* End Class Definition */


/*********************    End of Class Definitions    ************************/

#endif
