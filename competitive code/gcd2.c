#include<stdio.h>
int main()
{
    
    int a,b,t;
    scanf("%d%d",&a,&b);
    while((b>a))
    {t=a;
    a=b;
    b=t;}
    
    while(!b==0)
    {t=a;
    a=b;
    b=t%b;}
    
    printf("%d",a);  
    
    
    
    
    
    system("pause");
    return 0;
    }
