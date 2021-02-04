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

    int m;
    cin >> n >> m >> k;
    int a[n];
    f(i, n) cin >> a[i];
    f(i, n - 1)
    {
        int diff = a[i] - a[i + 1];
        //if (diff >= -k)
        {
            m = m + diff + min(k, a[i + 1]);
        }
        //else
        {
            //m = m - (a[i + 1] - (a[i] + k));
            if (m < 0)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    if (m < 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
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