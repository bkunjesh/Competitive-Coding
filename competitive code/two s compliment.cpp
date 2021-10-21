#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char a[15];
    int i,j;
     gets(a); 
     int len=strlen(a);
     //printf("%d",len);
     
     for(int k=0;k<len;k++)
     {
     	if(a[k]!='0'&&a[k]!='1')
     	{
     		printf("invalid no.  ");
     					 
			 exit(0);
		 }
	 }
	 
	 for(j=len-1;a[j]!='1';j--)
	 
	{
	  /// printf("%d\n",j);
	
	}
	   //printf("%d\n",j);

	  
	 
	 for(i=j-1;i>=0;i--)
	 {
	 //	printf("%d\n",i);
	 	if(a[i]=='0')
	 	{
		 a[i]='1';
		}
	 	else
	 	{
		 a[i]='0';
		}
	 }
printf("%s",a);

}
