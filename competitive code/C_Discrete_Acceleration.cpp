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
const int N = 1e7;

int n;

void solve()
{
    int i, j, k, l;

    cin >> n >> l;
    l *= N;

    vector<int> a(n + 3);
    a[0] = 0;
    rep(i, n) cin >> a[i], a[i] *= (N);
    a[n + 1] = l;

    cout << setprecision(7) << fixed;
    auto dist = [&](long double t, int ind, int k)
    {
        long double d = a[ind], speed = 1.0;
        while (t > 0&&ind>=0&&ind<=n+1)
        {
            long double x = abs(a[ind] - a[ind + k]) / speed;
            if (t * speed >= abs(a[ind] - a[ind + k]))
            {
                d = a[ind + k];
                t -= x;
            }
            else
            {
                d += (speed * t * k);
                t = 0;
            }
            speed += 1.0;
            ind += k;
        }
        return d;
    };

    int low = 0, high = l, ans = 0;
    while (low <= high)
    {
        int mid = (low + (high - low) / 2);

        long double d1 = dist(mid, 0, 1) / 10000000.0;
        long double d2 = dist(mid, n + 1, -1) / 10000000.0;
        // cout << mid << endl;
        // cout << d1 << " " << d2 << " " << (d1 == d2) << endl;
        if (d1 == d2)
        {
            ans = mid;
            break;
        }
        if (d1 >= d2)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    double res = (double)(ans) / N;
    cout << res << endl;

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