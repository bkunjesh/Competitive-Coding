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
    cin >> x >> y;
    n = sqrt(x + y);
    if (n * n != x + y)
    {
        cout << "NO" << endl;
        return;
    }

    if (n == 1)
    {
        if (x == 1)
        {
            cout << "YES" << endl;
            cout << 1 << endl;
            return;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    else
    {
        int even = 1, odd = n - 1;
        while (odd >= 1 && (2 * even * odd != y))
        {
            even++;
            odd--;
        }
        if (odd == 0)
        {
            cout << "NO" << endl;
            return;
        }

        cout << "YES" << endl;
        cout << n << endl;
        int node = 2;
        rep(i, odd)
        {
            cout << 1 << " " << node << endl;
            node++;
        }
        even--;
        rep(i, even)
        {
            cout << "2 " << node << endl;
            node++;
        }
    }

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