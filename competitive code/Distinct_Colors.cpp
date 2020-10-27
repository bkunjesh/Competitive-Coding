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
    vector<ll> visited, in, out, Flattree, color, ans;
    ll n, timer;
    Graph(ll n)
    {
        this->n = n;
        visited.assign(n + 1, 0);
        g.resize(n + 1);
        in.assign(n + 1, 0);
        out.assign(n + 1, 0);
        ans.assign(n + 1, 0);
        Flattree.assign(2 * n + 2, 0);
        color.assign(n + 1, 0);
        this->timer = 1;
    }
    void make_edge(ll a, ll b)
    {
        g[a].push_back(b), g[b].push_back(a);
    }
    set<ll> dfs(ll node, ll parent)
    {
        visited[node] = 1;
        in[node] = timer;
        set<ll> s2;
        s2.insert(color[node]);
        Flattree[timer++] = node;

        for (auto child : g[node])
        {
            if (!visited[child])
            {
                auto s = dfs(child, parent);
                if(s.size()>s2.size())
                    swap(s, s2);
                for (auto it : s)
                    s2.insert(it);
            }
        }

        ans[node] = s2.size();
        out[node] = timer;
        Flattree[timer++] = node;
        return s2;
    }
};

ll n;

void solve()
{
    ll i, j, k;
    cin >> n;
    Graph g(n);
    rep(i, n) cin >> g.color[i];
    f(i, n - 1) cin >> j >> k, g.make_edge(j, k);
    g.dfs(1, 0);
    rep(i, n) cout << g.ans[i] << " ";
    cout << endl;

    return;
}

int main()
{
    fast
    ll t = 1,i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

