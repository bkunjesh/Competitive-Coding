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

    cin >> n;
    //let say p element is in one of the total way ans
    //(2*a+p-1)*p=2*n
    n = 2 * n;
    int ans = 0;
    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            if (((n / i) + 1 - i) % 2 == 0 && ((n / i) + 1 - i) > 0)
                ans++;
            if ((i + 1 - n / i) % 2 == 0 && (i + 1 - n / i) > 0)
                ans++;
        }
    }
    cout << ans*2 << endl;

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