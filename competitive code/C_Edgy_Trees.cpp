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
const int N = 100005;

int n, cnt = 0;
vector<int> visited(N, 0);
vector<pair<int, int>> g[N];
void dfs(int node)
{
    visited[node] = 1;
    cnt++;
    for (auto child : g[node])
    {
        if (!visited[child.F] && child.S != 1)
        {
            dfs(child.F);
        }
    }
}
int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = ((res % mod) * (a % mod)) % mod;
        }
        b >>= 1;
        a = ((a % mod) * (a % mod)) % mod;
    }
    return res;
}

void solve()
{
    int i, j, k, l, m, minus = 0;

    cin >> n >> k;
    f(i, n - 1) cin >> j >> m >> l, g[j].push_back({m, l}), g[m].push_back({j, l});
    rep(i, n)
    {
        cnt = 0;
        if (!visited[i])
        {
            dfs(i);
            minus += power(cnt, k);
            minus %= mod;
        }
    }
    cout << (power(n, k) + mod - minus) % mod << endl;

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