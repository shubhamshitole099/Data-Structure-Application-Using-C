#include<stdio.h>
#include<stdlib.h>


typedef struct  node
{
    int data;
    struct node *next;

}NODE,*PNODE,**PPNODE;


void Display(PNODE Head,PNODE Tail)
{
    printf("\n");
    if((Head == NULL) && (Tail == NULL))
    {
        return;
    }

     do
     {
        printf("|%d|->",Head->data);
        Head = Head->next;
     } while (Head != Tail->next);
     
   
    printf("\n");
    
}

int Count(PNODE Head,PNODE Tail)
{
    int iCnt=0;
    do
    {
        iCnt++;
        Head=Head->next;
    } while (Head != Tail->next);
     

    return iCnt; 
}

void InsertFirst(PPNODE Head,PPNODE Tail,int no)
{
    PNODE newn = NULL;
    newn =(PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next =NULL;

    if((*Head == NULL)&&(*Tail == NULL))
    {
        *Head=newn;
        *Tail=newn;
    }
    else
    {
        newn->next=*Head;
        *Head=newn;
    }

    (*Tail)->next=*Head;
}

void InsertLast(PPNODE Head,PPNODE Tail,int no)
{
  
  PNODE newn = NULL;
  newn = (PNODE)malloc(sizeof(NODE));
  newn->data = no;
  newn->next=NULL;

  if((*Head==NULL) && (*Tail==NULL))
  {
    *Head=newn;
    *Tail=newn;
  }
  else
  {
    (*Tail) -> next = newn;
    *Tail=newn;
  }

  (*Tail) -> next =*Head;



}

void InsertAtPos(PPNODE Head,PPNODE Tail,int no,int iPos)
{
  PNODE newn = NULL;
  PNODE temp = *Head;

  int iSize = Count(*Head,*Tail);
  if(iPos < 1 || iPos > iSize+1)
  {
    printf("\nInvalide Position\n");
    return;
  }

  if(iPos == 1)
  {
    InsertFirst(Head,Tail,no);
  }
  else if(iPos == iSize+1)
  {
    InsertLast(Head,Tail,no);
  }
  else
  {
      int i = 0;
       newn=(PNODE)malloc(sizeof(NODE));
       newn->data=no;
       newn->next=NULL;

      for(i = 1; i<iPos-1; i++)
      {
        temp = temp->next;
      }

      newn -> next = temp -> next;
      temp->next =newn;

       (*Tail) -> next = *Head;
  }
 


}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
    if(*Head ==  NULL && *Tail == NULL)
    {
        return;
    }
    else if( *Head == *Tail)
    {
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Head = (*Head) -> next;
        free((*Tail) -> next);
        (*Tail) -> next = *Head;
    }


}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
      
      PNODE temp = *Head;

      if((*Head == NULL) && (*Tail == NULL))
      {
        return;
      }
      else if(*Head == *Tail)
      {
          *Head = NULL;
          *Tail == NULL;
      }
      else
      {
         while (temp -> next != *Tail)
         {
            temp = temp->next;
         }

         free(*Tail);

         *Tail = temp;

         (*Tail) -> next = *Head;
         
      }


}

void DeleteAtPos(PPNODE Head, PPNODE Tail,int iPos)
{
    PNODE temp = *Head;
    PNODE Targetted = NULL;

    int iSize=Count(*Head,*Tail);

    if(iPos < 1 || iPos > iSize)
    {
        printf("\nInvalide Position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head,Tail);
    }
    else if(iPos == iSize)
    {
        DeleteLast(Head,Tail);
    }
    else
    {
        int i = 0;
        for(i = 1; i<iPos-1; i++)
        {
            temp = temp-> next;
        }
        Targetted = temp ->next;
        temp -> next = Targetted -> next;
        free(Targetted);
        (*Tail) -> next = *Head;
    }
}





int main()
{
   PNODE first = NULL;
   PNODE last = NULL;

   InsertFirst(&first,&last,30);
   InsertLast(&first,&last,40);
   InsertAtPos(&first,&last,20,1);
   InsertAtPos(&first,&last,50,4);

   Display(first,last);
   printf("%d\n",Count(first,last));

//    DeleteFirst(&first,&last);
//    DeleteLast(&first,&last);

     DeleteAtPos(&first,&last,2);
    Display(first,last);
    printf("%d\n",Count(first,last));


   return 0;

}