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

int longestCommonSubsequence(string s, string t)
{
    int i, j, n = t.size(), m = s.size();
    int dp[n + 1][m + 1];
    f(i, n + 1) f(j, m + 1) dp[i][j] = 0;
    dp[0][0] = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (t[i - 1] == s[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int n;

void solve()
{
    int i, j, k;

    string s, t;
    cin >> s >> t;
    
    map<char, int> In_s, In_t;
    for (auto it : s)
        In_s[it]++;
    for (auto it : t)
        In_t[it]++;
    string forcomp = "";
    for (auto it : t)
    {
        if (In_t[it] > In_s[it])
        {
            cout << "need tree" << endl;
            return;
        }
    }
    int sz = longestCommonSubsequence(s, t);
    // cout << sz << endl;

    if (s.size() == t.size())
    {
        cout << "array" << endl;
    }
    else if (sz == t.size() && s.size() != t.size())
    {
        cout << "automaton" << endl;
    }
    else
    {
        cout << "both" << endl;
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