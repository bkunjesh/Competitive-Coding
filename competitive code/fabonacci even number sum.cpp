#include<stdio.h>
int n,s,c;
int fab(int a,int b)
{
	if(c>n)
	return s+2;
	c=a+b;
	a=b;
	b=c;
	if(c%2==0)
	s+=c;
	fab(a,b);
}
int main()
{
	n=4000000;
	s=0;
	s=fab(1,2);
	printf("%d",s);
}
