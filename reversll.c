#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, n,type)  ((p) = (type*)malloc((n) * sizeof (type)));

struct node{
        int info;
        struct node *link;
};

typedef struct node *NODE;

NODE insert_rear(NODE head,int item){
    NODE temp,cur;
    MALLOC(temp,1,struct node);
    temp->info=item;
    temp->link=NULL;
    if(head==NULL)
        return temp;
    cur=head;
    while(cur->link!=NULL)
        cur=cur->link;
    cur->link=temp;
    return head;
}

void display(NODE head){
    NODE cur;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    cur=head;
    printf("The contents of the list:\n");
    while(cur!=NULL){
        printf("%d ", cur->info);
        cur=cur->link;
    }
    printf("\n");
}

NODE reverse(NODE head){
    NODE prev, cur, next;
    prev=NULL;
    cur=head;

    while(cur!= NULL){
        next=cur->link;
        cur->link=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}
int main(){
    int i,n,t;
    NODE head=NULL;
    printf("Enter the number of the elements to be reversed\n");
    scanf("%d",&n);
    printf("Enter the elements to be reversed\n");
    for(i=0;i<n;i++){
        scanf("%d", &t);
        head=insert_rear(head,t);
    }
    printf("Before reversal:\n");
    display(head);
    head=reverse(head);
    printf("After reversal:\n");
    display(head);
}
