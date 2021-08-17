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

    int x;
    cin >> n >> k >> x;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> add;
    rep(i, n - 1)
    {
        int p = a[i] - a[i - 1];
        int q = p / x;
        if (p != 0 && p % x == 0)
            q--;
        // cout << q << " ";
        add.push_back(q);
    }
    sort(add.begin(), add.end());
    for (i = 0; i < add.size(); i++)
    {
        if (k >= add[i])
        {
            k -= add[i];
        }
        else
        {
            break;
        }
    }
    cout << add.size() - i + 1 << endl;

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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif