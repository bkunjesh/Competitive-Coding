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
const int inf = 1e15;
const int N = 200005;

int n, k;
vector<pair<int, int>> g[N];
vector<int> visited(N), dist(N, inf), parent(N, -1);
vector<vector<int>> dp(N, vector<int>(2, inf));
void dfs(int node, int parent = -1)
{
    visited[node] = 1;

    for (auto child : g[node])
    {
        dp[child.F][0] = min({dp[node][0] + child.S, dp[child.F][0]});
        dp[child.F][1] = min({dp[node][1] + child.S, dp[node][0] + child.S / k, dp[child.F][1]});
        if (!visited[child.F])
        {
            dfs(child.F, node);
        }
    }
}
void solve()
{
    int i, j, a, b, c;

    int m;
    cin >> n >> m >> k;
    f(i, m) cin >> a >> b >> c, g[a].push_back({b, c});

    // dfs(1);
    // cout << dp[n][1] << endl;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //dist,node
    dist[1] = 0;
    pq.push({0, 1});
    dp[1][0] = dp[1][1] = 0;

    while (!pq.empty())
    {
        auto p = pq.top();
        int d = p.F;
        int node = p.S;
        pq.pop();

        visited[node] = 1;

        if (dist[node] < d)
            continue;

        for (auto child : g[node])
        {
            dp[child.F][0] = min({dp[node][0] + child.S, dp[child.F][0]});
            dp[child.F][1] = min({dp[node][1] + child.S, dp[node][0] + child.S / k, dp[child.F][1]});
            if (!visited[child.F])
            {
                if (dist[node] + child.S < dist[child.F])
                {
                    dist[child.F] = dist[node] + child.S;
                    parent[child.F] = node;
                    pq.push({dist[child.F], child.F});
                }
            }
        }
    }

    cout << dp[n][1] << endl;

    

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