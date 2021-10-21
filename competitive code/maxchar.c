#include<stdio.h>
int main()
{int i,maxchar;
 char current='\n';
 char previous;
 
 scanf("%d",&maxchar);
 scanf("%c",&previous);
 for(i=0;i<maxchar;i=i+1)
 {previous=current;
 scanf("%c",&current);
 if((previous=='\n')&&(current=='\n'))
 {break;  }
                          }

printf("hence no of char is %d",i);
system("pause");
return 0;
    }
