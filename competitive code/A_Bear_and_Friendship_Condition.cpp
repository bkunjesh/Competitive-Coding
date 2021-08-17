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
vector<int> g[N], visited(N), bag;

void dfs(int node)
{
    bag.push_back(node);
    visited[node] = 1;

    for (auto child : g[node])
    {
        if (!visited[child])
        {
            dfs(child);
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
            bag.clear();
            dfs(i);

            int vcnt = bag.size();
            for (auto node : bag)
            {
                if (g[node].size() != (vcnt - 1))
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;

    /*
    2nd method-editorial
    edges=vertices*(vertices-1)/2;
    */

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