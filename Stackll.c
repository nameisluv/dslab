#include<stdio.h>
#include<stdlib.h>

#define MALLOC(p,n,type)    \
p=(type*)malloc(n*sizeof(type)); \
if(p==NULL){ \
    printf("Insufficient memory \n"); \
    exit(0);\
}  \

struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE push(int item, NODE first){
    NODE temp;
    MALLOC(temp,1,struct node);
    temp->info=item;
    temp->link=first;
    return temp;
}

NODE pop(NODE first){
    if(first==NULL){
        printf("Empty list \n");
        return NULL;
    }
    NODE temp;
    temp=first;
    first=first->link;
    printf("deleted item is %d\n",temp->info);
    free(temp);
    return first;
}

NODE display(NODE first){
    if(first==NULL){
        printf("Empty list \n");
        return NULL;
    }
    NODE temp;
    temp=first;
    while(temp!=NULL){
        printf("%d \n",temp->info);
        temp=temp->link;
    }
    return first;
}

void main(){
    int item,choice;
    printf("1.push 2.pop 3.display 4.exit  \n");
    NODE first=NULL;
    while (1)
    {
        printf("Enter your choice \n");
        scanf("%d",&choice);
        printf("\n");
        switch (choice){
            case 1:
                printf("Enter the item to push \n");
                scanf("%d",&item);
                first=push(item,first);
                break;
            
            case 2:
                first=pop(first);
                break;

            case 3:
                first=display(first);
                break;

            case 4:
                exit(0);

            default:
                printf("wrong choice \n");
        }
    }
    
}
