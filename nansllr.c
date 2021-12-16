#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

node *create()
{
    node *newptr = (node *)malloc(sizeof(node));
    printf("enter the data");
    scanf("%d", &newptr->data);
    newptr->next = NULL;
}

void insertbegin()
{
    node *newptr = create();

    if (head == NULL)
    {
        head = newptr;
        return;
    }
    newptr->next = head;
    head = newptr;
}

void insertafter()
{
    if (head == NULL)
    {
        insertbegin();
        return;
    }

    node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = create();
}

node *search(int data)
{
    node *ptr = head;
    if (ptr == NULL)
    {
        return NULL;
    }
    while (ptr != NULL)
    {
        if (ptr->data == data)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

void insertany()
{
    if (head == NULL)
    {
        insertbegin();
        return;
    }

    int pos, datapos;
    printf("enter 0 for left and 1 for right");
    scanf("%d", &pos);
    printf("enter the adjacent number");
    scanf("%d", &datapos);

    node *ptr = search(datapos);

    if (ptr == NULL)
    {
        printf("no element found");
        return;
    }
    node *newptr = create();
    if (pos == 0)
    {
        if (ptr == head)

        {
            newptr->next = head;
            head = newptr;
            return;
        }

        node *temp = head;
        while (temp->next != ptr)
        {
            temp = temp->next;
        }
        temp->next = newptr;
        newptr->next = ptr;
        return;
    }

    if (pos == 1)
    {
        newptr->next = ptr->next;
        ptr->next = newptr;
    }
}

void delete ()
{
    if (head == NULL)
    {
        printf("no element to delete");
        return;
    }
    int ee;
    printf("enter the element to delete");
    scanf("%d", &ee);

    node *temp = search(ee);
    if (temp == head)
    {
        head = head->next;
        free(temp);
        return;
    }
    node *ptr = head;
    while (ptr->next != temp)
        ptr = ptr->next;
    ptr->next = temp->next;
    free(temp);
}

void display()
{
    if (head == NULL)
    {
        printf("empty");
    }
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d \n ", ptr->data);
        ptr = ptr->next;
    }
}

void main(void)
{
    int ch;

    while (1)
    {
        printf("\n 1 insertbegin \n 2 insetafter \n 3 insertany \n 4 delete \n 5 display");
        printf(" \n enter your choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insertbegin();
            break;
        case 2:
            insertafter();
            break;
        case 3:
            insertany();
            break;
        case 4:
            delete ();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        }
    }
}
