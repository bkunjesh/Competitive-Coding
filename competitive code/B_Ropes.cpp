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

    cin >> n >> k;
    vector<int> a(n);
    f(i, n) cin >> a[i], a[i] *= 1000000;

    auto isCheck = [&](int len) {
        int pieces = 0;
        f(i, n)
        {
            pieces += a[i] / len;
        }
        if (pieces >= k)
            return 1;
        else
            return 0;
    };

    int l = 0, h = 1e14;
    double ans;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (isCheck(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    cout << fixed << setprecision(7);
    cout << ans / 1e6 << endl;

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