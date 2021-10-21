#include<stdio.h>
int main()
{int i,maxchar;
 char current='\n';
 char previous;
 
 scanf("%d",&maxchar);
 getchar();
 for(i=0;i<maxchar;i=i+1)
 { previous=current;
   current=getchar();
     if((previous=='\n')&&(current=='\n'))
             {break;  }
 }

printf("hence no of char is %d",i);
system("pause");
return 0;
    }
