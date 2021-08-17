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

    cin >> n >> k;

    // https://codeforces.com/contest/1511/submission/112952675
    // vector<int> ans;
    // vector<int> nxt(30, 0);
    // iota(nxt.begin(), nxt.end(), 0);
    // ans.push_back(0);
    // for (i = 1; i < n; i++)
    // {
    //     int prev = ans.back();
    //     ans.push_back(nxt[prev]);
    //     nxt[prev]++;
    //     if (nxt[prev] == k)
    //         nxt[prev] = 0;
    // }
    // for (auto it : ans)
    //     cout << char('a' + it);

    //https://codeforces.com/contest/1511/submission/112899219
    string s = "";
    for (i = 0; i < k; i++)
    {
        s += ('a' + i);
        for (j = i + 1; j < k; j++)
        {
            s += ('a' + i);
            s += ('a' + j);
        }
    }
    while (s.size() < n)
        s += s;
    s.resize(n);
    cout <<s<< endl;
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