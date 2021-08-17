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

    string s;
    cin >> s;
    n = s.size();
    int apos = 0;
    while (apos < n && s[apos] != 'a')
        apos++;
    if (apos >= n)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        i = apos + 1, j = apos - 1;
        char ch = 'b';
        while (j >= 0 || i < n)
        {
            if (i < n && s[i] == ch)
            {
                ch++;
                i++;
            }
            else if (j >= 0 && s[j] == ch)
            {
                ch++;
                j--;
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
    }

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