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

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};
bool isValid(int x, int y, int n, int m)
{
    return (x >= 0 and x < n and y >= 0 and y < m);
}

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> ans(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                vis[i][j] = true;
                q.push({i, j});
            }
        }
    }
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            
            if (isValid(x + dx[k], y + dy[k], n, m) and !vis[x + dx[k]][y + dy[k]] and grid[x + dx[k]][y + dy[k]] == 1)
            {
                
                q.push({x + dx[k], y + dy[k]});
                grid[x + dx[k]][y + dy[k]] = 2;
                ans[x + dx[k]][y + dy[k]] = ans[x][y] + 1;
                vis[x + dx[k]][y + dy[k]] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (grid[i][j] == 1)
                return -1;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res = max(res, ans[i][j]);
        }
    }
    return res;
}

void solve()
{
    int i, j, k;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    f(i, n) f(j, m) cin >> grid[i][j];

    cout << orangesRotting(grid);

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