//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int getcost(string s, string t)
{
    int cost = 0;
    int n = s.size(), m = t.size(), i = 0, j = 0, match = 0;
    while (i < n && j < m)
    {
        if (s[i] == t[j])
            j++, match++;
        i++;
    }
    // cout << s << " " << t << " ";

    cost = (n - match) + (m - match);
    // dbg(s, t, i, j, match, cost);
    return cost;
}
int n;
void solve()
{
    int i, j, k, ans;

    string s;
    cin >> s;
    ans = s.size() + 1;
    for (i = 0; i < 60; i++)
    {
        int val = getcost(s, to_string(1ll << i));
        // dbg(i, val);

        ans = min(ans, val);
    }
    cout << ans << endl;
    // cout << "---" << endl;
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