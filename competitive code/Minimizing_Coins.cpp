//@CodesUp
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
const int inf = 1e9;
int N = 1000001;

int n;

void solve()
{
    int i, j, k, x;

    cin >> n >> x;
    vector<int> a(n + 1);

//---------------------------------------------------------------------------------
//  1-d array solution
//---------------------------------------------------------------------------------
    // f(i, n) cin >> a[i];
    // vector<int> dp(x + 1, inf);
    // dp[0] = 0;
    // for (i = 1; i <= x;i++)
    // {
    //     for (j = 0; j < n;j++)
    //     {
    //         if(i-a[j]>=0)
    //         {
    //             dp[i] = min(dp[i], dp[i - a[j]] + 1);
    //         }
    //     }
    // }
    // if(dp[x]==inf)
    //     cout << -1 << endl;
    // else
    //     cout << dp[x] << endl;
//----------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------
//  Mine 2-d solution
//-----------------------------------------------------------------------------------
    rep(i, n) cin >> a[i];
    sort(a.begin() + 1, a.end());
    vector<vector<int>> dp(n + 1, vector<int>(N, inf));
    f(i, x + 1) dp[0][i] = inf;

    rep(i, n)
    {
        for (j = 0; j <= x; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (a[i] > j)
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            else
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                if (dp[i][j - a[i]] > 0 || a[i] == j)
                    dp[i][j] = min(dp[i][j], dp[i][j - a[i]] + 1);
            }
        }
    }
    int ans = dp[n][x];
    if (ans == inf)
        cout << -1 << endl;
    else
        cout << ans << endl;
//-------------------------------------------------------------------------------------




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