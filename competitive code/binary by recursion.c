#include<stdio.h>
#include<conio.h>
int rec(int num)
{ int b;
    if(num==0)
    {
    return 0; }
    
    b=num%2;
    num=num/2;
    rec(num);
    printf("%d",b);
    
    }
    int main()
    {
    int n;
    scanf("%d",&n);
    if(n==0)
    printf("0");
    else
    rec(n);
    
    
    getch();
    return 0;
    
    }
