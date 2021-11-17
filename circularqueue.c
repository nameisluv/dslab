#include<stdio.h>
#include <stdlib.h>
int n;
int myCQ[50];
int front = -1;
int rear = -1;
int element;
void enQueue()
{
    printf("\nEnter the value to be inserted:  ");
    scanf("%d",&element);
    if((front == 0 && rear == n - 1) || (front == rear+1))
    printf("\nSorry - Circular Queue is Full, therefore Insertion not possible!\n");
    else
    { 
        if(rear == n-1 && front != 0) 
        rear = -1;
        rear=rear+1;
        myCQ[rear] = element;
        printf("\nInserted %d Successfully!\n", myCQ[rear]);
        if(front == -1)
        front = 0;
    }
}

void deQueue()
{
    if(front == -1 && rear == -1)
    printf("\nCircular Queue is Empty. Therefore deletion is not possible!\n"); 
    else
    {
        element = myCQ[front];
        front=front+1;
        printf("\nDeleted element is : %d\n",element);      
        if(front-1 == rear)
        front = rear = -1;
        if(front == n )
            front = 0;
    }
}

void display()
{
    if(front == -1)
    printf("\nCircular Queue is Empty!\n");
    else
    {
        int i;
        printf("\nCircular Queue Elements are : \n");
        if(front <= rear)
        {
            for (i=front; i <= rear; i++)
            printf("%d\t",myCQ[i]);
        }
        else
        {
            for (i = 0;i <= rear; i++)
            printf("%d\t",myCQ[i]);          
            for (i = front;i <= n - 1; i++)
            printf("%d\t", myCQ[i]);
            
            
        }
    }
}

int main()
{
    int choice;
    printf("enter the size if the linear queue\n");
    scanf("%d",&n);
    while(1){
        printf("\n*** CIRCULAR Q MENU ***\n");
        printf(">>1. Insert\n>>2. Delete\n>>3. Display\n>>4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            enQueue();
            break;
            case 2:
            deQueue();
            break;
            case 3: 
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("\nPlease select the correct choice!!!\n");
        }
    }
}