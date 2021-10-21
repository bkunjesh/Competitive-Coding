#include<stdio.h>
int main()
{
    char ch;
    int i;
    ch=getchar();
    
    if(ch>='a'&&ch<='z')
    {ch=ch-'a'+'A';}

    
    printf("%c\n",ch);
    
    system("pause");
    return 0;
    
    }
