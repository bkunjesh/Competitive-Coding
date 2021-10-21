#include<stdio.h>
int main()
{int a,i,j,n,sum;
scanf("%d",&n);
sum=0;
for(i=1;i<=n;i++)
{
                   for(j=1;j<=n;j++)
                   {
                                      scanf("%d",&a);
                                      if(i==j)
                                      {sum=sum+a;
                                             }
                                      
                                      }
                   }
                   printf("%d",sum);
                   system("pause");
                   return 0;
    }
