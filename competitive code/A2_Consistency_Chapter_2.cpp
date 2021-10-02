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

void input(int &n, string &s, vector<vector<int>> &pre)
{
    cin >> s;
    n = s.size();
    for (int i = 0; i < 26; i++)
        pre[i][i] = 0;
    int x;
    cin >> x;
    f(i, x)
    {
        char u, v;
        cin >> u >> v;
        
        pre[u - 'A'][v - 'A'] = 1;
    }
    int i, j, k;
    for (k = 0; k < 26; k++)
    {
        for (j = 0; j < 26; j++)
        {
            for (i = 0; i < 26; i++)
            {
                pre[i][j] = min(pre[i][j], pre[i][k] + pre[k][j]);
            }
        }
    }
}
bool isvowel(char x)
{
    if (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
        return 1;
    return 0;
}
void solve()
{
    int i, j, k, n;
    string s;
    vector<vector<int>> pre(26, vector<int>(26, INT_MAX));
    input(n, s, pre);

    vector<int> mp(26, 0);
    int c = 0, v = 0;
    for (auto x : s)
    {
        mp[x - 'A']++;
        (isvowel(x)) ? v++ : c++;
    }

    int ans = INT_MAX;

    for (i = 0; i < 26; i++)
    {
        int val = 0;
        for (j = 0; j < 26; j++)
        {
            val += (pre[j][i] * mp[j]);
        }
        // dbg(i, val);
        ans = min(ans, val);
    }
    if (ans >= INT_MAX)
        ans = -1;
    cout << ans << endl;

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