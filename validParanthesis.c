#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char a[MAX];
int top=-1;
void push(char);
char pop();
void push(char ch)
{
	if(top==MAX-1)
        {
		printf("\nError:Stack Overflow\n");
		return;
	}
	top=top+1;
	a[top]=ch;
}
char pop()
{
	char c;
	if(top==-1)
		printf("\nError: No element in stack to pop\n");
	else
	{
		c = a[top];
		top = top-1;
	}
	return c;
}

int main()
{
	char a[MAX];
	char temp;
	int i,flag=1;
	printf("Enter paranthesis String: ");
	gets(a);
	for (i=0;i<strlen(a);i++)
	{
		if (a[i] == '{' || a[i] == '(' || a[i] == '[')
			push(a[i]);
		if (a[i] == '}' || a[i] == ')' || a[i] == ']')
		{
			if (top == -1)
				flag = 0;
			else
			{
				temp = pop();
				if (a[i] == '}' && (temp == '(' || temp == '['))
					flag = 0;
				if (a[i] == ')' && (temp == '{' || temp == '['))
					flag = 0;
				if (a[i] == ']' && (temp == '{' || temp == '('))
					flag = 0;
			}
		}
	}
	if (top >= 0)
		flag = 0;
	if (flag == 1)
		printf("\nValid Paranthesis\n");
	else
		printf("\nValid Paranthesis\n");
}		
