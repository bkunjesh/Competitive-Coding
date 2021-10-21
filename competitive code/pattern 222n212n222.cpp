#include<stdio.h>
main()
{
	int n,i,j,v,h;
	scanf("%d",&n);
	printf("\n");	
	for(i=0;((i<(2*n-1))&&(i<n-1?v=n-i:v=i-n+2));i++)
    {
    	for(j=0;((j<(2*n-1))&&(j<n-1?h=n-j:h=j-n+2));j++)
		{
			if(v>h)
			printf(" %d",v);
			else
			printf(" %d",h);
		}
		printf("\n");
	}
	
}
