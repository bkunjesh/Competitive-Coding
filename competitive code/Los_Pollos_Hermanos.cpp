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
int N = 100005;

int n;
int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
int modInverse(int b, int m)
{
    int x, y;
    int g = gcdExtended(b, m, &x, &y);
    if (g != 1)
        return -1;
    return (x % m + m) % m;
}
int modDivide(int a, int b, int m)
{
    a = a % m;
    int inv = modInverse(b, m);
    return (inv * a) % m;
}
bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return a.F > b.F;
}
void solve()
{
    int i, j, k;

    cin >> n;
    vector<pair<int, int>> a;
    vector<int> ans(n + 1);
    a.push_back({0, 0});
    rep(i, n) cin >> j, a.push_back({j, i});
    sort(a.begin() + 1, a.end(), comp);
    rep(i, n)
    {
        //cout << a[i].F << " ";
        int val = (1 << (n - i));
        //val = ((val % mod) * (1+(i-1) + (((i - 1) * (i - 2)) / 2) % mod)%mod) % mod;
        int val2 = (val * (i - 1)) % mod;
        int val3 = (val * ((((i - 1) * (i - 2))%mod) * modInverse(2, mod)) % mod) % mod;

        val = (val - 1 + mod) % mod;

        ans[a[i].S] = val + val2 + val3;
    }
    rep(i, n) cout << ans[i] << " ";
    cout << endl;

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