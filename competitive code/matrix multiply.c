#include<stdio.h>

void mat(int a[3][3])
{ int i,j;
     for( i=0;i<3;i++)
     {
                     for(j=0;j<3;j++)
                     {
                        scanf("%d",&a[i][j]);}
                     }
     
     }


int main()
{
    int i,k,j,a[3][3],b[3][3],c[3][3];
    mat(a);
    printf("\n");
    mat(b);  
    for(i=0;i<3;i++)
    { 
                    
    
    
         for(j=0;j<3;j++)
         {
                         c[i][j]=0;
             for(k=0;k<3;k++)
             { c[i][j]+=a[j][k]*b[k][j];
              }
         }
         }
    
    
    for(i=0;i<3;i++)
     {
                     for(j=0;j<3;j++)
                     {
                        printf("%d",c[i][j]);
                     }
                     printf("\n");
    }
    
 getch();
 return 0;   
}    
    
    
