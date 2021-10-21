#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<string>
#include<vector>
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
ll i, a, b, j, k, q, n, m;
//vect_ll a;
//ll visited[100001]={0};
//vect_ll g[100001];
ll power(ll a, ll b) {
	ll res = 1;
	while (b)
	{
		if (b % 2) b-- , res = res * a;
		else b = b / 2 , a *= a;
	}
	return res;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w", stdout);
#endif
	fast
//	int t; cin >> t;
//	while (t--)
	{
		cin >> n;
		string s = "codeforces", add = "s";
		if (n == 1)
		{
			cout << s << endl;
			return 0;
		}
		ll temp = n, cnt = 0, x = 1;
		while (temp)
		{
			temp /= 2;
			cnt++;
		}
		if (pow(2, cnt - 1) == n) cnt--;
		ll arr[11];
		if (cnt > 10)
		{
			ll first = cnt / 10;
			ll second = cnt % 10;
			rep(i, 10) arr[i] = pow(2, first);
			rep(i, second) arr[i] += 1;
			//arr[1]+=second;
		}
		else
		{
			rep(i, cnt) arr[i] = 2;
			for (i = cnt + 1; i <= 10; i++) arr[i] = 1;
		}
		string ans = "";
		for (i = 1; i <= 10; i++)
		{
			while (arr[i]--)
			{
				ans += s[i - 1];
			}
		}
		cout << ans << endl;
		//if((cnt-1)*10==n) cnt--;
		/*	cnt--;
			ll ans = power(cnt, 10);
			string answer;
			for (ll i = 0; i < 10; i++)
			{
				answer += string(cnt, s[i]);
				if (ans >= n)  continue;
				answer += s[i];
				ans /= cnt;
				ans *= (cnt + 1);
			}
			cout << answer << endl;
		*/
	}
	return 0;
}