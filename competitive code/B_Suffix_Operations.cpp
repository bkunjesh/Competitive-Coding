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
    int a[n], sum = 0;
    f(i, n)
    {
        cin >> a[i];
        if (i != 0)
            sum += abs(a[i - 1] - a[i]);
    }
    int y = max(abs(a[1] - a[0]), abs(a[n - 1] - a[n - 2]));
    for (i = 1; i < n - 1; i++)
    {
        y = max(y, abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]) - abs(a[i - 1] - a[i + 1]));
    }
    cout << sum - y << endl;

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