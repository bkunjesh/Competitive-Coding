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

    int a, b, c;
    cin >> a >> b >> c;
    vector<int> ans;
    for (i = 1; i <= 81; i++)
    {
        int x = 1;
        f(j, a) x = x * i;
        x = x * b;
        x += c;
        k = x;
        // cout << i << " " << x << ","<< " ";
        if (k > 1e9)
            continue;
        int digsum = 0;
        while (x)
        {
            // cout << (x % 10) << ",";
            digsum += (x % 10);
            x /= 10;
        }
        // cout << digsum << endl;
        if (digsum == i)
        {
            ans.push_back(k);
        }
    }
    cout << ans.size() << endl;
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif