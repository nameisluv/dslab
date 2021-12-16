#include<stdio.h>
#include<stdlib.h>

#define MALLOC(p,n,type) \
p=(type*)malloc(n*sizeof(type)); \
if(p==NULL){ \
    printf("Insufficient memory \n"); \
    exit(0); \
} \

struct node{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE enq(int item,NODE first){
    NODE temp;
    MALLOC(temp,1,struct node);
    NODE cur;
    temp->info=item;
    temp->link=NULL;
    if(first==NULL){
        first=temp;
        return first;
    }
    cur=first;
    while (cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=temp;
    return first;
}

NODE deq(NODE first){
    if(first==NULL){
        printf("Empty list\n");
        return first;
    }
    NODE temp;
    temp=first;
    first=first->link;
    printf("Deleted element is %d \n", temp->info);
    free(temp);
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
    int item,ch;
    NODE first=NULL;
    printf("1.enqueue 2.dequeue 3.display 4.exit \n");
    while(1){
        printf("Enter a choice \n");
        scanf("%d",&ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            printf("Enter an element\n");
            scanf("%d",&item);
            first=enq(item,first);
            break;

        case 2:
            first=deq(first);
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
