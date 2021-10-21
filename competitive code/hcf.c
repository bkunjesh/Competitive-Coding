#include<stdio.h>
int main()
{
    int a,b,t,x,y,lcm;
    scanf("%d%d",&a,&b);
     x=a;
               y=b;
    while(y!=0)
    {
              
               t=x;
               x=y;
               y=t%y;
               }
    printf("%d",x);
    
    
    system("pause");
    return 0;
    }
