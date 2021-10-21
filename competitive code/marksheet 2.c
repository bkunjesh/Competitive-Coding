#include<stdio.h>
int main()
{
    int p,c,m,t;
    printf("enter the marks of phy : \n");
    scanf("%d",&p);
    
    printf("enter the marks of chem. : \n");
    scanf("%d",&c);
    
    printf("enter the marks of math : \n");
    scanf("%d",&m);
    t=p+c+m;
    
    printf("total is %d\n",t);
    printf("pecentage is %d ",t/3);
  
system("pause");
return 0;  
}
