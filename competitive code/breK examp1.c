#include<stdio.h>
main()
{         
      int maxchars;
      int i;
      char current='\n';
      char previous;
      
      scanf("%d",&maxchars);
      
      getchar();
      
      
      for(i=0;i<maxchars;i=i+1)
      {
                               previous=current;
                               current=getchar();
                               
                               if((current=='\n')&&(previous=='\n'))
                               {break;}
                               }
                               printf("%d\n",i);
                               
                               
                               system("pause");
                               return 0;
      
      
      }
