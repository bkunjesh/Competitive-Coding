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
    ll t = 1, i, j;
    cin >> t;
    while (t--)
    {
        cin>>n;
        vector<ll> a(n),vis(n,0);
        for(i=0;i<n;i++) cin>>a[i];
        ll ans=0;
        for(i=30;i>=0;i--)
        {
            ll p=(1<<i);
            //cout<<p<<endl;
            ll cnt=0;
            for(j=0;j<n;j++)
            {
                if(vis[j]==0)
                {
                    if((a[j]&p)==p)
                    {
                        vis[j]=1;
                        cnt++;
                    }
                }
            }
            ans+=(cnt)*(cnt-1)/2;
           // cout<<i<<" "<<cnt<<" "<<endl;
        }
        cout<<ans<<endl;


    }
return 0;
}