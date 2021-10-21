#include<stdio.h>
int main()
{  
    int cur,pre,len,maxlen;
    scanf("%d",&pre);
    if(pre!=-1)
    {len=1;maxlen=1;
    scanf("%d",&cur);
    while(cur!=-1)
    {
     if(cur>pre)
    {len=len+1;}
    else{if(maxlen<len)
    {maxlen=len;}
    len=1;
         }
         pre=cur;
         scanf("%d",&cur);
    }
    if(maxlen<len)
    maxlen=len;
    printf("%d",maxlen);
    
    system("pause");
    return 0;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    }
