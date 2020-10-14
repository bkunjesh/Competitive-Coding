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

ll n,k;

int main()
{
    fast
    ll t = 1, i, j;
    cin >> t;
    while (t--)
    {
        cin>>n>>k;
        string s;cin>>s;
        ll w=0,ans=0,cnt=0;
        vector<ll> L;
        //cnt for W
        for(auto ch:s)
        {
            if(ch=='L'&&cnt!=0)
            {
                w+=cnt;
                ans+=cnt*2;
                ans--;
                cnt=0;
            }
            if(ch=='W')
            cnt++;
        }
        if(cnt!=0) w+=cnt,ans+=cnt*2,ans--,cnt=0;
        // cnt for L
        ll flag=0;
        for(auto ch:s)
        {
            if(ch=='W') flag=1;
            if(ch=='W'&&cnt!=0)
            {
                L.push_back(cnt);
                cnt=0;
            }
            if(ch=='L'&&flag) cnt++;
        }
        //if(cnt!=0) L.push_back(cnt),cnt=0;
        k=min(k,n-w);
        if(w==0&&k!=0)
        {
            cout<<k*2-1<<endl;
            continue;
        }

        sort(L.begin(),L.end());
        
        ans+=k*2;
        for(auto lost:L)
        {
            if(lost<=k)
            {
                ans++;
                k-=lost;
            }

        }
        cout<<ans<<endl;
        



        
    }
return 0;
}