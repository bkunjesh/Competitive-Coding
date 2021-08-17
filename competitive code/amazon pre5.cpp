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

const int N = 2000005;

int prime[N];
void primeHelp()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i < N; i++)
    {
        for (int j = i + i; prime[i] == 0 && j < N; j += i)
            prime[j] = 1;
    }
}
int toint(string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        res = res * 10 + (s[i] - '0');
    }
    return res;
}
bool isprime(int n)
{
    return (!prime[n]);
}
bool isprime(string s)
{
    return isprime(toint(s));
}
bool isvalidstring(string s, map<string, int> &m)
{
    if (isprime(s) && m[s] == 0 && s[0] != '0')
    {
        return 1;
    }
    return 0;
}

int ans;

void getans(int ind, string &s, map<string, int> &m)
{
    if (ind >= s.size())
    {
        for (auto it : m)
        {
            if (it.S == 1)
            {
                cout << it.F << " ";
            }
        }
        cout << endl;
        ans++;
        return;
    }

    for (int i = ind; i < s.size() && (i < ind + 7); i++)
    {
        int len = i - ind + 1;
        string str = s.substr(ind, len);

        if (isvalidstring(str, m))
        {
            m[str] = 1;
            getans(i + 1, s, m);
            m[str] = 0;
        }
    }
}

int n;
int uniquePrimeString(string s)
{
    map<string, int> m;
    getans(0, s, m);
    cout << ans << endl;
    return ans;
}
void solve()
{
    int i, j, k;
    primeHelp();
    string s = "3177";
    // string s = "52307";
    uniquePrimeString(s);

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