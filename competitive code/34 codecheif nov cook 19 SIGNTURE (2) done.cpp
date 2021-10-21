#include<stdio.h> 
#include<stdlib.h> 
#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;

int main()
{     int t;
     cin>>t;
     while(t--)
    {
        int n,m,error,minerror,element,i,j,dr,dc;
        cin>>n>>m;
        string a[n],b[n];
        // scan array a and b
        for(i=0;i<n;i++)
        cin>>a[i];
        for(i=0;i<n;i++)
        cin>>b[i];
        //print a and b
       /* for(i=0;i<n;i++)
        cout<<a[i]<<" ";
        for(i=0;i<n;i++)
        cout<<b[i]<<" ";*/
        // find error
        minerror=m*n;
        for(dr=-1*n;dr<n;dr++)
        {
            for(dc=-1*m;dc<m;dc++)
            {
                //check error
                error=0;
                for(i=0;i<n;i++)
                {
                    for(j=0;j<m;j++)
                    {
                        //cout<<" dr="<<dr<<" dc="<<dc<<" "<<" i="<<i<<" j="<<j<<" i+dr="<<i+dr<<"j+dc="<<j+dc<<" error="<<error<<endl;
                        //cout<<b[i][j]<<" ";
                        if(i+dr<0||j+dc<0||i+dr>=n||j+dc>=m)
                        {
                            if(a[i][j]!='0')
                            error++;
                        }
                        else if(a[i][j]!=b[i+dr][j+dc])
                        error++;
                    }
                }
                //cout<<"error= "<<error<<endl;
                if(minerror>error)
                minerror=error;
            }
        }
        cout<<minerror<<endl;
    }    

    return 0;
}
