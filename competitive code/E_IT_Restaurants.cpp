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
const int N = 1e4;

int n;
vector<int> subtreecnt(N), local(N), possible(N), visited(N), g[N];
set<pair<int, int>> s;

void dfs(int node, int parent)
{
    visited[node] = 1;
    vector<int> sizes;
    subtreecnt[node] = 1;

    for (auto child : g[node])
    {
        if (!visited[child])
        {
            dfs(child, node);
            subtreecnt[node] += subtreecnt[child];
            sizes.push_back(subtreecnt[child]);
        }
    }

    if (!sizes.empty())
    {
        if (parent != -1)
            sizes.push_back(n - subtreecnt[node]);

        f(i, n) local[i] = 0;
        local[0] = 1;
        for (auto x : sizes)
        {
            for (int i = n - x; i >= 0; i--)
            {
                if (local[i])
                {
                    local[x + i] = 1;
                    possible[x + i] = 1;
                }
            }
        }
    }
}

void solve()
{
    int i, j, k;

    cin >> n;
    f(i, n - 1) cin >> j >> k, g[j].push_back(k), g[k].push_back(j);
    dfs(1, -1);
    vector<int> ans;
    for (i = 1; i < n - 1; i++)
        if (possible[i])
            ans.push_back(i);

    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << " " << n - 1 - x << endl;
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