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
int dp[2005][2005];
int a[2005][2005];
int getans(int i, int j)
{
    int turn = 1;
    if ((i + j) % 2)
        turn = 0;
    if (i >= n - 1 && j >= m - 1)
        return 0;

    int &res = dp[i][j];
    if (res != -1)
        return res;

    if (turn)
    {
        res = -inf;
        if (i + 1 < n)
            res = max(res, getans(i + 1, j) + a[i + 1][j]);
        if (j + 1 < m)
            res = max(res, getans(i, j + 1) + a[i][j + 1]);
    }
    else
    {
        res = inf;
        if (i + 1 < n)
            res = min(res, getans(i + 1, j) - a[i + 1][j]);
        if (j + 1 < m)
            res = min(res, getans(i, j + 1) - a[i][j + 1]);
    }
    return res;
}

void solve()
{
    int i, j, k;
    cin >> n >> m;
    char ch;
    memset(dp, -1, sizeof(dp));
    f(i, n) f(j, m) cin >> ch, a[i][j] = (ch == '+') ? 1 : -1;
    k = getans(0, 0);
    // f(i, n)
    // {
    //     f(j, m) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    //cout << k << endl;
    if (k == 0)
    {
        cout << "Draw";
    }
    else if (k > 0)
    {
        cout << "Takahashi";
    }
    else
    {
        cout << "Aoki";
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