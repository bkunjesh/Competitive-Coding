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

    cin >> n;
    vector<int> a(n), bits(32, 0);
    f(i, n)
    {
        cin >> a[i];
        f(j, 32)
        {
            if ((a[i] & (1 << j)))
                bits[j]++;
        }
    }

    int firstind, maxval = -inf;
    f(i, n)
    {
        int val = a[i];
        f(j, 32)
        {
            if ((a[i] & (1 << j)))
            {
                if (bits[j] != 1)
                {
                    val ^= (1 << j);
                }
            }
        }
        if (maxval < val)
        {
            maxval = val;
            firstind = i;
        }
    }
    cout << a[firstind] << " ";
    f(i, n) if (i != firstind) cout << a[i] << " ";
    cout << endl;

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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif