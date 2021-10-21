#include<stdio.h>
int main()
{int i,n,ppre,pre,cur,count;
count=0;
scanf("%d",&n);

for(i=0;i<n;i=i+1)
{
                  scanf("%d",&cur);
                  if(cur<=0){continue;}
                  if(count==0)
                  {
                            ppre=cur;count=1;
                            }
                            else
                            {
                                if(count=s=1)
                                {pre=cur;count=2;
                                           }
                                           else
                                           {
                                               if((ppre*ppre)+(pre*pre)==(cur*cur))
                                               {printf("%d%d%d",ppre,pre,cur);}
                                      ppre=pre;
                  pre=cur;              }
                        
                    }
                            
                            
                  }
    
    
   system("pause");return 0; }
