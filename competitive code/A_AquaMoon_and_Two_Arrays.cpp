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
    int i, j, k, x = 0;

    cin >> n;
    vector<int> a(n), b(n), d(n);
    f(i, n) cin >> a[i];
    f(i, n) cin >> b[i], x += (b[i] - a[i]), d[i] = (b[i] - a[i]);
    if (x != 0)
    {
        cout << -1 << endl;
        return;
    }
    i = 0, j = 0;
    while (i<n&&d[i] <= 0)
        i++;
    while (j<n&&d[j] >= 0)
        j++;
    vector<pair<int, int>> ans;
    // for (auto x : d)
    //     cout << x << " ";
    // cout << endl;
    // cout << i << " " << j << endl;
    while (i < n && j < n)
    {
        if (d[i] == 0)
        {
            while (i < n && d[i] <= 0)
                i++;
        }
        if (d[j] == 0)
        {
            while (j < n && d[j] >= 0)
                j++;
        }
        if (i < n && j < n)
        {
            ans.push_back({j, i});
            d[i]--;
            d[j]++;
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x.F + 1 << " " << x.S + 1 << endl;

    // vector<pair<int, int>> diff,ans;
    // f(i, n) diff.push_back({b[i] - a[i], i});
    // sort(diff.begin(), diff.end());
    // i = 0,j=0;
    // int m = diff.size();

    // while(j<m&&diff[j].F<0)
    //     j++;

    // while(j<m)
    // {

    // }

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