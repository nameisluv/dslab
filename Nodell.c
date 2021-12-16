#include <stdio.h>
#include<stdlib.h>
#define MALLOC(p,n,type) \
p=(type*)malloc(n*sizeof(type)); \
if(p==NULL){ \
    printf("Insufficient memory \n"); \
    exit(0); \
}

struct node{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE insert(int item,int pos,NODE first){
    NODE temp,cur;
    MALLOC(temp,1,struct node);
    temp->info=item;
    temp->link=NULL;
    if(pos==1){
        temp->link=first;
        return temp;
    }
    if(first==NULL){
        printf("Cannot insert at this position since Empty list\n");
        return first;
    }
    NODE prev=NULL;
    cur=first;
    int count=1;
    while (cur!=NULL)
    {
        prev=cur;
        cur=cur->link;
        count++;
        if(count==pos){
            break;
        }
    }
    if(pos>count){
        printf("Cannot insert at this position \n");
        return first;
    }
    temp->link=cur;
    prev->link=temp;
    return first;        
}

NODE delete(int pos,NODE first)
{
    if(first==NULL){
        printf("Empty list \n");
        return first;
    }
    NODE temp;
    NODE cur;
    if(pos==1){
        printf("Element deleted is %d \n",first->info);
        temp=first;
        first=first->link;
        free(temp);
        return first;
    }
    int count=1;
    cur=first;
    NODE prev=NULL;
    while (cur!=NULL)
    {   prev=cur;
        cur=cur->link;
        if(cur!=NULL)
            count++;
        if(count==pos){
            break;
        }
    }
    if(pos>count){
        printf("Cannot enter in this position \n");
        return first;
    }
    printf("Element deleted is %d \n",cur->info);
    prev->link=cur->link;
    free(cur);
    return first;
}

NODE display(NODE first){
    if(first==NULL){
        printf("Empty list\n");
        return first;
    }
    NODE cur;
    cur=first;
    while(cur!=NULL){
        printf("%d ",cur->info);
        cur=cur->link;
    }
    printf("\n");
    return first;
}

void main(){
    int item,ch,pos;
    NODE first=NULL;
    printf("1.Insert at pos 2.delete  3.display 4.exit \n");
    while(1){
        printf("Enter a choice \n");
        scanf("%d",&ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            printf("Enter an element to insert\n");
            scanf("%d",&item);
            printf("Enter the position to insert \n");
            scanf("%d",&pos);
            first=insert(item,pos,first);
            break;

        case 2:
            printf("Enter element pos to delete \n");
            scanf("%d",&pos);
            first=delete(pos,first);
            break;

        case 3:
            first=display(first);
            break;
        
        case 4:
            exit(0);

        default:
            printf("Wrong choice\n");
            break;
        }
    }
}
