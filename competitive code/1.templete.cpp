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
ll i, s, j, k, q, x, n, m;
vect_ll a, h, pt;
map<ll, ll> ma, mb;
ll visited[100001] = {0};
vect_ll g[100001];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt" , "r" , stdin);
	freopen("output1.txt" , "w", stdout);
#endif
	fast
	int t = 1; //cin >> t;
	while (t--)
	{
		a.clear();
		cin >> n;
		input(i, n, a);
		ll cnt = 0;
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if ((a[i]&a[j]) == a[i])
					cnt++;
			}
		}
		cout << cnt << endl;
	}
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	return 0;
}
