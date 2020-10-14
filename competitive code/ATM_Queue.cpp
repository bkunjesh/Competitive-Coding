#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define endl "\n"
#define rep(i,n) for(i=1;i<=n;i++)
#define rew(i,a,b) for(ll i=a;i<=b;i++)
#define mod 1000000007
const ll inf = 1e18;

ll n;

int main()
{
    fast
    ll t = 1, i, j,k;
    cin >> t;
    for(ll test=1;test<=t;test++)
    {
        ll x;
        cin>>n>>x;
        vector<ll> a(n+1);
        rep(i,n) cin>>a[i];
        ll zero=0;
        //cout<<ceil(4)<<" ";
        cout<<"case #"<<test<<": ";
        map<ll,vector<ll>> m;
        for(i=1;i<=n;i++)
        {
            ll turn=ceil((double)a[i]/x);
            //cout<<turn <<" ";
            m[turn].push_back(i);
        }
        for(auto it:m)
        {
            auto no=it.first;
            for(auto x:m[no]) cout<<x<<" ";
        }
        cout<<endl;
        
    }
return 0;
}