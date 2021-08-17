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
const int N = 1e7 + 1;

int n;
// int dp[N];

// int getans(int i)
// {
//     if(i==2)
//     {
//         return 3;
//     }
//     else if(i<2)
//     {
//         return 0;
//     }

//     if(dp[i]!=-1)
//         return dp[i];

//     return dp[i]=((getans(i - 1) * 2)%mod + (getans(i - 2) * 3)%mod)%mod;

// }

void solve()
{
    int i, j, k;

    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;

        return;
    }
    // memset(dp, -1, sizeof(dp));
    int pp = 0, p = 3, cur = 3;
    for (i = 3; i <= n; i++)
    {
        // cur = (((p%mod) * 2) % mod + ((pp%mod) * 3) % mod)%mod;
        cur = (p * 2) % mod;
        cur = (cur % mod + (pp * 3) % mod) % mod;
        pp = p;
        p = cur;
    }
    cout << cur % mod << endl;

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