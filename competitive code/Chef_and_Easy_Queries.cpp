//@bkunjesh
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,k) for(i=0;i<k;i++)
#define endl "\n"
#define rep(i,n) for(i=1;i<=n;i++)
ll n;
int main()
{
    ll t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        cin>>n>>k;
        vector<ll> arr(n+1);
        ll d=0;
        arr[0]=0;
        rep(i,n) 
        {
            cin>>arr[i];
            arr[i]=arr[i]-k;
            arr[i]=arr[i]+arr[i-1];
        }
        rep(i,n)
        if(arr[i]<0)
        {
            d=i;
            break;
        }
        if(d==0)
        {
            d=n;
            d+=arr[n]/k+1;
        }
        cout<<d<<endl;
    }
return 0;
}