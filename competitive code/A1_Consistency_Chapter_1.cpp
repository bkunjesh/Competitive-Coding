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

void input(int &n, string &s)
{
    cin >> s;
    n = s.size();
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
    input(n, s);

    unordered_map<char, int> mp;
    int c = 0, v = 0;
    for (auto x : s)
    {
        mp[x]++;
        (isvowel(x)) ? v++ : c++;
    }

    int ans = INT_MAX;

    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        if (isvowel(ch))
        {
            ans = min(ans, c + (v - mp[ch]) * 2);
        }
        else
        {
            ans = min(ans, v + (c - mp[ch]) * 2);
        }
    }

    cout << ans << endl;

    return;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
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