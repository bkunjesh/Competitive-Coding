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

    vector<vector<int>> a(3, vector<int>(2));
    f(i, 3) f(j, 2) cin >> a[i][j];
    if ((abs(a[0][0] - a[1][0]) != 0 && abs(a[0][1] - a[1][1]) != 0))
        cout << abs(a[0][0] - a[1][0]) + abs(a[0][1] - a[1][1]) << endl;
    else
    {
        if ((abs(a[0][0] - a[1][0]) == 0 && (a[2][0]==a[0][0]) && a[2][1] > min(a[0][1], a[1][1]) && a[2][1] < max(a[0][1], a[1][1])) || (abs(a[0][1] - a[1][1]) == 0 && (a[2][1]==a[0][1]) && a[2][0] > min(a[0][0], a[1][0]) && a[2][0] < max(a[0][0], a[1][0])))
            cout << abs(a[0][0] - a[1][0]) + abs(a[0][1] - a[1][1]) + 2 << endl;
        else
            cout << abs(a[0][0] - a[1][0]) + abs(a[0][1] - a[1][1]) << endl;
    }

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