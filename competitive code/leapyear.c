#include<stdio.h>
int main()
{
      int year;
      scanf("%d",&year);
      
      if(((year%4)==0)&&((!((year%100)==0)))||((year%400)==0))
           printf("year is leap year");
           else
           printf("this is not a leap year");
           
           system("pause");
           return 0;
      
      }
