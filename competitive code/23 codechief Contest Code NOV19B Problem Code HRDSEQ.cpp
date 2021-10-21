#include<stdio.h> 
#include<stdlib.h> 
#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;

int main()
{     int t,n,j,i;
       cin>>t;
       while(t--)
      {
          int a[126];
          a[0]=0;
          cin>>n;
          for(i=0;i<n;i++)
          {
              for(j=i-1;a[j]!=a[i]&&j>=0;j--);
              if(j<0)
              a[i+1]=0;
              else
              a[i+1]=i-j;
          }
          int cnt=0;
          while(i>=0)
          {
              i--;
              if(a[i]==a[n-1])
              cnt++;
          }
          cout<<cnt;
          
      }    

    return 0;
}
