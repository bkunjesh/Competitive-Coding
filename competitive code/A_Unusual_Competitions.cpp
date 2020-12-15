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
    int i, j, k, cnt = 0, ans = 0, op = 0, cl = 0;

    cin >> n;
    string s;
    vector<int> a(n);
    cin >> s;
    i = 0;
    for (auto it : s)
    {
        if (it == '(')
            cnt++, op++;
        else
            cnt--, cl++;
        a[i] = cnt;
        if (cnt < 0||(i>0&&a[i-1]<0&&a[i]==0))
            ans++;
        i++;
    }
    if (op == cl)
    {
        cout << ans << endl;
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
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}