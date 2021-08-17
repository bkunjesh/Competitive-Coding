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

int n, iscycle;
vector<int> g[N], visited(N);

void dfs(int node, int parent)
{
    visited[node] = 1;
    
    for (auto child : g[node])
    {
        if (!visited[child])
        {
            dfs(child, node);
        }
    }
    if(g[node].size()!=2)
        iscycle = 0;
}

void solve()
{
    int i, j, k, m, ans = 0;
    cin >> n >> m;

    f(i, m) cin >> j >> k, g[j].push_back(k), g[k].push_back(j);

    for (i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            iscycle = 1;
            dfs(i, -1);
            if (iscycle)
            {
                ans++;
            }
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif