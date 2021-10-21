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
        ll z,p,element,count1=0,count2=0,count3=0;
        cin>>n;
        vector<double> b;
        f(i,n)
        {
            cin>>p;
            b.push_back(p);
        }
        sort(b.begin(),b.end());
        vector<double>::iterator it,it2;
         for(it=b.begin();it<b.end();it++)
         {         	
         	double a2=*it/(*it-1);
         	it2=lower_bound(b.begin(),b.end(),a2);
         	if((a2==0)&&binary_search(it+1,b.end(),a2))
         	{
         	    count3=1;
         	}
         	else if((a2==2)&&binary_search(it+1,b.end(),a2))
         	{
         	    count2=1;
         	}
         	else if(a2!=*it&&binary_search(it+1,b.end(),a2))
         	{
         	    count1++;
			 }
			 cout<<*it<<" "<<a2<<" "<<*it2<<" "<<count1<<" "<<count2<<" "<<count3<<endl;
		 }
        cout<<"sol:"<<count1<<" "<<count2<<" ";
        cout<<count1+count2+count3<<endl;
    }
    return 0;
}

         		/*if(*it==a2&&it!=it2)
         		{    
         			count1++;
				 }
         		else if(*it!=a2)
         		count2++;*/
