#include<stdio.h>
#include<string.h>
main()
{
	char line[]="********************";
	for(int i=0;i<7;i++)
	{
		printf("%7.*s\n",i+1,line);
	}
		for(int i=7;i>0;i--)
	{
		printf("%7.*s\n",i-1,line);
	}
}
