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
    string s;
    cin >> s;
    int a[26] = {0};
    for (auto it : s)
        a[it - 'a']++;
    int pair = 0, rem = 0;
    f(i, 26) pair += a[i] / 2, rem += a[i] % 2;
    int ans = min(pair, rem);
    pair -= ans;
    if (pair > 0)
    {
        int temp = pair / 3;
        ans += temp*2 ;
        if(pair%3==2)
            ans++;
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