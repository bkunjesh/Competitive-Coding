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

int n, num, deno;
string a;
bool isValid(string a, string b)
{
    int acnt = 0;
    for (auto it : a)
    {
        if (it == '+')
            acnt++;
        else
            acnt--;
    }
    int bcnt = 0;
    for (auto it : b)
    {
        if (it == '+')
            bcnt++;
        else
            bcnt--;
    }
    return acnt == bcnt;
}

void comp(string b, int ind)
{
    if (ind == n)
    {
        deno++;
        if (isValid(a, b))
            num++;
        return;
    }
    if (b[ind] == '?')
    {
        string temp = b;
        temp[ind] = '+';
        comp(temp, ind + 1);
        temp[ind] = '-';
        comp(temp, ind + 1);
    }
    else
    {
        comp(b, ind + 1);
    }
}

void solve()
{
    int i, j, k;

    string b;
    cin >> a >> b;
    n = a.size();
    comp(b, 0);
    cout << fixed << setprecision(12) << (num * 1.0) / (deno * 1.0) << endl;

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