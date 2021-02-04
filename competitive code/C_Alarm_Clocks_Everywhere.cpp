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
    int i, j, k;

    int m;
    cin >> n >> m;
    vector<int> a(n), p(m);
    // map<int, int> p;
    f(i, n) cin >> a[i];
    f(i, m) cin >> p[i];

    int g = (a[1] - a[0]);
    for (i = 1; i < n - 1; i++)
    {
        g = __gcd(g, (a[i + 1] - a[i]));
    }
    for (i = 0; i < m; i++)
    {
        if (g % p[i] == 0)
        {
            cout << "YES" << endl;
            cout << a[0] << " " << i + 1 << endl;
            return;
        }
    }
    // for (i = 1; i * i <= g; i++)
    // {
    //     if (g % i == 0)
    //     {
    //         if (p[i])
    //         {
    //             cout << "YES" << endl;
    //             cout << a[0] << " " << p[i] << endl;
    //             return;
    //         }
    //         if (p[g / i])
    //         {
    //             cout << "YES" << endl;
    //             cout << a[0] << " " << p[g / i] << endl;
    //             return;
    //         }
    //     }
    // }

    cout << "NO" << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}