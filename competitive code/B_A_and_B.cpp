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
    int ans = 0;
    if (a > b)
        swap(a, b);

    int diff = b - a;
    n = 0;
    while (!((n * (n + 1) / 2 >= diff) && ((n * (n + 1) / 2 - diff)%2==0)))
        n++;

    cout << n << endl;
    // i = 1;
    // while (a < b)
    // {
    //     a += i;
    //     i++;
    //     ans++;
    //     if (a == b - 1)
    //     {
    //         cout << ans + 2 << endl;
    //         return;
    //     }
    // }
    // cout << ans + (a - b) << endl;

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