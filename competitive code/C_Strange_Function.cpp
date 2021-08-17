//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;
int mul(int a, int b)
{
    return ((a % mod) * (b % mod)) % mod;
}
int add(int a, int b)
{
    return ((a % mod) + (b % mod)) % mod;
}

void solve()
{
    int i, j, k;

    cin >> n;
    if (n == 1)
    {
        cout << 2 << endl;
        return;
    }
    int ptr = 1, cnt = 1, ans = 0, p = n;
    while (p > 0)
    {
        int x = (p - n / ptr);
        p -= x;
        ans = add(ans, mul(x, cnt));
        cnt++;
        ptr = __gcd(ptr,cnt);
        // if (ptr > 1e17)
        // {
        //     cout << p << " <- p cnt-> "<<cnt << endl;
        //     break;
        // }
    }
    cout << ans << endl;

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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif