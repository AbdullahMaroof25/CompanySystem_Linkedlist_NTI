#ifndef 	SYSTEM_INTERFACE_H_		// file guard to the file to prevent multiple include
#define 	SYSTEM_INTERFACE_H_

/**************************************File Descrption *****************************************/
/**	                                                                                          **/
/*  	This file is used by the user to understand how the function works                    **/
/*	    and to knew what he can use and the input and output of each function                 **/
/*                                                                                            **/
/***********************************************************************************************/
//#include "StdTypes.h"


#define emp_name_size   50              // refers to the max size of the employee name 
#define emp_title_size  50              // refers to the max size of the employee title


/*
   Description : struct to contains the information of the employee 
   emp_name   -> the emplpoyee name     from u8"char"   data type  -->array
   emp_title  -> the emplpoyee title    from u8"char"   data type  -->array
   emp_age    -> the emplpoyee age      from u8"char"   data type
   emp_salary -> the emplpoyee salary   from u16"short" data type
   emp_id     -> the emplpoyee id       from u16"short" data type
   ptr_next   -> pointer to the next node in the list    from the same type of the struct
*/
typedef  struct emp_node
{
    u8  emp_name[emp_name_size];
    u8  emp_title[emp_title_size];
    u8  emp_age;
    u16 emp_salary;
    u16 emp_id;

    struct emp_node * ptr_next;

}emp_list;


/*
   Description : enum to contains the status of the operation on the list 
   fail       -> if the operation couldnt be done 
   success    -> if the operation is done
   list_empty -> if the list is empty
   change_id  -> if the id is used before with another employee
*/
typedef enum op
{
    fail=0,
    success,
    list_empty,
    change_id
}op_status;


/*
   Description : This func is used to design the GUI to the client 
   Input       : void 
   return      : void
                  
*/
void  GUI(void);


/*
   Description : This func is used to ask the client to add the information of the employee and store it
   Input       : void 
   return      : copy of the information of the employee
                  
*/		
emp_list  create_node(void);


/*
   Description : This func is used to add new employee to the list
   Input       : the pointer to the new node of the info 
   return      : status of the operation , fail when there is no space in the system
                 change id when the ID is used by another employee, success when the operation is done 
*/
op_status add_newEmployee (emp_list * ptr_emp);


/*
   Description : This func is used to modify of an employee in the list
   Input       : copy of the ID desired to be found in the lsit
   return      : status of the operation , fail when not found , empty list when the list is empty ,
                 success when the operation done 
*/
op_status del_employee(u16 cop_id);


/*
   Description : This func is used to modify of an employee in the list
   Input       : copy of the ID desired to be found in the lsit and the pointer to the new node of the info 
   return      : status of the operation , fail when the new ID is already used by another employee, 
                 empty list when the list is empty , success when the operation done 
*/
op_status modify_employee (u16 cop_id , emp_list * ptr_node);


/*
   Description : This func is used to show the information of the employee
   Input       : copy of the ID of the employee desired to show his data
   return      : status of the operation , fail when not found ,
                 empty list when the list is empty , success when the operation is done  
*/
op_status view_employeeInfo (u16 cop_id);


/*
   Description : This func is used to show the information of the employees'
   Input       : void
   return      : void (no thing ) 
*/
void view_employeeList(void);



#endif
