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

int ncr(int n, int r)
{
    r = min(n - r, r);
    int ans = 1;
    for (int i = 1; i <= r; i++)
    {
        ans = (ans * (n - (i - 1)));
    }
    for (int i = 1; i <= r; i++)
    {
        ans = (ans / i);
    }
    return ans;
}

int n;

void solve()
{
    int i, j, k;
    vector<int> fact(11, 1);
    rep(i, 10) fact[i] = fact[i - 1] * i;

    cin >> n;
    n /= 2;

    cout << (ncr(2 * n, n) / 2) * (fact[n - 1]) * (fact[n - 1]) << endl;

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