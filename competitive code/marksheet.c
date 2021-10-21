#include<stdio.h>
int main()
{int p,c,m,t;
    printf("enter the marks of phy : \n");
    scanf("%d",&p);
    
    printf("enter the marks of chem. : \n");
    scanf("%d",&c);
    
    printf("enter the marks of math : \n");
    scanf("%d",&m);
    t=p+c+m;
    
    printf("total is %d\n",t);
    printf("pecentage is %d%c ",t/3,37);
    
  
  if(t/3>60&&t/3<70)
  printf("pass\ngrade D\n");
  if (t/3>70&&t/3<80)
  printf("pass\ngrade C\n");
  if(t/3>80&&t/3<90)
  printf("pass\ngrade B\n");
  if(t/3>90&&t/3<100)
  printf("pass\ngrade A\n");
  
  if(t/3<60)
  printf("fail\n");
 
 
 
 
 system("pause");
  return 0;   
    }
