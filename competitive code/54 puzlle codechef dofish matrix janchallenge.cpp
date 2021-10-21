#include<stdio.h> 
#include<stdlib.h> 
#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
#define ull unsigned long long
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define vect_ll vector<long long> 
#define vect_ll_it vector<long long>::iterator
int board[2001][2001];
ll i,j,k,n;

//int cansolvefromcell(ll ,ll ,ll,int );
//int canplacevalue(ll ,ll ,ll ,int ,ll );

//constarint
int canplacevalue(ll row,ll col,ll n,int board[2001][2001],ll valuetoplace)
{
    for(i=0;i<n;i++)
    {
        if(board[i][col]==valuetoplace)
        return false;
        if(board[col][i]==valuetoplace)
        return false;
        if(board[row][i]==valuetoplace)
        return false;
        if(board[i][row]==valuetoplace)
        return false;
    }
    return true;
}
// value choice
int cansolvefromcell(ll row, ll col,ll n,int board[2001][2001])
{
    if(col==n)
    {
        col=0;
        row++;
        
        if(row==n)
        return true;
    }
    
    for (int valuetoplace = 1; valuetoplace <= 2*n-1; valuetoplace++) 
    {
        if(canplacevalue(row,col,n,board,valuetoplace))
        {
            board[row][col]=valuetoplace;
            if(cansolvefromcell(row,col+1,n,board))
            return true;
            
        }
        
    }
    return false;
}

int solve(ll n,int board[2001][2001])
{
    return cansolvefromcell(0,0,n,board);
}


int main()
{
	fast
	int t;cin>>t;
	while(t--)
	{
		ll n; cin>>n;
		f(i,n)
		f(i,n)
		board[i][j]=0;
		//int board[n][n];
		if(solve(n,board))
		{
		    cout<<"Hooray"<<endl;
		    for(i=0;i<n;i++)
		    {
		    	for( j=0;j<n;j++)
		    	cout<<board[i][j]<<" ";
				cout<<endl;			}
		}
		else
		cout<<"Boo"<<endl;
	}
	
	return 0;
}
