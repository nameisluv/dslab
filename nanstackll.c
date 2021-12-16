
# include <stdio.h>
# include <stdlib.h>

typedef struct node
{
    int data;
    struct node*next;
}node;
int data;

node *head=NULL;
node *temp=NULL;
node *ptr=NULL;

void create()
{
    temp=(node*)malloc(sizeof(int));
    printf("enter the data");
    scanf("%d",&temp->data);
    temp->next=NULL;

    if(head==NULL)
    head=temp;

    else{
        ptr=head;
        while(ptr->next!=NULL)
        
            ptr=ptr->next;
        
            ptr->next=temp;
    }
}

void delete()
{
    if(head==NULL)
    {
        printf("empty");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else{
        ptr=head;
        while(ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        free(ptr);
        temp->next=NULL;
    }
}


void display()
{   node *ptr=NULL;
    if(head==NULL)
    {
        printf("nothing to display");
    }
    else{
        ptr=head;
        while(ptr!=NULL)
        {
            printf("%d",ptr->data);
            ptr=ptr->next;
        }

    }
}


void main()
{
    int ch;
    while(1)
    {
        printf("\n 1 insert \n 2 delete \n 3 display \n 4 exit\n");
        printf("enter your choice ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: create();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
        }
    }
}
