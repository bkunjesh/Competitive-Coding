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
int nFactorial()
{
    int ans = 1;
    rep(i, n)
    {
        ans = ((ans % mod) * (i % mod)) % mod;
    }
    return ans;
}
int n_1pow()
{
    int ans = 1;
    rep(i, n - 1) ans = ((ans % mod) * (2 % mod)) % mod;
    return ans;
}


void solve()
{
    int i, j, k;

    cin >> n;
    cout << (nFactorial() - n_1pow()+mod)%mod << endl;

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