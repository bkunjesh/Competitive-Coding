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

int n;
vector<int> g[N], visited(N), parent(N);

void bfs()
{
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto child : g[node])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = 1;
                parent[child] = node;
                if(child==n)
                {
                    return;
                }
            }
        }
    }
}

void solve()
{
    int i, j, k;

    int m;
    cin >> n >> m;
    f(i, m) cin >> j >> k, g[j].push_back(k), g[k].push_back(j);
    
    bfs();

    if (parent[n] == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<int> ans;
    ans.push_back(n);
    int cur = n;

    while (cur != 1)
    {
        ans.push_back(parent[cur]);
        cur = parent[cur];
    }

    reverse(ans.begin(), ans.end());
    
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it << " ";

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