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
    vector<int> s(n), u(n), ans(n + 1, 0);
    vector<int> g[n + 1];
    f(i, n) cin >> u[i];
    f(i, n) cin >> s[i], g[u[i]].push_back(s[i]);
    rep(i, n) sort(g[i].rbegin(), g[i].rend());
    rep(i, n)
    {
        for (j = 1; j < g[i].size(); j++)
            g[i][j] += g[i][j - 1];
    }
    // rep(i, n)
    // {
    //     cout << i << "-> ";
    //     for (auto it : g[i])
    //         cout << it << " ";
    //     cout << endl;
    // }
    rep(i, n)
    {
        int sz = g[i].size();
        for (j = 1; j <= sz; j++)
        {
            int ind = sz - 1 - (sz % j);
            if (ind >= 0)
                ans[j] += g[i][ind];
        }
    }
    rep(i, n) cout << ans[i] << " ";
    cout << endl;

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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif