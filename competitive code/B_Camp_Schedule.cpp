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

int prefix_function(string s)
{

    // https://cp-algorithms.com/string/prefix-function.html

    int n = s.size(), i, j;
    vector<int> pi(n + 1);

    for (i = 1; i < n; i++)
    {
        j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
        // cout << pi[i] << " ";
    }

    return pi[n - 1];
}

int n;

void solve()
{
    int i, j, k, m;

    string s, t;
    cin >> s >> t;
    n = s.size();
    m = t.size();
    int socnt = 0, szcnt = 0, tocnt = 0, tzcnt = 0;
    for (auto it : s)
        (it == '0') ? szcnt++ : socnt++;
    for (auto it : t)
        (it == '0') ? tzcnt++ : tocnt++;

    int cmn = prefix_function(t);

    string ans = "";
    while (socnt >= tocnt && szcnt >= tzcnt)
    {
        ans += t;
        socnt -= tocnt;
        szcnt -= tzcnt;
        break;
    }

    string newt = t.substr(cmn);
    tzcnt = tocnt = 0;
    for (auto it : newt)
        (it == '0') ? tzcnt++ : tocnt++;

    while (socnt >= tocnt && szcnt >= tzcnt)
    {
        ans += newt;
        socnt -= tocnt;
        szcnt -= tzcnt;
    }

    string zero(szcnt, '0');
    string one(socnt, '1');
    // dbg(zero, one);
    cout << ans + one + zero << endl;
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