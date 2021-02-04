//@CodesUp
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
bool lucky(string s)
{
    //cout << s << endl;
    for (auto it : s)
        if (it != '4' && it != '7')
            return false;

    return true;
}
void solve()
{
    int i, j, k;

    string s;
    cin >> s;
    map<int, int> m;
    for (auto it : s)
        m[it - '0']++;

    int sum = m[4] + m[7];
    if (lucky(to_string(sum)))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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