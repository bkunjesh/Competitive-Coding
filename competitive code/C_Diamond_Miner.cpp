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
double dist(int x, int y)
{
    return sqrt(x * x + y * y);
}

void solve()
{
    int i, j, k;

    cout << setprecision(15) << fixed;

    cin >> n;
    vector<int> d, m;

    f(i, 2 * n)
    {
        int x, y;
        cin >> x >> y;
        if (x == 0)
        {
            m.push_back(abs(y));
        }
        else
        {
            d.push_back(abs(x));
        }
    }
    sort(m.begin(), m.end());
    sort(d.begin(), d.end());

    double ans = 0;

    f(i, n)
    {
        ans += dist(m[i], d[i]);
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