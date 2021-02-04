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
    int i, j, k, o = 0;

    cin >> n >> k;
    int a[n + 1];
    a[0] = 0;
    rep(i, n) cin >> a[i], o += (a[i] % 2 == 0) ? 0 : 1;

    if (k%2==o%2 && k <= o )
    {
        cout << "YES" << endl;
        int sum = 0;
        j = 0;
        for (i = 1; i <= n && j < k - 1; i++)
        {
            sum += a[i];
            if (sum % 2 == 1)
            {
                cout << i << " ";
                sum = 0;
                j++;
            }
        }
        cout << n << " " << endl;
    }
    else
    {
        cout << "NO" << endl;
        return;
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