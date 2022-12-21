#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StdTypes.h"

#include "System_Interface.h"


void  GUI(void)
{
    op_status flag = 0;    // to store the status of the func 
    u8 choice = 0;			// to store the selected task entered by the client 
    u16 id = 0;				// to store the selected ID entered by the client 
    emp_list  node ;		// create node from the type of the list 
    printf("\n");  // print new line
    while(1)
    {    // Display The GUI to the client so he can choose and undestand of the program
        printf("1- Add a new employee data. \n");
        printf("2- Delete the data of an employee.\n");
        printf("3- Modify the data of an employee.\n");
        printf("4- View the data of an employee.\n");
        printf("5- View the employees' data.\n");
        printf("6- Exit.\n");

        printf("\nEnter your operation :  ");
        scanf("\n");
        scanf("%c",&choice);
		// check on the enterd input from the clien to check if it has corresponding task to it or not 
        while( choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' )
        {
			// ask him again to enter the right choice from 1 to 6
            printf("\nWrong choice Enter your operation\n");
            printf("please choose from 1 to 6 :");
            scanf("\n");
            scanf("%c",&choice);
        }
        printf("\n");
		// check on the choice and call the corresponding function to it
        switch(choice)
        {
        case '1':  // the case is for add  an employee


            node = create_node();   // create node for the new employee
            flag = add_newEmployee(&node);  // call the func to add the employee and get the result of the func
            if(flag == fail)   // check on the status operation and print the corresponding message
            {
                printf("\nSorry your operation couldn't be done now please try later \n");
            }
            else if (flag == change_id)
            {
                printf("\nSorry but the ID you entered is already used please change the ID\n");
            }
            else
            {
                printf("\nYour operation was done successfully\n\n");
            }

            break;		//end that case when it ends its job

        case '2':   // the case is for delete an employee
            printf("Enter the ID of the employee you want to delete : ");  // asking for the id and scan it
            scanf("%d",&id);
            flag = del_employee(id);   // call the func to delete the employee and get the result of the func
            if( flag == fail)			// check on the status operation and print the corresponding message
            {
                printf("Sorry but the ID wasn't found in the list\n\n");
            }
            else if( flag == list_empty)
            {
                printf("Sorry but the list is empty\n\n");
            }
            else
            {
                printf("your operation was done successfully\n\n");
            }
            break;		//end that case when it ends its job

        case '3':  // the case is for modify an employee 
            printf("Enter the ID of the employee you want to modify : "); // asking for the id and scan it
            scanf("%d",&id);
            printf("\nEnter the new info \n");  // asking for the new info
            node = create_node();				// create node for the new info
            flag = modify_employee(id,&node);   // call the func to modify and get the result of the func
            if( flag == fail)  // check on the status operation and print the corresponding message 
            {
                printf("Sorry but the ID was n't found in the list\n\n");
            }
            else if( flag == list_empty)
            {
                printf("Sorry but the list is empty\n\n");

            }
            else if( flag == change_id)
            {
                printf("Sorry but the new ID is used with another employee \n\n");
            }
            else
            {
                printf("your operation was done successfully\n\n");
            }
            break;		//end that case when it ends its job

        case '4':  // this case is for display the info of one employee
            printf("Enter the ID of the employee you want to show : ");  // ask the client to enter the id and scan it
            scanf("%d",&id);
            flag = view_employeeInfo(id);
            printf("\n");
            if( flag == fail) // check on the status of the operation  
            {
                printf("Sorry but the ID was n't found in the list\n\n");
            }
            else if( flag == list_empty)
            {
                printf("Sorry but the list is empty\n\n");

            }

            break;	//end that case when it ends its job

        case '5':  // to display the list of the employees' when he select ->5
            printf("The list of Your employees' \n");
            view_employeeList();		// call the func to print the employees' list
            printf("\n");				// print new line
            break;						//end that case when it ends its job

        case '6':      // to end the func and the program if the client enterd ->6
            printf("Thanks for using our program \n");
            return;			// end the func and return to the main func 
            break;			//end that case when it ends its job

        default:

            break;

        }
    }

}
