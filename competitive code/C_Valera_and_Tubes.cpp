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

int n, m, k, p;
int visited[305][305];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> ans[100000];

bool isvalid(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y])
        return 1;
    return 0;
}
int X, Y;

void dfs(int i, int j, int q, int nodecnt)
{
    X = i, Y = j;
    if (q != k && nodecnt >= p)
        return;
    visited[i][j] = 1;
    ans[q].push_back(i);
    ans[q].push_back(j);
    for (int r = 0; r < 4; r++)
    {
        int x = dx[r] + i, y = dy[r] + j;
        if (isvalid(x, y))
        {
            dfs(x, y, q, nodecnt + 1);
            break;
        }
    }
}
void solve()
{
    int i, j, q, r, s, t;
    cin >> n >> m >> k;
    p = n * m / k;

    X = 0, Y = 0;
    rep(q, k)
    {
        dfs(X, Y, q, 0);
    }

    for (i = 1; i <= k; i++)
    {
        cout << ans[i].size() / 2 << " ";
        for (auto it : ans[i])
            cout << it + 1 << " ";
        cout << endl;
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