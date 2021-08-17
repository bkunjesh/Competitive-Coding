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
int c[N];
vector<int> g[N], visited(N);
int mncost;
void dfs(int node, int parent = -1)
{
    visited[node] = 1;
    mncost = min(mncost, c[node]);

    for (auto child : g[node])
    {
        if (!visited[child])
        {
            dfs(child, node);
        }
    }
}

void solve()
{
    int i, j, k;

    int m;
    cin >> n >> m;
    rep(i, n) cin >> c[i];
    int ans = 0;
    f(i, m) cin >> j >> k, g[j].push_back(k), g[k].push_back(j);

    rep(i, n)
    {
        mncost = inf;
        if (!visited[i])
        {
            dfs(i);
            ans += mncost;
        }
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