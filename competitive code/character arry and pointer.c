#include<stdio.h>
#include<string.h>
void print(char *c)
{
     while(*c!='\0')
     {
                   printf("%c",*c);
                   c++;
                   }
printf("\n");
     }
     int main()
     {
         char c[20]="hello";
         print(c);
         
         
         system("pause");
         return 0;
         
         
         }
