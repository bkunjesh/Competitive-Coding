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
    int i, j, k;

    cin >> n;
    string s;
    cin >> s;
    i = 0;
    while (i < n && s[i] == '?')
        i++;
    int ans = 0;
    int val = 0;
    char prev = '$';
    for (; i < n; i++)
    {
        if (s[i] == '?')
        {
            s[i] = (s[i - 1] == 'B') ? 'R' : 'B';
        }
        // if(s[i]=='?')
        // {
        //     val++;
        //     continue;
        // }
        // else{

        //     if(i>0&&s[i-1]=='?')
        //     {
        //         if ((prev == s[i] && val % 2 == 0) || (prev != s[i] && val%2==1))
        //         {
        //             ans++;
        //         }
        //     }
        //     else if(i>0&&s[i-1]==s[i])
        //     {
        //         ans++;
        //     }

        //     prev = s[i];
        //     val = 0;
        // }
    }

    for (i = n - 1; i >= 0; i--)
    {
        if (s[i] == '?')
        {
            s[i] = (s[i + 1] == 'B') ? 'R' : 'B';
        }
    }
    cout << s << endl;

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