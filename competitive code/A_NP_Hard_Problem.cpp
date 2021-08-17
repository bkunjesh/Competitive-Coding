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
vector<int> g[N], visited(N), color(N);
int flag = 0;
void dfs(int node, int col)
{
    // cout << node << " ";
    visited[node] = 1;
    color[node] = col + 1;

    for (auto child : g[node])
    {
        if (visited[child] == 0)
        {
            dfs(child, !col);
        }
        else
        {
            if (color[child] == col + 1)
            {
                flag = 1;
            }
        }
    }
}
void solve()
{
    int i, j, k, m;
    cin >> n >> m;
    f(i, m) cin >> j >> k, g[j].push_back(k), g[k].push_back(j);

    rep(i, n)
    {
        if (!visited[i])
        {
            dfs(i, 0);
        }
    }
    vector<int> ans[2];

    rep(i, n)
    {
        if (color[i] >= 1)
            ans[color[i] - 1].push_back(i);
    }

    if (flag || ans[0].size() == 0 || ans[1].size() == 0)
    {
        cout << -1 << endl;
        return;
    }

    f(i, 2)
    {
        cout << ans[i].size() << endl;
        for (auto it : ans[i])
            cout << it << " ";
        cout << endl;
    }
    return;

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