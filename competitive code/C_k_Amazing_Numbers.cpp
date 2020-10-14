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
    cin >> t;
    while (t--)
    {
        cin>>n;
        vector<ll> a(n+2);
        rep(i,n) cin>>a[i];
        map<ll,vector<ll>> mp;
        map<ll,ll> fromwheretowhat;
        vector<ll> ans(n+3,inf);
        rep(i,n) mp[a[i]].push_back(i);
        ll sz=0;
        for(auto it=mp.rbegin();sz<mp.size();it++,sz++)
        {
            ll temp=-1;
            for(i=1;i<mp[(*it).first].size();i++)
            {
                {
                     temp=max(temp,mp[(*it).F][i]-mp[(*it).F][i-1]);
                    
                }
            }
            temp=max(temp,max(mp[(*it).F][0],n-mp[(*it).F][mp[(*it).first].size()-1]+1));
            if(temp>0&&temp<=n) ans[temp]=min(ans[temp],(*it).F);
        }
        for(i=2;i<=n;i++)
        {
            ans[i]=min(ans[i-1],ans[i]);
        }
        for(i=1;i<=n;i++)
        {
            if(ans[i]==inf) ans[i]=-1;
            cout<<ans[i]<<" ";

        }
        cout<<endl;



        
    }
return 0;
}