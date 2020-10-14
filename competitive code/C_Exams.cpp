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
        ll k;
        cin>>n;
        vector<pair<ll,ll>> a;
        for(i=0;i<n;i++)
         cin>>j>>k, a.push_back({j,k});
         sort(a.begin(),a.end());
         ll prev=0;
         for(auto it:a)
         {
             prev=it.second>=prev?it.second:it.first;
         }
         cout<<prev<<endl;

	}
	return 0;
}

