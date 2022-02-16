#include <stdio.h>
#include <ctype.h>
#define length 50
int top = -1;
char s[50];
char infix[length],postfix[length];;
void push(char item)
{
    s[++top] = item;
}

char pop()
{
    char item_del;
    item_del = s[top--];
    return item_del;
}

int priority(char symbol)
{
    switch (symbol)
    {

    case '#':
        return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
    case '%':
        return 3;
    case '$':
    case '^':
        return 4;
    }
}

void infix_to_postfix()
{  
    char symbol;
    int j=0;
    push('#');
    for(int i=0;infix[i]!='\0';i++)
    {   symbol = infix[i];
        if (symbol == '(')
            push(symbol);

        else if (isalnum(symbol))
            postfix[j++] = symbol;

        else if (symbol == ')')
        {
            while (s[top] != '(')
                postfix[j++] = pop();
                pop();
        }
        else
        {
            while (priority(s[top]) >= priority(symbol))
                postfix[j++] = pop();

            push(symbol);
        }
    }

    while (s[top] != '#')
    postfix[j++] = pop();
    postfix[j] = '\0';
}

void main()
{   
    printf("enter valid infix expression ");
    scanf("%s", infix);

    infix_to_postfix();
    printf("entered infix expression %s \n", infix);
    printf("converted postfix expression %s", postfix);
}
