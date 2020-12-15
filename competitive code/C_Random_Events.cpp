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
    cout.precision(10);
    cout << fixed;
    int i, j, k, m, lastdif = -1;

    cin >> n >> m;
    vector<int> a(n + 1);
    rep(i, n) cin >> a[i], lastdif = (a[i] != i) ? i : lastdif;
    double ans = 1.0;
    if (lastdif == -1)
    {
        ans = 0.0;
    }
    while (m--)
    {
        double p;
        cin >> i >> p;
        if (i >= lastdif)
        {
            ans *= (1 - p);
        }
    }
    cout << (1 - ans) << endl;

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