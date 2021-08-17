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
    int i, j, k;

    int a, b;
    cin >> a >> b;
    // int z = b*10;
    // int x = 1;
    // int y = b*10 - 1;
    // x *= a;
    // y *= a;
    // z *= a;
    // if (x > 0 && y > 0 && z > 0)
    // {
    //     cout << "YES" << endl;
    //     cout << x << " " << y << " " << z << endl;
    // }
    // else
    // {
    //     cout << "NO" << endl;
    // }
    //cout << (30*42) / (__gcd(30, 42) * __gcd(30, 42));
    int p = (a * b) / (__gcd(a, b) * __gcd(a, b));
    int q = b / (__gcd(a, b));
    int z = p;
    int x = 1;
    int y = p - 1;
    while (y > 0 && (x % q == 0 || y % q == 0))
    {
        x++, y--;
    }
    x *= a;
    y *= a;
    z *= a;
    if (a % b != 0&&y>0 && x % b != 0 && y % b != 0 && x != y)
    {
        cout << "YES" << endl;
        cout << x << " " << y << " " << z << endl;
        return;
    }
    // int p = b;
    // for (i = 1; i < 100; i++)
    // {
    //     p = b * i;
    //     int z = p;
    //     int x = 1;
    //     int y = p - 1;
    //     x *= a;
    //     y *= a;
    //     z *= a;
    //     if (x % b != 0 && y % b != 0 && x != y)
    //     {
    //         cout << "YES" << endl;
    //         cout << x << " " << y << " " << z << endl;
    //         return;
    //     }
    // }
    cout << "NO" << endl;
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