//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;
vector<int> cost(N), g[N], visited(N, 0);
vector<pair<int, int>> mncost;
int mncostincomponent, mnnode;

void dfs(int node, int parent = -1)
{
    visited[node] = 1;
    if (mncostincomponent > cost[node])
    {
        mncostincomponent = min(mncostincomponent, cost[node]);
        mnnode = node;
    }
    for (auto child : g[node])
    {
        if (!visited[child])
        {
            dfs(child, node);
        }
    }
}
vector<vector<int>> graph;

void dfs2(int node)
{
    visited[node] = 1;
    for (auto child : g[node])
    {
        if (!visited[child])
        {
            vector<int> tmp;
            tmp.push_back(node);
            tmp.push_back(child);
            graph.push_back(tmp);
            dfs(child);
        }
    }
}

void solve()
{
    int i, j, k, m;

    cin >> n >> m;
    cost.clear();
    visited.clear();
    f(i, N) g[i].clear();

    rep(i, n) cin >> cost[i];

    f(i, m)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    rep(i, n)
    {
        if (!visited[i])
        {
            mncostincomponent = 0;
            dfs(i);
            mncost.push_back({mncostincomponent, mnnode});
        }
    }

    sort(mncost.begin(), mncost.end());
    int ans = 0;
    for (i = 1; i < mncost.size(); i++)
    {
        int u = mncost[0].S, v = mncost[i].S;
        ans += (abs(mncost[0].F - mncost[i].F));
        g[u].push_back(v);
        g[v].push_back(u);
    }
    visited.clear();

    dfs2(1);
    cout << ans << " " << graph.size() << endl;

    for (auto vec : graph)
    {
        for (auto x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif