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
vector<int> g[N], visited(N, 0), c(N);
map<int, int> col;
vector<int> ans;

void dfs(int node)
{
    if (col[c[node]] == 0)
    {
        ans.push_back(node);
    }
    col[c[node]]++;

    visited[node] = 1;

    for (auto child : g[node])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
    col[c[node]]--;
}

void solve()
{
    int i, j, k;
    cin >> n;
    rep(i, n) cin >> c[i];
    f(i, n - 1) cin >> j >> k, g[j].push_back(k), g[k].push_back(j);

    dfs(1);
    sort(ans.begin(), ans.end());

    for (auto it : ans)
    {
        cout << it << endl;
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