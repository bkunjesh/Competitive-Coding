//@ikung
#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
// const int inf = 1e18;
const int N = 200005;

int n;

void solve()
{
    int i, j, k;

    int x;
    cin >> x;
    vector<int> ans;
    int step = 0;
    // cout << (((39 ^ 63) + 1) ^ 31)+1 << " ";
    while (x > 0)
    {
        int y = x;
        int cnt = floor(log2(y + 1));
        if (x == ((1 << cnt) - 1))
        {
            break;
        }

        int pw = (1 << (cnt + 1));
        x = (x ^ (pw - 1));
        ans.push_back((cnt + 1));
        step++;

        y = x;

        cnt = floor(log2(y + 1));

        if (x == ((1 << cnt) - 1))
        {
            break;
        }

        x = x + 1;
        step++;

        y = x;

        cnt = floor(log2(y + 1));

        if (x == ((1 << cnt) - 1))
        {
            break;
        }
    }

    cout << step << endl;
    for (auto it : ans)
        cout << it << " ";

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