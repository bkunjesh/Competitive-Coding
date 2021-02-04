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
    int upper[n], lower[n], flag = 0, usumo = 0, usume = 0, lsumo = 0, lsume = 0;
    f(i, n) cin >> upper[i] >> lower[i], (upper[i] % 2 == 0) ? usume++ : usumo++, (lower[i] % 2 == 0) ? lsume++ : lsumo++, flag = (upper[i] % 2 != lower[i] % 2) ? 1 : flag;

    if (usumo % 2 == 0 && lsumo % 2 == 0)
    {
        cout << 0 << endl;
        return;
    }
    else if (usumo % 2 == 1 && lsumo % 2 == 1 && flag)
    {
        cout << 1 << endl;
        return;
    }
    else
    {
        cout << -1 << endl;
    }

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