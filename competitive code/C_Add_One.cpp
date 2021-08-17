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
// void pre()
// {
//     vector<vector<map<int, int>>> a(N+1,vector(10));
//     for(i,10)
//         a[0][i][i]++;

//     rep(i,N)
//     {
//         auto prev = a[i - 1];
//         auto m = a[i];
//         int temp = m[0];
//         for (j = 0; j < 10;j++)
//         {
//             m[j] = prev[(j - 1 + 9) % 9];
//         }

//     }
// }
int dp[10][N];
void pre()
{
    int i, j, k;
    memset(dp, 0, sizeof(dp));
    for (i = 0; i < 10; i++)
        dp[i][0] = 1;
    for (i = 1; i < N; i++)
    {
        for (j = 0; j < 9; j++)
        {
            dp[j][i] = dp[j + 1][i - 1];
        }
        dp[9][i] = ((dp[0][i - 1] % mod) + (dp[1][i - 1] % mod)) % mod;
    }
}

void solve()
{
    int i, j, k, m;
    cin >> n >> m;

    int ans = 0;

    while (n)
    {
        ans = ((ans % mod) + (dp[n % 10][m] % mod)) % mod;
        n /= 10;
    }
    cout << ans << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    pre();
    cin >> t;
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