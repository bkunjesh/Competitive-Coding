#include<stdio.h>       
int main()
{   int i,j,len,n,min;
printf("enter the element ");
scanf("%d",&n);
len=2*n-1;
for(i=0;i<len;i++)
{
  for(j=0;j<len;j++)
 { 
   min=i>j?j:i;
   min=min<len-i-1?min:len-i-1;
   min=min<len-j-1?min:len-j-1;
   printf("%d",n-min);
 }
 printf("\n");
}
   system("pause");
      return 0;
}
