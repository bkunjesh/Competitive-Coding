//@bkunjesh
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define endl "\n"
#define rep(i,n) for(i=1;i<=n;i++)
#define rew(i,a,b) for(ll i=a;i<=b;i++)
#define mod 1000000007
const ll inf = 1e18;

ll n;

int main()
{
    fast
    ll t = 1, i, j, k;
    //cin >> t;
    ll ans=INT_MAX;
    while (t--)
    {
        cin>>n;
        vector<ll> a;
        a.push_back(1);
        for(i=2;i*i<=n;i++)
        if(n%i==0)
        {

            ll cnt=1;
            while(n%i==0)
            {
                n/=i;
                cnt*=i;                                
            }
            a.push_back(cnt);
        }
        if(n>1) a.push_back(n);
        sort(a.begin(),a.end());
    //     ll start=0,end=a.size()-1;
    //     ll startpro=a[start],endpro=a[end];
    //     start++;
    //     while(start<end)
    //     {
    //         if(startpro*a[start]<=endpro*a[end])
    //         {
    //             startpro*=a[start];
    //             start++;
    //         }
    //         else
    //         {
    //             endpro*=a[end];
    //             end--;
    //         }
    //    }
    //    cout<<startpro<<" "<<endpro<<endl;
        ll ansa=1e18,ansb=1e18;
        for(i=0;i<(1<<a.size());i++)
        {
            ll s=1,e=1;
            for(j=0;j<a.size();j++)
            {
                if((i>>j)&1) s*=a[j];
                else e*=a[j];
            }
            if(max(s,e)<max(ansa,ansb))
            {
                ansa=s;
                ansb=e;
            }
        }
        cout<<ansa<<" "<<ansb<<endl;
    }

return 0;
}