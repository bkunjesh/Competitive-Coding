#include<stdio.h>
int main()
{
	int car,a[4][4]={{0},{0},{0},{0}};
	char city;
	
	for(int i=0;i<100;i++)
	{
		scanf("%c",&city);
		if(city=='x')
		{ 
		   
		   break;
	    }
		scanf("%d",&car);
		switch(city)
		{
			case 'a': a[0][car-1]++;
			        break;
			case 'b': a[1][car-1]++;
			        break;
			case 'c': a[2][car-1]++;
			        break;
			case 'd': a[3][car-1]++;
			        break;				        
				}		
		
	}
	printf("  ");
	for(int i=1;i<5;i++)
	printf("%4d",i);
	printf("\n");
	printf("__________________________________________\n");
	char k='a';
	for(int i=0;i<4;i++)
	{
		printf("%1c |",k);
		k++;
		for(int j=0;j<4;j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
}
