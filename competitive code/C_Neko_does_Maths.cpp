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
    if(a>b)
        swap(a, b);
    int diff = b - a;
    if(diff==0)
    {
        cout << 0 << endl;
        return;
    }

    auto lcm = [&](int x, int y) {
        return (x * y) / __gcd(x, y);
    };

    int ans = 0, res = inf;

    for (i = 1; i * i <= diff; i++)
    {
        if(diff%i==0)
        {
            int val = (i - a % i + i) % i;
            int z = lcm(a + val, b + val);

            if(z<res)
                res = z, ans = val
;
            else if(res==z&&val<ans)
                ans = val
;

            int i_ = diff / i;
            val = (i_ - a % i_ + i_) % i_;
            z = lcm(a + val, b + val);

            if(z<res)
                res = z, ans = val
;
            else if (res == z && val < ans)
                ans = val
;
        }
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