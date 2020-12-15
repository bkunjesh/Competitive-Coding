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

int n;
vector<int> g[N], visited(N), color(N);
int possibal = 1;
void dfs(int node, bool col)
{
    visited[node] = 1;
    color[node] = col;

    for (auto child : g[node])
    {
        if (possibal && visited[child] && color[child] == col)
        {
            possibal = 0;
            return;
        }
        if (!visited[child] && possibal)
        {
            dfs(child, !col);
        }
    }
}

void solve()
{
    int i, j, k, m;

    cin >> n >> m;
    f(i, m) cin >> j >> k, g[j].push_back(k), g[k].push_back(j);
    rep(i,n)
    if(!visited[i])
    dfs(i, 0);

    if (possibal)
    {
        rep(i, n) cout << color[i]+1 << " ";
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
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