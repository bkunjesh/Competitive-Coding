#include<stdio.h>
int iscoprime(int a,int b)
{
    int t;
    if(b>a){t=a;a=b;b=t;            
            }
            while(!(b==0)){
                           t=a;
                           a=b;
                           b=t%b;
                           }
                           if(a==1){return 1;}else{return 0;}                                                                                                                                                                                                                                        
    }
    
    int main()
    {
        int curr,pre,n,i,cnt;
        cnt=0;
        scanf("%d",&n);
        scanf("%d",&pre);
        for(i=2;i<=n;i++)
        {
                         scanf("%d",&curr);
                         
                         cnt=cnt+iscoprime(curr,pre);
                         pre=curr;
        }
        printf("no of succsesive coprime are %d",cnt);
        
        system("pause");
        return 0;
               }
