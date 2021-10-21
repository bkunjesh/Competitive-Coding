#include<stdio.h>
int main()
{
    int a,m,n,rowindex,colindex,rowsum,rowsumsq;
    
    rowsumsq=0;
    rowindex=1;
    
    printf("enter the value of m and n \n");
    scanf("%d%d",&m,&n);
    while(!(rowindex>n))
    {
                        colindex=1;
                        rowsum=0;
                        while(!(colindex>m))
                        {
                                            printf("enter a no. \n");
                                            scanf("%d",&a);
                                            rowsum=rowsum+a;
                                            colindex=colindex+1;
                                            
                                            }
                                            rowsumsq=(rowsum*rowsum)+rowsumsq;
                                            rowindex=rowindex+1;
                        }
                        printf("hence the rowsumsq is %d",rowsumsq);
                        
                        system("pause");
                        return 0;
                        
                        
      }
