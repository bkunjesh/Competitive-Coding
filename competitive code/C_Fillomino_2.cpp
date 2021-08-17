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

int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<int>> a(501, vector<int>(501, 0));
bool isvalid(int x, int y, int m)
{
    if (x >= 0 && x < n && y >= 0 && y <= m && a[x][y] == 0)
        return 1;
    return 0;
}
int cnt;
void dfs(int x, int y, int val)
{
    a[x][y] = val;
    cnt++;
    if (cnt == val)
        return;

    for (int j = 0; j < 4; j++)
    {
        if (cnt == val)
            return;
        int cx = x + dx[j];
        int cy = y + dy[j];
        if (isvalid(cx, cy, m))
        {
            dfs(cx, cy, val);
        }
    }
}
void solve()
{
    int i, j, k;

    cin >> n;
    f(i, n) cin >> a[i][i];

    for (i = n - 1; i >= 0; i--)
    {
        m = i;
        cnt = 0;
        dfs(i, i, a[i][i]);
    }
    f(i, n)
    {
        for (j = 0; j <= i; j++)
            cout << a[i][j] << " ";
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