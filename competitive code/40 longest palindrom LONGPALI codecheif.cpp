#include<stdio.h> 
#include<stdlib.h> 
#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
int pallindrom(string s,int left,int right,int n)
{
    int count=1;
    while(left>=0&&right<=n)
    {
        if(s[left]!=s[right])
        return count-1;
        right++;
        left--;
        count++;
    }
    return count-1;
}
int main()
{     int n,i,j,maxchar=1,high,low,p;
     cin>>n;  
     string s;
     cin>>s;
     //s="knjjnj";
     //n=6;
     //cout<<pallindrom(s,4,4,6);
     
     //for even output (return*2) && for odd (return*2 - 1)
     //even
     f(i,n-1)
     {
         p=pallindrom(s,i,i+1,n);
         if(maxchar<p)
         {
             maxchar=p*2;
             low=i-p+1;
             high=i+p;
         }
     }
     //odd
          f(i,n-1)
     {
         p=pallindrom(s,i,i,n);
         if(maxchar<p)
         {
             maxchar=p*2-1;
             //cout<<"p="<<p;
             low=i-p+1;
             high=i+p-1;
         }
     }
     cout<<maxchar<<endl;
     for(i=low;i<=high;i++) cout<<s[i];
     cout<<endl;
    

    return 0;
}
