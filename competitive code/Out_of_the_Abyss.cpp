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
    vector<ll> visited, in, out, Flattree, nodeweight, dis;
    ll n, timer;
    
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
        dis.assign(n + 1, inf);
    }
    void make_edge(ll a, ll b)
    {
        g[a].push_back(b), g[b].push_back(a);
    }
    void dfs(ll node, ll parent)
    {
        visited[node] = 1;
        in[node] = timer;
        Flattree[timer++] = node;

        for (auto child : g[node])
        {
            if (!visited[child])
            {
                dfs(child, parent);
            }
        }

        out[node] = timer;
        Flattree[timer++] = node;
    }

    void solve(ll k)
    {
        queue<ll> q;
        ll i;
        f(i, k)
        {
            ll ele;
            cin >> ele;
            dis[ele] = 0;
            q.push(ele);
        }
        while (!q.empty())
        {
            ll node = q.front();
            q.pop();
            visited[node] = 1;

            for (auto child : g[node])
            {
                if (!visited[child])
                {
                    if (dis[child] > dis[node] + 1)
                    {
                        dis[child] = dis[node] + 1;
                        q.push(child);
                        visited[child] = 1;
                    }
                }
            }
        }
    }
};

ll n;

void solve()
{
    ll i, j, k, m,p;

    cin >> n >> m >> k;
    Graph g(100005);
    f(i, m) cin >> j >> p, g.make_edge(j, p);
    g.solve(k);
    ll qery;
    cin >> qery;
    while (qery--)
    {
        ll node;
        cin >> node;
        if (g.dis[node] == inf)
            cout << -1 << endl;
        else
            cout << g.dis[node] << endl;
    }

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