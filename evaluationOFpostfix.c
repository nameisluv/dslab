#include <stdio.h>
#include <math.h>
#include <string.h>
int top = -1;
double stack[50];
void push(double item)
{
    stack[++top] = item;
}

double pop()
{
    double item;
    item = stack[top--];
    return item;
}

double evaluate(double op1, double op2, char symbol)
{
    switch(symbol){
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
        case '%':
            return (int)op1 % (int)op2;
        case '^':
        case '$':
            return pow(op1,op2);
    }
}

void main()
{
    char expression[50], symbol;
    double res, op1, op2;

    printf("\nEnter a valid postfix expression (avoid whitespaces): ");
    scanf("%s",expression);
	
    for(int i = 0; expression[i]!='\0' ; i++)
    {
        symbol = expression[i];
        if (symbol >= '0' && symbol <= '9')
        {   
            push(symbol - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();
            res = evaluate(op1,op2,symbol);

            push(res);
        }
        
    }
    res = pop();
    printf("\nResult : %lf",res);
}
