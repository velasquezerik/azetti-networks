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

/*****************************************************************************
*   Contact Class
*
*   Class that models the Contact needed for the network
*
* Revision History:
*   2018-June-15: Erik Velasquez
*                  - Class creation
*****************************************************************************/
class Contact
{
		
	public:

		/*Members*/
			std::string * uri_;
			std::string * name_;

		/* Constructor */
			Contact();
			Contact(std::string uri );
			Contact(std::string uri, std::string name);
			Contact(Contact & contact);

		/* Destructor*/
			~Contact();


		/* Access methods */
			bool isNull();
			std::string uri();
			std::string name();

		/* Modifications methods */
			void setName(std::string name);
			void setUri(std::string uri);

		/* Operators */
			bool operator == (Contact & contact);
			Contact & operator = ( Contact & contact);
			bool operator != ( Contact & contact);

		
}; /* End Class Definition */


/*********************    End of Class Definitions    ************************/

#endif
