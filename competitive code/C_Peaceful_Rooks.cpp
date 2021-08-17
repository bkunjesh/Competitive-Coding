//@CodesUp
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

int n, cycle;
vector<int> g[N], visited(N),recst(N);

void dfs(int node, int parent = -1)
{

    visited[node] = 1,recst[node]=1;

    for (auto child : g[node])
    {
        if (!visited[child])
        {
            dfs(child, node);
        }
        else if(recst[child])
        {
            // cout << node << " " << child << endl;
            cycle++;
        }
    }
    recst[node] = 0;
}

void solve()
{
    int i, j, k, ans = 0;
    fill(visited.begin(), visited.end(), 0);
    fill(recst.begin(), recst.end(), 0);
    cycle = 0;
    int m;
    cin >> n >> m;
    rep(i, n) g[i].clear();
    f(i, m)
    {
        cin >> j >> k;
        if (j != k)
            g[j].push_back(k), ans++;
    }
    rep(i, n)
    {
        if (!visited[i]&&g[i].size()>0)
        {
            dfs(i, -1);
        }
    }
    // cout << cycle << " ";
    cout << ans + cycle << endl;

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