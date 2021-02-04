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
vector<int> g[N], visited(N), mxsell(N), a(N);
void dfs(int node, int parent = -1)
{
    visited[node] = 1;
    mxsell[node] = (a[node]);

    for (auto child : g[node])
    {
        if (!visited[child])
        {
            dfs(child, node);
            mxsell[node] = max(mxsell[node], mxsell[child]);
        }
        else
        {
            mxsell[node] = max(mxsell[node], mxsell[child]);
        }
    }
}
void solve()
{
    int i, j, k;
    int m;

    cin >> n >> m;
    rep(i, n) cin >> a[i];
    f(i, m) cin >> j >> k, g[j].push_back(k);
    for (i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    int ans = 0;
    rep(i, n) ans = max(ans, mxsell[i] - a[i]);

    if (ans == 0)
    {
        rep(i, n) a[i] = -a[i], visited[i] = 0, mxsell[i] = INT_MIN;
        for (i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }
        rep(i, n) ans = max(ans, mxsell[i] - a[i]);
        ans = -ans;
    }

    cout << ans << endl;

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