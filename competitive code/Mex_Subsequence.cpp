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

int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b % 2)
            b--, res = (res % mod * a % mod) % mod;
        else
            b = b / 2, a = (a % mod * a % mod) % mod;
    }
    return res;
}

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n+1,0);
    map<int, int> m;

    rep(i, n) cin >> a[i], m[a[i]]++;
    int mex = 0;

    while(m[mex]!=0)
        mex++;
    // cout << mex << " ";
    if (mex == 0)
    {
        cout << power(2, n - 1) << endl;
        return;
    }

    vector<int> dp(n + 2,0), prefsumdp(n + 2,0), ind(n + 2,0);

    dp[0] = prefsumdp[0] = 1;

    multiset<int> index;
    f(i, mex) index.insert(0);

    for (i = 1; i <= n; i++)
    {
        if (a[i] < mex)
        {
            auto it = index.find(ind[a[i]]);
            index.erase(it);
            ind[a[i]] = i;
            index.insert(i);
        }
        int prev_ind = (*index.begin());
        if (prev_ind != 0)
            dp[i] = prefsumdp[prev_ind - 1];

        prefsumdp[i] = (prefsumdp[i - 1]%mod + dp[i]%mod) % mod;
    }

    cout << dp[n] << endl;

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

