#include<stdio.h>
int main()
{
    int m,colindex,a,rowsum;
       rowsum=0;
        printf("enter the value of m\n");
        scanf("%d",&m);
    
    for(colindex=1;colindex<=m;colindex=colindex+1)
    {
                              printf("enter a no \n");
                              scanf("%d",&a);
                              rowsum=rowsum+a;
                               }
                               printf("hence the sum is %d ",rowsum);
                               
    
    system("pause");
    return 0;
    
           }
