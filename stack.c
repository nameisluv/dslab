#include <stdio.h>
#include <stdlib.h>
int item,top=-1,s[10],n;
void push()
{
    if(top==n-1)
{
    printf("stack overflow\n");
    return;
}
 printf("enter the item to be inserted\n"); 
 scanf("%d",&item);
top=top+1;
s[top]=item;
}
int pop()
{
    if(top!=-1)
    return s[top--];
}
void display()
{
    if(top==-1)
    printf("stack is empty\n");
    else
    printf("contents of the stack are\n");
    for (int i = 0; i <=top ;i++)
    {
        printf("%d\t",s[i]);
    }
    printf("\n");
}
void main()
{
int choice;
printf("enter the size of the stack\n"); 
 scanf("%d",&n);
for(;;)
{
    printf(">>1 to push\n>>2 to pop\n>>3 to display\n>>4 to exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        push();
        break;
        
        case 2:
        if(top==-1)
        printf("stack is empty\n");
        else
        printf("item deleted = %d\n",pop());
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