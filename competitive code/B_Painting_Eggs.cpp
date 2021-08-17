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
    vector<int> a(n), g(n);
    f(i, n) cin >> a[i] >> g[i];
    string ans = "";
    int gs = 0, as = 0;
    f(i, n)
    {
        if (abs(a[i] + as - gs) < abs(g[i] + gs - as))
        {
            as += a[i];
            ans += 'A';
        }
        else
        {
            gs += g[i];
            ans += 'G';
        }
        // if(gs==as)
        // {
        //     if(g[i]<a[i])
        //     {
        //         gs += g[i];
        //         ans += 'G';
        //     }
        //     else
        //     {
        //         as += a[i];
        //         ans += 'A';
        //     }
        // }
        // else if(gs<as)
        // {
        //     gs += g[i];
        //     ans += 'G';
        // }
        // else if(gs>as)
        // {
        //     as += a[i];
        //     ans += 'A';
        // }
    }
    //cout << as << " " << gs << endl;
    if (abs(gs - as) <= 500)
        cout << ans << endl;
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif