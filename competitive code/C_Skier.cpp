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

int n;

void solve()
{
    int i, j, k, ans = 0;

    string s;
    cin >> s;
    n = s.size();
    map<pair<int, int>, map<pair<int, int>, int>> mp;
    int x = 0, y = 0;
    for (i = 0; i < n; i++)
    {

        if (s[i] == 'N')
        {
            if (mp[{x, y}][{x, y + 1}] == 1 || mp[{x, y + 1}][{x, y}] == 1)
            {
                ans++;
                y++;
                continue;
            }
            mp[{x, y}][{x, y + 1}] = 1;
            mp[{x, y + 1}][{x, y}] = 1;
            ans += 5;
            y++;
        }
        else if (s[i] == 'S')
        {
            if (mp[{x, y}][{x, y - 1}] == 1 || mp[{x, y - 1}][{x, y}] == 1)
            {
                ans++;
                y--;
                continue;
            }
            mp[{x, y}][{x, y - 1}] = 1;
            mp[{x, y - 1}][{x, y}] = 1;
            ans += 5;
            y--;
        }
        else if (s[i] == 'E')
        {
            if (mp[{x + 1, y}][{x, y}] == 1 || mp[{x, y}][{x + 1, y}] == 1)
            {
                ans++;
                x++;
                continue;
            }
            mp[{x + 1, y}][{x, y}] = 1;
            mp[{x, y}][{x + 1, y}] = 1;
            ans += 5;
            x++;
        }
        else if (s[i] == 'W')
        {
            if (mp[{x - 1, y}][{x, y}] == 1 || mp[{x, y}][{x - 1, y}] == 1)
            {
                ans++;
                x--;
                continue;
            }
            mp[{x - 1, y}][{x, y}] = 1;
            mp[{x, y}][{x - 1, y}] = 1;
            ans += 5;
            x--;
        }
    }

    cout << ans << endl;

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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif