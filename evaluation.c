#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
float S[50];
int top=-1;
void push(float item)
{
	S[++top]=item;
}

float pop()
{
	return(S[top--]);
}
main()
{
	char postfix[50], ch;
	int i=0;
	float op1, op2;
	printf("\n Enter the postfix expression:\n");
	gets(postfix);
	while((postfix[i])!='\0')
	{   ch = postfix[i];
		if(isdigit(ch))
			push((float)(ch-'0'));
		else
		{
			op2=pop();
			op1=pop();			
			switch(ch)
			{
				case '+':
					push(op1+op2);
					break;			
				case '-':				
					push(op1-op2);
					break;				
				case '*':				
					push(op1*op2);
					break;				
				case '/':				
					push(op1/op2);
					break;				
				case '^':				
					push(pow(op1,op2));
					break;
			}
		}
		i++;
	}
printf("\n Given postfix expression is %s\n:", postfix);
printf("\n Result of Evaluation is %f\n", S[top]);
}