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
    int i, j, k;

    int m;
    cin >> k >> n >> m;
    vector<int> a(n), b(m);
    f(i, n) cin >> a[i];
    f(i, m) cin >> b[i];

    i = 0, j = 0;
    vector<int> ans;
    while (i < n || j < m)
    {
        if (i < n && a[i] == 0)
        {
            while (i < n && a[i] == 0)
            {
                ans.push_back(a[i]);
                i++, k++;
            }
        }
        if (j < m && b[j] == 0)
        {
            while (j < m && b[j] == 0)
            {
                ans.push_back(b[j]);
                j++, k++;
            }
        }
        if (((i < n && a[i] > k) && ((j >= m) || (j < m && b[j] > k))) || ((j < m && b[j] > k) && ((i < n && a[i] > k)||(i>=n))))
        {
            cout << -1 << endl;
            return;
        }
        if ((i < n && a[i] <= k))
        {
            ans.push_back(a[i]);
            i++;
        }
        if ((j < m && b[j] <= k))
        {
            ans.push_back(b[j]);
            j++;
        }
    }
    for (auto it : ans)
        cout << it << " ";
    cout << endl;

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