#include<stdio.h>
#include<conio.h>
int main()
{
    int i=4,j;
    j=++i*i++;
    i*=j;
    printf("%d\n%d",i,j);
    getch();
    return 0;
    
    
    }
