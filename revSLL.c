#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *ptr = NULL,*head = NULL,*temp;

void create(){
    if(head==NULL){
        head=(node*)malloc(sizeof(node));
        printf("Enter the data :");
        scanf("%d",&head->data);
        head->next=NULL;
        temp=head;
    }
    else{
         ptr=(node*)malloc(sizeof(node));
        printf("Enter the data :");
        scanf("%d",&ptr->data);
        ptr->next=NULL;
        temp->next=ptr;
        temp=temp->next;
    }
}

void reverse()
{
    struct node *prevNode, *curNode;

    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL; 

        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode;

        printf("SUCCESSFULLY REVERSED LIST\n");
    }
}

void display(){
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); 
            temp = temp->next;                
    }
}
}
void main(){
    int n,i;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        create();
    }
    display();
    reverse();
    display();
}
