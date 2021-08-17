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
map<int, vector<int>> g;
stack<int> ans;
map<int, int> visited;

void dfs(int node, int parent = -1)
{
    visited[node] = 1;

    for (auto child : g[node])
    {
        if (!visited[child])
        {
            dfs(child, node);
        }
    }
    ans.push(node);
}
void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n);
    map<int, int> isPresent;
    f(i, n) cin >> a[i], isPresent[a[i]] = 1;

    f(i, n)
    {
        if (a[i] % 3 == 0 && isPresent[a[i] / 3] == 1)
        {
            g[a[i]].push_back(a[i] / 3);
        }
        if (isPresent[a[i] * 2] == 1)
        {
            g[a[i]].push_back(a[i] * 2);
        }
    }
    f(i,n)
    {
        if(!visited[a[i]])
        {
            dfs(a[i]);
        }
    }

        while (!ans.empty())
        {
            cout << ans.top() << " ";
            ans.pop();
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