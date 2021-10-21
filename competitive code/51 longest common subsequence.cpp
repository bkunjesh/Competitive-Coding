#include<iostream>
using namespace std;
int lcs(string a,string b)
{
	int m=a.length();
	int n=b.length();
	int l[m+1][n+1];
	for(int i=0;i<m+1;i++)
	for(int j=0;j<n+1;j++)
	{
		if(i==0||j==0)
		l[i][j]=0;
		else if(a[i]==b[j])
		l[i][j]=l[i-1][j-1]+1;
		else
		l[i][j]=max(l[i-1][j],l[i][j-1]);
	}
	// print
	int i=m,j=n;
	string Lcs="";
	while(l[i][j]!=0)
	{
		if(l[i-1][j]==l[i][j])
			i--;
		else if(l[i][j-1]==l[i][j])
			j--;
		else if(l[i][j]==l[i-1][j-1]+1)
		{
			i--;
			j--;
			Lcs=a[i]+Lcs;
		}
	}
	cout<<Lcs<<endl;
	return l[m][n];
}
int main()
{
	string a="abcdefg";
	string b="abcefzwq";
	cout<<lcs(a,b);
}
