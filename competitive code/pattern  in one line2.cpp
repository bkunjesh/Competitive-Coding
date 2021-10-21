#include<stdio.h>
main()
{
	char ch[]={"*****************"};
	for(int i=0;i<5;i++)
	{
		printf("%5.*s",i+1,ch);
		printf("%-10.*s\n",i,ch);
	}
    for(int i=0;i<4;i++)
    {
    	 printf("%5.*s",4-i,ch);
		printf("%-10.*s\n",3-i,ch);
	}
}
