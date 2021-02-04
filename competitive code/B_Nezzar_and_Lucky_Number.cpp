//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;

void solve()
{
    int i, j, k, d;

    cin >> n >> d;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    int rem[d + 1];
    f(i, d + 1) rem[i] = inf;
    k = d;
    while (k <= 10 * d)
    {
        rem[(k) % d] = min(rem[(k) % d], k);
        k += 10;
    }
    // f(i, d) cout << rem[i] << " ";

    for (i = 0; i < n; i++)
    {
        if (a[i] >= 10 * d || a[i] % d == 0)
        {
            cout << "YES" << endl;
            continue;
        }
        if (rem[(a[i]) % d] != inf && rem[a[i] % d] <= a[i])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}