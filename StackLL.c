// stack using linked list 
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
    printf("Enter the data");
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

void delete(){
    if(head==NULL)
      printf("stack is empty");
    else if(head->next==NULL){
      free(head);
      head=NULL;
    }
    else{
        ptr=head;
        while(ptr->next!=NULL){
            temp=ptr;
            ptr=ptr->next;
        }
        free(ptr);
        temp->next=NULL;
    }
}

void display(){
     if(head==NULL)
      printf("stack is empty");
    else{
        ptr=head;
        while(ptr!=NULL){
            printf("\t %d -> ",ptr->data);
            ptr=ptr->next;
        }
    }
}



void main(){
        int ch;
    printf("\nMenu\n1.push\n2.pop\n3.display\n4:exit");
    while(1){
        printf("\nEnter choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:insert();
                    break;
            case 2:delete();
                    break;
            case 3:display();
                    break;
            case 4:exit(0);
}
}
}
