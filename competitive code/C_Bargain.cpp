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
int power(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = ((res % mod) * (a % mod)) % mod;
        }
        n >>= 1;
        a = ((a % mod) * (a % mod)) % mod;
    }
    return res;
}

int n;
int sum(int x,int y)
{
    return ((x % mod) + (y % mod)) % mod;
}
int prod(int x,int y)
{
    return ((x % mod) * (y % mod)) % mod;
}

void solve()
{
    int i, j, k;

    string s;
    cin >> s;
    n = s.size();
    
    vector<int> pref(n + 5),ten(n+5),dp(n+5,0);
    pref[0] = s[0] - '0',ten[0]=1;
    rep(i, n - 1) pref[i] = pref[i - 1] + (s[i] - '0'),pref[i]%=mod;
    rep(i, n) ten[i] = ten[i - 1] * 10, ten[i] %= mod;
    int ans = 0;
    f(i, n) 
    {
        // dp[i] = ten[n - i - 1] ;
        int x = i * (i + 1) / 2;
        dp[i] = sum(dp[i], prod(x, ten[n - i - 1]));
        ans = sum(ans, prod(dp[i], (s[i] - '0')));
    }

    for (i = 0; i < n - 1;i++)
    {
        ans = sum(ans, prod(prod(i + 1, ten[i]), pref[n - 1 - (i + 1)]));
    }

    cout << ans << endl;

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