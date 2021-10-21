#include<stdio.h>
int binary_search(int* pos,int low,int high,int data)
{
	int mid=(low+high)/2;
	
	if(high<low)
	return 0;
	if(pos[mid]==data)
	return 1;
	else if(pos[mid]>data)
	return binary_search(pos,low,mid-1,data);
	else if(pos[mid]<data)
	return binary_search(pos,mid+1,high,data);
	
}
void print(int a[3][3])
{  int i,j;
	 for(i=0;i<3;i++)
	 {
	    for(j=0;j<3;j++)
		  { printf("%4d |",a[i][j]);
          }
        printf("\n");
     }
}

int check(int a[3][3])
{
	int i,j=0;
	for(i=0;i<3;i++)
	{
		if(((a[i][j]==a[i][j+1])&&(a[i][j+1]==a[i][j+2]))||
		((a[j][i]==a[j+1][i])&&(a[j+1][i]==a[j+2][i]))||
		((a[j][j]==a[j+1][j+1])&&(a[j][j]==a[j+2][j+2]))||
		((a[1][1]==a[0][2])&&(a[1][1]==a[2][0])))
         {
		 return 1;
		 }
	}
     return 0;
}

int main()
{  int a[3][3],i,j,position;
   int pos[9]={11,12,13,21,22,23,31,32,33};
	int c,k=1;
 printf(" ***tic tac toe***\nchoose a no. to mark your position\nlet's begin\n");
 for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{   a[i][j]=((i+1)*10)+(j+1);
			printf("%4d |",a[i][j]);
		}
		printf("\n");
    }
  int attemp=1;
  while(attemp<10)	
  {
	
  k=(!k);     //player turn count
  again:
  printf("\nplayer-%d turn,\nchose ur position: \n",k+1);
  scanf("%d",&position);
  i=position/10;
  j=position%10;
  if(a[i-1][j-1]==0||a[i-1][j-1]==1||(!(binary_search(pos,0,8,position))))  //chech for if position is already occupied or not!!!
  {
  	printf("\nenter valid position\n");
  	goto again;
  }
  a[i-1][j-1]=k;
  print(a);
  c=check(a);      // check for winning condition
  if(c)        
  {
  	printf("\nplayer %d win\n",k+1);
  	break;
  }
  attemp++;
  if(attemp>9)     // whole board is filled and no one is winner
  printf("\nno one is winner\n");
 }  
}
