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

int n;

void solve()
{
    int i, j, k, m;

    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    int sumup[n][m], sumdown[n][m], sumleft[n][m], sumright[n][m];
    f(i, n)
    {
        f(j, m)
        {
            cin >> a[i][j];

            sumup[i][j] = 0, sumdown[i][j] = 0, sumleft[i][j] = 0, sumright[i][j] = 0;
            if (i == 0)
            {
                sumup[i][j] = a[i][j];
            }
            if (i == n - 1)
            {
                sumdown[i][j] = a[i][j];
            }
            if (j == 0)
            {
                sumleft[i][j] = a[i][j];
            }
            if (j == m - 1)
            {
                sumright[i][j] = a[i][j];
            }
        }
    }

    for (j = 0; j < m; j++)
    {
        for (i = 1; i < n; i++)
        {
            if (a[i][j])
                sumup[i][j] = sumup[i - 1][j] + a[i][j];
        }
        for (i = n - 2; i >= 0; i--)
        {
            if (a[i][j])
                sumdown[i][j] = sumdown[i + 1][j] + a[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            if (a[i][j])
            {
                sumleft[i][j] = sumleft[i][j - 1] + a[i][j];
            }
        }
        for (j = m - 2; j >= 0; j--)
        {
            if (a[i][j])
            {
                sumright[i][j] = sumright[i][j + 1] + a[i][j];
            }
        }
    }
    int ans = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            // cout << sumright[i][j] << " ";
            //left-up
            {
                int left = sumleft[i][j];
                int up = sumup[i][j];
                int leftans = max(0ll,min((left / 2), up) - 1ll);
                int upans = max(0ll,min(left, (up / 2)) - 1ll);
                ans = ans + upans + leftans;
            }
            //left-down
            {
                int left = sumleft[i][j];
                int down = sumdown[i][j];
                int leftans = max(0ll,min((left / 2), down) - 1ll);
                int downans = max(0ll,min(left, (down / 2)) - 1ll);
                ans = ans + downans + leftans;
            }
            //right-down
            {
                int right = sumright[i][j];
                int down = sumdown[i][j];
                int rightans = max(0ll,min((right / 2), down) - 1ll);
                int downans = max(0ll,min(right, (down / 2)) - 1ll);
                ans = ans + downans + rightans;
            }
            //right-up
            {
                int right = sumright[i][j];
                int up = sumup[i][j];
                int rightans = max(0ll,min((right / 2), up) - 1ll);
                int upans = max(0ll,min(right, (up / 2)) - 1ll);
                ans = ans + upans + rightans;
            }
        }
        // cout << endl;
    }
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