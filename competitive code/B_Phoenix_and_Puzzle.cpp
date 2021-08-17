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

bool isPerfectSquare(long double x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0)
    {

        long long sr = sqrt(x);

        // if product of square root
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}

void solve()
{
    int i, j, k;
    cin >> n;
    if (n % 2)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        k = n;
        rep(j, 32)
        {
            int p = (1 << j), flag = 1;
            n = k;
            if (n % p)
                continue;
            n = n / p;
            if (isPerfectSquare(n))
            {
                cout << "YES" << endl;
                return;
            }
            // if (flag && n == 1)
            // {
            //     cout << "YES" << endl;
            //     return;
            // }
        }
        cout << "NO" << endl;
    }

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    i = 2;

    // cout << temp.size() << endl;
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