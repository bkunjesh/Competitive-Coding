#include<stdio.h>
#include<string.h>
main()
{
	char string[5][10],cpy[1][10];
	for(int i=0;i<5;i++)
	{
		scanf("%s",&string[i]);
	}
    for(int i=5;i>0;i--)
	{
		for(int j=0;j<i-1;j++)
		{
			if(strcmp(*(string+j+1),*(string+j))<0)
			{
				strcpy(*(cpy),*(string+j));
				strcpy(*(string+j),*(string+j+1));
				strcpy(*(string+j+1),*(cpy));
			}
		}
	}
	printf("after rearranging");
	for(int i=0;i<5;i++)
	{
		printf("\n%s\n",string[i]);
	}
}
