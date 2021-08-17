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
int ans = 0;
void reduce(vector<int> &a)
{
    int i, j, k;
    if (a[0] > a[1])
    {
        ans += (a[0] - a[1]);
        a[0] = a[1];
    }
    for (i = 1; i < n - 1; i++)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
        {
            ans += min(abs(a[i] - a[i + 1]), abs(a[i] - a[i - 1]));
            a[i] = max(a[i - 1], a[i + 1]);
        }
    }
    if (a[n - 1] > a[n - 2])
    {
        ans += (a[n - 1] - a[n - 2]);
        a[n - 1] = a[n - 2];
    }
}
void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    ans = 0;
    if (n == 1)
    {
        cout << a[0] << endl;
        return;
    }
    if (n > 1)
        reduce(a);
    for (i = 1; i < n; i++)
        ans += (abs(a[i - 1] - a[i]));
    ans += (a[0] + a[n - 1]);
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