#include<stdio.h>
int main()
{
    int a,sum=0;
    while(1)
    {
            scanf("%d",&a);
            if(a==-1){
                      break;}
                      sum=sum+a;
            }
            printf("%d",sum);
            
            system("pause");
            return 0;
            
    }
