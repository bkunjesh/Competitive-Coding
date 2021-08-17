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
const int ten = 1e10;
double get_d(int x)
{
    return (x) / (12 * ten);
}
int get_hour(double d)
{
    return 12 * d / 360;
}
int get_min(double d)
{
    return 60 * d / 360;
}
int get_sec(double d)
{
    return 60 * d / 360;
}
int get_nsec(double d)
{
    return d * 1e9 / 6;
}
void solve()
{
    int i, j, k;
    int a, b, c;
    cin >> a >> b >> c;
    double hour_d = get_d(a);
    double min_d = get_d(b);
    double sec_d = get_d(c);
    double nsec_d = sec_d - get_sec(sec_d) / 6;
    // cout << hour_d << " " << min_d << " " << sec_d << endl;
    cout << get_hour(hour_d) << " " << get_min(min_d) << " " << get_sec(sec_d) << " " << get_nsec(nsec_d) << endl;
    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
    rep(test, t)
    {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif