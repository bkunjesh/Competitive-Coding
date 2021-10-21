#include<stdio.h>
int iscoprime(int a,int b)
{
    int t;
              if(a<b)
              {
                     t=a;a=b;b=t;
                     }
                     while(!(b==0))
                     {
                                   t=a;
                                   a=b;
                                   b=t%b;
                                   }
                                   if(a==1)
                                   return 1;
                                   else
                                   return 0;
              }

int main()
{
    int pre,cur,i,n,count;
    count=0;
    scanf("%d\n%d",&n,&pre);
    for(i=1;i<n;i++)
    { 
                    scanf("%d",&cur);
                    iscoprime(pre,cur);
                    count=count+iscoprime(pre,cur);
                    pre=cur;
                    
                    }
                    
                    
    printf("%d ",count);
    system("pause");
    return 0;
    }              
