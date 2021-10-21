#include<stdio.h>
main()
{
      char s[7];
      char ch;
      int i,count,n;
      
      
      for(i=1;i<8;i++){
                       
                       ch=getchar();
                       s[i]=ch;
                       }
                       for(i=0;(count=7-i)&&i<8;i++)
                       {printf("%c",s[count]);
                                                   
                                                   }
                                                   system("pause");
                                                   return 0;
      
      
      }
