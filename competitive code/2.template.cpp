#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define rep(i,n) for(i=1;i<=n;i++)
#define input(i,n,arr) for(i=0;i<n;i++) cin>>j, arr.push_back(j)
#define vect_ll vector<long long>
#define vect_ll_it vector<long long>::iterator
#define pb(p) push_back(p)
#define endl "\n"
#define mod 1000000007
const ll inf = 1e18;
ll i, j, k, q, n, m;
vect_ll a;
//ll visited[100001]={0};
//vect_ll g[100001];
ll power(ll a, ll n)
{
	ll res = 1;
	while (n)
	{
		if (n & 1) res = res * a;
		n >>= 1;
		a = a * a;
	}
	return res;
}
ll presentcnt(string s)
{
	string s1 = "abacaba";
	ll cnt = 0;
	for (i = 0; i <= s.size() - 7; i++)
	{
		string temp = s.substr(i, 7);
		if (temp == s1) cnt++;
	}
	return cnt;
}
ll ncr(ll n, ll r)
{
	if (n < r) return 0;
	r = min(r, n - r);
	ll res = 1;
	for (i = 0; i < r; i++)
	{
		res = res * (n - i);
		res = res / (i + 1);
	}
	return res;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt" , "r" , stdin);
	freopen("output1.txt" , "w", stdout);
#endif
	fast
	//cout << fixed << setprecision(10) ;
//	int t; cin >> t;
//	rep(k, t)
	{
		a.clear();
		cin >> n;
		input(i, n, a);
		ll ans[n + 1] = {0};
		set<ll> fact;
		for (i = 0; i < n; i++)
		{
			for (auto it : fact) if (a[i] % it == 0) ans[i]++;
			/*ll temp2 = a[i];
			for (j = 2; j * j <= a[i]; j++)
			{
				ll temp = j;
				while (a[i] % temp == 0)
				{
					temp2 /= temp;
					fact.insert(temp);
					temp *= j;
				}
			}
			if (temp2 > 0) fact.insert(temp2);*/
			fact.insert(a[i]);
		}
		f(i, n) cout << ans[i] << " ";

	}
	return 0;
}