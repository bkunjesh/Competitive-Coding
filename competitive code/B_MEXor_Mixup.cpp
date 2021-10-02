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
const int N = 300005;

int n;
vector<int> prexor(N, 0);
void precal()
{
    rep(i, N - 1)
        prexor[i] = prexor[i - 1] ^ i;
}

void solve()
{
    int i, j, k;

    int a, b;
    cin >> a >> b;
    // dbg(prexor[a - 1]);

    if (prexor[a - 1] == b)
    {
        cout << a << endl;
    }
    else if ((prexor[a - 1] ^ b) == a)
    {
        // dbg(prexor[a - 1] ^ b, a);
        cout << a + 2 << endl;
    }
    else
    {
        cout << a + 1 << endl;
    }

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    precal();
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