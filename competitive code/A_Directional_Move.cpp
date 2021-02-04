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
    string s;
    cin >> s;
    int ans = 0;
    for (auto it : s)
    {
        if (it == '1')
            ans++;
        else
            ans--;
    }
    if (ans >= 0)
    {
        if (ans % 4 == 0)
            cout << "E" << endl;
        else if (ans % 2 == 0)
            cout << "W" << endl;
        else if (ans % 4 == 1)
            cout << "N" << endl;
        else
            cout << "S" << endl;
    }
    else
    {
        ans = -ans;
        if (ans % 4 == 0)
            cout << "E" << endl;
        else if (ans % 2 == 0)
            cout << "W" << endl;
        else if (ans % 4 == 1)
            cout << "S" << endl;
        else
            cout << "N" << endl;
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