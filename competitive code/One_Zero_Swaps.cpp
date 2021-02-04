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
    string s, p;
    cin >> s >> p;
    int zcnts = 0, ocnts = 0, zcntp = 0, ocntp = 0;
    f(i, n) if (s[i] != p[i])
    {
        if (s[i] == '0')
            zcnts++;
        else
            ocnts++;
        if (p[i] == '0')
            zcntp++;
        else
            ocntp++;
        if(zcnts>ocnts)
        {
            cout << "No" << endl;
            return;
        }
    }
    if (ocnts == ocntp && zcntp == zcnts)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
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