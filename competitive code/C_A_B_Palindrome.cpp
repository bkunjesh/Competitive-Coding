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

    int a, b;
    string s;
    cin >> a >> b >> s;
    int acnt = a, bcnt = b;
    n = s.size();
    f(i, n)
    {
        if (s[i] == '0')
            a--;
        else if (s[i] == '1')
            b--;
    }
    j = n - 1;
    for (i = 0; i <= j;)
    {
        if (s[i] != s[j])
        {
            if (s[i] != '?' && s[j] != '?')
            {
                cout << -1 << endl;
                return;
            }
            else
            {
                (s[i] != '?') ? s[j] = s[i]:s[i] = s[j];
                if (s[i] == '0')
                    a -= 1;
                else
                    b -= 1;
            }
        }
        j--;
        i++;
    }
    j = n - 1;
    for (i = 0; i <= j;i++,j--)
    {
        if (i == j)
        {
            if (s[i] == '?')
            {
                if (a >= 1)
                {
                    s[i] = '0';
                    a--;
                }
                else if (b >= 1)
                {
                    s[i] = '1';
                    b--;
                }
                else
                {
                    cout << -1 << endl;
                    return;
                }
            }
        }
        else if (s[i] == s[j])
        {
            if (s[i] == '?' && s[j] == '?')
            {
                if (a >= b && a > 1)
                {
                    s[i] = '0';
                    s[j] = '0';
                    a -= 2;
                }
                else if (a <= b && b > 1)
                {
                    s[i] = '1';
                    s[j] = '1';
                    b -= 2;
                }
                else
                {
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }
    if (a >= 0 && b >= 0)
    {
        cout << s << endl;
    }
    else
    {
        cout << -1 << endl;
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