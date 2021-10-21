#include<stdio.h>
int main()
{
    int count,num,a,b;
    
    count=0;
    scanf("%d",&num);
    scanf("%d",&a);
    while(num!=0)
    {
                 b=num%10;
                 num=num/10;
                 if(b==a)
                 {count=count+1;}
                 
                 }
    printf("\n%d",count);


 system("pause");
    return 0;
}
                 
    
    
