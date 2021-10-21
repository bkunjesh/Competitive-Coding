#include<stdio.h>
#include <windows.h>

void gotoxy(short x, short y)           //definition of gotoxy function//                                               
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void pat(int p)
{
     int s,i,j,k;
s=0;

for(i=1;i<=4;i++)
{
                 
                 for(j=1;j<=4-i;j++)
                 {
                                    printf(" ");}
                 printf("|");
                 for(k=1;k<=s;k++)
                 {printf(" ");}
                                  printf("|");
                             s=s+2;
                             
                 for(j=1;j<=4-i;j++)
                 {printf(" ");}
                 printf("\n");

     
}
     gotoxy(p*8,0);
     p=p+1;
     pat(p);            
}
int main()
{
    int p=1;
    pat(p);
    
    system("pause");
    return 0;
    }
