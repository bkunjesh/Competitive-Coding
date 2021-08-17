//@ikung
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
// const int inf = 1e18;
const int N = 10000005;

int n;
int C[N], ans[N];
void calc()
{
    memset(ans, -1, sizeof(ans));
    // memset(C, 1, sizeof(C));
    // C[0] = 0;
    rew(i, 1, 1e7) C[i] = 1;
    for (int i = 2; i <= 1e7; i++)
    {
        for (int j = i; j <= 1e7; j += i)
        {
            C[j] += i;
        }
    }
    for (int i = 1; i <= 1e7; i++)
    {
        if (C[i] <= 1e7 && ans[C[i]] == -1)
            ans[C[i]] = i;
    }
}
void solve()
{
    int i, j, k;

    cin >> n;
    cout << ans[n] << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    calc();
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