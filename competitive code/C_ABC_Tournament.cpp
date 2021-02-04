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

void cmax(int &a, int &b)
{
    a = max(a, b);
    //b = a;
}

void solve()
{
    int i, j, k;

    cin >> n;
    int m = pow(2, n);
    vector<int> a(m);
    
    f(i, m) cin >> a[i];
    auto b = a;

    for (i = 0; i < n - 1; i++)
    {
        // dbg(i);
        int to_com_sz = pow(2, i);
        for (j = 0; j < m;)
        {
            cmax(a[j], a[j + to_com_sz]);
            // cout << a[j] << " " << a[j + to_com_sz] << " " << pow(2, i + 1) << endl;

            j += pow(2, i + 1);
        }
    }
    k = min(a[0], a[pow(2, i)]);
    // if (n == 1)
    // {

    //     cmax(a[0], a[1]);

    // }
    //cout << k << " ";

    f(i, m) if (b[i] == k) cout << i + 1 << endl;

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

