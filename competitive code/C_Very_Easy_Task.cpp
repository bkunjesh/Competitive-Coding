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

    int x, y;
    cin >> n >> x >> y;

    auto check = [&](int m) {
        int timeleft = m - min(x, y), copy = 1;
        if (timeleft >= 0)
            copy += (timeleft / x + timeleft / y);
        else
            return 0;

        // cout << copy << endl;
        if (copy >= n)
            return 1;
        else
            return 0;
    };

    int l = 1, r = 1e11, ans;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        // cout << l << " " << r << " " << mid << endl;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
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