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
int l[N], r[N], visited[N], leftans[N], rightans[N];
vector<int> g[N];

void dfs(int node, int p = -1)
{
    visited[node] = 1;

    for (auto child : g[node])
    {
        if (!visited[child])
        {
            dfs(child, node);
        }
    }

    if (p != -1 && g[node].size() == 1)
    {
        return;
    }

    for (auto child : g[node])
    {
        if (child == p)
            continue;
        leftans[node] += max(abs(l[node] - l[child]) + leftans[child], abs(l[node] - r[child]) + rightans[child]);
        rightans[node] += max(abs(r[node] - l[child]) + leftans[child], abs(r[node] - r[child]) + rightans[child]);
    }
}

void solve()
{
    int i, j, k;

    cin >> n;
    f(i, N) leftans[i] = 0, rightans[i] = 0, l[i] = 0, r[i] = 0, visited[i] = 0, g[i].clear();

    rep(i, n) cin >> l[i] >> r[i];
    rep(i, n - 1) cin >> j >> k, g[j].push_back(k), g[k].push_back(j);

    // auto ans1 = bfs(1);
    // auto ans2 = bfs(0);
    // cout << max(ans1, ans2) << endl;
    dfs(1);
    cout << max(leftans[1], rightans[1]) << endl;

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