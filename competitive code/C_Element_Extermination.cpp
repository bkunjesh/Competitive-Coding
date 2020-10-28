#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll n;

int main()
{
    ll t = 1, i;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        if (a[0] < a[n - 1])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}