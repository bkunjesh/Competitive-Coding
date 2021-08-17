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
const int N = 2005;

int n;
vector<string> a(N);
vector<int> ans(10, 0);

void rotatematrix()
{
    int i, j;
    auto rotate = [&](char &a, char &b, char &c, char &d)
    {
        swap(a, b);
        swap(a, c);
        swap(a, d);
    };
    for (i = 0; i <= n / 2; i++)
    {
        for (j = i; j < n - 1 - i; j++)
        {
            rotate(a[i][j], a[j][n - i - 1], a[n - i - 1][n - j - 1], a[n - j - 1][i]);
        }
    }
}

void getans(int k)
{
    int i, j;

    int y_mn = inf, y_mx = -inf;
    f(i, n)
        f(j, n)
    {
        if (a[i][j] - '0' == k)
        {
            y_mn = min(y_mn, j);
            y_mx = max(y_mx, j);
        }
    }
    if (y_mn == inf || y_mx == -inf)
        return;
    // cout << "y_mx: " << y_mx << " y_mn: " << y_mn << endl;
    f(j, n)
    {
        int x_mn = inf, x_mx = -inf;
        f(i, n)
        {
            if (a[i][j] - '0' == k)
            {
                x_mn = min(x_mn, i);
                x_mx = max(x_mx, i);
            }
        }
        if (x_mn == inf && x_mx == -inf)
        {
            continue;
        }

        int h = max(abs(j - y_mn), abs(j - y_mx));
        ans[k] = max({ans[k], ((x_mx - x_mn) * max(j, n - 1 - j)), (max((n - 1 - x_mn), x_mx) * h)});
    }
}

void solve()
{
    int i, j, k;
    a.clear();
    ans.clear();

    cin >> n;
    f(i, n) cin >> a[i];

    f(k, 10)
    {
        ans[k] = 0;
        // cout << "k= " << k << endl;
        getans(k);
    }
    rotatematrix();
    f(k, 10)
    {
        getans(k);
    }

    f(i, 10) cout << ans[i] << " ";
    cout << endl;

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