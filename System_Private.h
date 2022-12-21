#ifndef SYSTEM_PRIVATE_H_  // file guard to the file to prevent multiple include
#define SYSTEM_PRIVATE_H_

/********************** Descpription of the file *****************************/
/**	    											                        **/
/**	      This file is used just by the owner of the program 	            **/
/**		  to save the prototypes of the functions he used in the program    **/
/**		  and don't won't the user to know about them nor use               **/
/**                                          			                    **/
/*****************************************************************************/

//#include "System_Interface.h"

/*
   Description : This func is used to search for the ID in the list
   Input       : copy of the ID desired to be found in the lsit
   return      : pointer to the node in the list of the matched node (or) null pointer if the ID wasn't found 
*/
emp_list * search_employeeIDbyrefernce(u16 cop_id);   


/*
   Description : This func is used to search for the ID in the list
   Input       : copy of the ID desired to be found in the lsit
   return      : status of the operation , fail when not found , empty list if the list is empty , success when find the ID 
*/
op_status search_employeeIDbyvalue(u16 cop_id);


/*
   Description : This func is used to show the information of the employee
   Input       : pointer to the node of the employee to show his info
   return      : void (no thing ) 
*/
void view_employeebyrefernce (emp_list * ptr_node);




#endif
