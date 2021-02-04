//@ikung
#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
// const int inf = 1e18;
const int N = 200005;

int n;

void non_dp_sol(string s)
{
    // time o(n^2) space  o(1)

    n = s.size();
    int mxlen = 1;
    string ans;
    ans = s[0];
    for (i = 0; i < n - 1; i++)
    {
        int l = i - 1, r = i + 1;
        if (l >= 0 && s[l] == s[r])
        {
            string cur = "";
            cur += s[i];
            while (l >= 0 && r < n && s[l] == s[r])
            {
                cur = s[l] + cur + s[r];
                l--, r++;
            }
            if (cur.size() > mxlen)
            {
                mxlen = cur.size();
                ans = cur;
            }
        }
        l = i, r = i;
        if (r < n - 1 && s[l] == s[r + 1])
        {
            r++;
            string cur = "";
            while (l >= 0 && r < n && s[l] == s[r])
            {
                cur = s[l] + cur + s[r];
                l--, r++;
            }
            if (cur.size() > mxlen)
            {
                mxlen = cur.size();
                ans = cur;
            }
        }
    }
    cout << ans << endl;
}

void dp_sol(string s)
{
    n = s.size();
    int i, j, k;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    f(i, n) dp[i][i] = 1;
    f(i,n-1)
    {
        if(s[i]==s[i+1])
            dp[i][i + 1] = 1;
    }
    for (int len = 2; len < n;len++)
    {
        for (i = 0; i < n;i++)
        {
            j = i + len - 1;
            if(s[i]==s[j])
        }
    }
}
void solve()
{
    int i, j, k;
    string s;
    cin >> s;

    non_dp_sol();


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