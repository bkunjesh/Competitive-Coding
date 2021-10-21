#include<bits/stdc++.h>
#define ll long long
using namespace std;
void logestsubsegment(ll a[], ll n, ll k)
{
	ll mx = 0;
	ll l = 0;
	ll cnt = 0;

	for (ll i = 0; i < n; i++)
	{
		if (a[i] == 0) cnt++;
		while (cnt > k)
		{
			if (a[l] == 0) cnt--;
			l++;
		}
		mx = max(mx, i - l + 1);
	}
	cout << mx << endl;
}
int main()
{
	ll a[] = {1, 0, 1, 1, 0, 0, 1, 0, 0, 0};
	ll k = 3;
	logestsubsegment(a, 10, k);
}