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

    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    n = s.size();
    s = s;
    int dp[s.size() + 2] = {0}, flag = 0, pref[s.size() + 2] = {0};
    i = 0;
    for (i = 1; i < n; i++)
    {
        if (s[i - 1] == '1' && s[i] == '0')
            pref[i] = 1;
        else if (s[i] == '0')
            pref[i] = pref[i - 1] + 1;
        else
            pref[i] = pref[i - 1];

        //cout << pref[i] << " ";
    }
    i = 0;
    for (auto it : s)
    {

        if (it == '0' && flag)
        {
            break;
        }
        if (it == '1' && flag == 0)
        {
            flag = 1;
        }
        i++;
    }
    //cout << i << " ";
    if(i==n&&flag==0)
    {
        cout << 0 << endl;
        return;
    }
    int boom = 0;
    for (; i < s.size(); i++)
    {
        dp[i] = dp[i - 1];
        if (s[i] == '1' && s[i - 1] == '0')
        {
            if (b * pref[i] + dp[i - 1] > dp[i - 1] + a)
            {
                dp[i] = dp[i - 1] + a;
                boom = 1;
            }
            else
            {
                dp[i] = b * pref[i] + dp[i - 1];
                boom = 0;
            }
        }

        //cout<<dp[i]<<" ";
    }
    // if(boom)
    // cout << dp[n-1] << endl;
    // else
    cout << dp[n - 1] + a << endl;

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