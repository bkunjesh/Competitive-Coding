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

vector<vector<int>> a(501, vector<int>(501));
bool check()
{
    int i, j, k;
    for (i = 1; i <= m; i++)
    {
        k = 1;
        for (j = i; j <= m && k <= n; j++)
        {
            if (a[k][j] != a[1][i])
                return false;
            k++;
        }
    }

    for (i = 1; i <= n; i++)
    {
        k = 1;
        for (j = i; j <= n && k <= m; j++)
        {
            if (a[j][k] != a[i][1])
                return false;
            k++;
        }
    }

    return true;
}

void solve()
{
    int i, j, k, q;

    cin >> n >> m;
    rep(i, n) rep(j, m) cin >> a[i][j];
    cin >> q;
    int mismatch = 0;
    for (i = 2; i <= n; i++)
    {
        for (j = 2; j <= m; j++)
        {
            mismatch += (a[i][j] != a[i - 1][j - 1]);
        }
    }

    while (q--)
    {
        int x, y, v;
        cin >> x >> y >> v;
        //cout << a[2][2] << " ";
        if (x - 1 >= 1 and y - 1 >= 1)
            mismatch -= (a[x][y] != a[x - 1][y - 1]);

        if (x + 1 <= n and y + 1 <= m)
            mismatch -= (a[x][y] != a[x + 1][y + 1]);

        a[x][y] = v;

        if (x - 1 >= 1 and y - 1 >= 1)
            mismatch += (a[x][y] != a[x - 1][y - 1]);

        if (x + 1 <= n and y + 1 <= m)
            mismatch += (a[x][y] != a[x + 1][y + 1]);

        if (mismatch == 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

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