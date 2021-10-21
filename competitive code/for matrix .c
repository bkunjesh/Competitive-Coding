#include<stdio.h>
int main()
{
    int a,m,n,rowindex,colindex,rowsum,rowsumsq;
    rowsumsq=0;
    printf("enter the value m,n :\n");
    scanf("%d%d",&m,&n);
    
    for(rowindex=1;rowindex<=n;rowindex=rowindex+1)
    {
                                                   colindex=1;rowsum=0;
                                                   for(colindex=1;colindex<=m;colindex=1+colindex)
                                                   {
                                                                                                  printf("enter a no. \n");
                                                                                                  scanf("%d",&a);
                                                                                                  rowsum=rowsum+a;
                                                                                                  
                                                                                                  
                                                                                                  }
                                                                                                  rowsumsq=(rowsum*rowsum) + rowsumsq;
                                                   }
                                                   
                                                   printf("row square sum is %d",rowsumsq);
    
    system("pause");
    return 0;
    }
