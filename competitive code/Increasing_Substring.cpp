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

    string s;
    cin >> n >> s;
    vector<int> ans(n, 1);
    for (i = 1; i < n; i++)
    {
        if (s[i] > s[i - 1])
        {
            ans[i] = ans[i - 1] + 1;
        }
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif