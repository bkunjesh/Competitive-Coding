#include<stdio.h>
main()
{
      int a;
      printf("enter the value of a:\n");
      scanf("%d",&a);
      
      if(((a%3)==0)&&((a%4)==0))
      {
                  printf("the input %d is divisibal by 3 and 4.\n",a);}
                  else
                  {
                      printf("input %d is not divisibal by 3 and 4.\n",a); }
  
  system("pause");
  return 0;    }
