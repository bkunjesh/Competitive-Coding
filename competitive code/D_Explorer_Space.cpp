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
const int N = 502;

int n, m, k, X, Y;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int visited[N][N], vcost[N][N], hcost[N][N], ans[N][N][21];
bool isValid(int x, int y)
{
    if (x > 0 && x <= n && y > 0 && y <= m && ((abs(x - X) + abs(y - Y)) <= k / 2) && visited[x][y] == 0)
        return 1;
    return 0;
}
void dfs(int x, int y, int len, int cost)
{

    visited[x][y] = 1;

    if (len > k / 2)
        return;
    // if(len%(k/2)==0) 
    ans[X][Y][len] = min(ans[X][Y][len], 2*cost);
    ans[X][Y][k] = min(ans[X][Y][k], 2*cost + ans[X][Y][k/2 - len]);
    // if (len == k / 2)
    // {
    //     ans[X][Y][k] = min(ans[X][Y][k], 2 * cost);
    //     return;
    // }


    for (int i = 0; i < 4; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];

        if (isValid(cx, cy))
        {
            if (i == 0)
            {
                dfs(cx, cy, len + 1, cost + vcost[x][y]);
            }
            else if (i == 1)
            {
                dfs(cx, cy, len + 1, cost + vcost[cx][cy]);
            }
            else if (i == 2)
            {
                dfs(cx, cy, len + 1, cost + hcost[x][y]);
            }
            else if (i == 3)
            {
                dfs(cx, cy, len + 1, cost + hcost[cx][cy]);
            }
        }
    }
}
void solve()
{
    int i, j;

    cin >> n >> m >> k;

    rep(i, n) rep(j, m - 1) cin >> hcost[i][j];
    rep(i, n - 1) rep(j, m) cin >> vcost[i][j];

    rep(i, n)
    {
        if (k % 2)
            break;
        rep(j, m)
        {
            memset(visited, 0, sizeof(visited));
            for (int p = 0; p < 21;p++)
                ans[i][j][0] =0,ans[i][j][p] = inf;
            X = i, Y = j;
            dfs(i, j, 0, 0);
        }
    }
    rep(i, n)
    {
        rep(j, m)
        {
            if (ans[i][j][k] != inf && k % 2 == 0)
            {
                cout << ans[i][j][k] << " ";
            }
            else
            {
                cout << -1 << " ";
            }
        }
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