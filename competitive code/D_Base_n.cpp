
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
string x, s;
int m, isMore = 1;

bool pbase(int p)
{
    int val = 0, pw = 1;
    int flag = 0;

    int i = 0;

    while (s[i] - '0' == 0)
    {
        i++;
        pw *= p;
        if ((pw > 1e18 || pw <= 0))
            return 0;
    }

    for (; i < n; i++)
    {
        val += (s[i] - '0') * pw;

        //dbg(val);

        if (val > m || val <= 0)
            return 0;
        pw *= p;
        //dbg(pw);

        if (i != n - 1 && (pw > 1e18 || pw <= 0))
            return 0;
    }
    // cout<<p<<" "<<val<<endl;
    return val <= m;
}

void solve()
{
    int i, j, k;

    cin >> x >> m;
    s = x;
    reverse(s.begin(), s.end());
    n = x.size();

    int mx = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        int p = (x[i] - '0');
        mx = max(mx, p);
    }
    int d;
    if (n == 1)
        d = (x[0] - '0');
    if (n == 1 && d > m)
    {
        cout << 0 << endl;
        return;
    }
    else if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    int l = mx + 1, h = 1e18 + 1, val = mx;
    while (l <= h)
    {
        int mid = (l + (h - l) / 2);
        if (pbase(mid))
        {
            val = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    //dbg(pbase(3));

    ans = val - mx;
    // if (pbase(val)) ans = val - mx;
    // else ans = 0;
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