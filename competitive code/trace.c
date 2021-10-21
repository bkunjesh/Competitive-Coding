#include<stdio.h>
int main()
{
    int a,m,i,tr;
    tr=0;
    printf("enter the value of m \n");
    scanf("%d",&m);
    for(i=1;i<=m;i=i+1)
    {
                          printf("enter %d,%d no. \n",i,i);
                          scanf("%d",&a);
                          
                          tr=tr+a;
                          }
                          printf("since the trace of matrix is %d ",tr);
    
    
    system("pause");
    return 0;
    }
