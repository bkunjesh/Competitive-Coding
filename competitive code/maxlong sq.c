#include<stdio.h>
main()
{int pre,curr,len,maxlen;
scanf("%d",&pre);
if(pre!=-1)

{   len=1;maxlen=1;
           scanf("%d",curr);
           while(curr!=-1)
           {
                          if(curr>pre)
                          {len=len+1;}
                          
                          else{
                               if(maxlen<len)
                              { maxlen=len;}
                              
                              len=1;}
                              pre=curr;
                              scanf("%d",&curr);
                              
                              if(maxlen<len)
                              {maxlen=len;}
                              }
                              printf("%d",maxlen);
                              

                              system("pause");
                              return 0;        
                               
                          

      
      
      
}     }
