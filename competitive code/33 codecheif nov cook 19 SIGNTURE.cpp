#include<stdio.h> 
#include<stdlib.h> 
#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
int n,m;
int error(int n,int m,vector<vector<int>> a,vector<vector<int>> b,int dr,int dc)
{
    int terror=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i+dr<0||j+dc<0)
            {
                if((a[i][j])!=0)
                terror++;
            }
            else if(a[i][j]!=b[i+dr][j+dc])
            terror++;
        }
    }
    return terror;
}

int main()
{     int t;
     cin>>t;
     while(t--)
    {
        int element,n,m,dr,dc,minerro;
        cin>>n>>m;
        vector<vector<int>> a(n, vector<int>(m)),b(n, vector<int>(m));
        minerro=m*n;
        for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
          {
            cin>>element;
            a.at(i).push_back(element);
            cout<<a[i][j]<<" ";
          }
          cout<<endl;
       }
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
          {
            cin>>element;
            b[i].push_back(element);
            cout<<b[i][j]<<" ";
          }
          cout<<endl;
       }
        for(int i=-1*n;i<n;i++)
        {
            for(int j=-1*m;j<m;j++)
            if(minerro>error(n,m,a,b,i,j))
            minerro=error(n,m,a,b,i,j);
        }
        cout<<minerro<<endl;
        a.clear();
        b.clear();
    }    

    return 0;
}