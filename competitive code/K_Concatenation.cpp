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
const int N = 200005;

int n;

void solve()
{
    int i, j, k;

    cin >> n >> k;
    int a[n + 1];
    f(i, n) cin >> a[i];


    int mx = a[0];
    int local_mx = a[0];

    for (i = 1; i < n; i++)
    {
        local_mx = max(local_mx + a[i], a[i]);
        mx = max(mx, local_mx);
    }

    if (k == 1)
    {
        cout << mx << endl;
        return;
    }
    

    int prefmx=INT_MIN,cur=0, sufmx=INT_MIN;

    for (i = 0; i < n; i++)    cur += a[i], prefmx = max(prefmx, cur);
    cur = 0;
    for (j = n - 1; j >= 0; j--)    cur += a[j], sufmx = max(sufmx, cur);


    mx = max({mx,prefmx+sufmx, prefmx + sufmx + cur * (k - 2)});

    cout << mx << endl;
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