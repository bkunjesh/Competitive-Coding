//@CodesUp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (i = 1; i <= n; i++)
#define rew(i, a, b) for (ll i = a; i <= b; i++)
#define mod 1000000007
const ll inf = 1e18;

class Graph
{
public:
    vector<vector<ll>> g;
    vector<ll> visited, in, out, Flattree, nodeweight;
    ll n, timer, maxdist = -1, maxnode = 1;
    Graph(ll n)
    {
        this->n = n;
        visited.assign(n + 1, 0);
        g.resize(n + 1);
        in.assign(n + 1, 0);
        out.assign(n + 1, 0);
        Flattree.assign(2 * n + 2, 0);
        nodeweight.assign(n + 1, 0);
        this->timer = 1;
    }
    void make_edge(ll a, ll b)
    {
        g[a].push_back(b), g[b].push_back(a);
    }
    void dfs(ll node, ll dist)
    {
        visited[node] = 1;
        if (dist >= maxdist)
        {
            maxdist = dist;
            maxnode = node;
        }

        for (auto child : g[node])
        {
            if (!visited[child])
            {
                dfs(child, dist + 1);
            }
        }
    }
};

ll n;

void solve()
{
    ll i, j, k;
    cin >> n;
    Graph g(n + 1);
    f(i, n - 1) cin >> j >> k, g.make_edge(j, k);
    g.dfs(1, 0);
    g.maxdist = 0;
    //cout << g.maxnode << " ";
    f(i, n + 1) g.visited[i] = 0;
    g.dfs(g.maxnode, 0);
    ll ans = g.maxdist;
    cout << (ans + 1) / 2 << endl;

    return;
}

int main()
{
    fast
        ll t = 1,
           i, j, k;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}