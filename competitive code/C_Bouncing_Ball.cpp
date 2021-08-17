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

int n;

void solve()
{
    int i, j, k, p, x, y;

    cin >> n >> p >> k;
    string s;
    cin >> s;
    cin >> x >> y;
    int ans = 1e9;
    vector<int> a(n, 0);
    for (i = n - 1; i >= 0; i--)
    {
        if (i + k < n)
            a[i] = a[i + k];
        if (s[i] == '0')
            a[i]++;
    }
    for (i = 0; i + p - 1 < n; i++)
    {
        j = i + p - 1;
        int val = i * y;
        if (j < n)
            val += (x * a[j]);
        ans = min(val, ans);
    }
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