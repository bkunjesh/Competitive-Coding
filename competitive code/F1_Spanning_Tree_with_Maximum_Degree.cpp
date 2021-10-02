//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N = 200005;
vector<int> g[N], visited(N, 0), deg(N, 0);
int n;

void solve()
{
    int i, j, k, m;

    cin >> n >> m;
    f(i, m)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    vector<pair<int, int>> ans;
    priority_queue<pair<int, int>> pq; //deg,node

    int src = max_element(deg.begin(), deg.end()) - deg.begin();
    visited[src] = 1;

    pq.push({deg[src], src});

    while (!pq.empty())
    {
        int par = pq.top().S;
        pq.pop();

        for (auto child : g[par])
        {
            if (!visited[child])
            {
                pq.push({deg[child], child});
                visited[child] = 1;
                ans.push_back({par, child});
            }
        }
    }
    for (auto it : ans)
    {
        cout << it.F << " " << it.S << endl;
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