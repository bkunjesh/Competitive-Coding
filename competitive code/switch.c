#include<stdio.h>
int main()
{
    int n1,n2;
    char ch;
    scanf("%d%d",&n1,&n2);
    fflush(stdin);
    scanf("%c",&ch);
    switch(ch)
    {
              case '+': 
                   printf("%d",n1+n2);
              }
    
    system("pause");
    return 0;
    
    }
