#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE, *PNODE,**PPNODE;


void Display(PNODE Head)
{
  printf("\n");

  while(Head != NULL)
  {
  	 
  	printf("|%d| -> ",Head -> data);
  	Head = Head -> next;
  }

  printf("NULL\n");

}

int Count(PNODE Head)
{
  int iCnt = 0;
  printf("\n");

  while(Head != NULL)
  {
  	 iCnt++; 
  	 Head = Head -> next;
  }
 return iCnt;
}

void InsertFirst(PPNODE Head,int no)
{
  PNODE newn = NULL;

  newn = (PNODE)malloc(sizeof(NODE));

  newn -> data = no;
  newn -> next = NULL;

  if(Head == NULL )
  {
  	*Head = newn;
  } 
  else
  {
  	newn -> next = *Head;
  	*Head = newn;
  }


}

void InsertLast(PPNODE Head,int no)
{
  PNODE newn = NULL;
  PNODE temp = *Head;

  newn = (PNODE)malloc(sizeof(NODE));

  newn -> data = no;
  newn -> next = NULL;

  if(Head == NULL)
  {
  	*Head = newn;
  }
  else
  {
    while(temp -> next != NULL)
    {
    	temp = temp -> next;
    }

    temp -> next = newn;

  }

}

void InsertAtPos(PPNODE Head , int no, int iPos)
{
  PNODE newn = NULL;
  PNODE temp = *Head;
  int iSize = 0;
  int i = 0;

  iSize = Count(*Head);

  if((iPos < 1) || (iPos > iSize+1))
  {
    printf("\nInvalide Position");
  	return;
  }
  
  if(iPos == 1)
  {
  	InsertFirst(Head,no);
  }
  else if(iPos == iSize+1)
  {
  	InsertLast(Head,no);
  }
  else
  {
    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    for(i = 1; i < iPos-1; i++)
    {
    	temp = temp -> next;
    }

      
    newn -> next = temp -> next;
    temp -> next = newn;

  }


}

void DeleteFirst(PPNODE Head)
{
   PNODE temp = *Head;  
 
   if((*Head) != NULL)
   {
      
     *Head = (*Head) -> next;
     free(temp); 
    
   }  

}

void DeleteLast(PPNODE Head)
{
  PNODE temp = *Head;
  
  while(temp -> next ->next != NULL)
  {
  	temp = temp -> next;
  }
  
   free(temp -> next);
   temp -> next = NULL;

}


void DeleteAtPos(PPNODE Head,int iPos)
{
	PNODE temp = *Head;
	PNODE targetted = NULL;
	int i = 0;
	int iSize = 0;

	iSize = Count(*Head);

	if((iPos < 1) || (iPos < iSize))
	{
		printf("\nInvalide Position");
		return;
	}

	if(iPos == 1)
	{
		DeleteFirst(Head);
	}
	else if(iPos == iSize)
	{
		DeleteLast(Head);
	}
	else
	{
	  
	    for(i = 1; i < iPos; i++)
	    {
	    	
	    	temp = temp -> next;

	    }

	    targetted = temp -> next;
	    temp -> next = targetted -> next;
	    free(targetted);

	}


}




int main()
{
   PNODE first = NULL;
   int iChoice = 1;
   int iRet = 0;
   int iVal = 0;
   int iPos = 0;


   while(iChoice != 0)
   {
    
     printf("\n-------------------------------------------------------------------------------------------\n");
   
     printf("\n1 : Insert the node at first position\n");
     
     printf("\n2 : Insert the node at last position\n");

     printf("\n3 : Insert the node at the desired position\n");

     printf("\n4 : Delete the node at first position\n");

     printf("\n5 : Delete the node at last position\n");

     printf("\n6 : Delete the node at the desired position\n");

     printf("\n7 : Display the node\n");

     printf("\n8 : Count the number of nodes in the linkedlist\n");

     printf("\n0 : Terminates the application\n") ; 

     printf("\n");
   
     printf("\n-------------------------------------------------------------------------------------------\n");

     printf("\nEnter The Desired Operation That You Want To Perform On LinkedList : ");
     scanf("%d",&iChoice);
     printf("\n");

     switch(iChoice)
     {

       case 1: 
               printf("\nEnter the data to insert : ");
               scanf("%d",&iVal);

               InsertFirst(&first,iVal);
               break;  

       case 2: 
               printf("\nEnter the data to insert : ");
               scanf("%d",&iVal);

               InsertLast(&first,iVal);
               break;          
       
       case 3: 
               printf("\nEnter the data to insert : ");
               scanf("%d",&iVal);

               printf("\nEnter the desired position you want : ");
               scanf("%d",&iPos);

               InsertAtPos(&first,iVal,iPos);
                break;  

       case 4: 
               
               DeleteFirst(&first);
               break;  


       case 5: 
               
               DeleteLast(&first);
               break; 


       case 6 : 
               printf("\nEnter the desired position you want : ");
               scanf("%d",&iPos);


               DeleteAtPos(&first,iPos);

               break;


       case 7: 
               printf("\nElements Of LinkedList Are :\n");
            
               Display(first);
               printf("\n");

               break;  



        case 8: 
               
               iRet = Count(first);

               printf("\nNumber of elements are : %d",iRet);
               printf("\n");
               break;  

        case 0: 
               
                printf("\nApplication Successfully Terminated");
                break;                               
         

        default: 
        
                  printf("\nInvalid Choice");
                  printf("\n");
                   break;      
    

     }



   }

    printf("\n");

    return 0;
  

}


