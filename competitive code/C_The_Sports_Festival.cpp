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
const int N = 2e3 + 4;
int n;
int dp[N][N];
int getans(vector<int> &a, int l, int r)
{
    int &res = dp[l][r];
    if (res != -1)
        return res;
    if (l == r)
        return 0;
    res = a[r] - a[l] + min(getans(a, l + 1, r), getans(a, l, r - 1));
    return res;
}
void solve()
{
    int i, j, k;
    memset(dp, -1, sizeof(dp));

    cin >> n;
    vector<int> a(n);
    f(i, n)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << getans(a, 0, n - 1) << endl;
    

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