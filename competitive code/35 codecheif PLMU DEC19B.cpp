#include<stdio.h> 
#include<stdlib.h> 
#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
int main()
{     ll t,n,i,j;
     cin>>t;
     while(t--)
    {
        ll z,p,element,count1=0,count2=0,count=0;
        cin>>n;
        z=100000;
		//cout<<z;
        int a[z]={0};
        //vector<ll> a;
        //a.resize(1000000000ll);
        //a={0};
        //cout<<a.size();
        f(i,n)
        {
            cin>>p;
            a[p]++;
        }
        //cout<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<a[5];
        for(i=2;i<z;i++)
        {
            //cout<<i<<" "<<a[i]<<endl;
            ll a2=i/(i-1);
            if(a[i]>0)
            {
                if(i==a2)
                {
                    if(a[i]>1)
                    count1++;
                }
                else if(a[a2]>0)
                count2++;
            }
        }
        cout<<count1+count2/2<<endl;
    }    

    return 0;
}

