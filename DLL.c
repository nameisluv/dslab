#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;
Node *CreateElement()

{
    Node *newptr = (Node *)malloc(sizeof(Node));
    printf("Enter the element ");
    scanf("%d", &newptr->data);
    newptr->next = NULL;
    newptr->prev = NULL;
}

void InsertBegin()
{
    Node *newptr = CreateElement();

    if (head == NULL)
    {
        head = newptr;
        tail = newptr;
        return;
    }
    head->prev = newptr;
    newptr->next = head;
    head = newptr;
}

void InsertEnd()
{
    Node *ptr = tail;
    if(ptr==NULL){
        InsertBegin();
        return;
    }
    Node *newPtr =CreateElement();
    ptr->next = newPtr;
    newPtr->prev=ptr;
    tail = newPtr;
}

Node *Search(int data)
{
    Node *ptr = head;
    if (head == NULL)
        return NULL;
    while (ptr != NULL)
    {
        if (ptr->data == data)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

void InsertAny()
{
    if (head == NULL)
    {
        InsertBegin();
        return;
    }

    int pos, datapos;
    printf("Enter 0 for left and 1 for right ");
    scanf("%d", &pos);
    printf("enter the position whose adjacent is to be inserted ");
    scanf("%d", &datapos);

    Node *ptr = Search(datapos);

    if (ptr == NULL)
    {
        printf("element does not exist");
        return;
    }
    Node *newptr = CreateElement();

    if (pos == 0)
    {
        if (ptr == head)
        {
            newptr->next = head;
            head->prev= newptr;
            head = newptr;
            return;
        }

        Node *temp = ptr->prev;

        newptr->prev= temp;
        newptr->next = ptr;
        temp->next = newptr;
        ptr->prev= newptr;
        return;
    }

    if (pos == 1)
    {
        if(ptr==tail){
            ptr->next = newptr;
            newptr->prev = ptr;
            tail = newptr;
            return;
        }
        newptr->next = ptr->next;
        newptr->prev = ptr;
        ptr->next->prev = newptr;
        ptr->next = newptr;
    }
}

void Delete()
{

    Node *ptr = head;
    if (head == NULL)
    {
        printf("no elements exist");
        return;
    }
    int eee;
    printf("Enter data to delete\n");
    scanf("%d", &eee);

    Node *temp = Search(eee);
    if (temp == NULL)
    {
        printf("elements not exist");
        return;
    }
    if (temp == head)
    {
        
        head = head->next;
        head->prev = NULL;
        free(temp);
        return;
    }
    if(temp==tail){
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
        return;
    }
    ptr = temp->prev;
    temp->next->prev = ptr;
    ptr->next = temp->next;
    free(temp);
}

void Display()
{
    if (head == NULL)
    {
        printf("NOTHING TO DISPLAY");
        return;
    }
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void main(void)
{
    int ch;
    int ele;
    while (1)
    {
        printf("0. Menu\n1. Search an Element\n2. Insert at Beginning\n3. Insert at End\n4. Insert Any\n5. Delete\n6. Display\nEnter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {

        case 1:

            printf("Enter the data to search\n");
            scanf("%d", &ele);
            Node *a = Search(ele);
            if (a == NULL)
                printf("Element not present");
            else
                printf("Element present");
            break;
        case 2:
            InsertBegin();
            break;
        case 3:
            InsertEnd();
            break;
        case 4:
            InsertAny();
            break;
        case 5:
            Delete();
            break;
        case 6:
            Display();
            printf("\n");
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid input");
        }
    }
}
