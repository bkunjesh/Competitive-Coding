#include<stdio.h>
void main()
{
	char line[81],ch;
	int c=3;
     
    gets(line);
	printf("\n%*.*s\n",c+1,c,line);
	printf("\n%15.7s\n",line);
	printf("\n%-15.9s\n",line);
	printf("\n%7.5s\n",line);
	printf("\n%7.7s\n",line);
	printf("\n%7.9s\n",line);
	printf("\n%5.9s\n",line);
	printf("\n%5.5s\n",line);
    printf("\n%5.3s\n",line);

}
