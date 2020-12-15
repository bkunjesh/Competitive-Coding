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
const int N = 1005;

int n, m;
vector<vector<char>> grid(1005, vector<char>(1005));
vector<vector<bool>> visited(1005, vector<bool>(1005, 0));
map<pair<int, int>, pair<int, int>> parent;
pair<int, int> start, dest;
bool isvalid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || grid[x][y] == '#')
        return 0;
    else
        return 1;
}
void bfs()
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.F][start.S] = 1;
    int X[4] = {1, -1, 0, 0};
    int Y[4] = {0, 0, 1, -1};
    while (!q.empty())
    {
        pair<int, int> curr = q.front();

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = X[i] + curr.F;
            int y = Y[i] + curr.S;
            if (isvalid(x, y))
            {
                q.push({x, y});
                parent[{x, y}] = curr;
                visited[x][y] = 1;
            }
        }
    }
}

void solve()
{
    int i, j, k;

    cin >> n >> m;
    f(i, n)
    {
        f(j, m)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
            if (grid[i][j] == 'B')
            {
                dest = {i, j};
            }
        }
    }

    bfs();
    if(visited[dest.F][dest.S]==0)
    {
        cout << "NO" << endl;
        return;
    }
    vector<char> ans;
    pair<int, int> cur = dest;
    pair<int, int> par = parent[dest];
    while (cur != start)
    {
        if ((cur.F - par.F) != 0)
        {
            ((cur.F - par.F) == 1) ? ans.push_back('D') : ans.push_back('U');
        }
        else
        {
            (cur.S - par.S == 1) ? ans.push_back('R') : ans.push_back('L');
        }
        cur = par;
        par = parent[cur];
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (auto it : ans)
        cout << it;
    cout << endl;

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