#include<stdio.h>
int main()
{
    int a,b;
    b=0;
    scanf("%d",&a);
    while(!(a==-1))
    {b=b+a;
    scanf("%d",&a);}
printf("sum is %d",b); 
 
    system("pause");
    return 0;
    
    }
