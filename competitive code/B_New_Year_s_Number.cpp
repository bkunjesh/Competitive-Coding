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

    cin >> n;
    int x = 0, y = 0;

    for (i = 0; i <= 1e3; i++)
    {
        for (j = 0; j <= 1e3; j++)
        {
            int temp = 2020 * i + 2021 * j;
            //cout << temp << " ";
            if (temp == n)
            {
                cout << "YES" << endl;
                return;
            }
            if (temp > n)
                break;
        }
    }
    cout << "NO" << endl;

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