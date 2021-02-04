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

    cin >> n;
    vector<int> c(n + 1), a(n + 1), b(n + 1);
    int ans = 0;
    rep(i, n) cin >> c[i];
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    int val = 0;
    for (i = 2; i <= n; i++)
    {
        int u = a[i], l = b[i];
        if (l < u)
            swap(u, l);
        if (l == u)
        {
            val = 0;
        }
        else
        {
            val = max(val - (l - u), (l - u));
        }
        val += 2;
        val += c[i] - 1;
        ans = max(ans, val);
    }
    // for (i = 2; i <= n; i++)
    // {
    //     int u = a[i], l = b[i];
    //     if (l < u)
    //         swap(u, l);

    //     if (l == u)
    //     {
    //         val += ((u - 1) + (c[i - 1] - l));
    //         ans = max(ans, val);
    //         val = 0;
    //     }

    //     if (val == 0)
    //     {
    //         val += (l - u);
    //         val = max(val, (l - u));
    //         val += 2;
    //         ans = max(ans, val + c[i] - 1);
    //     }
    //     else
    //     {
    //         val += ((u - 1) + (c[i - 1] - l));
    //         ans = max(ans, val + l - u);
    //         val = max(val, (l - u));

    //         val += 2;

    //     }
    //     if (i == n)
    //     {
    //         ans = max(ans, val + c[i] - 1);
    //     }
    // }
    cout << ans << endl;

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