#include<stdio.h>
int main()

{
    int i;
    float recsum=0.0;
    for(i=1;i<=3;i=i+1)
    {
                         recsum=recsum+(1.0/i);
                         }
                         printf("sum of reciprocal of 1 to 100 is %f",recsum);
    system("pause");
    return 0;
    
    }
    
    
