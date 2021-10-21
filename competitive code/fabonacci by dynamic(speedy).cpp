#include<stdio.h>
int fab_bottum_up(int n)
{
	if(n==1||n==2)
	return 1;
	int fab[n+2];
	fab[1]=1;
	fab[2]=1;
	for(int i=3;i<=n;i++)
	fab[i]=fab[i-1]+fab[i-2];
	int result=fab[n];
	return result;
}
int main()
{
	printf("%d\n",fab_bottum_up(5));
	printf("%d\n",fab_bottum_up(6));
}
