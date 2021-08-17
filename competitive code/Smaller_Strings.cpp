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
int pro(int x, int y)
{
    return ((x % mod) * (y % mod)) % mod;
}
void solve()
{
    int i, j, k, m;

    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    j = (n + 1) / 2;
    for (i = 0; i < (n) / 2; i++)
    {
        m = min(s[i] - 'a' + 1ll, k);
        ans += pro((m - 1), (power(k, j - i - 1)));
        ans %= mod;
    }
    if(n%2)
    {
        ans += (s[n / 2] - 'a');
        ans %= mod;
    }
    for (i = n / 2 - 1; i >= 0;i--)
    {
        if(s[i]<s[n-i-1]){
            ans++;
            break;
        }
        else if(s[i]>s[n-i-1])
            break;
    }
    ans %= mod;
    cout << ans << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
    rep(j, t)
    {
        cout << "Case #" << j << ": ";
        solve();
    }
    return 0;
}
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif