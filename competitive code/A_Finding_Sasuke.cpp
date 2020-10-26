#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, k) for (i = 0; i < k; i++)


void solve()
{
    ll i,n;
    cin >> n;
    vector<ll> a(n);
    f(i, n) cin >> a[i];
    for (i = 0; i < n - 1; i = i + 2)
    {
        ll y = (a[i] * a[i + 1]) / __gcd(a[i + 1], a[i]);
        cout << y / a[i] << " " << -(y / a[i + 1]) << " ";
    }
    cout << endl;

    return;
}

int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}