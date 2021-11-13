#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
	
}NODE ,*PNODE, **PPNODE;


void Display(PNODE Head)
{
  printf("\n");

  while(Head != NULL)
  {
  	printf("|%d|->",Head -> data);
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
  newn -> prev = NULL;

  if(*Head == NULL)
  {
  	*Head = newn;
  }
  else
  {
    newn -> next = *Head;

    (*Head) -> prev = newn;

    *Head = newn;

  }

}
void InsertLast(PPNODE Head , int no)
{
 PNODE newn = NULL;
 PNODE temp = *Head;

 newn = (PNODE)malloc(sizeof(NODE));

 newn -> data = no;
 newn -> next = NULL;
 newn -> prev = NULL;

 if(*Head == NULL)
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
    newn -> prev = temp;
 }

}
void InsertAtPos(PPNODE Head, int no,int iPos)
{ 
  PNODE newn = NULL;
  PNODE temp = *Head;

  int isize = Count(*Head);
  int i = 0;


  if((iPos < 1) || (iPos > isize+1))
  {
    printf("\nInvalide Position");
    return;
  }

  if(iPos == 1)
  {
  	InsertFirst(Head,no);
  }
  else if(iPos == isize+1)
  {
  	InsertLast(Head,no);
  }
  else
  {
    newn =(PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    for(i = 1; i< iPos-1; i++)
    {
    	temp = temp -> next;
    }

     newn -> next = temp -> next;
     newn -> prev = temp;
     temp -> next -> prev = newn;
     temp -> next = newn;
       
    }
 

}
void DeleteFirst(PPNODE Head)
{
  if(*Head == NULL)
  {
    return;

  }
  else if((*Head) -> next == NULL)
  {
  	free(*Head);
  	*Head = NULL;
  }
  else
  {
    *Head = (*Head) -> next;
    free((*Head) -> prev);
    (*Head)-> prev = NULL;
    

  }

}
void DeleteLast(PPNODE Head)
{
  PNODE temp = *Head;

  if(*Head == NULL)
  {
  	return;
  }
  else if((*Head) -> next == NULL)
  {
    free(*Head);
    *Head = NULL;

  }
  else
  {
  	while(temp -> next != NULL)
  	{
  		temp = temp -> next;
  	}
     
    temp -> prev -> next = NULL;
    free(temp); 


  }


}
void DeleteAtPos(PPNODE Head,int iPos)
{
  PNODE temp = *Head; 

  int isize = Count(*Head);
  int i = 0;

  if((iPos < 1) || (iPos > isize+1))
  {
  	printf("\nInvalide Position");
    return;

  }

  if(iPos == 1)
  {
  	DeleteFirst(Head);
  }
  else if(iPos == isize)
  {
  	DeleteLast(Head);
  }
  else
  {
  	for(i = 1; i < iPos-1; i++)
  	{
  		temp = temp -> next;
  	}

  	temp -> next = temp -> next -> next;
  	free(temp -> next -> prev);
  	temp -> next -> next -> prev = temp;
  	
  }


}



int main()
{
   PNODE first = NULL;

   int iVal = 0;
   int iRet = 0;
   int iChoice = 1;
   int iPos = 0;

 
   while(iChoice != 0)
   {

     printf("\n-------------------------------------------------------------------------\n");
    
     printf("\n1 : Insert Node At First Position\n");
     printf("\n2 : Insert Node At Last Position\n");
     printf("\n3 : Insert Node At The Desired Position You Want\n");
     printf("\n4 : Delete Node At First Position\n");
     printf("\n5 : Delete Node At Last Position\n");
     printf("\n6 : Delete Node At The Desired Position You Want\n");
     printf("\n7 : Display  The Nodes\n");
     printf("\n8 : Count The Nodes Of In The Linked List\n");
     printf("\n0 : Terminates The Application\n");
     printf("\n");

    printf("\n-------------------------------------------------------------------------\n");
     
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

               printf("\nEnter the data to  insert : ");
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


        case 6: 
                 printf("\nEnter the desired position you want : ");
                 scanf("%d",&iPos);

                 DeleteAtPos(&first,iPos);

                 break;

         case 7: 
                
                printf("\nElements Of LinkedList Are : ");
                printf("\n");

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
       
                  printf("\nInvalide Choice");
                 
                  printf("\n");
                 
                   break;      
       
             
     }
  

}

 printf("\n");

 return 0;

}