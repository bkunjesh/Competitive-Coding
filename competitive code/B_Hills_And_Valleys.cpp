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
bool check(int prev, int cur, int next)
{
    return (prev > cur && cur < next) || (prev < cur && cur > next);
}
void solve()
{
    int i, j, k, ans = 0;

    cin >> n;
    int a[n];
    f(i, n) cin >> a[i];
    int tobecnted[n] = {0};
    for (i = 1; i < n - 1; i++)
    {
        if (check(a[i - 1], a[i], a[i + 1]))
        {
            tobecnted[i] = 1;
            ans++;
        }
    }
    int minus = 0;
    //cout << ans << " ";
    for (i = 1; i < n - 1; i++)
    {
        int temp = tobecnted[i - 1] + tobecnted[i] + tobecnted[i + 1], t1 = 0, t2 = 0;
        if (i + 2 < n)    t1 = check(a[i - 1], a[i + 1], a[i + 2]);
        if (i - 2 >= 0)   t2 = check(a[i - 2], a[i - 1], a[i + 1]);
        minus = max(minus, max(temp - t1, temp - t2));
    }
    //cout << minus << " ";

    cout << ans - minus << endl;

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