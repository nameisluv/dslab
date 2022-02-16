// queue using linked list 
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head=NULL;
node *temp=NULL;
node *ptr=NULL;

void insert(){
    temp=(node*)malloc(sizeof(node));
    printf("\n Enter the data");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
       head=temp;
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=temp;
    }
}

void delete(){
    if(head==NULL)
     printf("Queue is empty");
    else if(head->next==NULL)
     {
         free(head);
         head=NULL;
     }
    else{
        temp=head;
        head=head->next;
        free(temp);
}
}

void display(){
    if(head==NULL)
      printf("Queue is empty\n");
    else{
      ptr=head;
      while(ptr!=NULL)
       {
           printf("\t %d --> ",ptr->data);
           ptr=ptr->next;
       }
    }
}

void main(){
    int ch;
    while(1){
        
		printf("\n Menu \n 1. Insert  \n 2. Delete  \n 3. Display  \n 4. exit : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert();
				break;
			case 2: delete();
				break;
			case 3: display();
				break;
			case 4: exit(0);

		}

    }
}
