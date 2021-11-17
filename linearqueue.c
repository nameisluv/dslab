#include <stdio.h>
#include <stdlib.h>
int front=-1,rear=-1;s[50],n;

void push()
{
    if(rear==n-1)
    {
          printf("Overflow!!!\n");
          return;
    }
    if(front==-1||rear==-1)
    {front=0;rear=0;}
     else 
    {
     rear=rear+1;
    }
    printf("enter the item to be inserted\n");
    scanf("%d",&s[rear]);
}

void pop()
{
    if(front==-1||front>rear)
        {
        printf("Underflow!!!\n");
        return;
        }
        else
 {     
     if(front == rear)  
        {  
            front = -1;  
            rear = -1 ;  
        }  
        else
        {
        printf("item deleted = %d\n",s[front]);
        front=front+1;
        }
}
}


void display()
{
    if(front==-1)
    printf("linear queue is empty\n");
    else
    {
    printf("contents of the linear queue are\n");
    for (int i = front; i <= rear ;i++)
    {
        printf("%d\t",s[i]);
    }
    printf("\n");
    }
}


void main()
{
    printf("enter the size if the linear queue\n");
    scanf("%d",&n);
     for(;;)
     {
         int choice;
    printf("****Menue****\n>>1 to push\n>>2 to pop\n>>3 to display\n>>4 to exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        push();
        break;
        
        case 2:
        pop();
        break;
        
        case 3:
        display();
        break;
        
        case 4:
        exit (0);
        
        default:
        break;
    }
}
}