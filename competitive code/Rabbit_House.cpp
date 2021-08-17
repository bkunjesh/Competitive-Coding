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
const int N = 302;
const int M = 302;

int n, m;

void solve()
{
    int i, j, k;

    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    map<pair<int, int>, int> visited;
    int mxval = -1;
    f(i, n)
    {
        f(j, m)
        {
            cin >> a[i][j];
            if (a[i][j] > mxval)
            {
                mxval = a[i][j];
            }
        }
    }
    queue<pair<int, int>> q;
    f(i, n)
    {
        f(j, m)
        {
            if (a[i][j] == mxval)
            {
                q.push({i, j});
                visited[{i, j}] = 1;
            }
        }
    }
    auto isvalid = [&](int x, int y) {
        if (x >= 0 && x < n && y >= 0 && y < m && visited[{x, y}] == 0)
            return 1;

        return 0;
    };
    vector<int> dx = {1ll, -1ll, 0ll, 0ll};
    vector<int> dy = {0ll, 0ll, 1ll, -1ll};
    int ans = 0;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            auto p = q.front();
            int parentstack = a[p.F][p.S];
            // cout << parentstack << endl;
            q.pop();

            for (i = 0; i < 4; i++)
            {
                int curx = p.F + dx[i], cury = p.S + dy[i];
                if(visited[{curx,cury}])
                {
                    while (abs(parentstack - a[curx][cury])>1)
                        ;
                }
                if (isvalid(curx, cury))
                {
                    visited[{curx, cury}] = 1;
                    q.push({curx, cury});
                    ans = ans + max(((parentstack - 1) - a[curx][cury]), 0ll);
                    a[curx][cury] = max(a[curx][cury], parentstack - 1);
                }

            }
        }
    }
    // cout << endl;
    // f(i, n)
    // {
    //     f(j, m)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
    for (i = 1; i <= t; i++)
    {
        cout << "case #" << i << ": ";
        solve();
    }
    return 0;
}
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif