#include<iostream>
using namespace std;
//*********WRITE AN ANOTHER CLEAN AND READABLE CODE..THIS IS NOT CLEAN CODE******************
int knapsack(int weight[],int value[],int n,int m)
{
	int table[n][m+1];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			if(i==0&&j>=weight[i])
			table[i][j]=value[i];
			else if(i==0&&j<weight[i])
			table[i][j]=0;
			else if(j<weight[i])
			table[i][j]=table[i-1][j];
			else if(j>=weight[i])
			{			
				if(value[i]+table[i-1][j-weight[i]]>table[i-1][j])
				{
					table[i][j]=value[i]+table[i-1][j-weight[i]];
				}
				else
				table[i][j]=table[i-1][j];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m+1;j++)
	    cout<<table[i][j]<<" ";
	    cout<<endl;
	}
	return table[n-1][m];
}
int main()
{
	/*int weight[]={2,3,5,7,1,4,1};
	int value[]={10,5,15,7,6,18,3};*/
	int weight[]={5,3,4,2};
	int value[]={60,50,70,30};
	int n=sizeof(weight)/sizeof(weight[0]);
	int m=5;
	cout<<knapsack(weight,value,n,m);
}
