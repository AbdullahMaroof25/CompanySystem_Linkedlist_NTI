


/**************************************File Descrption *****************************************/
/**	                                                                                          **/
/**  	This file is for the implementation of the funcs in the program.                      **/
/**	    ->>>> Note : I tried to apply my theoretical information in this project              **/
/**                   so I tried many theories and designs in my code        <<<<-             **/
/**																							  **/
/***********************************************************************************************/



//   (#include)  refers to the libraries I included to use in my program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StdTypes.h"

#include "System_Interface.h"
#include "System_Private.h"


emp_list * ptr_list_head = NULLPTR;  // pointer from the type of the employee type to point to the first node and initialized to 0
emp_list * ptr_list_tail = NULLPTR;  // pointer from the type of the employee type to point to the last node and initialized to 0

static u8 count = 0;                 // used to track the pos of the node in the list

emp_list * search_employeeIDbyrefernce(u16 cop_id)
{
    emp_list * ptr_index = ptr_list_head; // pointer from the type of the employee type and initialized to the first node
    if( ptr_list_head == NULLPTR)		 // check if the list is empty
        return NULLPTR;					//return pointer to 0
    while( ptr_index != NULLPTR )      // while the list isn't empty and the pointer doesn't reach the end of the list yet
    {
        if( ptr_index->emp_id == cop_id) //checking if the id was found in the list
        {
            return ptr_index;         // if it was found , return pointer to the node  of the id
        }
        ptr_index = ptr_index->ptr_next; // make the pointer to move to the next node so it can reach the end of the list
        count++;  // increment till reach the id of the employee
    }

    return NULLPTR;   //return pointer to 0 when the id couldn't be found in the list
}


op_status search_employeeIDbyvalue(u16 cop_id)
{


    emp_list * ptr_index = ptr_list_head;  // pointer from the type of the employee type and initialized to the first node
    if( ptr_index == NULLPTR)  // check if the list is empty
        return list_empty;     //return list_empty
    while( ptr_index != NULLPTR )  // while the list isn't empty and the pointer doesn't reach the end of the list yet
    {
        if( ptr_index->emp_id == cop_id)  //checking if the id was found in the list
        {
            return change_id;        // return change_id
        }
        ptr_index = ptr_index->ptr_next; // make the pointer to move to the next node so it can reach the end of the list

    }
    return fail;  //return fail when the id couldn't be found in the list
}



void view_employeebyrefernce (emp_list * ptr_node)
{
	// Display the information of the employee
    printf("\nEmployeer Name      : %s\n",ptr_node->emp_name);
    printf("Employeer Title     : %s\n",ptr_node->emp_title);
    printf("Employeer ID        : %d\n",ptr_node->emp_id);
    printf("Employeer Age       : %d\n",ptr_node->emp_age);
    printf("Employeer Salary    : %d\n",ptr_node->emp_salary);

}

emp_list  create_node(void)
{
    emp_list node;        // struct from the type of the employee node
	// ask the client to enter the employee name
    printf("Enter the Employee name     : ");
	//I used this way to read the name from the client and to over come the scanf problem  
    scanf("\n");
    scanf("%[^\n]%*c",node.emp_name);
    // ask the client to enter the employee title and read it
    printf("Enter the Employee title    : ");
    scanf("\n");
    scanf("%[^\n]%*c",node.emp_title);
    // ask the client to enter the employee age and read it
    printf("Enter the Employee age      : ");
    scanf("%d",&node.emp_age);
    // ask the client to enter the employee salary and read it
    printf("Enter the Employee salary   : ");
    scanf("%d",&node.emp_salary);
    // ask the client to enter the employee ID and read it
    printf("Enter the Employee id       : ");
    scanf("%d",&node.emp_id);

    node.ptr_next = NULLPTR;   // make the next pointer refers to 0

    return (node);  // return copy of the employee node
}


op_status add_newEmployee (emp_list * ptr_emp)
{

    emp_list * ptr_node = NULLPTR ; // pointer from the type of the employee type and initialized to 0
    ptr_node = malloc(sizeof(emp_list)); // allocate storage eauals to employee node in the run time and assign the return pointer in ptr_node

    if( ptr_node == NULLPTR)  // check if the storage couldn't be allocated
    {
        return fail;    // retunr fail if it couldn't be
    }

	if( search_employeeIDbyvalue(ptr_emp->emp_id) == change_id ) // check if the ID of the new employee is used
    {
        return change_id;   // return change_id
    }

	// assign the information to the allocated node in the list
    ptr_node->emp_id = ptr_emp->emp_id;
    ptr_node->emp_age = ptr_emp->emp_age;
    ptr_node->emp_salary = ptr_emp->emp_salary;

    strcpy( ptr_node->emp_name, ptr_emp->emp_name);        // I used this way to assign the name and title
    strcpy( ptr_node->emp_title, ptr_emp->emp_title);



    if( ptr_list_head == NULLPTR)  // check if the list is empty and this is the first node in the list
    {
        ptr_node->ptr_next = NULLPTR; // assign the next pointer to 0
        ptr_list_head = ptr_node;     // assign the head pointer to this node
        ptr_list_tail = ptr_node;     // assign the tai pointer to this node as long as it's the first and the last
    }
    else
    {

        ptr_list_tail->ptr_next = ptr_node; // make the next pointer in the last node point to the new node in the list
        ptr_list_tail = ptr_node;		// then make the tail pointer to move and point to the new node as it becomes the last node in the list
        ptr_list_tail->ptr_next = NULLPTR; // make the next pointer in the tail to point to 0
	    ptr_node->ptr_next = NULLPTR;  // make the next pointer in the new node to point to 0
    }

    return success; // retun success if the node is added to the list

}


op_status view_employeeInfo (u16 cop_id)
{
    op_status flag = search_employeeIDbyvalue(cop_id); // search for the id and get the result in the flag

    if( ptr_list_head == NULLPTR  ) // check if list is empty and return list_empty if it was empty
    {
        return list_empty;
    }
    else if( flag == fail) // check if the id wasn't found and return fail
    {
        return fail;
    }

    emp_list * ptr_index =  search_employeeIDbyrefernce(cop_id); // get pointer to the node of the id
    view_employeebyrefernce(ptr_index);  // call the function to display the info of the employee
    return success;  // retun success if the id was found and the display the info
}


void view_employeeList(void)
{

    emp_list * ptr_index = ptr_list_head;  // pointer from the type of the node points to firsr node in the list

    if(ptr_index == NULLPTR) // check if the list is empty and print if it is then end the whole func and return
    {
        printf("There is no employees to show in your system yet \n");
        return;
    }
    else
    {
        while( ptr_index != NULLPTR)  // lop while the pointer not point to 0
        {


            view_employeebyrefernce(ptr_index); // call the func to display the info of the employee

            if( ptr_index->ptr_next != NULLPTR  )  // check if the node wasn't the last to print this phase
            {
                printf("\n**************************  The next Employee INFO   *****************\n");
            }

            ptr_index = ptr_index->ptr_next; // move the pointer to the next nodee
        }
    }

}


op_status modify_employee (u16 cop_id, emp_list * ptr_node)
{
    op_status flag = search_employeeIDbyvalue(cop_id); // call func to search for the id of the employee to modify his info

    if( ptr_list_head == NULLPTR  ) // if the list is empty , return list_empty
    {
        return list_empty;
    }
    else if( flag == fail) // if the employee wasn't found in the list , return fail
    {
        return fail;
    }

    emp_list * ptr_index = search_employeeIDbyrefernce(cop_id);  // get pointer of the employee node
	// modify his informaton
    strcpy( ptr_index->emp_name, ptr_node->emp_name);
    strcpy( ptr_index->emp_title, ptr_node->emp_title) ;

    ptr_index->emp_age = ptr_node->emp_age;
    ptr_index->emp_salary = ptr_node->emp_salary;
    ptr_index->emp_id = ptr_node->emp_id;

    emp_list * ptr_copy = search_employeeIDbyrefernce(cop_id); // search if the modified ID is used by anothe employee in the list

    if( ptr_copy != ptr_index ) //->>> I used ptr_copy to over come that the ID is different from the original ID before modifing
    {                           // it was a bug with me so i did that. Like if i just changed the name and keep the original id , it won't work and retun change_id<<<-
        return change_id;
    }

    return success;  // retun success if the modify is done

}


op_status del_employee(u16 cop_id)
{
    op_status flag = search_employeeIDbyvalue(cop_id); // call func to search for the id of the employee to modify his info

    if( ptr_list_head == NULLPTR  ) // if the list is empty ,retun list_empty
    {
        return list_empty;
    }
    else if( flag == fail)  // if the id wasn't found , retun fail
    {
        return fail;
    }
    count = 0;         // it's sure that the id is in the list so to get the previous node i used counter to get its pos
    emp_list * ptr_index  = search_employeeIDbyrefernce(cop_id); // get pointer to the id node
    emp_list * ptr_prev   = ptr_list_head;                // initialize pointer to the next node of the employee node
	// if we have more than 256 employee in the system we can change the type of i from u8 to anothe big one 
	for(u8 i = 1; i<count ; i++)      // move the pointer till one step before the node of the employee
        {
            ptr_prev = ptr_prev->ptr_next;

        }

    if (ptr_index == ptr_list_head)   // if the node is the first node in the list
    {
        ptr_list_head = ptr_list_head->ptr_next; // move the head pointer to the next node
        free(ptr_index);                         // delete the node from the lit

    }
     else if (ptr_index == ptr_list_tail)   // if the node is the first node in the list
    {

        ptr_list_tail = ptr_prev;  // make the tail point to one step before the node
        ptr_list_tail->ptr_next = NULLPTR;  // make the next pointer point to 0
        free(ptr_index);  // free the node
    }
	else
	{
			ptr_prev->ptr_next = ptr_index->ptr_next;  // make the prev node point to the next node that will be deleted
			free(ptr_index);  // free the node

    }
    return success;

}
