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
int N = 200005;

void dfs(vector<vector<int>> &g, int i, int j, int &c)
{
    int n = g.size();
    if (i < 0 || i == n || j < 0 || j == n || g[i][j] == 0)
    {
        return;
    }
    c++;
    g[i][j] = 0;
    dfs(g, i - 1, j, c);
    dfs(g, i + 1, j, c);
    dfs(g, i, j - 1, c);
    dfs(g, i, j + 1, c);
}

void solve()
{
    int i, j, k, n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(n));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int p;
    cin >> p;
    int flag = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                int c = 0;
                dfs(arr, i, j, c);
                if (c == p)
                {
                    cout << i << " " << j << "\n";
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1)
            break;
    }
    if (flag == 0)
        cout << "-1 -1\n";
    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}