//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e18;
const int N = 200005;

int n;
vector<int> g[N], visited(N);

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n + 1), ans(n + 1, inf);
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i - a[i] > 0)
        {
            g[i - a[i]].push_back(i);
        }
        if (i + a[i] <= n)
        {
            g[i + a[i]].push_back(i);
        }
    }

    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = 1;
    while (!q.empty())
    {
        int node = q.front().first;
        int time = q.front().second;
        q.pop();

        ans[node] = min(ans[node], time);

        for (auto child : g[node])
        {
            if (!visited[child])
            {
                q.push({child, time + 1});
                visited[child] = 1;
            }
        }
    }

    for (i = 1; i <= n; i++)
    {
        if (ans[i] == inf)
        {
            cout << -1 << endl;
        }
        else
            cout << ans[i] << endl;
    }

    return;
}

signed main()
{
    int t = 1, i, j, k;
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