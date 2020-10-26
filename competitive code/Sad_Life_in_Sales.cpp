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

vector<ll> visited(100005), level(100005), val(100005);
vector<pair<ll, ll>> g[100005];
ll MAXN;
ll lca[100005][25];

void make_edge(ll a, ll b, ll w)
{
    g[a].push_back({b, w}), g[b].push_back({a, w});
}

void dfs(ll node, ll parent, ll d)
{
    lca[node][0] = parent;
    level[node] = d;
    visited[node] = 1;

    for (auto child : g[node])
    {
        if (!visited[child.F])
        {
            val[child.F] += val[node] + child.S;
            dfs(child.F, node, d + 1);
        }
    }
}

void buildlca(ll n)
{
    for (ll j = 1; j <= MAXN; j++)
    {
        for (ll i = 1; i <= n; i++)
        {
            if (lca[i][j - 1] != -1)
            {
                lca[i][j] = lca[lca[i][j - 1]][j - 1];
            }
        }
    }
}
ll getlca(ll a, ll b)
{
    if (level[a] > level[b])
    {
        swap(a, b);
    }
    ll d = level[b] - level[a];

    while (d > 0)
    {
        ll i = log2(d);
        b = lca[b][i];
        d -= (1ll << i);
    }
    if (a == b)
        return a;
    for (ll i = MAXN; i >= 0; i--)
    {
        if (lca[a][i] != -1 && lca[a][i] != lca[b][i])
        {
            a = lca[a][i], b = lca[b][i];
        }
    }
    return lca[a][0];
}
ll n;
void solve()
{
    ll i, j, l, k, q, r;
    cin >> n >> q >> r;

    f(i, n + 2)
    {
        visited[i] = 0;
        g[i].clear();
        val[i] = 0;
        level[i] = 0;
    }
    MAXN = log2(n);
    f(i, n + 1)
    {
        f(j, MAXN+1) lca[i][j] = -1;
    }

    f(i, n - 1)
    {
        cin >> j >> k >> l;
        make_edge(j, k, l);
    }
    dfs(r, -1, 0);
    buildlca(n);
    // for(i=1;i<=n;i++)
    // {
    //     for(j=0;j<=MAXN;j++)
    //     {
    //         cout<<lca[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        ll c = getlca(a, b);
        cout << val[a] + val[b] - 2 * val[c] << endl;
    }

    return;
}

int main()
{
    fast
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}