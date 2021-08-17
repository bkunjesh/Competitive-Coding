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
bool isdraw(string s)
{
    for (auto it : s)
    {
        if (it == '0')
            return 0;
    }
    return 1;
}
bool is_pallindrom(string s)
{
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[n - 1 - i])
            return 0;
    }
    return 1;
}
void solve()
{
    int i, j, k;

    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (auto it : s)
        if (it == '0')
            cnt++;
    if (is_pallindrom(s))
    {
        if (n % 2 == 0)
        {
            cout << "BOB" << endl;
            return;
        }
        else
        {
            if (cnt == 1 || cnt % 2 == 0)
            {
                cout << "BOB" << endl;
                return;
            }
            else
            {
                cout << "ALICE" << endl;
                return;
            }
        }
    }
    else
    {
        if (n % 2 && cnt == 2 && s[n / 2] == '0')
        {
            cout << "DRAW" << endl;
            return;
        }
        cout << "ALICE" << endl;
        return;
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