#include<stdio.h>
int read_next_line();

int read_all_line() 
{
    int linecnt=0;
    int isline;
    
    while(!feof(stdin)){
                        isline=read_next_line();
                        linecnt=linecnt+isline;
                        }
    return linecnt;    }
    
int read_next_line()
{
    
    int ch;
    
    int flag=0;
    ch=getchar();
    while(ch!=EOF&&ch!='\n'){
                             ch=getchar();
                             flag=1;
                             }

                          return flag||(ch=='\n');
                            /* if(flag==1||(ch=='\n')){
                                                     return 1;}  else{return 0;} */
}

int main()
{read_all_line();
system("pause");
return 0;
}
