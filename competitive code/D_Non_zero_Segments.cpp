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
    while (t--)
    {
        cin>>n;
        vector<ll> a(n+3);
        rep(i,n) cin>>a[i];
        ll presum[n+3]={0};
        presum[0]=0;
        map<ll,ll> m;
        m[0]=0;
        ll ans=0;
        vector<pair<ll,ll>> p;
        rep(i,n) 
        {
            presum[i]=presum[i-1]+a[i];

            if(m.count(presum[i]))
            {
                //cout<<i<<" ";
                ans++;
                m.clear();
                m[0]=0;
                presum[i]=a[i];
                m[presum[i]]=i;
            }
            else
            {
                m[presum[i]]=i;
            }
        }
        // if(p.empty())
        // {
        //     cout<<0<<endl;
        //     return 0;
        // }
        // sort(p.begin(),p.end());
        // for(auto it=p.begin()+1;it!=p.end();it++)
        // {
        //    // cout<<(*it).F<<" "<<(*it).S<<endl;
        //     auto prev=it;
        //     prev--;
        //     if((*it).F<(*prev).S)
        //     {
        //         p.erase(it);
        //         it=prev;
        //     }
        // }
        // ll ans=0;
        
        //if(p.empty()) ans=0;
        //ans=p.size();
        cout<<ans<<endl;

    }
return 0;
}