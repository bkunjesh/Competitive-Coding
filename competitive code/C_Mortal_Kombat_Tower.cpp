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
const int inf = 1e9;
const int N = 2e5 + 5;

int n;
int dp[N][2];

vector<int> a(N);
int mkt(int pos, int turn)
{
    if (pos > n)
    {
        return 0;
    }
    int &ans = dp[pos][turn];
    if (ans != -1)
        return ans;

    ans = inf;
    if (turn == 0)
    {
        ans = min(mkt(pos + 1, 1), mkt(pos + 2, 1));
    }
    else
    {
        ans = min(a[pos] + mkt(pos + 1, 0), a[pos] + a[pos + 1] + mkt(pos + 2, 0));
    }

    return ans;
}
void solve()
{
    int i, j, k;

    cin >> n;
    rep(i, n) cin >> a[i],dp[i][0]=-1,dp[i][1]=-1;
    

    cout << mkt(1, 1) << endl;

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