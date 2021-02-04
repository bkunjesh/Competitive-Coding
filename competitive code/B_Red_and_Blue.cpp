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
    int i, j, k, m;

    cin >> n;
    vector<int> r(n), prefr(n + 1, 0);
    f(i, n) cin >> r[i];
    prefr[0] = r[0];
    rep(i, n - 1) prefr[i] = prefr[i - 1] + r[i];
    //cout << prefr[i] << " ";
    // cout << endl;

    cin >> m;
    vector<int> b(m), prefb(m + 1, 0);
    f(i, m) cin >> b[i];
    prefb[0] = b[0];
    rep(i, m - 1) prefb[i] = prefb[i - 1] + b[i];

    vector<int> rsum, bsum;
    rsum.push_back(0);
    bsum.push_back(0);

    f(i, n)
    {
        for (j = i; j < n; j++)
        {
            if (i > 0)
                rsum.push_back(prefr[j] - prefr[i - 1]);
            else
            {
                rsum.push_back(prefr[j]);
            }
        }
    }
    f(i, m)
    {
        for (j = i; j < m; j++)
        {
            if (i > 0)
                bsum.push_back(prefb[j] - prefb[i - 1]);
            else
            {
                bsum.push_back(prefb[j]);
            }
        }
    }
    int rmax = *max_element(prefr.begin(), prefr.end()), bmax = *max_element(prefb.begin(), prefb.end());
    if (rmax > 0 && bmax > 0)
    {
        cout << rmax + bmax << endl;
    }
    else
    {
        cout << max(max(max(rmax, bmax), rmax + bmax), 0ll) << endl;
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