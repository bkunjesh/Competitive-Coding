#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define rep(i,n) for(i=1;i<=n;i++)
#define rew(i,a,b) for(ll i=a;i<=b;i++)
#define endl "\n"
#define mod 1000000007

const ll inf = 1e18;
ll n;

int main()
{
	fast
	ll t = 1, i, j;
	//cin >> t;

	while (t--)
	{
        ll tm;
        cin>>n>>tm;
        vector<ll> a(n);
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll ans=0,cnt=0,bk_cnt=0;
        vector<ll> suf(n+1,0);
        for(i=n-1;i>=0;i--)
        {
            suf[i]+=suf[i+1]+a[i];
        }
        reverse(suf.begin(),suf.end());
        for (i = n; i>0; i--)
        {
            ll need=suf[i]-tm;
            auto ind=lower_bound(suf.begin(),suf.end(),need);
            cnt=(suf.begin()+i)-ind;
            //cout<<cnt<<" ";
            ans=max(ans,cnt);
        }
        cout<<ans<<endl;
        
	}
	return 0;
}

