//@CodesUp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (i = 1; i <= n; i++)
#define rew(i, a, b) for (ll i = a; i <= b; i++)
#define mod 1000000007
const ll inf = 1e18;

ll n;

void solve()
{
    ll i, j, k, change = 0;

    cin >> n;
    string s, ans;
    cin >> s;
    if (n == 1)
    {
        cout << 0 << endl
             << s << endl;
        return;
    }

    for (i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            //cout << i << " ";
            change++;
            if ((s[i] == 'G' || s[i] == 'R') && s[i + 1] != 'B')
            {
                s[i] = 'B';
            }
            else if ((s[i] == 'G' || s[i] == 'B') && s[i + 1] != 'R')
            {
                s[i] = 'R';
            }
            else if ((s[i] == 'B' || s[i] == 'R') && s[i + 1] != 'G')
            {
                s[i] = 'G';
            }
        }
    }
    cout << change << endl;
    f(i, n) cout << s[i];
    cout << endl;

    return;
}

int main()
{
    fast
        ll t = 1,
           i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}