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

int sol(int n, int k)
{
    string s = to_string(n);
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int d = s[i] - '0';
        if (9 - d <= k)
        {
            s[i] += (9 - d);
            k -= (9 - d);
        }
        else
        {
            s[i] += k;
            k -= k;
        }
        ans = ans * 10 + (s[i] - '0');
    }
    // dbg(ans);
    return ans;
}

void solve()
{
    int i, j, k;
    sol(191, 4);

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