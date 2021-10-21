#include<stdio.h>
int main()
{
    int a,m,n,colindex,rowindex,rowsum,rowsumsq;
    scanf("%d%d",&m,&n);
    rowsumsq=0;rowindex=1;
    while(!(rowindex>m))
    {
                        
                     colindex=1;rowsum=0;
                     while(!(colindex>n))
                     {
                                     scanf("%d",&a);
                                     rowsum=rowsum+a;
                                     colindex=colindex+1;
                                     
                                      }
                                      rowsumsq=rowsumsq+(rowsum*rowsum);
                                      rowindex=rowindex+1;
                     }
                     printf("rowsumsq is %d",rowsumsq);
                     
                     system("pause");
                     return 0;
    
    
    
    }
