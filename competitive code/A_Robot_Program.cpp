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
    int i, j, k;

    cin >> j >> k;
    int ans = 0;
    int mn = min(j, k);
    // if(mn%2!=0)
    // {
    //     ans = 2 * mn - 1;
    // }
    // else
    {
        ans = 2 * mn;
    }
    
    
    int d = max(j, k) - mn;
    if(d!=0)
    if (d % 2 != 0)
    {
        ans = ans + 2 * d - 1;
    }
    else
    {
        ans = ans + 2 * d-1;
    }

    cout << ans << endl;

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