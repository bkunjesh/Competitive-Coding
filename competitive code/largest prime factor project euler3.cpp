#include<stdio.h>
#include<math.h>
int prime(unsigned long long  i)
{
	for(unsigned long long  j=2;j<i;j++)
	{
		if(fmod(i,j)==0)
		return 0;
	}
	return 1;
}
int max(int i,int j)
{
	int max=i>j?i:j;
	return max;
 } 
int main()
{
unsigned long long  largeprimefact,n;
	scanf("%llu",&n);
	//printf("%llu",n);
//	printf("%f",sqrt(n));
	for(int i=2;i<sqrt(n);i++)
	{
			//printf("cfghj");
		if(fmod(n,i)==0)
		{
			//printf("cfghj");
			if(prime(i)) largeprimefact=i;
			if(prime(n/i)) largeprimefact=n/i;
	//	if(prime(i)&&prime(n/i)) largeprimefact=max(i,n/i);
		}

	}
	printf("%llu",largeprimefact);
}
