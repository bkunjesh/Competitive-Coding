//@CodesUp
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
int N = 200005;

int n;

void solve()
{
    int i, j, k, ans = 0;
    string s;
    cin >> s;
    vector<int> ope, clo, sqope, sqclo;
    i = 0;
    for (auto it : s)
    {
        if (it == '(')
            ope.push_back(i);
        else if (it == ')')
            clo.push_back(i);
        else if (it == '[')
            sqope.push_back(i);
        else
            sqclo.push_back(i);
        i++;
    }
    i = 0, j = 0;
    if (ope.size() != 0 && clo.size() != 0)
        while (i < ope.size() && j < clo.size())
        {
            if (clo[j] < ope[i])
            {
                j++;
            }
            else if (ope[i] < clo[j])
            {
                i++, j++, ans++;
            }
        }
    i = 0, j = 0;
    if (sqope.size() != 0 && sqclo.size() != 0)
        while (i < sqope.size() && j < sqclo.size())
        {
            if (sqclo[j] < sqope[i])
            {
                j++;
            }
            else if (sqope[i] < sqclo[j])
            {
                i++, j++, ans++;
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