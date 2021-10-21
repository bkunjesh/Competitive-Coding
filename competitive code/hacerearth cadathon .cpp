#include<stdio.h>

int ans(int year,int t[3])
{
	int res;
	if(year==0|year==1|year==2)
	{
		return t[year];
	}
	res=ans(year-3,t)*3+year*2+ans(year-1,t);
	
	return res;
}


int main()
{
	int q,t[3],year,res;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		//printf("\n1");
		for(int j=0;j<3;j++)
		{
			//printf("\n2");
			scanf("%d",&t[j]);
			
		}
		scanf("%d",&year);
		res=ans(year,t);
		printf("%d\n",res%1000000007);
		
	}
	
}
