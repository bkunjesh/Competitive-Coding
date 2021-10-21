#include<stdio.h>
#include<string.h>
int top=-1;
char stack[15];
void push(char x)
{
	top=top+1;
	stack[top]=x;
}
void pop()
{
	top=top-1;
}
int check(char exp)
{
	if(stack[top]=='('&&exp==')')
	return 1;
	if(stack[top]=='{'&&exp=='}')
	return 1;
	if(stack[top]=='['&&exp==']')
	return 1;
	return 0;
}
int main()
{
	char exp[36]="([a+b]+{c+d}+f)";
	for(int i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
		{
			push(exp[i]);
		}
		if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
		{
			int a=check(exp[i]);
			pop();
			if(a==0)
			break;
		}
	}
	if(top==-1)
	printf("balenced");
	else
	printf("not balenced");
}
