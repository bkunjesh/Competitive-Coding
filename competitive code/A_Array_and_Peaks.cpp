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

    cin >> n >> k;
    // if (n < 3 && k > 0)
    // {
    //     cout << -1 << endl;
    //     return;
    // }
    vector<int> a(n);
    f(i, n) a[i] = i + 1;

    int cnt = 0, flag = 0;
    for (i = 1; (i < n - 1) && k; i += 2)
    {
        swap(a[i], a[i + 1]);
        cnt++;
        if (cnt == k)
        {
            flag = 1;
            break;
        }
    }
    if (cnt == k)
    {
        flag = 1;
    }
    if (flag)
    {
        for (auto it : a)
            cout << it << " ";
        cout << endl;
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif