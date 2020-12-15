//@CodesUp
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
int N = 200005;

int n;

void solve()
{
    int i, j, k, x, flag = 0;

    cin >> n >> x;
    vector<int> a(n);
    map<int, int> m;
    f(i, n) cin >> a[i], m[a[i]]++, flag = (flag || m[a[i]] > 1) ? 1 : 0;
    if (flag)
    {
        cout << 0 << endl;
        return;
    }

    for (i = 0; i < n; i++)
    {
        if ((a[i] & x) == a[i])
            continue;
        a[i] = a[i] & x;
        if (m[a[i]] > 0)
        {
            //cout << i << endl;
            cout << 1 << endl;
            return;
        }
    }
    m.clear();
    f(i, n) m[a[i]]++, flag = (flag || m[a[i]] > 1) ? 1 : 0;
    if (flag)
    {
        cout << 2 << endl;
        return;
    }
    else
        cout << -1 << endl;

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