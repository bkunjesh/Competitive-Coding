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
		ll v1,v2,d;
		cin>>v1>>v2>>n>>d;
		vector<ll> a(n+1);
		a[n]=max(v1,v2);
		a[1]=min(v1,v2);
		for(i=n-1;i>1;i--) a[i]=a[i+1]+d;
		for(i=2;i<n;i++)
		{
			if(abs(a[i]-a[i-1])<=d) break;
			a[i]=a[i-1]+d;
		}
		ll ans=0;
		for(i=1;i<=n;i++) ans+=a[i];
		cout<<ans<<endl;



	}
	return 0;
}

