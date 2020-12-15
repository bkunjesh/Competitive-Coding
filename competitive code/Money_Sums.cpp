//@CodesUp
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
int N = 100005;

int n;

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<vector<int>> dp(n + 1, vector<int>(N, 0));
    set<int> s;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < N; j++)
        {
            if (i > 0 && j < a[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            if (i > 0 && j > a[i])
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]]);
            }
            if (a[i] == j)
            {
                dp[i][j] = 1;
            }

            if (dp[i][j])
            {
                s.insert(j);
            }
        }
    }
    cout << s.size() << endl;
    for (auto it : s)
        cout << it << " ";
    cout << endl;

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