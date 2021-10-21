#include<stdio.h>
int main()
{
    int a;
    printf("enter a no: \n");
    scanf("%d",&a);
    if((a%6)==0)
    {printf("input %d is divisibal by 6\n",a);}
    else
    {printf("%d is not divisibal by 6\n",a);}
    
    system("pause");
    return 0;
     
    }
