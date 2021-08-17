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

    cin >> n;
    vector<int> a(n), b, odd(1e5 + 5, 0), even(1e5 + 5, 0);
    f(i, n) cin >> a[i];
    b = a;
    sort(b.begin(), b.end());
    f(i, n)
    {
        if (i % 2)
            odd[b[i]]++;
        else
            even[b[i]]++;
    }
    f(i, n)
    {
        if (i % 2)
        {
            if (odd[a[i]] > 0)
                odd[a[i]]--;
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            if (even[a[i]] > 0)
                even[a[i]]--;
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;

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