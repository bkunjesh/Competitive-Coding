#include<stdio.h>
int i,j;
void respons(int a[][25],int d)
{
	for(int j=0;j<5;j++)
	{
		scanf("%d",&a[d][j]);
	}
}
int check(int *correct,int a[][25],int d)
{   int rcor=0,c=0;
	for(j=0;j<5;j++)
	{
		correct[j]==a[d][j]?rcor=rcor+1:(c++==0?printf("wrong que no. is : \n%d",j+1):printf("%4d",j+1));
 	}
	return rcor;
}

int main()
{
	int correct[25],s[3][25];
	
	for(int j=0;j<5;j++)
	{
		scanf("%d",&correct[j]);
	}
	for(int i=0;i<3;i++)
	{
		int j=0;
		printf("enter the response of stud-%d:\n",i+1);
		respons(s,i);
		printf("\nstud-%d got %d marks\n",i+1,check(correct,s,i));
	}
}


