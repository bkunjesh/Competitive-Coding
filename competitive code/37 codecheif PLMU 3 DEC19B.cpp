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
        //z=1000000;
        //cout<<z;
        //int a[10000]={0};
        vector<ll> b;
        //a.resize(1000000000ll);
        //a={0};
        //cout<<a.size();
        f(i,n)
        {
            cin>>p;
          //  a[p]++;
            b.push_back(p);
        }
        sort(b.begin(),b.end());
        //cout<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<a[5];
        vector<ll>::iterator it,it2;
        /*for(it=b.begin();it<b.end();it++)
        {
            //cout<<i<<" "<<a[i]<<endl;
            ll a2=*it/(*it-1);
            if(a[*it]>0)
            {
                if(p==a2)
                {
                    if(a[*it]>1)
                    count1++;
                }
                else if(a[a2]>0)
                count2++;
            }
        }*/
         for(it=b.begin();it<b.end();it++)
         {         	
         	ll a2=*it/(*it-1);
         	//cout<<*it<<" "<<a2<<endl;
         	it2=upper_bound(b.begin(),b.end(),a2);
         	//cout<<it2;
         	if(binary_search(b.begin(),b.end(),a2))
         	{
         		if(*it==a2&&it!=it2)
         		{    // check once here ,some mistake is their
         			count1++;
				 }
         		else if(*it!=a2)
         		count2++;
			 }
		 }
        cout<<count1+count2/2<<endl;
    }    

    return 0;
}

