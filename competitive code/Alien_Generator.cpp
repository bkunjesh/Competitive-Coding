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
vector<int> sum(N, 0);
void getsum()
{
    f(i, N)
    {
        sum[i] = (i * (i + 1) / 2);
    }
}

void solve()
{
    int i, j, k;

    cin >> n;
    int ans = 0;
    n = 2 * n;

    for (i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i != i)
            {
                int f1 = i;
                int f2 = n / i;
                if ((f1 + f2 - 1) % 2 == 0)
                {
                    ans++;
                }
            }
        }
    }
    // f(i, N)
    // {
    //     if (binary_search(sum.begin()+i, sum.end(), n + sum[i]))
    //     {
    //         ans++;
    //     }
    // }
    cout << ans << endl;
    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    // getsum();
    cin >> t;
    rep(j, t)
    {
        cout << "Case #" << j << ": ";
        solve();
    }
    return 0;
}
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif