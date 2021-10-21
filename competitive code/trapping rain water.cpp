#include<bits/stdc++.h>
#define ll long long
using namespace std;

void maxwater(ll a[], ll n)
{
	ll i, left[n], right[n];
	left[0] = a[0], right[n - 1] = a[n - 1];
	for (i = 1; i < n; i++)
		left[i] = max(left[i - 1], a[i]), right[n - i - 1] = max(right[n - i], a[n - i - 1]);
	ll ans = 0;
	for (i = 1; i < n; i++) ans += min(left[i], right[i]) - a[i];
	cout << ans << endl;
}
int main()
{
	ll arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	ll n = sizeof(arr) / sizeof(arr[0]);
	maxwater(arr, n);
}