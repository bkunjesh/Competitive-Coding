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
int prefix_function(string s)
{
    int n = s.size(), i, j;
    vector<int> pi(n);
    for (i = 1; i < n; i++)
    {
        j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
        // cout << pi[i] << " ";
    }
    return pi[n - 1];
}

void solve()
{
    int i, j, k;
    string s;
    cin >> s;
    int len = 0;
    n = s.size();
    j = n - 1, i = 0;
    while (i < j && s[i] == s[j])
        i++, j--, len++;
    string ans = s.substr(0, len);

    string rem = s.substr(len, n - 2 * len);
    string rem_rev = rem;
    reverse(rem_rev.begin(), rem_rev.end());

    if (rem.size() > 0)
    {
        string t = rem + '#' + rem_rev;
        int pre = prefix_function(t);
        t = rem_rev + '#' + rem;
        int suf = prefix_function(t);

        if (pre > suf)
        {
            ans += rem.substr(0, pre);
        }
        else
        {
            ans += rem_rev.substr(0, suf);
        }
    }

    ans += s.substr(n - len, len);
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif