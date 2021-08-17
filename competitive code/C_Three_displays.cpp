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
const int inf = 4 * 1e9;
const int N = 200005;

int n;

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> s(n), c(n);
    f(i, n) cin >> s[i];
    f(i, n) cin >> c[i];

    int dpf[n], dps[n];
    memset(dpf, inf, sizeof(dpf));
    memset(dps, inf, sizeof(dps));
    dpf[0] = inf;
    for (i = 1; i < n; i++)
    {
        int mn = inf;
        for (j = 0; j < i; j++)
        {
            if (s[j] < s[i])
                mn = min(mn, c[j] + c[i]);
        }
        dpf[i] = mn;
    }
    // i 23 21 24 25 22 23 23 28 23
    // 0  0 34 35 36 33 34 34 39 34
    dps[0] = inf;
    dps[1] = inf;
    int ans = inf;
    for (i = 2; i < n; i++)
    {
        int mn = inf;
        for (j = 1; j < i; j++)
        {
            if (s[j] < s[i])
                mn = min(mn, dpf[j] + c[i]);
        }
        dps[i] = mn;
        ans = min(ans, mn);
    }
    // for (auto it : dpf)
    //     cout << it << " ";
    // cout << endl;

    // for (auto it : dps)
    //     cout << it << " ";
    // cout << endl;

    if (ans == inf)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }

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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif