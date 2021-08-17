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

void solve()
{
    int i, j, k;

    string a;
    cin >> a;
    n = a.size();
    int ind = -1, indg = -1;
    for (i = n - 2; i >= 0; i--)
    {
        //cout << a[i];
        if ((a[i] - '0') % 2 == 0)
        {
            if (ind == -1)
                ind = i;
            else if (a[i] < a[n - 1])
                ind = i;

            if (indg == -1 && a[i] > a[n - 1])
                indg = i;
        }
    }
    if (ind == -1)
    {
        if (indg == -1)
            cout << -1 << endl;
        else
        {
            swap(a[indg], a[n - 1]);
            cout << a << endl;
        }
    }
    else
    {
        swap(a[ind], a[n - 1]);
        cout << a << endl;
    }

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