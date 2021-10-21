#include<stdio.h>
int main()
{
 char bellch,vtabch,ch;
 bellch='\x7';
 vtabch='\xb';
 ch='\x41';
 printf("%c%c\n%c",bellch,vtabch,ch);
 system("pause");
 return 0;
}
