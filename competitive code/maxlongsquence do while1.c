#include<stdio.h>
main()

{
      int cur,pre,len,maxlen;
      scanf("%d",&pre);
      maxlen=1;len=1;
      if(pre!=-1)
      {
      do
      {
                       scanf("%d",&cur);
                       if(cur>pre)
                       {len=len+1;maxlen=len;}
                       else
                       {if(maxlen<len)
                       {maxlen=len;}
                       len=1;}
      pre=cur;
                       }
                       while(cur!=-1);
                       }
      printf("%d\n",maxlen);
      
      system("pause");
      return 0;
      
      }
